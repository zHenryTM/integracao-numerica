#include <stdio.h>
#include "integrar_trapezio.c"

int main() {
    float f = integrar_trapezio(0, 2, 4);
    printf("Método do trapézio!\n");
    printf("f: %f\n", f);
    
}
