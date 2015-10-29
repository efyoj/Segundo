#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


void lanza(const char *programa){
    pid_t numero_de_mi_hijo = fork();

    if(!numero_de_mi_hijo){
	execl(programa, programa, NULL);
	fprintf(stderr, "No he podido arrancar %s.\n", programa);
    }
}

int main(int argc, char *argv[]) {

    lanza("./aleatorio");

    return EXIT_SUCCESS;
}
