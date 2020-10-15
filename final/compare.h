#ifndef COMPARE_H_   /* Include guard */
#define COMPARE_H_

int getSize(const char *file_path);
int getTime(const char *file_path);
int getDir(const char *file_path);
int compareTimes(const char *temp_path, const char *final_path);
int compareSize(char *temp_path, char *final_path);

#endif
