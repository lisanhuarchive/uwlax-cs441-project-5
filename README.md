# CS441/541
## Project 5 Template

** Author ** : ** Sanhu Li **

** Date ** : ** Dec. 11, 2014 **

----

## Summary

This software is a similar tool to unix command ls.

It supports for the -a -l -h -m parameters.

## How to build

When you are in the root folder of the source, please use command `make` and you will find it start building the project.

## How to use
In the command line, please enter

	$ ./check_mode [-a] [-h] [-l] [-r] -m ### [arg1] [arg2] ...
	
The `###` after `-m` represents three digital numbers, all of which are in the range of [0-7]

For the meaning of these parameters, please refer to the man page of command ls. These parameters are similar to those of ls.

You can get the ls help by enter `man ls`

## Examples

```
[li.sanh@CS441 project-5]$ ./check_mode -m 600
-------------------------------
Desired Mode: 600
Option (-a) : disabled (Default)
Option (-h) : disabled (Default)
Option (-l) : disabled (Default)
Option (-r) : disabled (Default)
Directory/File Parameters:
	.
-------------------------------
*check_mode.h
*README.md
*support.o
*support.h
*support.c
 tests
 given-tests
*check_mode.c
 check_mode
*Makefile
[li.sanh@CS441 project-5]$ ./check_mode -m 700 given-tests/level2/ fake given-tests/level1
-------------------------------
Desired Mode: 700
Option (-a) : disabled (Default)
Option (-h) : disabled (Default)
Option (-l) : disabled (Default)
Option (-r) : disabled (Default)
Directory/File Parameters:
	given-tests/level2/
	fake
	given-tests/level1
-------------------------------
given-tests/level2/:
 empty.txt
 hello.txt
*emptydir

./check_mode: cannot access fake: No such file or directory

given-tests/level1:
 hello.txt
[li.sanh@CS441 project-5]$ ./check_mode -l -m 600
-------------------------------
Desired Mode: 600
Option (-a) : disabled (Default)
Option (-h) : disabled (Default)
Option (-l) : enabled
Option (-r) : disabled (Default)
Directory/File Parameters:
	.
-------------------------------
*-rw------- (600) li.sanh       students    756 ( 3340) Dec 11 07:09 [ 791216] check_mode.h
*-rw------- (600) li.sanh       students    153 ( 3943) Dec 11 07:07 [ 790771] README.md
*-rw------- (600) li.sanh       students   6312 ( 1880) Dec 11 07:14 [ 789661] support.o
*-rw------- (600) li.sanh       students   1362 ( 2734) Dec 11 07:09 [ 791322] support.h
*-rw------- (600) li.sanh       students   2518 ( 1578) Dec 11 07:14 [ 791321] support.c
 drwx------ (700) li.sanh       students   4096 (    0) Dec 11 07:07 [ 791323] tests
 drwx------ (700) li.sanh       students   4096 (    0) Dec 11 07:15 [ 791283] given-tests
*-rw------- (600) li.sanh       students   9074 ( 3214) Dec 11 07:14 [ 790787] check_mode.c
 -rwx------ (700) li.sanh       students  24378 (  198) Dec 11 07:14 [ 792428] check_mode
*-rw------- (600) li.sanh       students    815 ( 3281) Dec 11 07:07 [ 790599] Makefile
[li.sanh@CS441 project-5]$ ./check_mode -l -m 752 given-tests/level3/subdir1/subdir3/subdir4/-------------------------------
Desired Mode: 752
Option (-a) : disabled (Default)
Option (-h) : disabled (Default)
Option (-l) : enabled
Option (-r) : disabled (Default)
Directory/File Parameters:
	given-tests/level3/subdir1/subdir3/subdir4/
-------------------------------
 -rwxr-xr-x (755) li.sanh       students 2205696 ( 2048) Dec 11 07:15 [ 792449] test-2154.dat
 -rw--w-r-x (625) li.sanh       students 314368 ( 1024) Dec 11 07:15 [ 792448] test-307.dat
*-rwxr-x-w- (752) li.sanh       students  45056 (    0) Dec 11 07:15 [ 792447] test-44.dat
*-rwxr-x-w- (752) li.sanh       students 15451136 ( 3072) Dec 11 07:15 [ 792450] test-15089.dat
[li.sanh@CS441 project-5]$ ./check_mode -l -m 752 given-tests/level3/subdir1/subdir3/subdir4/ -h
-------------------------------
Desired Mode: 752
Option (-a) : disabled (Default)
Option (-h) : enabled
Option (-l) : enabled
Option (-r) : disabled (Default)
Directory/File Parameters:
	given-tests/level3/subdir1/subdir3/subdir4/
-------------------------------
 -rwxr-xr-x (755) li.sanh       students   2.1M ( 2.0K) Dec 11 07:15 [ 792449] test-2154.dat
 -rw--w-r-x (625) li.sanh       students 307.0K ( 1.0K) Dec 11 07:15 [ 792448] test-307.dat
*-rwxr-x-w- (752) li.sanh       students  44.0K (   0 ) Dec 11 07:15 [ 792447] test-44.dat
*-rwxr-x-w- (752) li.sanh       students  14.7M ( 3.0K) Dec 11 07:15 [ 792450] test-15089.dat
[li.sanh@CS441 project-5]$ -m 700 -l /home/li.sanh/
-bash: -m: command not found
[li.sanh@CS441 project-5]$ ./check_mode -m 700 -l /home/li.sanh/
-------------------------------
Desired Mode: 700
Option (-a) : disabled (Default)
Option (-h) : disabled (Default)
Option (-l) : enabled
Option (-r) : disabled (Default)
Directory/File Parameters:
	/home/li.sanh/
-------------------------------
*drwx------ (700) li.sanh       students   4096 (    0) Nov 06 08:09 [ 786521] project-3
*drwx------ (700) li.sanh       students   4096 (    0) Oct 14 03:52 [ 786462] tmp
*drwx------ (700) li.sanh       students   4096 (    0) Nov 21 02:42 [   4605] ls
*drwx------ (700) li.sanh       students   4096 (    0) Dec 11 07:14 [ 789632] project-5
*drwx------ (700) li.sanh       students   4096 (    0) Nov 21 02:44 [   4606] project-4
[li.sanh@CS441 project-5]$ ./check_mode -m 700 -a -l /home/li.sanh/
-------------------------------
Desired Mode: 700
Option (-a) : enabled
Option (-h) : disabled (Default)
Option (-l) : enabled
Option (-r) : disabled (Default)
Directory/File Parameters:
	/home/li.sanh/
-------------------------------
 -rw-r--r-- (644) li.sanh       students    176 ( 3920) Jul 18  2013 [ 786459] .bash_profile
 -rw-r--r-- (644) li.sanh       students     18 ( 4078) Jul 18  2013 [ 786458] .bash_logout
*drwx------ (700) li.sanh       students   4096 (    0) Sep 04 09:26 [ 786546] .pki
*drwx------ (700) li.sanh       students   4096 (    0) Nov 06 08:09 [ 786521] project-3
 -rw-r--r-- (644) li.sanh       students    708 ( 3388) Sep 09 14:34 [ 786461] .bashrc
 -rw------- (600) li.sanh       students   9420 ( 2868) Nov 21 04:12 [ 786513] .bash_history
*drwx------ (700) li.sanh       students   4096 (    0) Oct 14 03:52 [ 786462] tmp
*drwx------ (700) li.sanh       students   4096 (    0) Nov 21 02:42 [   4605] ls
*drwx------ (700) li.sanh       students   4096 (    0) Dec 11 07:14 [ 789632] project-5
 -rw------- (600) li.sanh       students   5687 ( 2505) Oct 28 15:02 [ 789996] .viminfo
*drwx------ (700) li.sanh       students   4096 (    0) Nov 21 02:44 [   4606] project-4
*drwx------ (700) li.sanh       students   4096 (    0) Sep 04 08:56 [ 786516] .emacs.d
*drwx------ (700) li.sanh       students   4096 (    0) Dec 11 07:07 [ 786457] .
 drwxr-xr-x (755) root          root       4096 (    0) Sep 08 23:37 [      2] ..
 -rw-r--r-- (644) li.sanh       students   1457 ( 2639) Sep 02 07:34 [ 786460] .emacs
 -rw------- (600) li.sanh       students     71 ( 4025) Sep 04 10:17 [ 786777] .gitconfig
[li.sanh@CS441 project-5]$ ./check_mode -m 600 given-tests/level1/hello.txt given-tests/level2
-------------------------------
Desired Mode: 600
Option (-a) : disabled (Default)
Option (-h) : disabled (Default)
Option (-l) : disabled (Default)
Option (-r) : disabled (Default)
Directory/File Parameters:
	given-tests/level1/hello.txt
	given-tests/level2
-------------------------------
*hello.txt

given-tests/level2:
 empty.txt
*hello.txt
 emptydir
[li.sanh@CS441 project-5]$

```

## How I test it

using command `make check`
and try the examples to compare with the result in the pdf

## Test traces
I'm not quite understand what does this part means.
I think you may need the test results and they are in the **Examples** part

## Known bugs and problem areas
Not found right now.

If you have found some bugs, please report to <li.sanh@uwlax.edu>