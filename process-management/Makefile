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

OBJS_UTILITIES_CALCULATOR_ENGINE = utilities_calculator_engine.o log.o csv_reader.o\
	file_service.o building.o table.o\

OUT_UTILITIES_CALCULATOR_ENGINE = utilities_calculator_engine

#-----------------------------------------------

all: $(PATH_OBJ) $(OUT_UTILITIES_CALCULATOR_ENGINE)

$(OUT_UTILITIES_CALCULATOR_ENGINE): $(addprefix $(PATH_OBJ)/, $(OBJS_UTILITIES_CALCULATOR_ENGINE))
	$(CC) $(CFLAGS) -o $@ $^

$(PATH_OBJ)/utilities_calculator_engine.o: utilities_calculator_engine.cpp utilities_calculator_engine.hpp	
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
	rm -rf $(OUT_UTILITIES_CALCULATOR_ENGINE) $(PATH_OBJ) $(PATH_INC)/*.h.gch *.o *.out > /dev/null 2>&1

