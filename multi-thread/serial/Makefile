CC      =  g++
CPPFLAGS += -std=c++11

PATH_LIB = ../lib

PATH_SRC  = ./src
PATH_SRC_LIB = $(PATH_LIB)/src
PATH_SRC_LIB_BMP = $(PATH_SRC_LIB)/bmp

PATH_INC  = ./include
PATH_INC_LIB =  $(PATH_LIB)/include
PATH_INC_LIB_BMP = $(PATH_INC_LIB)/bmp


PATH_OBJ  = ./obj

OUTPUT = ImageFilters.out

# ----------------------------------------------------------------------------------------

vpath %.cpp $(PATH_SRC) $(PATH_SRC_LIB) $(PATH_SRC_LIB_BMP)
vpath %.hpp $(PATH_INC) $(PATH_INC_LIB) $(PATH_INC_LIB_BMP)

OBJS = main.o bmp.o filter.o

# ----------------------------------------------------------------------------------------

all: $(PATH_OBJ) $(OUTPUT)

$(OUTPUT): $(addprefix $(PATH_OBJ)/, $(OBJS))
	$(CC) $(CPPFLAGS) -o $@ $^

$(PATH_OBJ)/main.o: main.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(PATH_OBJ)/bmp.o: bmp.cpp bmp.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(PATH_OBJ)/filter.o: filter.cpp filter.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

# ----------------------------------------------------------------------------------------

$(PATH_OBJ):  ; mkdir -p $@

.PHONY: all clean run

clean:
	rm -rf $(PATH_OBJ) $(OUTPUT) > /dev/null 2>&1