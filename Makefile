# AP 04-sep-12 Examples for Unit 7
#
#
SHELL=/bin/sh

TARGETS=cap_rev test_atoi wc

all: $(TARGETS)

atoi_HDR=atoiEx.h
atoi_SRC=test_atoi.c atoiEx.c
atoi_OBJ=$(atoi_SRC:%.c=%.o)

DEPENDFILE=.depend
-include $(DEPENDFILE)

clean: 
	rm -f $(TARGETS)
	rm -f *.o
	rm -f *.s
	rm -rf *.dSYM
	rm -f $(DEPENDFILE)

dep:
	$(CC) -MM $(atoi_SRC) > $(DEPENDFILE)

test_atoi: $(atoi_OBJ)
	echo $(atoi_SRC)
	make dep
	make -s CFLAGS=$(CFLAGS) $(atoi_OBJ)
	$(CC) -o $@ $(atoi_OBJ)

debug:
	make CFLAGS=-g all
