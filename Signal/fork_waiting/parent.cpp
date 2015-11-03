#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

sig_atomic_t finished = 0;

void kaput(int signum){
    finished = 1;
}

void spawn(const char *command, const char *parameter){
    pid_t child = fork();

    if(!child){
	execl(command, command, parameter, NULL);
	fprintf(stderr, "Error: Programa no encontrado.\n");
    }
}

int main(int argc, char *argv[]) {
    const char *child = "./child";
    const char *text_file = "file.txt";

    FILE *pf = NULL;
    int child_status;
    char ch;

    struct sigaction sa;
    sa.sa_handler = kaput;

    sigaction(SIGCHLD, &sa, NULL);

    spawn(child, text_file);

    while( !finished ){
	system("clear");
	printf("Ejecutandose.\n");
    }
    
    wait(&child_status);

    if( !(pf = fopen(text_file, "r"))){
	fprintf(stderr, "Error: Archivo no encontrado.\n");
	exit(EXIT_FAILURE);
    }

    while( (ch = getc(pf) )!= EOF) 
	printf("%c", ch);

    fclose(pf);

    return EXIT_SUCCESS;
}
