#ifndef SPI_ST7735S_DRIVER_H
#define SPI_ST7735S_DRIVER_H

#include "spi_st7735s_driver/spi_st7735s_error.h"

ST7735S_Error_t st7735s_reset();
ST7735S_Error_t st7735s_read_RDDID();

#endif // SPI_ST7735S_DRIVER_H