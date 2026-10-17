#define _USE_MATH_DEFINES
#include <math.h>

double dpm(double z) {
    return exp(-0.5 * z * z);
}

double calcular_probabilidade_normal(int opcao) {
    double A, B;

    A = 1 / sqrt(2 * M_PI);

    switch (opcao) {
        case 1:
            B = integrar_trapezio(dpm, -1, 1.96, 100);
            break;
        case 2:
            B = integrar_simpson(dpm, -1, 1.96, 100);
            break;
    }

    printf("Probabilidade normal: %f\n", A * B);

    return A * B;
}