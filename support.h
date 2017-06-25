/*
 * Josh Hursey
 *
 * CS 441/541: File System Traversal (Project 5)
 *
 * Based on code provided by Matt Dailey
 */
#ifndef SUPPORT_H
#define SUPPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/*
 * Given a time_t, create a string representing the time in the same
 * format as "ls".
 *
 * Parameters:
 *  pTime: Time value to convert (e.g., time from stat())
 *  time_str: A pointer to a string. The function will allocate the memory,
 *            but it is the responsibility of the caller to free the
 *            allocated memory.
 *
 * Returns:
 *  0 on success
 *  -1 otherwise and time_str is unchanged
 */
int get_time_str(time_t *pTime, char **time_str);

/*
 * Given a mode, return a string representing the mode in the same
 * format as "ls". (E.g., drwxr-xr--).
 * Supported file types: directory, link, regular, and pipe
 *
 * Parameters:
 *  mode: Unix file mode (e.g., mode from stat())
 *  mode_str: A pointer to a string. The function will allocate the memory,
 *            but it is the responsibility of the caller to free the
 *            allocated memory.
 *
 * Returns:
 *  0 on success
 *  -1 otherwise and mode_str is unchanged
 */
int get_mode_str(mode_t mode, char **mode_str);

#endif
