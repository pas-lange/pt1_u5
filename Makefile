# MB 15.01.2013 Makefile pt1_u5
#
#
SHELL=/bin/sh

TARGETS=cap_rev test_atoi wc

# all: erste Target im Makefile --> Defaulttarget, 
# wenn make ohne Parameter aufgerufen wird
all: $(TARGETS)

atoi_HDR=atoiEx.h
atoi_SRC=$(atoi_HDR:%.h=%.c) test_atoi.c
atoi_OBJ=$(atoi_SRC:%.c=%.o)

# - vor include unterdrückt Fehler, falls .depend File nicht existiert
DEPENDFILE=.depend
-include $(DEPENDFILE)

clean: 
	rm -f $(TARGETS)
	rm -f *.o
	rm -f *.s
	rm -rf *.dSYM
	rm -f $(DEPENDFILE)

# gcc -MM durchsucht includes und erstellt Abhängigkeiten
dep:
	$(CC) -MM $(atoi_SRC) > $(DEPENDFILE)

test_atoi: $(atoi_OBJ)
	echo $(atoi_SRC)
	make dep
	make -s CFLAGS=$(CFLAGS) $(atoi_OBJ)
	$(CC) -o $@ $(atoi_OBJ)

#make -s CFLAGS=$(CFLAGS) $(atoi_OBJ)
# -D_atoiEx definet _atoiEx (damit extended Atoi aus atoi.h genutzt wird - präprozessor)
# gcc -c compilet oder assemblet nur, ohne zu linken .c -> .o
# gcc -o linkt auf $@ -> Target
hex_atoi: $(atoi_OBJ)
	echo $(atoi_SRC)
	make dep
	$(CC) -D_atoiEx -c test_atoi.c
	$(CC) -o test_atoi $(atoi_OBJ)

cap_rev: cap_rev.o
	echo cap_rev.c
	$(CC) -o cap_rev cap_rev.o

wc: wc.o
	echo wc.c
	$(CC) -o wc wc.o

debug:
	make CFLAGS=-g all
