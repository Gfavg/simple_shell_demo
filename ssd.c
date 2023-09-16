#include "ssd.h"


/**
 * Program entry point
 * main -
 *
 */

char inp[MAX_INPUT_LENGTH];
char *args[MAX_ARG_COUNT];
int main()
{

        while(1)
        {
		char *cmdPath;

                showPrompt();
		readInput(inp);
		tokInp(inp, args);
		
		if( _strcmp(args[0], "exit") == 0)
		{
			exit_shell();
		}else if (_strcmp(args[0], "env") == 0)
		{
			print_env();
		}else 
		{
			executable(args);

			cmdPath = getCmdPath(args[0]);
			if (cmdPath == NULL)
                	{
                        	gfPrint("No such file or directory\n");
                        	continue;
                	}
		
			executablle(cmdPath, args);
                	free(cmdPath);
		}
        }

        return (0);
}
