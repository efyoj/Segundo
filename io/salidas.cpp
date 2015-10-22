#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char nombre [0x20];

    printf("Dime tu nombre: ");
    scanf(" %s", nombre);


    return EXIT_SUCCESS;
}
