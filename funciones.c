#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingLibro(struct Biblio *libro, struct Biblio libros[], int *cant) {
    if (*cant >= 20) {
        printf("No se pueden agregar mas libros.\n");
        return;
    }
    
    int IDU;
    do {
        IDU = 0;

        printf("Ingrese el ID: ");
        scanf("%d", &libro->id);

        if (libro->id < 0) {
            printf("El ID no puede ser negativo, vuelva a intentar\n");
            IDU = 1; 
        }

        for (int i = 0; i < *cant; i++) {
            if (libros[i].id == libro->id) {
                printf("El ID ya existe, vuelva a intentar\n");
                IDU = 1;
                break;
            }
        }

    } while (IDU==1);

  
    printf("Ingrese titulo: ");
    fflush(stdin);
    fgets(libro->titulo, 100, stdin);
    libro->titulo[strcspn(libro->titulo, "\n")] = '\0';   
    

    printf("Ingrese autor: ");
    fflush(stdin);
    fgets(libro->autor, 50, stdin);
    libro->autor[strcspn(libro->autor, "\n")] = '\0'; 
    

    
    do {
        printf("Ingrese el año: ");
        scanf("%d", &libro->año);
        if (libro->año < 0) {
            printf("El año no puede ser negativo, vuelva a ingresarlo\n");
        }
    } while (libro->año < 0);


    strcpy(libro->estado, "Disponible");

    (*cant)++;
    
}

void impLibros(struct Biblio libros[], int cant) {
    if (cant == 0) {
        printf("No hay libros en la Biblioteca.\n");
        return;
    }

    printf("\nID   Título   Autor   Año   Estado\n");
    
    for (int i = 0; i < cant; i++) {
        printf("%d   %s   %s   %d   %s\n", 
            libros[i].id, libros[i].titulo, libros[i].autor, libros[i].año, libros[i].estado);
    }
}


void buscLibro(struct Biblio libros[], int cant) {
    int op;
    printf("Ingrese la opcion, 1 por ID, 2 por Titulo: ");
    scanf("%d", &op);

    if (op == 1) {
        int ID;
        printf("Ingrese ID: ");
        scanf("%d", &ID);

        for (int i = 0; i < cant; i++) {
            if (libros[i].id == ID) {
                printf("%d   %s   %s   %d   %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor, libros[i].año, libros[i].estado);
                return; 
            }
        }
       
        printf("Libro no encontrado.\n");

    } else if (op == 2) {
        char titulo[100];
        printf("Ingrese título: ");
        fflush(stdin);
        fgets(titulo, 100, stdin);
        titulo[strcspn(titulo, "\n")] = '\0'; 

        for (int i = 0; i < cant; i++) {
            if (strcmp(libros[i].titulo, titulo) == 0) {
                printf("%d   %s   %s   %d   %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor, libros[i].año, libros[i].estado);
                return; 
            }
        }
        
        printf("Libro no encontrado.\n");

    } 
}


void Estado(struct Biblio libros[], int cant) {
    int ID;
    printf("Ingrese ID: ");
    scanf("%d", &ID);

    for (int i = 0; i < cant; i++) {
        if (libros[i].id == ID) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado %s.\n", libros[i].estado);

        }else if (libros[i].id != ID){ 
        printf("Libro no encontrado.\n");
        }
    }
   
}

void borrarLibro(struct Biblio libros[], int *total) {
    int ID;
    printf("Ingrese ID del libro: ");
    scanf("%d", &ID);

    for (int i = 0; i < *total; i++) {
        if (libros[i].id == ID) {
            for (int j = i; j < *total - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*total)--;
            printf("Libro eliminado.\n");
        }else{
        printf("Libro no encontrado.\n");
        }
    }
  
}

