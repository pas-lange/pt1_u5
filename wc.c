/* MB 10.01.2013  wc.c						*/
/*	Zeilen, Worte und Zeichen der Standardeingabe erfassen 	*/
/*@+charint*/

# include <stdio.h>
# include <stdlib.h>

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
//#define durchschnitt( A, N, C ) A+=((N-A)/(A))

float durchschnitt(float *alt, int neu, int anzahl){
	return (*alt) += (neu-(*alt)) / (++anzahl);
}

int main(int argc, char *argv[]){
	// Array zum zählen der Buchstaben häufigkeit
	// von '!'(33) bis '~'(126) Zeichen zu zählen (94 Zeichen)
	// '!' = offset
	unsigned short int anzahl[94];
	// Standardeingabe Char
	char c;
	int i;

	// Ausgabewerte
	int worte = 0, zeilen = 1, zeichen = 0;
	int letzte_wort_len = 0;
	float avg_wort_len = 0;
	
	// Zählarray initialisieren
	for (i=0; i<94; i++) anzahl[i] = 0;

	// Alle Eingabechars verarbeiten
	while ((c = getchar()) != EOF){
		zeichen ++;
		if (c == '\n') 
			zeilen ++;
		if (c == ' ' || c == '\t' || c == '\n'){
			if(letzte_wort_len > 0){
			// Wort beendet -> neue dursch. Wortlänge -> Wortzahl erhöhen
				durchschnitt(&avg_wort_len, letzte_wort_len, worte++);
				//durchschnitt(avg_wort_len, letzte_wort_len, ++worte);
				letzte_wort_len = 0;
			}
		}
		else {
			// Anderes Zeichen -> gehört zum Wort
			// Zählen darstellbarer Zeichen 
			if ((c-'!') <= ('~'-'!')) anzahl[c-'!']++;
			letzte_wort_len++;
		}
	}

	// Ausgabe :
	printf("%d Wörter, \t %d Zeilen, \t %d Zeichen \n", worte, zeilen, zeichen);
	printf("Durchschnittliche Wortlänge: %f \n \n", avg_wort_len);
	
	printf("Zeichen\t\tVorkommen \n");
	for (i='!'; i<='~'; i++){
		if(anzahl[i-'!']) 
			if(anzahl[i-'!'] > (zeichen / 20)) printf(ANSI_COLOR_CYAN "%c\t\t%d\n" ANSI_COLOR_RESET, i, anzahl[i-'!']);
			else printf("%c\t\t%d\n", i, anzahl[i-'!']);;
	}
}
