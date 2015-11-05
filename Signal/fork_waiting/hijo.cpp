#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    FILE *pf = NULL;

    if(argc <2){
	fprintf(stderr, "Error: No hay archivo.\n");
	exit(EXIT_FAILURE);
    }

    if(!(pf = fopen(argv[1], "w"))) {
	fprintf(stderr, "Error: No se abre el fichero.\n");
	exit(EXIT_FAILURE);
    }

    sleep(2);
    fprintf(pf, "Este es MI ejercicio.\n");

    fclose(pf);

    return EXIT_SUCCESS;
}
