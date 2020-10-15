//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki, Brandon Petkovic
//  Student number(s):   22716248, 22502051

#include "headers.h"

int main(int argc, char *argv[]){
    char finalPath[19];
    memcpy(finalPath, makeFinal(), 19);
    size_t numberOfTars = argc - 2;
    char output_name[] = argv[argc];

    int currentTar = 0;
    while(currentTar != numberOfTars - 1){
        char tempPath[19];
        memcpy(tempPath, makeTempFile(), 19);
        unTar(argv[currentTar], tempPath); //untar into temppath
        processFiles(tempPath, finalPath);
        removeFile(tempPath);
        currentTar++;
    }

    Tar(finalPath, output_name);
    removeFile(finalPath);

}