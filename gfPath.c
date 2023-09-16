#include "ssd.h"

/**
 * executable - function to execute the prompt
 * @inp -
 *
 */
void executablle(char *cmmd, char *args[])
{
        pid_t childPid = fork();

        if (childPid == -1)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }
        else if (childPid == 0)
        {
                if (execve(cmmd, args, NULL) == -1)
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
 * getCmd - find full path to a specific command, cmmd
 * @cmmd - command whose full path we are searching for
 *
 * Return - fullPath on success, NULL on failure
 */
char *getCmdPath(char *cmmd)
{
	char *path;
	char *tok;
	char *envPath;

	envPath = getenv("PATH");
	if (envPath == NULL)
		return (NULL);

	path = _strdup(envPath);

	for (tok = strtok(path, ":"); tok != NULL; tok = strtok(NULL, ":"))
	{
		char fullPath[MAX_INPUT_LENGTH];
		_strcpy(fullPath, tok);
		_strcat(fullPath, "/");
		_strcat(fullPath, cmmd);

		if (access(fullPath, X_OK) == 0)
		{
			free(path);
			return (_strdup(fullPath));
		}
	}
	free(path);
	return (NULL);
}
