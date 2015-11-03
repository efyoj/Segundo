#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    FILE *pf = NULL;

    if(argc < 2){
	fprintf(stderr, "Error: No se encontro el archivo.\n");
	exit(EXIT_FAILURE);
    }

    if ( !(pf = fopen(argv[1], "w"))) {
	fprintf(stderr, "Error: No se puede abrir el fichero.\n");
	exit(EXIT_FAILURE);
    }

    sleep(5);
    fprintf(pf, "The World is a Vampire.\n");

    fclose(pf);
    return EXIT_SUCCESS;
}
