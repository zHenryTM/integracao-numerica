#include <stdio.h>
#include "Funcoes_Auxiliares/obter_m2.c"
#include "Funcoes_Auxiliares/obter_erro_estimado.c"
#include "Funcoes_Auxiliares/calcular_probabilidade_normal.c"

double integrar_trapezio(double (*f)(double), double a, double b, int n) {
    /* Esta função integra numericamente uma função f, definida em [a,b], com n
     * subintervalos de tamanho h, utilizando o Método do Trapézio Repetido.

     * No intervalo [0,2], a resposta da integral da função de teste é: e^2 + 1 = 8.3890461584
     * Validada analiticamente através do método de integração por partes. */
     

      double h = (b - a) / n;
      double somatorio = 0;
     
      for (int i = 1; i < n; i++) 
         somatorio += f(a + i * h);
        
      // apagar depois:
         double m2 = obter_m2(a, b);
         double erro_estimado = obter_erro_estimado(a, b, h, 2, m2);
        
         printf("Estimativa de erro: %f\n", erro_estimado);
         printf("M2: %f\n", m2);

      calcular_probabilidade_normal(1);

      return (h / 2) * ( f(a) + 2 * somatorio + f(b) );
}
