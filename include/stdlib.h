/*
 *
 *		stdlib.h
 *		通用工具函数库头文件
 *
 *		2025/2/15 By MicroFish
 *		基于 GPL-3.0 开源协议
 *		Copyright © 2020 ViudiraTech，保留最终解释权。
 *
 */

#ifndef INCLUDE_STDLIB_H_
#define INCLUDE_STDLIB_H_

#include "stdint.h"

#define MAX_PRECISION (10)

static const double rounders[MAX_PRECISION + 1] = {
	0.5,				// 0
	0.05,				// 1
	0.005,				// 2
	0.0005,				// 3
	0.00005,			// 4
	0.000005,			// 5
	0.0000005,			// 6
	0.00000005,			// 7
	0.000000005,		// 8
	0.0000000005,		// 9
	0.00000000005		// 10
};

/* 延迟 */
void delay(uint32_t count);

/* 阻塞函数 */
void hang(void);

/* 判断是否是数字 */
int isdigit(int c);

/* 将字符串数字转换为整数数字 */
int atoi(char* pstr);

/* 把浮点数转换成字符数组 */
char *ftoa(double f, char *buf, int precision);

#endif // INCLUDE_STDLIB_H_
