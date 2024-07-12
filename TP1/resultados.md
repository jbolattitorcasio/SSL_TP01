# Resultados
***
- **Comando para compilar el proyecto (sin el makefile):** `gcc -std=c2x main.c tabla.c conversion.c -o prog`
- **Al excluir conversion.h de tabla.c figura el siguiente error:**
```bash
main.c: In function 'main':
main.c:8:5: warning: implicit declaration of function 'assert' [-Wimplicit-function-declaration]
    8 |     assert(argc >= 3);
      |     ^~~~~~
main.c:2:1: note: 'assert' is defined in header '<assert.h>'; did you forget to '#include <assert.h>'?
    1 | #include "tabla.h"
  +++ |+#include <assert.h>
    2 |
main.c:11:21: warning: implicit declaration of function 'atof' [-Wimplicit-function-declaration]
   11 |     double inicio = atof(argv[1]);
      |                     ^~~~
main.c:22:19: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
   22 |     if(fin == 42) printf("Usted encontro el sentido de la vida, el universo y todo lo dem├ís.");
      |                   ^~~~~~
main.c:2:1: note: include '<stdio.h>' or provide a declaration of 'printf'
    1 | #include "tabla.h"
  +++ |+#include <stdio.h>
    2 |
main.c:22:19: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
   22 |     if(fin == 42) printf("Usted encontro el sentido de la vida, el universo y todo lo dem├ís.");
      |                   ^~~~~~
main.c:22:19: note: include '<stdio.h>' or provide a declaration of 'printf'
tabla.c: In function 'tabla':
tabla.c:5:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    5 |     printf("\n-----------------------\n");
      |     ^~~~~~
tabla.c:2:1: note: include '<stdio.h>' or provide a declaration of 'printf'
    1 | #include "tabla.h"
  +++ |+#include <stdio.h>
    2 |
tabla.c:5:5: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
    5 |     printf("\n-----------------------\n");
      |     ^~~~~~
tabla.c:5:5: note: include '<stdio.h>' or provide a declaration of 'printf'
tabla.c:10:46: warning: implicit declaration of function 'conversion' [-Wimplicit-function-declaration]
   10 |         printf("| %8.4g | %8.4f |\n", nudos, conversion(nudos));
      |                                              ^~~~~~~~~~
C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/12.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\Usuario\AppData\Local\Temp\cc89awb1.o:main.c:(.text+0x21): undefined reference to `assert'
C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/12.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\Usuario\AppData\Local\Temp\cc89awb1.o:main.c:(.text+0xa8): undefined reference to `assert'
C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/12.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\Usuario\AppData\Local\Temp\cc89awb1.o:main.c:(.text+0xc2): undefined reference to `assert'
collect2.exe: error: ld returned 1 exit status
```
> Se puede ver 2 tipos de errores diferentes:
> - El primero es producido a causa de que los includes `<stdio.h> <stdlib.h>` y `<assert.h>` estaban dentro de conversion.h, y por lo tanto main.c y tabla.c nunca acceden a ellos.
> - El segundo es que a falta de llamar a conversion.c, el uso de la funcion conversion() es implicita, es decir, que no esta declarada.

- **Un comando que excluye el tabla.c seria** `gcc -std=c2x main.c conversion.c -o prog` **y muestra el siguiente error:**
```bash
C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/12.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\Usuario\AppData\Local\Temp\ccq8vLcz.o:main.c:(.text+0x19e): undefined reference to `tabla'
collect2.exe: error: ld returned 1 exit status
```
> El error hace referencia a que, cuanco el main.c quiere hacer el include de tabla.h, esta no la encuentra, ya que no se indico al compilar.

- **El comando necesario para obtener conversion.i seria:** `gcc -std=c2x -E conversion.c -o conversion.i`