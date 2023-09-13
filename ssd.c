#include "ssd.h"


/**
 * Program entry point
 * main -
 *
 */


int main(void)
{
	char inp[MAX_INPUT_LENGTH];
	char *args[MAX_ARG_COUNT];
        while(1)
        {
                showPrompt();
		readInput(inp);
                executable (args);
        }

        return (0);
}
