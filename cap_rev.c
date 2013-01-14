/* AP mod MB 9-jan-12	cap_rev.c				*/
/*	Argumente großschreiben und komplett umkehren   	*/

# include <string.h>
# include <stdio.h>

/* reverse a string in place */
void reverse( char s[] ) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i <= j; i++, j--) {
		c = s[i];
		// Change to upper-case 
		s[i] = ((s[j] >= 'a') && (s[j] <= 'z'))? s[j]-'a'+'A' : s[j]; 
		s[j] = ((c    >= 'a') && (c    <= 'z'))? c   -'a'+'A' : c;
	}
}

int main( int argc, char * argv [] ) {
	char * prog = argv[0];
	int i = 0;

	if (argc < 2 ) {
		printf("usage: %s <string>+\n", prog );
		return 1;
	}
	for (i = argc-1; i > 0; i--) {
		//printf("%s - \t", argv[ i ]);
		reverse( argv[ i ] );
		printf("%s ", argv[i]);
		//printf("%s\n", argv[ i ]);
	}
	printf("\n");
	return 0;
}
		

	
