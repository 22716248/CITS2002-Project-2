//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki, Brandon Petkovic
//  Student number(s):   22716248, 22502051

#include "headers.h"
#include "processing.h"
#include "managefiles.h"

/**
 * This project aims to combine multiple tar archive backups into
 * one, revised most recent copy of all the given tars to a single tar,
 * output_name.tar, given by the last argument. Arguments before beforementioned
 * name are the tar files to be merged. There must be at least 2 arguments.
 * The output of this function is returned in the location of the program when its run.
 * */
int main(int argc, char *argv[]){

    if (argc < 3){
        printf("mergetars: You must provide at least 2 arguments.\n");
        exit(EXIT_FAILURE);
    }

    char finalPath[19];
    memcpy(finalPath, makeTempFile(), 19);
    char *output_name = argv[argc-1];

    int currentTar = 1;
    while(currentTar != argc - 1){
        char tempPath[19];
        memcpy(tempPath, makeTempFile(), 19);
        unTar(argv[currentTar], tempPath);
        processFiles(tempPath, finalPath);
        removeFile(tempPath);
        currentTar++;
    }

    Tar(output_name, finalPath);
    removeFile(finalPath);

    printf("mergetars: Merging tars complete. \nmergetars: Final tar: [%s]\n", output_name);
}
