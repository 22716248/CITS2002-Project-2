#include "headers.h"
#include "compare.h"

int getSize(const char *file_path)
{
    struct stat s;
    stat(file_path, &s);
    int size = s.st_size;
    return size;
}

int getTime(const char *file_path)
{
    struct stat s;
    stat(file_path, &s);
    int time = s.st_mtime;
    return time;
}

int getDir(const char *file_path)
{
    struct stat s;
    stat(file_path, &s);
    int test = S_ISDIR(s.st_mode);
    return test;
}

/**
 * If tempFile is older, 1
 * If finalFile is older, -1
 * both the same, 0 
 **/
int compareTimes(const char *temp_path, const char *final_path){
    int tempTime = getTime(temp_path);
    int finalTime = getTime(final_path);

    if (tempTime < finalTime){
        return  1;
    } else if(tempTime > finalTime) {
        return -1;
    }
        return  0;
}

/**
 * If tempFile is smaller, 1
 * If finalFile is smaller, -1
 * both the same, 0 
 **/
int compareSize(char *temp_path, char *final_path){
    int tempSize = getSize(temp_path);
    int finalSize = getSize(final_path);

    if (tempSize < finalSize){
        return  1;
    } else if(tempSize > finalSize) {
        return -1;
    }
        return  0;
}
