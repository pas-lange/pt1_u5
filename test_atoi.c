/* MB 10.01.2013	test_atoi.c	 	*/
/* 	Testen der eigenen atoi-Funktion	*/

#include <stdio.h>
#include <string.h>
#include "atoiEx.h"

int main(int argc, char *argv[]){
	char *prog = argv[0];
	int i = 0;	

	if(argc <= 1){
		printf("usage: %s <zahl>+ \n", prog);
		printf("Hexadezimal: 0x... ; Bsp.: 0xAFFE, -0xBEAF \n");
	} else {
		for(i=1; i<argc; i++){
			printf("%s = %d \n", argv[i], atoiEx(argv[i]));
		}
	}

	return 0;
}
