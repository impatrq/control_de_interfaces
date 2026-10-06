#include <stdio.h> 
#include "pico/stdlib.h"  
/*
int main() {   
    const uint LED_PIN = 27; 
    gpio_init(LED_PIN);  
    gpio_set_dir(LED_PIN, GPIO_OUT); 
    while (true) { 
        gpio_put(LED_PIN, 1);         
        sleep_ms(500);         
        gpio_put(LED_PIN, 0);         
        sleep_ms(500);     
    }
} 
*/

/*
int main() {    
    const uint LED_PIN = 27;  
    gpio_init(LED_PIN);       
    gpio_set_dir(LED_PIN, GPIO_OUT);     
    const uint BUTTON_PIN = 8;      
    gpio_init(BUTTON_PIN);     
    gpio_set_dir(BUTTON_PIN, GPIO_IN);      
    int BUTTON_VALUE = 0 ;       
    while (true) {          
        BUTTON_VALUE = gpio_get(BUTTON_PIN);         
        if (BUTTON_VALUE == 1) {           
        gpio_put(LED_PIN, 1);         
        }         
        else{           
            gpio_put(LED_PIN, 0);         
        }     
    } 
} 
*/

int main() {    
    const uint LED1 = 6;  
    gpio_init(LED1);       
    gpio_set_dir(LED1, GPIO_OUT);     
    const uint BUTTON1 = 20;      
    gpio_init(BUTTON1);     
    gpio_set_dir(BUTTON1, GPIO_IN);      
    int BUTTON1_VALUE = 0 ; 

    const uint LED2 = 7;  
    gpio_init(LED2);       
    gpio_set_dir(LED2, GPIO_OUT);     
    const uint BUTTON2 = 21;      
    gpio_init(BUTTON2);     
    gpio_set_dir(BUTTON2, GPIO_IN);      
    int BUTTON2_VALUE = 0 ;    

    const uint LED3 = 8;  
    gpio_init(LED3);       
    gpio_set_dir(LED3, GPIO_OUT);     
    const uint BUTTON3 = 22;      
    gpio_init(BUTTON3);     
    gpio_set_dir(BUTTON3, GPIO_IN);      
    int BUTTON3_VALUE = 0 ;  

    while (true) {          
        BUTTON1_VALUE = gpio_get(BUTTON1);         
        if (BUTTON1_VALUE == 1) {           
        gpio_put(LED1, 1);         
        }         
        else{           
            gpio_put(LED1, 0);         
        }     
        BUTTON2_VALUE = gpio_get(BUTTON2);         
        if (BUTTON2_VALUE == 1) {           
        gpio_put(LED2, 1);         
        }         
        else{           
            gpio_put(LED2, 0);         
        }    
        BUTTON3_VALUE = gpio_get(BUTTON3);         
        if (BUTTON3_VALUE == 1) {           
        gpio_put(LED3, 1);         
        }         
        else{           
            gpio_put(LED3, 0);         
        }      
    } 
}  