#include <math.h>

double obter_m4(double a, double b) {
    /* Esta funcao recebe a e b, que determinam o intervalo [a,b], calcula e retorna M4,
     * um parametro usado para concluir a estimativa de erro do calculo de uma integral pelo
     * metodo do simpson repetido.

     * m4 = max(f^(4)(x)), a <= x <= b.
     * f(x) = x.e^x, logo f^(4)(x) = 4e^x + e^x.

	Derivamos 4e^x + e^x e igualamos a 0:
		f^(5)(x) = 5e^x + xe^x
		(5 + x)e^x = 0
		5 + x = 0
		x = -5
		
	Nesse caso o máximo não está dentro do intervalo dado [0, 2]
	Logo o máximo vai ser um dos dois valores
	*/
	
	double funcao_em_a = 4.0 * exp(a) + a * exp(a);
	double funcao_em_b = 4.0 * exp(b) + b * exp(b);
	
	return funcao_em_a>funcao_em_b ? funcao_em_a:funcao_em_b;
}
