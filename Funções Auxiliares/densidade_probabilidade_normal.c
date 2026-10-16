#include <math.h>

float densidade_probabilidade_normal(float z) {
    return 1 / (2 * sqrt(2 * 3.14159) * pow(2.71828, z * z));
}
