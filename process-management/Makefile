CC := g++
CFLAGS := 

PATH_SRC = ./src
PATH_SRC_UTIL = $(PATH_SRC)/util
PATH_SRC_SERVICE = $(PATH_SRC)/service
PATH_INC = ./include
PATH_INC_UTIL = $(PATH_INC)/util
PATH_INC_SERVICE = $(PATH_INC)/service
PATH_OBJ = ./obj

vpath %.cpp $(PATH_SRC) $(PATH_SRC_UTIL) $(PATH_SRC_SERVICE)
vpath %.hpp $(PATH_INC) $(PATH_INC_UTIL) $(PATH_INC_SERVICE)

OBJS_MAIN = main.o utilities_calculator_engine.o log.o\
	csv_reader.o file_service.o building.o table.o worker.o\

OUT_MAIN = main

#-----------------------------------------------

all: $(PATH_OBJ) $(OUT_MAIN)

$(OUT_MAIN): $(addprefix $(PATH_OBJ)/, $(OBJS_MAIN))
	$(CC) $(CFLAGS) -o $@ $^

$(PATH_OBJ)/main.o: main.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/utilities_calculator_engine.o: utilities_calculator_engine.cpp utilities_calculator_engine.hpp	
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/worker.o: worker.cpp worker.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/building.o: building.cpp building.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/file_service.o: file_service.cpp file_service.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/csv_reader.o: csv_reader.cpp csv_reader.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/log.o: log.cpp log.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/table.o: table.cpp table.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

#-----------------------------------------------

$(PATH_OBJ): ; mkdir -p $@

.PHONY: all clean

clean:
	rm -rf $(OUT_MAIN) $(PATH_OBJ) $(PATH_INC)/*.h.gch *.o *.out > /dev/null 2>&1

