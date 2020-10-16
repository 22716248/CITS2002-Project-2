#ifndef MANAGEFILES_H_   /* Include guard */
#define MANAGEFILES_H_

extern struct stat getStat(const char *file_path);
extern struct stat getStat(const char *file_path);
extern int Tar(char tarname[], char *tarfile);
extern int unTar(char tarfile[], char *checkDir);
extern char * makeTempFile(void);
extern void removeFile(char *location);
extern int copyFile(char source[], char destination[]);

#endif