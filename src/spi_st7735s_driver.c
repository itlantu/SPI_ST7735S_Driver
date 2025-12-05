#include "spi_st7735s_driver/spi_st7735s_driver.h"
#include "spi_st7735s_driver/spi_st7735s_inc.h"
#include "spi_st7735s_driver/spi_st7735s_arch.h"

#define BUFFER_LENGTH 512
static uint8_t buffer[BUFFER_LENGTH];


ST7735S_Error_t st7735s_reset() {
	st7735s_arch_send_opcode(SWRESET);
	st7735s_arch_delay_120ms();
	return ST7735S_OK;
}

ST7735S_Error_t st7735s_read_RDDID(uint8_t* id1, uint8_t* id2, uint8_t* id3) {
	if (id1 == NULL)
		return ST7735S_FUNC_ARG1_NULL;
	if (id2 == NULL)
		return ST7735S_FUNC_ARG2_NULL;
	if (id3 == NULL)
		return ST7735S_FUNC_ARG3_NULL;
	st7735s_arch_send_opcode(RDDID);
	st7735s_arch_receive_data(buffer, 4, BUFFER_LENGTH);

	*id1 = buffer[1];
	*id2 = buffer[2];
	*id3 = buffer[3];

	return ST7735S_OK;
}