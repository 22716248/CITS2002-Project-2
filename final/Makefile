
# A Makefile to build our 'calcmarks' project

PROJECT =  mergetars
HEADERS =  $(PROJECT).h
OBJ     =  tars.o globals.o processfile.o compare.o


C99     =  cc -std=c99
CFLAGS  =  -Wall -pedantic -Werror 


$(PROJECT) : $(OBJ)
       $(C99) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm


%.o : %.c $(HEADERS)
       $(C99) $(CFLAGS) -c $<

clean:
       rm -f $(PROJECT) $(OBJ)

