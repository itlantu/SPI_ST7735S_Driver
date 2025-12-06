#include "spi_st7735s_driver/spi_st7735s_driver.h"
#include "spi_st7735s_driver/spi_st7735s_inc.h"
#include "spi_st7735s_driver/spi_st7735s_arch.h"
#include "spi_st7735s_driver/spi_st7735s_config.h"

#define BUFFER_LENGTH 512
static uint8_t buffer[BUFFER_LENGTH];
static const uint8_t GPIO_SET = 1;
static const uint8_t GPIO_RESET = 0;

void _st7735s_send_opcode(const uint8_t byte_data) {
	st7735s_arch_gpio_write_DC(GPIO_RESET);
	st7735s_arch_gpio_write_CS(GPIO_RESET);
	st7735s_arch_spi_send(&byte_data, 1);
	st7735s_arch_gpio_write_CS(GPIO_SET);
}

void _st7735s_send_data(const uint8_t* data, uint16_t data_length) {
	st7735s_arch_gpio_write_DC(GPIO_SET);
	st7735s_arch_gpio_write_CS(GPIO_RESET);
	st7735s_arch_spi_send(data, data_length);
	st7735s_arch_gpio_write_CS(GPIO_SET);
}

ST7735S_Error_t st7735s_reset(const enum ST7735S_Reset_t type) {
	if (type == ST7735S_RESET_SOFTWARE) {
		// 软件REST
		_st7735s_send_opcode(SWRESET);
		st7735s_arch_delay_ms(120);
	}else if (type == ST7735S_RESET_HARDWARE) {
		// 硬件RESET
		st7735s_arch_gpio_write_RST(GPIO_RESET);
		st7735s_arch_delay_ms(10);
		st7735s_arch_gpio_write_RST(GPIO_SET);
		st7735s_arch_delay_ms(10);
	}else {
		// 未定义的type
		return ST7735S_RESET_UNKNOWN_TYPE;
	}

	return ST7735S_OK;
}

// ST7735S_Error_t st7735s_read_RDDID(uint8_t* id1, uint8_t* id2, uint8_t* id3) {
// 	if (id1 == NULL)
// 		return ST7735S_FUNC_ARG1_NULL;
// 	if (id2 == NULL)
// 		return ST7735S_FUNC_ARG2_NULL;
// 	if (id3 == NULL)
// 		return ST7735S_FUNC_ARG3_NULL;
// 	_st7735s_send_opcode(RDDID);
// 	st7735s_arch_spi_receive(buffer, 4, BUFFER_LENGTH);
//
// 	*id1 = buffer[1];
// 	*id2 = buffer[2];
// 	*id3 = buffer[3];
//
// 	return ST7735S_OK;
// }