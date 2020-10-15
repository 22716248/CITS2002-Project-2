#include "headers.h"
#include "compare.c"
#include "managefiles.c"

void processFiles(char *basedir, char *finalpath)
{
    DIR *dir;
    struct dirent *ent;
    dir = opendir(basedir);

    if (dir != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            //ignore . or ..
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, ".." ) == 0){
                continue;
            }

            //record current paths for current and final
            char entpath[MAXPATHLEN] = "";
            char finpath[MAXPATHLEN] = "";
            strcat(entpath, basedir);
            strcat(entpath, "/");
            strcat(entpath, ent->d_name);
            strcat(finpath, finalpath);
            strcat(finpath, "/");
            strcat(finpath, ent->d_name);
            
            //check if current path is a directory
            int dir_check = getDir(entpath);

            if (dir_check) //directory
            {   
                //if no directory in final exists, make one
                if(mkdir(finpath, 0777) && errno != EEXIST){
                    printf("error: file exists");
                    perror("mkdir(): ");
                }
                //recursivly go through this directory
                processFiles(entpath, finpath);
            }
            else //file itself
            {
                //if file doesn't exist in final folder, copy it
                //if it does, check parameters, and update accordingly
                if( access(finpath, F_OK ) != -1 ) {
                    // file exists
                    //check time modified and size...
                    int time_comparison = compareTimes(entpath, finpath);
                    int size_comparison = compareSize(entpath, finpath);
                    if(time_comparison == -1){ //final is older
                        copyFile(entpath, finpath);
                    } else if (time_comparison == 0){ //both same
                    //if final is smaller AND are the same change it. this should be the most recent file
                        if(size_comparison != -1){ 
                            copyFile(entpath, finpath);
                        }
                    } //skip if final is newer
                } else {
                    // file doesn't exist
                    // make file seketon and copy it over
                    if(open (finpath, O_CREAT) == -1){
                        printf("open failed");
                    }
                    close (*finpath);
                    copyFile(entpath, finpath);
                }
                printf("\n\tFILE: %s\n\tBASEDIR: %s\n\tENTPATH: %s\n \tFINALPATH: %s\n", ent->d_name, basedir, entpath, finpath);
            }
        }
        closedir(dir);
    }
    else
    {
        fprintf(stderr, "\nFailed to access dir \"%s\"\n", basedir);
        perror("opendir()");
    }
}

/** TESTING CODE
int main (){
    processFiles("./test", "./test2");
}
**/