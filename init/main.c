/*
 *
 *		main.c
 *		Xenon-x64内核入口
 *
 *		2025/2/15 By MicroFish
 *		基于 GPL-3.0 开源协议
 *		Copyright © 2020 ViudiraTech，保留最终解释权。
 *
 */

#include "stdint.h"
#include "stddef.h"
#include "limine.h"
#include "common.h"
#include "video.h"
#include "printk.h"
#include "gdt.h"
#include "idt.h"
#include "info.h"

/* 内核入口 */
void kernel_entry(void)
{
	video_init();	// 初始化视频驱动

	plogk("Xenon-x64 version %s (gcc version %d.%d.%d) #%d %s %s\n",
          KERNL_VERS, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__, KERNL_BUID, __DATE__, __TIME__);
	plogk("Copyright 2020 ViudiraTech. All rights interpretation reserved\n");
	plogk("Computer architecture: x86_64 | Firmware mode: UEFI\n");
	plogk("Video memory address: 0x%016X | Resolution: %dx%d\n",
          get_framebuffer()->address, get_framebuffer()->width, get_framebuffer()->height);

	init_gdt();		// 初始化全局描述符
	init_idt();		// 初始化中断描述符
	krn_halt();
}
