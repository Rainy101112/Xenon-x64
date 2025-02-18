/*
 *
 *		common.c
 *		常见设备驱动
 *
 *		2025/2/15 By MicroFish
 *		基于 GPL-3.0 开源协议
 *		Copyright © 2020 ViudiraTech，保留最终解释权。
 *
 */

#include "common.h"

/* 端口写（8位） */
inline void outb(uint16_t port, uint8_t value)
{
	__asm__ __volatile__("outb %1, %0" : : "dN" (port), "a" (value));
}

/* 端口读（8位） */
inline uint8_t inb(uint16_t port)
{
	uint8_t ret;
	__asm__ __volatile__("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

/* 端口写（16位） */
inline void outw(uint16_t port, uint16_t value)
{
	__asm__ __volatile__("outw %1, %0" : : "dN" (port), "a" (value));
}

/* 端口读（16位） */
inline uint16_t inw(uint16_t port)
{
	uint16_t ret;
	__asm__ __volatile__("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

/* 端口写（32位） */
inline void outl(uint16_t port, uint32_t value)
{
	__asm__ __volatile__("outl %1, %0" : : "dN"(port), "a"(value));
}

/* 端口读（32位） */
inline uint32_t inl(uint16_t port)
{
	uint32_t ret;
	__asm__ __volatile__("inl %1, %0" : "=a"(ret) : "dN"(port));
	return ret;
}

/* 从I/O端口批量地读取数据到内存（16位） */
inline void insw(uint16_t port, void *buf, unsigned long n)
{
	__asm__ __volatile__("cld; rep; insw"
                 : "+D"(buf),
                 "+c"(n)
                 : "d"(port));
}

/* 从内存批量地写入数据到I/O端口（16位） */
inline void outsw(uint16_t port, const void *buf, unsigned long n)
{
	__asm__ __volatile__("cld; rep; outsw"
                 : "+S"(buf),
                 "+c"(n)
                 : "d"(port));
}

/* 从I/O端口批量地读取数据到内存（32位） */
inline void insl(uint32_t port, void *addr, int cnt)
{
	__asm__ __volatile__("cld;"
                 "repne; insl;"
                 : "=D" (addr), "=c" (cnt)
                 : "d" (port), "0" (addr), "1" (cnt)
                 : "memory", "cc");
}

/* 从内存批量地写入数据到I/O端口（32位） */
inline void outsl(uint32_t port, const void *addr, int cnt)
{
	__asm__ __volatile__("cld;"
                 "repne; outsl;"
                 : "=S" (addr), "=c" (cnt)
                 : "d" (port), "0" (addr), "1" (cnt)
                 : "memory", "cc");
}

/* 开启中断 */
inline void enable_intr(void)
{
	__asm__ __volatile__("sti");
}

/* 关闭中断 */
inline void disable_intr(void)
{
	__asm__ __volatile__("cli" ::: "memory");
}

/* 内核停机 */
inline void krn_halt(void)
{
	disable_intr();
	while(1) {__asm__("hlt");}
}
