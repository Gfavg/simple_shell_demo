#ifndef SSD_H
#define SSD_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>


#define MAX_INPUT_LENGTH 100
#define MAX_ARG_COUNT 10


/**
 * gfPrint
 */
void gfPrint(const char *argt);
void showPrompt(void);
void executable (char *args[]);
void readInput(char *inp);
void tokInp(char *inp, char *args[]);


/**
 * gfPath
 */
char *getCmdPath(char *cmmd);
void executablle (char*cmmd, char *args[]);


/**
 * string libraries
 */
size_t _strlen(const char *str);
char* _strcpy(char *dest, const char *src);
char* _strdup(const char *str);
size_t _strcspn(const char *str, const char *reject);
void _strcat(char *dest, const char *src);
int _strcmp(const char* str1, const char* str2);


/**
 * Exit the simple shell
 */
void exit_shell();

/**
 * Implement Environment
 */
void print_env();
#endif
