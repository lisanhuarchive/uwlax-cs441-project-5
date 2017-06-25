/*
 * By Sanhu Li
 *
 * CS 441/541: File System Traversal (Project 5)
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

#include "libgen.h"

#include "support.h"

/******************************
 * Defines
 ******************************/


/******************************
 * Structures
 ******************************/


/******************************
 * Global Variables
 ******************************/
char *error_msg = NULL;


/******************************
 * Function declarations
 ******************************/
void execute(char **argv, const char *mode);