#include "funcao_de_teste.c"

loat integrar_trapezio(float a, float b, float n) {
    /* Esta função integra numericamente uma função f, definida em [a,b], com n
     * subintervalos de tamanho h, utilizando o Método do Trapézio Repetido */
     
     float h = (b - a) / n;
     float somatorio = 0;
     
     for (int i = 1; i < n; i++)
        somatorio += f(a + i * h);
        
     somatorio += f(b);
     
     return (h / 2) * (f(a) + 2 * somatorio);
}


// Falta implementar a função para calcular o erro.
