# CITS2002-Project-2
#### Systems Programming Project 2

The goal of this project is to write a command-line utility program in C99, named mergetars, which merges the contents of multiple tar archive files into a single tar archive file.

Successful completion of the project will develop your understanding of advanced features of the C99 programming language, and many useful Linux operating system system-calls and POSIX function calls.

### Main Overview

- *temppath* = **makeTempFile**();
- *finalpath* = **makeFile**(output_tarfile (argv[-1]) );
  - *mkdir*();
- **while** over *argv[]*;
  - **unTar**(argv[N], *temppath*);
  - **walkDir**(temppath);
    - **compareTimes**(*temppath*, *finalpath*);
      - **compareSize**(file1, file2);
      - **readWrite**(filepath);
- **Tar**(*finalpath*);
- **removeFile**(*temppath* AND *finalpath*);
- **Free**(memory) (if needed)

## Files
```diff
- processfile.c -> compare.c, globals.c
+ globals.c -> N/A
! compare.c -> globals.c, tars.c
# tars.c -> globals.c
@@ mergetars.c -> processfile.c, globals.c, compare.c, tars.c @@
```
***makefile*** **to link above**

## Functions
```diff
- processfile.c -> walkDir, readWrite, removeFile, makeFile, makeTempFile
+ globals.c -> GLOBALS
! compare.c -> compareTimes, compareSize
# tars.c -> Tar (tar and untar)
@@ mergetars.c -> Free + ABOVE @@
```
