#ifndef SPI_ST7735S_INC_H
#define SPI_ST7735S_INC_H

typedef enum {
	/* 系统功能指令 */
	// 空指令
	NOP = 0x00,
	// 软件复位, 需等待120ms后发送后续指令
	SWRESET = 0x01,
	// RDDID 读取显示ID
	RDDID = 0x04,
	// 读取显示状态
	RDDST = 0x09,
	// 进入睡眠模式
	SLPIN = 0x10,
	// 退出睡眠模式
	SLPOUT = 0x11,
	// 开启部分显示模式
	PTLON = 0x12,
	// 关闭部分显示模式(正常显示模式)
	NORON = 0x13,
	// 关闭显示反转
	INVOFF = 0x20,
	// 开启显示反转
	INVON = 0x21,
	// 选择伽马曲线
	GAMSET = 0x26,
	// 关闭显示, 帧内存不变
	DISPOFF = 0x28,
	// 开启显示
	DISPON = 0x29,
	// 设置列地址(x轴)
	CASET = 0x2A,
	// 设置行地址(Y轴)
	RASET = 0x2B,
	// 向帧内存写入数据
	RAMWR = 0x2C,
	// 配置颜色查找表
	RGBSET = 0x2D,
	// 从帧内存读取数据
	RAMRD = 0x2E,
	// 设置部分显示区域的起始和结束行
	PTLAR = 0x30,
	// 设置滚动区域
	SCRLAR = 0x33,
	// 关闭撕裂效应输出
	TEOFF = 0x34,
	// 开启撕裂效应输出，可选择模式
	TEON = 0x35,
	// 配置帧内存存读写扫描方向, RGB/BGR格式
	MADCTL = 0x36,
	// 设置垂直滚动起始地址
	VSCSAD = 0x37,
	// 退出空闲模式，恢复全色显示
	IDMOFF = 0x38,
	// 进入空闲模式
	IDMON = 0x39,
	// 设置接口像素格式
	COLMOD = 0x3A,
	// 读取制造商ID
	RDID1 = 0xDA,
	// 读取模版版本ID
	RDID2 = 0xDB,
	// 读取驱动ID
	RDID3 = 0xDC,


	/* 面板功能指令 */
}ST7735S_Opcode_t;


#endif // SPI_ST7735S_INC_H