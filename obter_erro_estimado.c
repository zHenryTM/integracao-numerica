#include <math.h>

float obter_erro_estimado(float a, float b, float h, int expoente_h, float m) {
	/* Esta função modular calcula e retorna a estimativa de erro do cálculo da 
	 * integral com os métodos do trapézio e simpson repetido. Ela recebe como entrada:
	
	- Os extremos do intervalo [a, b];
	- O comprimento h de cada subintervalo;
	- O expoente ao qual h será elevado;
	- m, que corresponde ao M2, do método do trapézio, e M4, do simpson
	*/
	
	
	float erro_estimado;
	int divisor = (expoente_h == 2) ? 12 : 180 ;
	
	h = pow(h, expoente_h);
	
	erro_estimado = ( (b - a) * h / 12 ) * m;
	
	if (erro_estimado < 0)
	    erro_estimado *= -1;
	    
	return erro_estimado;
}
