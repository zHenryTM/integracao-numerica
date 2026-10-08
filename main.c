#include <stdio.h>
#include "integrar_trapezio.c"

int main() {
    float f = integrar_trapezio(2, 10, 4);
    printf("Olá, mundo!\n");
    printf("f: %f\n", f);
}
