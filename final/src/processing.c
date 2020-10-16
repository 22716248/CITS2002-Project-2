#include "headers.h"
#include "compare.h"
#include "managefiles.h"
#include "processing.h"

/**
 * This function takes two file paths
 * They are compared agaisnt one another and final path recieves updated,
 * new files. This will check and copy files to the final path given.
 * This function returns nothing. 
 **/
void processFiles(char *current_path, char *final_path)
{
    DIR *folder;
    struct dirent *file;
    folder = opendir(current_path);

    if (folder != NULL)
    {
        while ((file = readdir(folder)) != NULL)
        {
            if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, ".." ) == 0){
                continue; //skips .. and . dirs. continiues out of while loop
            }

            //record current paths for current and final
            char curr_file_path[MAXPATHLEN] = "";
            char fin_file_path[MAXPATHLEN] = "";
            strcat(curr_file_path, current_path);
            strcat(curr_file_path, "/");
            strcat(curr_file_path, file->d_name);
            strcat(fin_file_path, final_path);
            strcat(fin_file_path, "/");
            strcat(fin_file_path, file->d_name);
            
            //Checks if current path is a directory
            int dir_check = getDir(curr_file_path);
            if (dir_check) //directory
            {   
                //If no directory in final exists, makes one.
                if(mkdir(fin_file_path, 0777) && errno != EEXIST){
                    perror("mkdir() [processing.c] failed: ");
                    exit(EXIT_FAILURE);
                }
                //Recursivly go through this directory
                processFiles(curr_file_path, fin_file_path);
            }
            else //File itself, main comparison happens here.
            {
                //If file doesn't exist in final folder, copy it.
                //If it does, check parameters, and update accordingly.
                if( access(fin_file_path, F_OK ) != -1 ) {
                    //Check time modified and size, since file exists
                    int time_comparison = compareTimes(curr_file_path, fin_file_path);
                    int size_comparison = compareSize(curr_file_path, fin_file_path);
                    if(time_comparison == -1){ //final is older
                        copyFile(curr_file_path, fin_file_path);
                    } else if (time_comparison == 0){ //both same
                    //If final is smaller AND are the same change it. 
                    //This should also be the most recent file in the command line,
                    //if this situation were to stack.
                        if(size_comparison != -1){ 
                            copyFile(curr_file_path, fin_file_path);
                        }
                    } //Skip if final is newer.
                } else {
                    //Make file skeleton and copy it over, since file doesn't exist.
                    if(open (fin_file_path, O_CREAT) == -1){
                        perror("open() [processing.c] failed: ");
                        exit(EXIT_FAILURE);
                    }
                    close (*fin_file_path);
                    copyFile(curr_file_path, fin_file_path);
                }
                // uncomment to see what processfile is doing
                //printf("\n\tFILE: %s\n\tcurrent_path: %s\n\tENTPATH: %s\n \tFINALPATH: %s\n", file->d_name, current_path, curr_file_path, fin_file_path);
            }
        }
        closedir(folder);
    }
    else
    {
        fprintf(stderr, "\nFailed to access folder \"%s\"\n", current_path);
        perror("opendir() [processing.c] failed: ");
        exit(EXIT_FAILURE);
    }
}