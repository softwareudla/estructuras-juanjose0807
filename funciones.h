
struct Biblio {
    int id;
    char titulo[100];
    char autor[50];
    int año;
    char estado[10];
};

void ingLibro(struct Biblio *libro, struct Biblio libros[], int *cant);
void impLibros(struct Biblio libros[], int cant);
void buscLibro(struct Biblio libros[], int cant);
void Estado(struct Biblio libros[], int cant);
void borrarLibro(struct Biblio libros[], int *cant);