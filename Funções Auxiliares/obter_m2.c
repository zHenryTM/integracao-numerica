#include <math.h>

double obter_m2(double a, double b) {
    /* Esta função recebe a e b, que determinam o intervalo [a,b], calcula e retorna M2,
     * um parâmetro usado para concluir a estimativa de erro do cálculo de uma integral pelo
     * método do trapézio repetido.

     * m2 = max(f"(x)), a <= x <= b.
     * f(x) = x.e^x, logo f"(x) = e^x(2 + x) */


	double m2;

	for (double x = a; x <= b; x++)
    {
		double temp = exp(x) * (2 + x);  // exp(x) é uma função de <math.h> e equivale a e^x.

		if (x == a || temp > m2)
            m2 = temp;
	}

	return m2;
}
