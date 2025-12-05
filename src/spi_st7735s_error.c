#include "spi_st7735s_driver/spi_st7735s_error.h"
#include <assert.h>
#include <stdint.h>

const char *ST7735S_ErrorTable[] = {
	"ST7735S_OK",
	"ST7735S_FUNC_ARG1_NULL",
	"ST7735S_FUNC_ARG2_NULL",
	"ST7735S_FUNC_ARG3_NULL",
	"ST7735S_FUNC_ARG4_NULL",
	"ST7735S_FUNC_ARG5_NULL",
};

// 判断ST7735S_ErrorTable与ST7735S_Error_t的数量是否匹配
static_assert(
	sizeof(ST7735S_ErrorTable) / sizeof(const char*) == ST7735S_ERROR_NUM,
	"length of ST7735S_ErrorTable != number of ST7735S_Error_t \r\n"
);

const char* st7735s_error_name(const ST7735S_Error_t error) {
	const uint8_t error_to_num = error;
	if (error_to_num >= ST7735S_ERROR_NUM)
		return NULL;
	return ST7735S_ErrorTable[error_to_num];
}