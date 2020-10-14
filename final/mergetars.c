
//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki (, student-name2)
//  Student number(s):   22716248 (, student-number2)

#include <headers.h>

/**
 * This will be the actual main
 * */

int main(int argc, char *argv[]){
    char tempPath[] = makeTempFile();
    char finalPath[] = makeTempFile();
    size_t numberOfTars = sizeof(argv)/sizeof(argv[0]);
    char output_name[] = argv[numberOfTars];

    int currentTar = 0;
    while(currentTar != numberOfTars - 1){
        unTar(argv[currentTar], tempPath); //untar into temppath
        processFiles(tempPath, finalPath);
        currentTar++;
    }

    Tar(finalPath, output_name);
    removeFile(tempPath);
    removeFile(finalPath);

}