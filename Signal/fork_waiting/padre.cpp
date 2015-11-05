#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

sig_atomic_t acabado = 0;

void finiquito(int signum){
    acabado = 1;
    }

void spawn (const char* programa, const char* argumentos){
    pid_t hijo = fork();

    if(!hijo){
	execl(programa, programa, argumentos, NULL);
	fprintf(stderr, "Error: No hay programa.\n");
    }
}

int main(int argc, char *argv[]) {
    const char *hijo = "./hijo";
    const char *archivo = "archivo.txt";

    FILE *pf = NULL;
    int estado_hijo;
    char ch;

    struct sigaction sa;
    sa.sa_handler = finiquito;

    sigaction(SIGCHLD, &sa, NULL);

    spawn(hijo, archivo);

    while(!acabado){
	system("clear");
	printf("Procesando.\n");
    }

    wait(&estado_hijo);

    if(!(pf = fopen(archivo, "r"))){
	fprintf(stderr, "Error: No hay archivo.\n");
	exit(EXIT_FAILURE);
    }

    while(ch = getc(pf))
	printf("%c", ch);

    fclose(pf);

    return EXIT_SUCCESS;
}
