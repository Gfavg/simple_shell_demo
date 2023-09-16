#include "ssd.h"

/**
 * print_env - prints the current environment
 */
void print_env()
{
	extern char **environ;
	char **enVar = environ;

	for(; *enVar != NULL; enVar++)
	{
		gfPrint(*enVar);
		gfPrint("\n");
	}
}
