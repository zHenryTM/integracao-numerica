#include <stdio.h>
#include "integrar_trapezio.c"
#include "Funcoes_Auxiliares/funcao_de_teste.c"


int main() {
    double resultado = integrar_trapezio(f, 0, 2, 100);

    printf("Metodo do Trapezio! f: %f\n", resultado);
}
