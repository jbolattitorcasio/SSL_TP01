#include "tabla.h"

void tabla(double inicio, double fin, double incremento) {

    printf("\n-----------------------\n");
    printf("| %8s | %8s |\n", "Nudos", "Km/h"); 
    printf("-----------------------\n");

    for(double nudos = inicio; nudos <= fin; nudos += incremento)
        printf("| %8.4g | %8.4f |\n", nudos, conversion(nudos)); 

    printf("-----------------------\n");

    // Forma con mas codigo:
    // for(int nudos = inicio; nudos <= fin; nudos += incremento) {
    //     double kmh = conversion(nudos);
    //     printf("| %8d | %8.4f |\n", nudos, kmh); 
    // }
}