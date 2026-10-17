#include "Funções Auxiliares/obter_m4.c"
#include "Funções Auxiliares/funcao_de_teste.c"
#include "Funções Auxiliares/obter_erro_estimado.c"
#include<stdio.h>

/* Esta funcaoo integra numericamente uma funcao f, definida em [a,b], com n
 * subintervalos de tamanho h, utilizando o metodo do Simpson Repetido.

 * No intervalo [0,2], a resposta da integral da funcao de teste e: e^2 + 1 = 8.3890461584
 * Validada analiticamente atraves do metodo de integracao por partes. */


typedef double (*Funcao)(double); //declara um tipo funcao que recebe um double como parametro

double integrar_simpson(Funcao f, double a, double b, int n) {
	
	double Is; // Is = o valor da integral calculada com o metodo do 1/3 de simpson
	
	//verifica se o valor de n e impar, se for retorna -1
	if ((n%2)!= 0){ 
		
		printf("Para integrar pelo metodo 1/3 de simpson repetido, n deve ser par!\n");
		
		return -1.0;
		
	} else{ //se n for par
		
		double h = (b - a) / n; //calcula o h (largura constante dos subintervalos)
		double soma_impar = 0.0; //soma quando i for impar
		double soma_par = 0.0; //soma quando i for par
		double x = 0.0; //incia x com 0
		
		int i = 0; //i faz a iteração do loop
		
		for(i = 0; i<n; i++){ //loop inicia com 0 e itera ate i ser igual a n - 1
			
			x = a + i * h; // x recebe o valor de a + i multiplicado a largura dos suintervalos 
			
			if((i%2) == 0){
				//se i for par soma o valor anterior de soma_par ao resultado da funcao em x
				soma_par = soma_par + f(x); 
				
			} else{
				//se i for impar soma o valor anterior de soma_par ao resultado da funcao em x
				soma_impar = soma_impar + f(x);
				
			}
		}
		
		Is = h / 3.0 * (f(a) + 4.0 * soma_impar + 2.0 * soma_par + f(b)); // calcula o Is
	

	}

    
    return Is;
}
