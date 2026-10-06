#include <stdio.h> 
#include "pico/stdlib.h"  

int main() { 
  const uint PIN_IN1 = 17; 
  gpio_init(PIN_IN1);  
  gpio_set_dir(PIN_IN,1 GPIO_OUT); 

  const uint PIN_IN2 = 27; 
  gpio_init(PIN_IN2);  
  gpio_set_dir(PIN_IN2, GPIO_OUT); 

	const uint PIN_IN3= 28; 
  gpio_init(PIN_IN3);  
  gpio_set_dir(PIN_IN3, GPIO_OUT); 

	const uint PIN_IN4 = 19; 
  gpio_init(PIN_IN4);  
  gpio_set_dir(PIN_IN4, GPIO_OUT); 

  while (true) { 
		gpio_put(PIN_IN1, 1);
		gpio_put(PIN_IN2, 0);

		gpio_put(PIN_IN3, 1);
		gpio_put(PIN_IN4, 0);
		sleep_ms(5000); 


		gpio_put(PIN_IN1, 0);
		gpio_put(PIN_IN2, 1);

		gpio_put(PIN_IN3, 0);
		gpio_put(PIN_IN4, 1);
		sleep_ms(5000); 
	}
}
