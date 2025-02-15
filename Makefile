# =====================================================
#
#		Makefile
#		Xenon-x64编译文件
#
#		2025/2/15 By MicroFish
#		基于 GPL-3.0 开源协议
#		Copyright © 2020 ViudiraTech，保留所有权利。
#
# =====================================================

KERNEL_ELF		= XeImage
ISO_FILE		= Xenon-x64.iso

CC				= gcc
LD				= ld

QEMU			= qemu-system-x86_64
QEMU_FLAGS		= -drive if=pflash,format=raw,file=./assets/ovmf-code.fd

C_FLAGS			= -c -I ./include/ -m64 -std=c99 -Wall -Wextra -Wstrict-aliasing -Werror \
                  -nostdinc -fno-builtin -ffunction-sections -fdata-sections -fno-stack-protector
LD_FLAGS		= -nostdlib -static -T ./assets/linker.ld

C_SOURCES		= $(shell find . -name "*.c")
C_OBJECTS		= $(patsubst %.c, %.o, $(C_SOURCES))

all: info iso

info:
	@printf "Xenon-x64 Compile Script.\n"
	@printf "Copyright 2020 ViudiraTech. All rights interpretation reserved.\n"
	@printf "Based on the GPL-3.0 open source license.\n"
	@echo

.c.o:
	@printf "\033[1;32m[Build]\033[0m Compiling Code Files $< ...\n"
	@$(CC) $(C_FLAGS) $< -o $@

XeImage: $(C_OBJECTS)
	@echo
	@printf "\033[1;32m[Link]\033[0m Linking kernel...\n"
	@$(LD) $(LD_FLAGS) $(C_OBJECTS) -o $(KERNEL_ELF)

.PHONY: iso
iso: XeImage
	@echo
	@printf "\033[1;32m[ISO]\033[0m Packing ISO file...\n"
	@mkdir -p ./iso/limine
	@cp ./assets/limine/* ./iso/limine/
	@cp $< ./iso/limine/

	@xorriso -as mkisofs -efi-boot-part --efi-boot-image --protective-msdos-label \
             -no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus \
             -R -r -J -apm-block-size 2048 --efi-boot /limine/limine-uefi-cd.bin \
             --efi-boot /limine/limine-uefi-cd.bin ./iso/ -o $(ISO_FILE)

	@rm -rf iso
	@printf "\033[1;32m[Done]\033[0m Compilation complete.\n\n"

.PHONY: clean
clean:
	@rm -rf $(KERNEL_ELF) $(C_OBJECTS) $(ISO_FILE)
	@printf "\033[1;32m[Done]\033[0m Clean complete.\n\n"

.PHONY: run
run: iso
	$(QEMU) $(QEMU_FLAGS) -cdrom $(ISO_FILE)

.PHONY: run_db
run_db: iso
	$(QEMU) $(QEMU_FLAGS) -cdrom $(ISO_FILE) -d in_asm
