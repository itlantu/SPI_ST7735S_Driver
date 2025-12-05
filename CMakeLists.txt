cmake_minimum_required(VERSION 4.0)
project(spi_st7735s_driver_demo C)

set(CMAKE_C_STANDARD 17)

add_library(SPI_ST7735S_Driver STATIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src/spi_st7735s_driver.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/spi_st7735s_error.c"
)

target_include_directories(SPI_ST7735S_Driver PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(spi_st7735s_driver_demo main.c)
target_include_directories(spi_st7735s_driver_demo PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(spi_st7735s_driver_demo PRIVATE SPI_ST7735S_Driver)
