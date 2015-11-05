#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

struct TDatos { 
    char caracter;
};

sig_atomic_t finish;

void bye (int sig_num){
    finish = 1;
    printf("\n\nHastalue\n\n");
}

void *create (void *datos){
    struct TDatos *dato = (struct TDatos *) datos;
    char c = dato->caracter;

    while(!finish)
	putc (c, stderr);

    return NULL;
}

int main(int argc, char *argv[]) {

    pthread_t hilo[5];
    struct TDatos j = {'j'};
    struct TDatos u = {'u'};
    struct TDatos a = {'a'};
    struct TDatos s = {'s'};
    struct TDatos x = {' '};

    struct sigaction sa;
    sa.sa_handler = &bye;
    sigaction(SIGINT, &sa, NULL);

    pthread_create(&hilo[0], NULL, &create, &j);
    pthread_create(&hilo[1], NULL, &create, &u);
    pthread_create(&hilo[2], NULL, &create, &a);
    pthread_create(&hilo[3], NULL, &create, &s);
    pthread_create(&hilo[4], NULL, &create, &x);

    for(int i=0; i<5; i++)
	pthread_join(hilo[i], NULL);

    return EXIT_SUCCESS;
}
