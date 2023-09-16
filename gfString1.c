#include "ssd.h"

/**
 * _strcmp - compare two strings character by character until we reach the end of either string or until we find a character that doesn't match
 * @str1 - first string to compare with
 * @str2 - second string to compare against
 *
 * Return - difference between the ASCII values of the two characters
 */
int _strcmp(const char* str1, const char* str2)
{
	for(;*str1 != '\0' && *str2 != '\0'; str1++, str2++)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
	}
	return (*str1 - *str2);
}
