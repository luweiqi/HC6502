#include <stdio.h>
#include <stdlib.h>
#include "acia.h"
#include "led.h"
#include "utils.h"

#include "uart.h"
#include "gpio.h"

#include "ps2.h"
#include "vga.h"

#define HC6502_REV  "v1.0"

char sys_banner[] = {"hc6502 system buildtime [" __TIME__ " " __DATE__ "] " "rev " HC6502_REV};

void mdelay(int ms)
{
    delay_ms(ms);
}

long main() 
{
  int count = 5;

  uart_init();
  led_init();

  while(count--) {
    led_set(1);
    uart_puts("6502 HomeComputer ready.\r\n");
    mdelay(500);
    led_set(0);
    mdelay(500);
  }

  uart_puts("uart test start.\r\n");

  uart_puts("uart test ok.\r\n");

  uart_printf("%s\r\n", sys_banner);

  uart_printf("sizeof(char):  %d \r\n", sizeof(char));
  uart_printf("sizeof(short): %d \r\n", sizeof(short));
  uart_printf("sizeof(int): %d \r\n", sizeof(int));
  uart_printf("sizeof(long): %d \r\n", sizeof(long));

  ps2_init();
  vga_init();

  while(1) {
    //c = uart_getc();
    //uart_putc(c);
    uart_handler();

  }

  return 0;
}
