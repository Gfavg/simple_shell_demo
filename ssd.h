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


#define MAX_INPUT_LENGTH 100
#define MAX_ARG_COUNT 10


void gfPrint(const char *argt);
void showPrompt(void);
void executable (char *args[]);
void readInput(char *inp);

#endif
