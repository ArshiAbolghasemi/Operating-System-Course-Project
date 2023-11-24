CC := gcc
CFLAGS := 

PATH_SRC = ./src
PATH_SRC_UTIL = $(PATH_SRC)/util
PATH_INC = ./include
PATH_INC_UTIL = $(PATH_INC)/util
PATH_OBJ = ./obj

vpath %.c $(PATH_SRC) $(PATH_SRC_UTIL)
vpath %.h $(PATH_INC) $(PATH_INC_UTIL)

#-----------------------------------------------

$(PATH_OBJ)/log.o: log.cpp log.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

#-----------------------------------------------

$(PATH_OBJ): ; mkdir -p $@

.PHONY: all clean

clean:
	rm -rf $(PATH_OBJ) $(PATH_INC)/*.h.gch *.o *.out > /dev/null 2>&1

