#define _POSIX_C_SOURCE 200809L
#include <dirent.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h> //cp
#include <sys/sysmacros.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <sys/time.h>

//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki, Brandon Petkovic
//  Student number(s):   22716248, 22502051

extern struct stat getStat(const char *file_path);
extern void unTar(char tarfile[], char *checkDir);
extern int Tar(char tarfile[], char *checkDir);
extern char * makeTempFile(void);
extern void removeFile(char *location);
extern int copyFile(char source[], char destination[]);
extern void processFiles(char *basedir, char *finalpath);
extern int getSize(const char *file_path);
extern int getTime(const char *file_path);
extern int getDir(const char *file_path);
extern int compareTimes(const char *temp_path, const char *final_path);
extern int compareSize(char *temp_path, char *final_path);