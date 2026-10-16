#include <math.h>

double obter_m2(double a, double b) {
    /* Esta função recebe a e b, que determinam o intervalo [a,b], calcula e retorna M2,
     * um parâmetro usado para concluir a estimativa de erro do cálculo de uma integral pelo
     * método do trapézio repetido.

     * m2 = |max(f"(x))|, a <= x <= b.
     * f(x) = x.e^x, logo f"(x) = e^x(2 + x) */


    return exp(b) * (2 + b);  // explicação no comentário abaixo.

    /*
     Preciso retornar o maior valor de f''(x), em módulo, para a <= x <= b

     Como descobrir qual valor será maior? Através dos máximos e mínimos de uma função.

     g(x) = |f''(x)|

     Assim, g'(x) = f'''(x) = e^x(3 + x)



     Achando pontos críticos:

     g'(x) = e^x(3 + x)
     Ponto crítico em x = -3, ou seja, fora do intervalo.

     Isso nos indica que o intervalo será crescente ou decrescente.

     Sendo assim, o maior valor será |f''(a)| ou |f''(b)|, e se conclui que |f''(b)| é maior,
     portanto, sendo o valor de M2
     */



    /* CÓDIGO ANTIGO (ainda pode ser usado como referência):

	double m2;

	for (double x = a; x <= b; x++)
    {
		double temp = exp(x) * (2 + x);  // exp(x) é uma função de <math.h> e equivale a e^x.

		if (x == a || temp > m2)
            m2 = temp;
	}

	return m2;
    */
}
