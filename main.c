#include <stdio.h>
#include "pico/stdlib.h"

int main() {
  stdio_init_all();
  for(int pin=0;pin<7;pin++){
    gpio_init(pin);
    gpio_set_dir(pin,true);
  }
  
  gpio_init(10);
  gpio_init(11);
  gpio_init(12);
  gpio_set_dir(10,false);
  gpio_set_dir(11,false);
  gpio_set_dir(12,false);
  
  int boton =0;
  uint8_t digitos[]={
    ~0x01,
    ~0x4f,
    ~0x12,
    ~0x06,
    ~0x4c,
    ~0x24,
    ~0x20,
    ~0x0f,
    ~0x00,
    ~0x0c,
  };

  while (true){
    if(gpio_get(10)==true) {
      boton=boton+1;
    }
    else if(gpio_get(11)==true){
      boton=boton-1;
    }
    else if(gpio_get(12)==true){
      boton=0;
    }
    for(int i=0;i<7;i++){
      bool val = digitos[boton] & (1<<i);
      gpio_put(i, (bool) val);
    }
    sleep_ms(500);
  }
}
