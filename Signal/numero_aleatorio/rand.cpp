#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

FILE * pFile;

int numero_rand(){
    char buf[BUFSIZ];
    srand(time(NULL));
    pFile = fopen(".numero.txt","w");
    sprintf(buf,"%i",(0+rand()%100));
    fputs(buf,pFile);
    fclose(pFile);
}

int spawn (char* numero_rand, char** arg_list){
    pid_t child_pid;
    child_pid = fork();
    if (child_pid != 0)
	return child_pid;
    else {
	execvp (numero_rand,arg_list);
	fprintf(stderr, "Error\n");
	abort();
    }
  
}

int main(int argc, char *argv[]) {

    int child_status;

    char* arg_list[] = {
    "./rand",
    NULL};

    spawn("./rand",arg_list);

    wait (&child_status);
    if(WIFEXITED (child_status)){

	long lSize;
	char* buffer;
	int aleatorio;

	fseek (pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind (pFile);

	buffer = (char*) malloc (sizeof(char)*lSize);
	aleatorio = fread(buffer,1,lSize,pFile);

	printf("%i", aleatorio);

	free(buffer);
    }

    else
	printf ("El proceso hijop no acabo con normalidad\n");

    fclose(pFile);
    return EXIT_SUCCESS;
}
