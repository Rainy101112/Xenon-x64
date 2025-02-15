# 欢迎来到 Xenon-x64内核项目

![](https://img.shields.io/badge/License-GPLv3-blue) ![](https://img.shields.io/badge/hardware-x64-green) ![](https://img.shields.io/badge/firmware-UEFI-yellow)

## 简介

一个使用C语言写的UEFI x64位类Unix内核，GPL-3.0开源协议，使用Limine启动规范。

## 编译要求

1. **操作系统**：必须是Linux环境，例如Debian、Ubuntu，或者WSL、Cygwin。
2. **工具安装**：必须安装好gcc、make和xorriso工具。如果需要测试，请安装qemu虚拟机。

## 编译指南

1. **获取源码**：将源码PULL到本地。
2. **编译**：在已PULL到本地的项目源码根目录内执行make命令，即可开始编译。
3. **编译结果**：编译后会生成两个文件：Xenon-x64.iso和XeImage，这两个文件分别为带UEFI引导的ISO和内核文件
4. **清理与测试**：
   - 输入“make clean”清理所有中间文件及引导和内核。
   - 输入“make run”即可通过qemu测试。
   - “make run-db”可以调出调试（控制台显示汇编调试代码）。

# 贡献者

1. **MicroFish**

# 项目所使用的开源代码

- Uinxed-Kernel: [https://github.com/ViudiraTech/Uinxed-Kernel/](https://github.com/ViudiraTech/Uinxed-Kernel/)
- CoolPotOS-x64: [https://github.com/plos-clan/CoolPotOS/](https://github.com/plos-clan/CoolPotOS/)

## 版权声明

本项目所有商为ViudiraTech。
内核源码为GPL-3.0开源协议
Copyright © 2020 ViudiraTech，保留最终解释权。
