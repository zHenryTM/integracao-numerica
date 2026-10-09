#include <stdio.h>
#include "integrar_trapezio.c"

int main() {
    float f = integrar_trapezio(0, 2, 100);
    printf("Olá, mundo!\n");
    printf("f: %f\n", f);
}
