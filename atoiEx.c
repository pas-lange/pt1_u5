/* 10.01.2013 Marvin Bornstein, Pascal Lange 	*/
/* atoiEx.c - Erweitertes atoi()		*/
/* Hex-Angabe wie folgt: 0xAF.. ; Dez: 124.. 	*/

#include <string.h>
#include "atoiEx.h"

/* Prüft, ob das Zeichen zulässig ist und schreibt
in v den entsprechenden Dezimalwert		*/
int isInRange(char c, int *v){
	if 	(c>='0' && c<='9') (*v)=   (c-'0');
	else if (c>='a' && c<='f') (*v)=10+(c-'a');
	else if (c>='A' && c<='F') (*v)=10+(c-'A');
	else return 0;

	return 1;
}

int atoiEx(char zahl[]){
	int i, n = 0;
	int vorzeichen = 0;
	int buf_value = 0;
	int offset = 0;

	if(zahl[0] == '-'){
		vorzeichen = -1;
		offset ++;
	} else {
		vorzeichen = 1;
	}

	// Prüfen, ob der Parameter eine Hex-Zahl ist
	if((zahl[offset+0] == '0') && (zahl[offset+1] == 'x')){
		for(i=offset+2; isInRange(zahl[i], &buf_value); i++) n = 16*n + buf_value;
	} else {
		for(i=offset+0; zahl[i] >= '0' && zahl[i] <= '9'; i++) n=10*n + (zahl[i]-'0');
	}

	return n*vorzeichen;
}
