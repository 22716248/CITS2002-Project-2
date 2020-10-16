#ifndef COMPARE_H_   /* Include guard */
#define COMPARE_H_

extern int getSize(const char *file_path);
extern int getTime(const char *file_path);
extern int getDir(const char *file_path);
extern int compareTimes(const char *temp_path, const char *final_path);
extern int compareSize(char *temp_path, char *final_path);

#endif
