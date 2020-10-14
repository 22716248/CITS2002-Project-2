//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki, Brandon Petkovic
//  Student number(s):   22716248, 22502051

#include <headers.h>

int main(int argc, char *argv[]){
    char tempPath[] = makeTempFile();
    char finalPath[] = makeTempFile();
    size_t numberOfTars = sizeof(argv)/sizeof(argv[0]);
    char output_name[] = argv[numberOfTars-1];

    int currentTar = 0;
    while(currentTar != numberOfTars - 2){
        unTar(argv[currentTar], tempPath); //untar into temppath
        processFiles(tempPath, finalPath);
        currentTar++;
    }

    Tar(finalPath, output_name);
    removeFile(tempPath);
    removeFile(finalPath);

}