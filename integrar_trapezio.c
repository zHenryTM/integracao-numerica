#include <math.h>
#include "funcao_de_teste.c"

float obter_m2(float a, float b) {
	// m2 = max(f"(x)), a <= x <= b, f"(x) = 2e^x + xe^x = e^x(2 + x)
	float m2;
	for (int x = a; x <= b; x++) {
		float temp = pow(2.71828, x) * (2 + x);
		if (x == a || temp > m2) m2 = temp;
	}
	return m2;
}


float obter_estimativa_erro(float a, float b, float h) {
	float m2 = obter_m2(a, b), estimativa_erro = (h * h * (b - a) * m2) / 12;
	return (estimativa_erro > 0) ? estimativa_erro : estimativa_erro * -1 ;
}

float integrar_trapezio(float a, float b, float n) {
    /* Esta função integra numericamente uma função f, definida em [a,b], com n
     * subintervalos de tamanho h, utilizando o Método do Trapézio Repetido */
     float h = (b - a) / n, somatorio = 0;
     for (int i = 1; i < n; i++) somatorio += f(a + i * h);
     return (h / 2) * (f(a) + 2 * (somatorio + f(b)));
}

// Nos intervalos [0, 2], a resposta da integral da função de teste é e^2 + 1 = 8.3890461584
