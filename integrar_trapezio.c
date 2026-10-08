#include "funcao_de_teste.c"


float somatorio(float fxi, float fxn) {
    /* Esta função realiza o somatório presente na fórmula do Método do Trapézio Repetido.
    
    Ela realiza o somatório de f(xi) e f(xn), em que 1 <= i < n */
    
    
}


float integrar_trapezio(float a, float b, float n) {
    /* Esta função integra numericamente uma função f, definida em [a,b], com n
     * subintervalos de tamanho h, utilizando o Método do Trapézio Repetido */
     
     float integral;
     float h = (b - a) / n;
     float fxn = a + n * h;
     
     
     return integral;
}
