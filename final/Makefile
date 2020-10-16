
# Mergetars makefile
# Adapted from lecture notes by Chris McDonald, UWA.


PROJECT =  mergetars
HEADERS =  $(PROJECT).h
OBJ     =  mergetars.o processing.o managefiles.o compare.o


C99     =  cc -std=c99
CFLAGS  =  -Wall -pedantic -Werror


$(PROJECT) : $(OBJ)
	$(C99) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm


%.o : %.c $(HEADERS)
	$(C99) $(CFLAGS) -c $<

clean:
	rm -f $(PROJECT) $(OBJ)
