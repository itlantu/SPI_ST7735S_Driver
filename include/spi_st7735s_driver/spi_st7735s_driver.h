#ifndef SPI_ST7735S_DRIVER_H
#define SPI_ST7735S_DRIVER_H

#include "spi_st7735s_driver/spi_st7735s_error.h"
#include "spi_st7735s_driver/spi_st7735s_color.h"

enum ST7735S_Reset_t {
	ST7735S_RESET_SOFTWARE = 0,
	ST7735S_RESET_HARDWARE,
};

ST7735S_Error_t st7735s_reset(enum ST7735S_Reset_t type);
ST7735S_Error_t st7735s_read_RDDID();

#endif // SPI_ST7735S_DRIVER_H