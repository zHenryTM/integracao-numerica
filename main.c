#include <stdio.h>
#include "integrar_trapezio.c"

int main() {
    float f = integrar_trapezio(0, 2, 100);
    printf("f: %f\n", f);
    return 0;
}
