/*
 *
 *		printk.h
 *		内核字符串打印
 *
 *		2025/2/15 By MicroFish
 *		基于 GPL-3.0 开源协议
 *		Copyright © 2020 ViudiraTech，保留最终解释权。
 *
 */

#ifndef INCLUDE_PRINTK_H_
#define INCLUDE_PRINTK_H_

#include "vargs.h"

#define is_digit(c)	((c) >= '0' && (c) <= '9')

#define ZEROPAD		1	// pad with zero
#define SIGN		2 	// unsigned/signed long
#define PLUS    	4	// show plus
#define SPACE		8 	// space if plus
#define LEFT		16	// left justified
#define SPECIAL		32	// 0x
#define SMALL		64	// use 'abcdef' instead of 'ABCDEF'

#define do_div(n,base) ({														\
        int __res;																\
        __asm__("divl %4":"=a" (n),"=d" (__res):"0" (n),"1" (0),"r" (base));	\
        __res; })

/* 内核打印字符串 */
void printk(const char *format, ...);

/* 内核打印日志 */
void plogk(const char *format, ...);

/* 内核打印带颜色的字符串 */
void printk_color(int fore, const char *format, ...);

/* 内核打印带颜色的日志  */
void plogk_color(int fore, const char *format, ...);

/* 格式化字符串并将其输出到一个字符数组中 */
int vsprintf(char *buff, const char *format, va_list args);

/* 将格式化的输出存储在字符数组中 */
void sprintf(char *str, const char *fmt, ...);

#endif // INCLUDE_PRINTK_H_
