#ifndef SPI_ST7735S_ARCH_H
#define SPI_ST7735S_ARCH_H

#include <stdint.h>

/* 延迟函数 */
void st7735s_arch_delay_ms(uint16_t delay_ms);

/* SPI通讯 */
// 发送数据
uint8_t st7735s_arch_spi_send(const uint8_t *data, uint16_t data_length);
// 接收数据
uint8_t st7735s_arch_spi_receive(uint8_t *buffer,  uint16_t data_length, uint16_t buffer_length);

/* GPIO通讯 */
// RST硬件复位引脚
void st7735s_arch_gpio_write_RST(uint8_t value);
// DC引脚, 为高时表示传递的是数据信息, 为低时表示传递的是指令
void st7735s_arch_gpio_write_DC(uint8_t value);
// CS片选引脚
void st7735s_arch_gpio_write_CS(uint8_t value);

#endif // SPI_ST7735S_ARCH_H