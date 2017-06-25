/*
 * By Sanhu Li
 *
 * CS 441/541: File System Traversal (Project 5)
 */
#include "check_mode.h"

void errors_and_usage() {
    if (error_msg != NULL) {
        printf("%s\n", error_msg);
    }
    printf("Usage: ./check_mode [-a] [-h] [-l] [-r] -m ### [arg1] [arg2] ...\n");
}

/**
* Judge whether the given str is all digit
*/
bool all_digits(const char *str) {
    size_t len = strlen(str);
	size_t i;
    for (i = 0; i < len; ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

/**
* Judge whether all digits in str are in range [0, 7]
*/
bool all_valid_digits(const char *str) {
    int d;
    d = strtol(str, NULL, 10);
    while (d > 0) {
        if (!(d % 10 >= 0 && d % 10 <= 7)) {
            return false;
        }
        d /= 10;
    }
    return true;
}

/**
* Extract the -m parameter from argv
* It will return the str representing the parameter
*/
char *extract_mode(char **argv) {
    int i;
    char *mode = NULL;

    for (i = 0; argv[i] != NULL; ++i) {
        if (!strcmp("-m", argv[i]) &&
                argv[i + 1] != NULL &&
                all_digits(argv[i + 1]) &&
                all_valid_digits(argv[i + 1]) &&
                strlen(argv[i + 1]) == 3) {
            mode = strdup(argv[i + 1]);
            break;

        } else if (!strcmp("-m", argv[i]) &&
                argv[i + 1] == NULL) {
            error_msg = "Error: Mode argument must have an argument";

        } else if (!strcmp("-m", argv[i]) &&
                argv[i + 1] != NULL &&
                (!all_digits(argv[i + 1]) ||
                        !all_valid_digits(argv[i + 1]) ||
                        !strlen(argv[i + 1]) != 3)) {
            error_msg = "Error: Mode must be three digits. Each digit between 0-7";
        }
    }

    if (mode != NULL) {
        for (; argv[i + 2] != NULL; ++i) {
            argv[i] = argv[i + 2];
        }
        argv[i] = NULL;
    }

    if (mode == NULL && error_msg == NULL) {
        error_msg = "Error: Did not specify a mode";
    }

    return mode;
}

/**
* Judge whether the arguments have option opt
*/
bool extract_option(const char *opt, char **argv) {
    int i;
    bool result = false;
    for (i = 0; argv[i] != NULL; ++i) {
        if (!strcmp(opt, argv[i])) {
            result = true;
            continue;
        }

        if (result) {
            argv[i - 1] = argv[i];
        }
    }
    if (result) {
        argv[i - 1] = NULL;
    }
    return result;
}

/**
* print out all the arguments received
*/
void print_args(char **argv) {
    int i;
    for (i = 1; argv[i] != NULL; ++i) {
        printf("%s\n", argv[i]);
    }
}

int main(int argc, char **argv) {
    char *mode = extract_mode(argv);

    if (mode == NULL) {
        errors_and_usage();
        exit(1);
    }

    execute(argv, mode);

    return 0;
}

/**
* get the size of the arguments except for the first one
*/
int args_size(char **argv) {
    int i, count = 0;
    for (i = 1; argv[i] != NULL; ++i) {
        count++;
    }
    return count;
}

void print_dashes() {
    printf("-------------------------------\n");
}

void print_mode_param(const char *mode) {
    printf("Desired Mode: %s\n", mode);
}

void print_opt_param(const char *opt, bool value) {
    printf("Option (%s) : %s\n", opt, value ? "enabled" : "disabled (Default)");
}

void print_file_param(char **argv) {
    int i;

    printf("Directory/File Parameters:\n");
    for (i = 1; argv[i] != NULL; ++i) {
        printf("\t%s\n", argv[i]);
    }
}

void print_ls_args(char **argv, const char *mode, bool all_opt, bool hum_opt, bool lst_opt, bool rcs_opt) {
    print_dashes();
    print_mode_param(mode);
    print_opt_param("-a", all_opt);
    print_opt_param("-h", hum_opt);
    print_opt_param("-l", lst_opt);
    print_opt_param("-r", rcs_opt);
    print_file_param(argv);
    print_dashes();
}

/**
* This function converts mode_str to mode_digits
*/
char *convert(const char *mode_str) {
    int mode = 0;
    char buf[4];

    strcpy(buf, "");

    if (mode_str[1] != '-') {
        mode += 4;
    }
    if (mode_str[2] != '-') {
        mode += 2;
    }
    if (mode_str[3] != '-') {
        mode += 1;
    }
    sprintf(buf, "%s%d", buf, mode);
    mode = 0;

    if (mode_str[4] != '-') {
        mode += 4;
    }
    if (mode_str[5] != '-') {
        mode += 2;
    }
    if (mode_str[6] != '-') {
        mode += 1;
    }
    sprintf(buf, "%s%d", buf, mode);
    mode = 0;

    if (mode_str[7] != '-') {
        mode += 4;
    }
    if (mode_str[8] != '-') {
        mode += 2;
    }
    if (mode_str[9] != '-') {
        mode += 1;
    }
    sprintf(buf, "%s%d", buf, mode);

    return strdup(buf);
}

/**
* Humanize the size
*/
char *humanize_size(off_t size, bool hum_opt) {
    char buf[7], tail = ' ';
    float s_f = size;
    if (!hum_opt) {
        sprintf(buf, "%lld", size);
        return strdup(buf);
    } else {
        if (s_f < 1000) {
            sprintf(buf, "%lld%c", size, tail);
            return strdup(buf);
        }

        s_f /= 1024;
        tail = 'K';
        if (s_f < 1000) {
            sprintf(buf, "%.1f%c", s_f, tail);
            return strdup(buf);
        }

        s_f /= 1024;
        tail = 'M';
        if (s_f < 1000) {
            sprintf(buf, "%.1f%c", s_f, tail);
            return strdup(buf);
        }

        s_f /= 1024;
        tail = 'G';
        if (s_f < 1000) {
            sprintf(buf, "%.1f%c", s_f, tail);
            return strdup(buf);
        }

        s_f /= 1024;
        tail = 'T';
        if (s_f < 1000) {
            sprintf(buf, "%.1f%c", s_f, tail);
            return strdup(buf);
        }
    }

    return NULL;
}

char *get_remain(struct stat fs, bool hum_opt) {
    off_t remain;
    char *str;
    remain = fs.st_blocks;
    if (remain == 0) {
        str = humanize_size(remain, hum_opt);
    } else {
        remain = remain * 512 - fs.st_size;
        str = humanize_size(remain, hum_opt);
    }
    return str;
}

void execute_single_file(char *path, const char *mode, bool all_opt, bool hum_opt, bool lst_opt, bool rcs_opt) {
    char *name = basename(path), *mode_digits;
    struct stat fs;
    char *mode_str, prefix = ' ', *buf;

    if (!all_opt && name[0] == '.') {
        return;
    }

    lstat(path, &fs);

    get_mode_str(fs.st_mode, &mode_str);
    mode_digits = convert(mode_str);
    if (!strcmp(mode_digits, mode)) {
        prefix = '*';
    }

    printf("%c", prefix);

    if (lst_opt) {
        printf("%s ", mode_str);
        printf("(%s) ", mode_digits);
        printf("%-13s ", getpwuid(fs.st_uid)->pw_name);
        printf("%-8s ", getgrgid(fs.st_gid)->gr_name);
        printf("%6s ", humanize_size(fs.st_size, hum_opt));
        printf("(%5s) ", get_remain(fs, hum_opt));
        get_time_str(&fs.st_mtime, &buf);
        printf("%12s ", buf);
        printf("[%7llu] ", fs.st_ino);
    }
    printf("%s", name);

    printf("\n");
}

/**
* Remove the last / if exists for directory names
*/
char *trim(char *str) {
    size_t len = strlen(str);

    while (str[len - 1] == '/' || str[len - 1] == '\\') {
        str[len - 1] = '\0';
        len = strlen(str);
    }
    return str;
}

void execute_single_dir(char *path, const char *mode, bool all_opt, bool hum_opt, bool lst_opt, bool rcs_opt) {
    DIR *dd;
    struct dirent *file;
    char prefix[MAXNAMLEN], tmp[MAXNAMLEN];
    dd = opendir(path);
    strcpy(prefix, trim(path));
    sprintf(prefix, "%s/", prefix);

    while ((file = readdir(dd)) != NULL) {
        sprintf(tmp, "%s%s", prefix, file->d_name);
        execute_single_file(tmp, mode, all_opt, hum_opt, lst_opt, rcs_opt);
    }
}

void execute_single(char *path, const char *mode, bool all_opt, bool hum_opt, bool lst_opt, bool rcs_opt) {
    struct stat fs;
    int result = lstat(path, &fs);
    if (result != 0) {
        exit(errno);
    }

    if (S_ISDIR(fs.st_mode)) {
        execute_single_dir(path, mode, all_opt, hum_opt, lst_opt, rcs_opt);
    } else {
        execute_single_file(path, mode, all_opt, hum_opt, lst_opt, rcs_opt);
    }
}

/**
* Execute the program
*/
void execute(char **argv, const char *mode) {
    bool all_opt, hum_opt, lst_opt, rcs_opt;
    int i, size;
    struct stat fs;

    all_opt = extract_option("-a", argv);
    hum_opt = extract_option("-h", argv);
    lst_opt = extract_option("-l", argv);
    rcs_opt = extract_option("-r", argv);

    size = args_size(argv);

    if (size == 0) {
        argv[1] = ".";
        argv[2] = NULL;
        size = 1;
    }

    print_ls_args(argv, mode, all_opt, hum_opt, lst_opt, rcs_opt);

    for (i = 0; i < size; ++i) {
        if (stat(argv[i + 1], &fs) == 0) {
            if (S_ISDIR(fs.st_mode) && size > 1) {
                printf("%s:\n", argv[i + 1]);
            }
            execute_single(argv[i + 1], mode, all_opt, hum_opt, lst_opt, rcs_opt);

            if (i != size - 1) {
                printf("\n");
            }
        } else {
            printf("%s: cannot access %s: No such file or directory\n\n", argv[0], argv[i + 1]);
        }
    }
}
