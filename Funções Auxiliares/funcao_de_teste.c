#include <math.h>

double f(double x) {
    /* Esta é a função de referência f(x) = x . e^x que será usada
     * no cáluclo da integral através dos métodos dos trapézios e de simpson */

    return x * pow(2.71828, x);
}
