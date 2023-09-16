#include "ssd.h"

/**
 * gfPrint - function to print to standard output like printf
 * @argt - string argument to print to the standard output
 *
 */

void gfPrint(const char *argt)
{
        write(STDOUT_FILENO, argt, _strlen(argt));
}

/**
 * showPrompt - function to display the prompt
 *
 */
void showPrompt()
{
        gfPrint("SSD$ ");
}

/**
 * executable - function to execute the prompt
 * @inp -
 *
 */
void executable(char *args[])
{
        pid_t childPid = fork();

        if (childPid == -1)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }
        else if (childPid == 0)
        {
                if (execve(args[0], args, NULL) == -1)
                {
                        perror("execve");
                        _exit(1);
                }
        }
        else
		{
                int status;
                wait(&status);
        }
}

/**
 * readInput - reads the user input
 * @inp -
 * @inpSize -
 *
 */
void readInput(char *inp)
{
        if (fgets(inp, MAX_INPUT_LENGTH, stdin) == NULL)
        {
                if (feof(stdin))
                {
                        gfPrint("\n");
                        exit(EXIT_SUCCESS);
                }
                else
                {
                        gfPrint("Error reading input from user\n");
                        exit(EXIT_FAILURE);
                }
	}
	inp[_strcspn(inp, "\n")] = '\0';
}

/**
 * tokInp - tokenizes the input string
 * @inp - a pointer to the command input string
 * @args - an array of pointers to strings to store tokens(command and arguments)
 *
 */
void tokInp(char *inp, char *args[])
{
	char *tok;
	int arg_cnt;
	
	arg_cnt = 0;
	tok = strtok(inp, " ");
	while (tok != NULL && arg_cnt < (MAX_ARG_COUNT - 1))
	{
		args[arg_cnt] = tok;
		arg_cnt++;
		tok = strtok(NULL, " ");
	}
	args[arg_cnt] = NULL;
}
