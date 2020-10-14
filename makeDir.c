
//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki, Brandon Petkovic
//  Student number(s):   22716248, 22502051
#include <dirent.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/sysmacros.h>
#include <sys/param.h>

char * makeTemporary(void){
    char template[] = "/tmp/tmpdir.XXXXXX";
    char *dir_name = mkdtemp(template);

    if(dir_name == NULL)
    {
            perror("mkdtemp failed: ");
    }

    return dir_name;
}


void removeTemporary(char *location){
    if(rmdir(location) == -1)
    {
        perror("rmdir failed: ");
    }
}

char * makeFinal(void){
    char template[] = "/tmp/tmpdir.XXXXXX";
    char *dir_name = mkdtemp(template);

    if(dir_name == NULL)
    {
            perror("mkdtemp failed: ");
    }

    return dir_name;
}


void removeFinal(char *location){
    if(rmdir(location) == -1)
    {
        perror("rmdir failed: ");
    }
}

int main(void)
{
    char temporary[19];
    memcpy(temporary, makeTemporary(), 19);
    removeTemporary(temporary);

    char final[19];
    memcpy(final, makeFinal(), 19);
    removeFinal(final);

    return 0;
}