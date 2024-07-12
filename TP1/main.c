#include "tabla.h"

int main(int argc, char const *argv[])
{
    // Verificar que se esten pasando los parametros
        // Como el nombre del programa es un parametro, hay que contar que el counter del argumento tiene un parametro mas
        // Entonces verificamos que tenga mas de 3
    assert(argc >= 3);

    // Convertir los parametros (array) a variables (float)
    double inicio = atof(argv[1]);
    double fin = atof(argv[2]);
    double incremento = (argc == 4) ? atof(argv[3]) : 1; // Si se pasaron 4 argumentos, entonces el incremento es ese argumento, sino, es igual a 1

    // Verificar que el valor inicial sea menor al final
    assert(inicio < fin);

    // Verificar que el incremento sea mayor a 0
    assert(incremento > 0.0);

    // Verificar que se haya encontrado el sentido de la vida
    if(fin == 42) printf("Usted encontro el sentido de la vida, el universo y todo lo demás.");

    // Llamar a la funcion para hacer tablas 
    tabla(inicio, fin, incremento);

    return 0;
}
