CC := gcc
CFLAGS := 

PATH_SRC = ./src
PATH_SRC_UTIL = $(PATH_SRC)/util
PATH_INC = ./include
PATH_INC_UTIL = $(PATH_INC)/util
PATH_OBJ = ./obj

vpath %.c $(PATH_SRC) $(PATH_SRC_UTIL)
vpath %.h $(PATH_INC) $(PATH_INC_UTIL)

OBJS_RESTAURANT = restaurant.o user.o recipe.o cli.o util.o
OBJS_CUSTOMER = customer.o user.o cli.o util.o
OBJS_SUPPLIER = supplier.o user.o cli.o util.o

OUT_RESTAURANT  = restaurant
OUT_CUSTOMER = customer

#-----------------------------------------------

all: $(PATH_OBJ) $(OUT_RESTAURANT) $(OUT_CUSTOMER)

$(OUT_RESTAURANT): $(addprefix $(PATH_OBJ)/, $(OBJS_RESTAURANT))
	$(CC) $(CFLAGS) -o $@ $^

$(OUT_CUSTOMER): $(addprefix $(PATH_OBJ)/, $(OBJS_CUSTOMER))
	$(CC) $(CFLAGS) -o $@ $^

$(PATH_OBJ)/restaurant.o: restaurant.c restaurant.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/customer.o: customer.c customer.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/supplier.o: supplier.c supplier.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/user.o: user.c util.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/recipe.o: recipe.c recipe.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/cli.o: cli.c cli.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/util.o: util.c util.h
	$(CC) $(CFLAGS) -c -o $@ $<

#-----------------------------------------------

$(PATH_OBJ): ; mkdir -p $@

.PHONY: all clean

clean:
	rm -rf $(PATH_OBJ) $(OUT_RESTAURANT) $(OUT_CUSTOMER) $(OBJS_SUPPLIER) $(PATH_INC)/*.h.gch *.o *.out > /dev/null 2>&1

