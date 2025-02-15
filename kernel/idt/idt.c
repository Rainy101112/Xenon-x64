/*
 *
 *		idt.c
 *		中断描述符
 *
 *		2025/2/15 By MicroFish
 *		基于 GPL-3.0 开源协议
 *		Copyright © 2020 ViudiraTech，保留最终解释权。
 *
 */

#include "idt.h"

struct idt_register idt_pointer;
struct idt_entry idt_entries[256];

/* 初始化中断描述符表 */
void init_idt(void)
{
	idt_pointer.size = (uint16_t) sizeof(idt_entries) - 1;
	idt_pointer.ptr = &idt_entries;
	__asm__ __volatile__("lidt %0" : : "m"(idt_pointer) : "memory");
}

/* 注册一个中断处理函数 */
void register_interrupt_handler(uint16_t vector, void *handler, uint8_t ist, uint8_t flags)
{
	uint64_t addr = (uint64_t) handler;
	idt_entries[vector].offset_low = (uint16_t) addr;
	idt_entries[vector].ist = ist;
	idt_entries[vector].flags = flags;
	idt_entries[vector].selector = 0x08;
	idt_entries[vector].offset_mid = (uint16_t) (addr >> 16);
	idt_entries[vector].offset_hi = (uint32_t) (addr >> 32);
}
