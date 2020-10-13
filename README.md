# CITS2002-Project-2
#### Systems Programming Project 2

The goal of this project is to write a command-line utility program in C99, named mergetars, which merges the contents of multiple tar archive files into a single tar archive file.

Successful completion of the project will develop your understanding of advanced features of the C99 programming language, and many useful Linux operating system system-calls and POSIX function calls.

### Main Overview

- *temppath* = **makeTempFile**();
- *finalpath* = **makeFile**(output_tarfile (argv[-1]) );
  - *mkdir*();
- **while** over *argv[]*;
  - *unTar*(argv[N], *temppath*);
  - **walkDir**(temppath);
    - **compareTimes**(*temppath*, *finalpath*);
      - **compareSize**(file1, file2);
      - **readWrite**(filepath);
- **Tar**(*finalpath*);
- **removeFile**(*temppath* AND *finalpath*);
- **Free**(memory) (if needed)

//put into github, orginise into files, make makefile

## test
```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ text in purple (and bold)@@
```


### Quick Overview:
> *feel free to change this up!*

1. **loop** through each *tar* file, given as string in main. (may need to be opened as temporary as well?)
2. create a *new* **temporary** file, which will be the *final* file.
3. **compare** the contents of *current* tar and *final* tar
4. **add/replace** most *recent file* from currently *looping* tar to *final* tar
   - This will be decided by the *name, file location and date* of the currently selected file.
5. ensure the program **cleans up** and releases *unused memory*.
6. **output** the *final, merged file* to user.

## Files planned to add
- globals.c
- processfile.c  
- mergefile.c
- mergetars.c
- compare.c
