#ifndef SPI_ST7735S_ARCH_H
#define SPI_ST7735S_ARCH_H

#include <stdint.h>

void st7735s_arch_delay_120ms();

// 发送指令操作码
uint8_t st7735s_arch_send_opcode(uint8_t opcode);
// 发送数据
uint8_t st7735s_arch_send_data(const uint8_t *data, uint16_t data_length);
// 接收数据
uint8_t st7735s_arch_receive_data(uint8_t *buffer,  uint16_t data_length, uint16_t buffer_length);


#endif // SPI_ST7735S_ARCH_H