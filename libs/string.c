/*
 *
 *		string.c
 *		基础内存操作与字符串处理函数库
 *
 *		2025/2/15 By MicroFish
 *		基于 GPL-3.0 开源协议
 *		Copyright © 2020 ViudiraTech，保留最终解释权。
 *
 */

#include "string.h"

/* 比较两个内存区域的前count个字节 */
inline int memcmp(const void* buffer1, const void* buffer2, unsigned int count)
{
	if(!count) {
		return 0;
	}
	while(count-- && *(char*)buffer1 == *(char*)buffer2) {
		buffer1 = (char*)buffer1 + 1; // 转换类型，移动指针
		buffer2 = (char*)buffer2 + 1;
	}
	return (*((uint8_t *)buffer1) - *((uint8_t *)buffer2));    
}

/* 将len个字节从源地址复制到目标地址 */
inline void *memcpy(void *dest, const void *src, unsigned int len)
{
	uint8_t *sr = (uint8_t *)src;
	uint8_t *dst = (uint8_t *)dest;

	while (len != 0) {
		*dst++ = *sr++;
		len--;
	}
	return dest; // 返回目标地址
}

/* 将目标内存区域的前len个字节设置为值val */
inline void *memset(void *dest, int val, unsigned int len)
{
	uint8_t *dst = (uint8_t *)dest;
	uint8_t byte_val = (uint8_t)val;

	while (len != 0) {
		*dst++ = byte_val;
		len--;
	}
	return dest; // 返回目标地址
}

/* 将目标内存区域的前len个字节设置为0 */
inline void bzero(void *dest, unsigned int len)
{
	memset(dest, 0, len);
}

/* 清除一个字符数组s的内存 */
inline void memclean(char *s, int len)
{
	int i;
	for (i = 0; i != len; i++) {
		s[i] = 0;
	}
	return;
}

/* 比较两个字符串 */
inline int strcmp(const char *dest, const char *src)
{
	int ret = 0 ;

	while(!(ret = *(unsigned char *)src - *(unsigned char *)dest) && *dest) {
		++src;
		++dest;
	}
	if (ret < 0) {
		ret = -1;
	}
	else if (ret > 0) {
		ret = 1;
	}
	return ret;
}

/* 将字符串src复制到dest */
inline char *strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while (*src) {
		*dest++ = *src++;
	}
	*dest = '\0';	
	return tmp;
}

/* 将字符串的前len个字符复制到dest */
inline char *strncpy(char *dest, const char *src, unsigned int len)
{
	char *dst = dest;

	while (len > 0) {
		while (*src) {
			*dest++ = *src++;
		}
		len--;
	}
	*dest = '\0';
	return dst;
}

/* 将字符串src连接到dest的末尾 */
inline char *strcat(char *dest, const char *src)
{
	char *cp = dest;

	while (*cp) {
		cp++;
	}
	while ((*cp++ = *src++));
	return dest;
}

/* 查找字符串中的一个字符并返回该字符在字符串中第一次出现的位置 */
inline char *strchr(char *str, int c)
{
	for (; *str != 0; ++str) {
		if (*str == c) {
			return str;
		}
	}
	return 0;
}

/* 返回字符串src的长度 */
inline int strlen(const char *src)
{
	const char *eos = src;

	while (*eos++);
	return (eos - src - 1);
}

/* 删除字符串中指定位置的字符 */
inline void delete_char(char *str, int pos)
{
	int i;
	for (i = pos; i < strlen(str); i++) {
		str[i] = str[i + 1];
	}
}

/* 在字符串的指定位置插入一个字符 */
inline void insert_char(char *str, int pos, char ch)
{
	int i;
	for (i = strlen(str); i >= pos; i--) {
		str[i + 1] = str[i];
	}
	str[pos] = ch;
}

/* 在字符串的指定位置插入另一个字符串 */
inline void insert_str(char *str, char *insert_str, int pos)
{
	for (int i = 0; i < strlen(insert_str); i++) {
		insert_char(str, pos + i, insert_str[i]);
	}
}

/* 将字符串中的所有字母转换为大写 */
inline char *strupr(char *src)
{
	while (*src != '\0')
	{
		if (*src >= 'a' && *src <= 'z')
			*src -= 32;
		src++;
	}
	return src;
}

/* 将字符串中的所有字母转换为小写 */
inline char *strlwr(char *src)
{
	while (*src != '\0')
	{
		if (*src > 'A' && *src <= 'Z'){
			//*src += 0x20; 
			*src += 32;
		}
		src++;
	}
	return src;
}
