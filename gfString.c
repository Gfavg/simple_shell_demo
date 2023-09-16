#include "ssd.h"

/**
 * _strlen - calculates the length of a string
 * str - the string whose length we want to calc
 *
 * Return - length of string on success
 */
size_t _strlen(const char *str)
{
	size_t i;

	for(i = 0; str[i] != '\0'; i++);
	return (i);
}

/**
 * _strcpy - copies string from a source to a destination
 * @src - source from which to be copied
 * @dest - destination to copy string to
 *
 * Return - pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - duplicates string by allocatn mem for it & copyn its contents
 * @str - pointer to string to be copied
 *
 * Return - duplicate string
 */
char* _strdup(const char *str)
{
	int i;
	int j;
	char* dup;

	for(i = 0; str[i] != '\0'; i++);
	dup = (char*)malloc(i + 1);

	if (dup == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		dup[j] = str[j];

	return (dup);
}

/**
 * _strcspn - calcutes len of initial segment of a str not containing any xter specified in the reject str
 * @str - string to be searched, looking for reject
 * @reject - string to be searched for in str
 *
 * Return - No. of xters before any of the reject str are found
 */
size_t _strcspn(const char* str, const char* reject)
{
	size_t i;
	size_t len;
	int rejExist[256] = {0};

	for(i = 0; reject[i] != '\0'; i++)
		rejExist[(unsigned char)reject[i]] = 1;

	for (len = 0; str[len] != '\0' && !rejExist[(unsigned char)str[len]]; len++);

	return (len);
}

/**
 * _strcat - adds one string, source string, to the end of another string, destination string
 * @dest - string to be added to
 * @src - string to add to the destination
 *
 */
void _strcat(char *dest, const char *src)
{
	for (; *dest != '\0'; dest++);

	for (; *src != '\0';dest++, src++)
		*dest = *src;

	*dest = '\0';
}
