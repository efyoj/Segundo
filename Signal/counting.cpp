#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

sig_atomic_t veces = 0;

void suma(int signal_number) {
    veces++;
}

int main(int argc, char *argv[]) {

    struct sigaction nueva, viejo;

    bzero(&nueva, sizeof (nueva));
    nueva.sa_handler = &suma;

    sigaction(SIGINT, &nueva, &viejo);

    sleep(5);

    printf("Nivel de pesadez de usuario: %i\n", veces);

    return EXIT_SUCCESS;
}
