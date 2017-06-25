/*
 * Josh Hursey
 *
 * CS 441/541: File System Traversal (Project 5)
 *
 * Based on code provided by Matt Dailey
 */
#include "support.h"

#define TIMESTRLEN 80

int get_time_str(time_t *pTime, char **time_str) {
    char aCharTime[TIMESTRLEN];
    struct tm tmCur;
    struct tm tmGiven;
    time_t timeCur;

    /* Convert given time into a broken-down local time */
    localtime_r( pTime, &tmGiven );

    /* Get the current time and convert it into a broken-down local time */
    timeCur = time(NULL);
    localtime_r( &timeCur, &tmCur );

    /* Two different formats, depending on how long ago tmCur is */
    if( tmCur.tm_year == tmGiven.tm_year ||
        ( tmCur.tm_year == tmGiven.tm_year + 1 &&
          tmCur.tm_mon  <  tmGiven.tm_mon ) ) {
        /* Current year or late last year.  Output MMM DD HH:MM */
        if( 0 == strftime( aCharTime, TIMESTRLEN, "%b %d %R", &tmGiven) ) {
            return -1;
        }
    } else {
        /* Older than a year.  Output MMM DD  YYYY */
        if( 0 == strftime( aCharTime, TIMESTRLEN, "%b %d  %Y", &tmGiven) ) {
            return -1;
        }
    }
    
    *time_str = strdup(aCharTime);

    return 0;
}

int get_mode_str(mode_t fmode, char **mode_str) {
    char aCharProt[11];  /* Character buffer to store the output */

    /* Initialize output buffer */
    sprintf( aCharProt, "----------" );

    /* Check the file type: regular (-), directory (d), link (l), pipe (p) */
    if ( S_ISDIR( fmode )) {
        aCharProt[0] = 'd';
    }
    if ( S_ISLNK( fmode )) {
        aCharProt[0] = 'l';
    }
    if ( S_ISFIFO( fmode )) {
        aCharProt[0] = 'p';
    }

    /* Check the 9 protection bits (read/write/execute for owner/group/other) */

    /* Check 3 protection bits for owner */
    if ( S_IRUSR & fmode ) {
        aCharProt[1] = 'r';
    }
    if ( S_IWUSR & fmode ) {
        aCharProt[2] = 'w';
    }
    if ( S_IXUSR & fmode ) {
        aCharProt[3] = 'x';
    }

    /* Check 3 protection bits for group */
    if ( S_IRGRP & fmode ) {
        aCharProt[4] = 'r';
    }
    if ( S_IWGRP & fmode ) {
        aCharProt[5] = 'w';
    }
    if ( S_IXGRP & fmode ) {
        aCharProt[6] = 'x';
    }

    /* Check 3 protection bits for other */
    if ( S_IROTH & fmode ) {
        aCharProt[7] = 'r';
    }
    if ( S_IWOTH & fmode ) {
        aCharProt[8] = 'w';
    }
    if ( S_IXOTH & fmode ) {
        aCharProt[9] = 'x';
    }

    /* Write the final string to stdout */
    *mode_str = strdup( aCharProt );

    return 0;
}