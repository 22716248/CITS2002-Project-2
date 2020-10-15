 PROJECT =  mergetars
# changed from .h to .c FOR NOW
HEADERS =  $(PROJECT).c
OBJ     =  processing.o managefiles.o compare.o


C99     =  cc -std=c99
CFLAGS  =  -Wall -pedantic -Werror


$(PROJECT) : $(OBJ)
	$(C99) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm


%.o : %.c $(HEADERS)
	$(C99) $(CFLAGS) -c $<

clean:
	rm -f $(PROJECT) $(OBJ)
