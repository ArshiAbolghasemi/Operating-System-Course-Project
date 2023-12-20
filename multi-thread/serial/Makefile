CC      =  g++
CPPFLAGS += -std=c++11

PATH_LIB = ../lib

PATH_SRC  = ./src
PATH_SRC_LIB = $(PATH_LIB)/src
PATH_SRC_LIB_BMP = $(PATH_SRC_LIB)/bmp
PATH_SRC_LIB_UTIL = $(PATH_SRC_LIB)/util

PATH_INC  = ./include
PATH_INC_LIB =  $(PATH_LIB)/include
PATH_INC_LIB_BMP = $(PATH_INC_LIB)/bmp
PATH_INC_LIB_UTIL = $(PATH_INC_LIB)/util

PATH_OBJ  = ./obj

PATH_OUTPUT = ./output

OUTPUT = ImageFilters.out
INPUT = ../input/sample_input.bmp

# ----------------------------------------------------------------------------------------

vpath %.cpp $(PATH_SRC) $(PATH_SRC_LIB) $(PATH_SRC_LIB_BMP) $(PATH_SRC_LIB_UTIL)
vpath %.hpp $(PATH_INC) $(PATH_INC_LIB) $(PATH_INC_LIB_BMP) $(PATH_INC_LIB_UTIL)

OBJS = main.o bmp.o filter.o apm.o time_service.o pixel.o

# ----------------------------------------------------------------------------------------

run: all
	(make all)
	(./$(OUTPUT) $(INPUT))

all: $(PATH_OBJ) $(OUTPUT) $(PATH_OUTPUT)

$(OUTPUT): $(addprefix $(PATH_OBJ)/, $(OBJS))
	$(CC) $(CPPFLAGS) -o $@ $^

$(PATH_OBJ)/main.o: main.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(PATH_OBJ)/bmp.o: bmp.cpp bmp.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(PATH_OBJ)/filter.o: filter.cpp filter.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(PATH_OBJ)/apm.o: apm.cpp apm.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(PATH_OBJ)/time_service.o: time_service.cpp time_service.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(PATH_OBJ)/pixel.o: pixel.cpp pixel.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

# ----------------------------------------------------------------------------------------

$(PATH_OBJ):  ; mkdir -p $@

$(PATH_OUTPUT):
	mkdir -p $(PATH_OUTPUT)

# -----------------------------------------------------------------------------------------

.PHONY: all clean run

clean:
	rm -rf $(PATH_OBJ) $(OUTPUT) $(PATH_OUTPUT) > /dev/null 2>&1