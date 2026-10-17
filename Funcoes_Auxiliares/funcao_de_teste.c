#include <math.h>

double f(double x) {
    /* Esta é a função de referência f(x) = x . e^x que será usada
     * no cáluclo da integral através dos métodos dos trapézios e de simpson */

    return x * exp(x);  // exp(x) é uma função de <math.h> e equivale a e^x.
}
