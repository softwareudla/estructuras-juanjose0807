#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    struct Biblio libro1[20];
    int cant = 0;
    int opcion = 0;

    do {
        printf("1. Ingresar un libro\n");
        printf("2. Imprimir los libros\n");
        printf("3. Buscar  un libro\n");
        printf("4. Cambiar estado de un libro\n");
        printf("5. Borrar un libro\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingLibro(&libro1[cant], libro1 ,&cant);
                break;
            case 2:
                impLibros(libro1, cant);
                break;
            case 3:
                buscLibro(libro1, cant);
                break;
            case 4:
                Estado(libro1, cant);
                break;
            case 5:
                borrarLibro(libro1, &cant);
                break;
            case 6:
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 6);

    return 0;
}

