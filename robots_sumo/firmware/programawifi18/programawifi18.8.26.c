#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwip/pbuf.h"
#include "lwip/tcp.h"

// Definición de pines para los motores
#define MOTOR1_IN1 8
#define MOTOR1_IN2 7
#define MOTOR2_IN1 19
#define MOTOR2_IN2 20
#define SERVO 12
// HTML ultra liviano con AJAX
const char *HTML_CONTENT = 
"HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=utf-8\r\n\r\n"
"<!DOCTYPE html><html><head><title>Control Pico W</title></head>"
"<body style='font-family:sans-serif; text-align:center; margin-top:50px;'>"
"<h1>Control Pico W en C</h1>"
"<p>Usa <b>W, A, S, D</b> para motores y la <b>Barra Espaciadora</b> para el SERVO.</p>"
"<h2 id='st'>Estado: Esperando comando...</h2>"
"<script>"
"function enviar(cmd) {"
"  var xhr = new XMLHttpRequest();"
"  xhr.open('GET', '/cmd?action=' + cmd, true);"
"  xhr.onreadystatechange = function() {"
"    if (xhr.readyState == 4 && xhr.status == 200) {"
"      document.getElementById('st').innerText = 'Accion: ' + xhr.responseText;"
"    }"
"  };"
"  xhr.send();"
"}"
"document.addEventListener('keydown', function(e) {"
"  if (e.repeat) return;"
"  if (e.code === 'Space') { e.preventDefault(); enviar('space'); }"
"  else if (e.key === 'w' || e.key === 'W') { enviar('w'); }"
"  else if (e.key === 's' || e.key === 'S') { enviar('s'); }"
"  else if (e.key === 'a' || e.key === 'A') { enviar('a'); }"
"  else if (e.key === 'd' || e.key === 'D') { enviar('d'); }"
"});"
"document.addEventListener('keyup', function(e) {"
"  if (['w','W','s','S','a','A','d','D'].includes(e.key)) { enviar('stop'); }"
"});"
"</script></body></html>";

const char *RESP_OK = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n";

// Variables de estado globales que procesará el loop principal
typedef enum { CMD_NONE, CMD_STOP, CMD_W, CMD_S, CMD_A, CMD_D, CMD_SPACE } command_t;
static volatile command_t current_cmd = CMD_NONE;
static bool led_state = false;

// Callback HTTP: solo lee la orden y responde rápido al navegador
static err_t server_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
    if (p == NULL) {
        tcp_close(tpcb);
        return ERR_OK;
    }

    char buffer[512];
    int len = p->tot_len > sizeof(buffer) - 1 ? sizeof(buffer) - 1 : p->tot_len;
    pbuf_copy_partial(p, buffer, len, 0);
    buffer[len] = '\0';

    tcp_recved(tpcb, p->tot_len);
    pbuf_free(p);

    char resp_msg[64] = "OK";

    // ORDEN ESTRICTO: Evaluamos primero palabras largas ('space', 'stop') antes que letras sueltas ('s')
    if (strstr(buffer, "GET /cmd?action=space") != NULL) {
        current_cmd = CMD_SPACE;
        strcpy(resp_msg, "LED Toggled");
    }
    else if (strstr(buffer, "GET /cmd?action=stop") != NULL) {
        current_cmd = CMD_STOP;
        strcpy(resp_msg, "Detenido");
    }
    else if (strstr(buffer, "GET /cmd?action=w") != NULL) {
        current_cmd = CMD_W;
        strcpy(resp_msg, "Avanzando");
    } 
    else if (strstr(buffer, "GET /cmd?action=s") != NULL) {
        current_cmd = CMD_S;
        strcpy(resp_msg, "Retrocediendo");
    } 
    else if (strstr(buffer, "GET /cmd?action=a") != NULL) {
        current_cmd = CMD_A;
        strcpy(resp_msg, "Izquierda");
    } 
    else if (strstr(buffer, "GET /cmd?action=d") != NULL) {
        current_cmd = CMD_D;
        strcpy(resp_msg, "Derecha");
    } 
    else {
        // Enviar la página HTML completa si entra a la raíz
        tcp_write(tpcb, HTML_CONTENT, strlen(HTML_CONTENT), TCP_WRITE_FLAG_COPY);
        tcp_output(tpcb);
        tcp_close(tpcb);
        return ERR_OK;
    }

    // Armar respuesta HTTP de texto plano dinámica para AJAX
    char full_resp[128];
    snprintf(full_resp, sizeof(full_resp), "%s%s", RESP_OK, resp_msg);
    tcp_write(tpcb, full_resp, strlen(full_resp), TCP_WRITE_FLAG_COPY);
    tcp_output(tpcb);led_state;
    tcp_close(tpcb);
    return ERR_OK;
}

static err_t server_accept(void *arg, struct tcp_pcb *newpcb, err_t err) {
    tcp_recv(newpcb, server_recv);
    return ERR_OK;
}

int main() {
    stdio_init_all();

    // Inicializar pines de motores como salida
    gpio_init(MOTOR1_IN1); gpio_set_dir(MOTOR1_IN1, GPIO_OUT);
    gpio_init(MOTOR1_IN2); gpio_set_dir(MOTOR1_IN2, GPIO_OUT);
    gpio_init(MOTOR2_IN1); gpio_set_dir(MOTOR2_IN1, GPIO_OUT);
    gpio_init(MOTOR2_IN2); gpio_set_dir(MOTOR2_IN2, GPIO_OUT);
    gpio_init(SERVO); gpio_set_dir(SERVO, GPIO_OUT);
    
    
    // Arrancar con motores detenidos
    gpio_put(MOTOR1_IN1, 0); gpio_put(MOTOR1_IN2, 0);
    gpio_put(MOTOR2_IN1, 0); gpio_put(MOTOR2_IN2, 0);

    // Inicializar Wi-Fi
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    cyw43_arch_enable_sta_mode();
    printf("Connecting to Wi-Fi...\n");
    
    if (cyw43_arch_wifi_connect_timeout_ms("Cooperadora Alumnos",NULL, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("failed to connect.\n");
        return 1;
    } else {
        printf("Connected.\n");
        uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);
        printf("IP address %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    }

    // Configurar Servidor TCP en puerto 80
    struct tcp_pcb *pcb = tcp_new();
    if (!pcb) return 1;

    if (tcp_bind(pcb, IP_ADDR_ANY, 80) != ERR_OK) return 1;

    pcb = tcp_listen(pcb);
    tcp_accept(pcb, server_accept);
    printf("Servidor web iniciado en el puerto 80.\n");

    // Bucle principal seguro
    while (true) {
        cyw43_arch_poll(); // Mantiene vivo el stack de red

        // Procesamos los comandos fuera de las interrupciones de red usando ifs
        
        uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);
        printf("IP address %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);

        if (current_cmd != CMD_NONE) {
            if (current_cmd == CMD_W) {
                gpio_put(MOTOR1_IN1, 1); gpio_put(MOTOR1_IN2, 0);
                gpio_put(MOTOR2_IN1, 1); gpio_put(MOTOR2_IN2, 0);
                printf("Motores: Adelante (W)\n");
            }
            else if (current_cmd == CMD_S) {
                gpio_put(MOTOR1_IN1, 0); gpio_put(MOTOR1_IN2, 1);
                gpio_put(MOTOR2_IN1, 0); gpio_put(MOTOR2_IN2, 1);
                printf("Motores: Atrás (S)\n");
            }
            else if (current_cmd == CMD_A) {
                gpio_put(MOTOR1_IN1, 0); gpio_put(MOTOR1_IN2, 1);
                gpio_put(MOTOR2_IN1, 1); gpio_put(MOTOR2_IN2, 0);
                printf("Motores: Izquierda (A)\n");
            }
            else if (current_cmd == CMD_D) {
                gpio_put(MOTOR1_IN1, 1); gpio_put(MOTOR1_IN2, 0);
                gpio_put(MOTOR2_IN1, 0); gpio_put(MOTOR2_IN2, 1);
                printf("Motores: Derecha (D)\n");
            }
            else if (current_cmd == CMD_STOP) {
                gpio_put(MOTOR1_IN1, 0); gpio_put(MOTOR1_IN2, 0);
                gpio_put(MOTOR2_IN1, 0); gpio_put(MOTOR2_IN2, 0);
                printf("Motores: Detenidos\n");
            }
            else if (current_cmd == CMD_SPACE) {
                led_state = !led_state;
                gpio_put(SERVO, led_state ? 1 : 0);
                printf("LED Interno: %s\n", led_state ? "ENCENDIDO" : "APAGADO");
            }

            current_cmd = CMD_NONE; // Limpiar comando procesado
        }

        sleep_ms(10);
    }

    cyw43_arch_deinit();
    return 0;
}
