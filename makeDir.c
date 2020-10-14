
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

int main()
{
    char template[] = "/tmp/tmpdir.XXXXXX";
    char *dir_name = mkdtemp(template);

    if(dir_name == NULL)
    {
            perror("mkdtemp failed: ");
            return 0;
    }

    /* Use it here */
    printf("\n%s\n", dir_name);

    /* Don't forget to delete the folder afterwards. */
    if(rmdir(dir_name) == -1)
    {
            perror("rmdir failed: ");
            return 0;
    }


    return 0;

}