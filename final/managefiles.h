#ifndef MANAGEFILES_H_   /* Include guard */
#define MANAGEFILES_H_

struct stat getStat(const char *file_path);
struct stat getStat(const char *file_path);
int Tar(char tarfile[], char *checkDir);
int unTar(char tarfile[], char *checkDir);
char * makeTempFile(void);
void removeFile(char *location);
int copyFile(char source[], char destination[]);

#endif