#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    /* Esta é a função de referência f(x) = x . e^x que será usada
     * no cálculo da integral através dos métodos dos trapézios e de simpson */

    return x * exp(x);  // exp(x) é uma função de <math.h> e equivale a e^x.
}

double obter_m2(double a, double b) {
    /* M2 é o maior valor de |f''(x)| em todo o intervalo [a,b].

     * Para calcular M2, podemos usar o teste da primeira derivada na função f''(x) = e^x(x + 2),
     * para o obter seu número crítico.
     
     * considerando g(x) = f''(x) ==> g'(x) = f'''(x) = e^x(x + 3)
     
     * Achando o ponto crítico:
     * g'(x) = 0
     * e^x(x + 3) = 0
     * Logo, x = -3
     * 
     * Na função de referência, o intervalo é limitado em [0,2].
     * Assim, percebe-se que -3 está fora do intervalo.
     * 
     * Portanto, M2 será um extremo do intervalo. Ou seja, ou será |f''(0)| ou será |f''(2)|
     * 
     * Um algoritmo pode ser implementado facilmente para calcular M2 com essa técnica,
     * mas como o exercício limita o intervalo, podemos fazer analiticamente e concluir que M2 = |f''(2)| */
    
    if (a <= -3 && -3 <= b)
        return fabs(exp(-3) * -1);
    
    double fa = fabs(exp(a) * (a + 2));
    double fb = fabs(exp(b) * (b + 2));     
    
    return (fa > fb) ? fa : fb ;
}

double obter_m4(double a, double b) {
    /* Esta funcao recebe a e b, que determinam o intervalo [a,b], calcula e retorna M4,
     * um parametro usado para concluir a estimativa de erro do calculo de uma integral pelo
     * metodo do simpson repetido.

     * m4 = max(f^(4)(x)), a <= x <= b.
     * f(x) = x.e^x, logo f^(4)(x) = 4e^x + x.e^x = e^x(x + 4).

     * Derivamos 4e^x + e^x e igualamos a 0:
     * f^(5)(x) = 5e^x + xe^x
     * (5 + x)e^x = 0
     * 5 + x = 0
     * x = -5
                
     * Nesse caso o máximo não está dentro do intervalo dado [0, 2]
     * Logo o máximo vai ser um dos dois valores */

    if (a <= -5 && -5 <= b)
        return fabs(exp(-5) * -1);

    double funcao_em_a = fabs(exp(a) * (a + 4));
    double funcao_em_b = fabs(exp(b) * (b + 4));
    
    return (funcao_em_a > funcao_em_b) ? funcao_em_a : funcao_em_b ;
}

double obter_erro_estimado(double a, double b, double h, int expoente_h, double m) {
        /* Esta função modular calcula e retorna a estimativa de erro do cálculo da 
         * integral para os métodos do trapézio e simpson repetido. Ela recebe como entrada:
        
         * - Os extremos do intervalo [a,b];
         * - O comprimento h de cada subintervalo;
         * - O expoente ao qual h será elevado;
         * - m, que corresponde ao M2, do método do trapézio, ou M4, do simpson */

        double erro_estimado;
        int divisor = (expoente_h == 2) ? 12 : 180 ;

        h = pow(h, expoente_h);

        erro_estimado = ( (b - a) * h / divisor ) * m;

        if (erro_estimado < 0)
            erro_estimado *= -1;

        return erro_estimado;
}

double integrar_trapezio(double (*g)(double), double a, double b, int n) {
    /* Esta função integra numericamente uma função f, definida em [a,b], com n
     * subintervalos de tamanho h, utilizando o Método do Trapézio Repetido.

     * No intervalo [0,2], a resposta da integral da função de teste é: e^2 + 1 = 8.3890560989
     * Validada analiticamente através do método de integração por partes. */

    double h = (b - a) / n, somatorio = 0;

    for (int i = 1; i < n; i++) 
        somatorio += g(a + i * h);

    return (h / 2) * ( g(a) + 2 * somatorio + g(b) );
}

double integrar_simpson(double (*g)(double), double a, double b, int n) {
    /* Esta função integra numericamente uma função g, definida em [a,b], com n
     * subintervalos de tamanho h, utilizando o Método do Simpson Repetido.

     * No intervalo [0,2], a resposta da integral da função de teste é: e^2 + 1 = 8.3890560989
     * Validada analiticamente através do método de integração por partes. */


    double Is;  // Valor da integral
    
    if (n % 2 != 0) { 
        printf("Para integrar pelo metodo 1/3 de simpson repetido, n deve ser par!\n");
        exit(1);
    } else {
        double h = (b - a) / n, soma_par = 0.0, soma_impar = 0.0, x;

        for (int i = 1; i < n; i++) {
            x = a + i * h;
            
            if (i % 2 == 0)
                soma_par = soma_par + g(x); 
            else
                soma_impar = soma_impar + g(x);
            
        }

        Is = h / 3.0 * (g(a) + 4.0 * soma_impar + 2.0 * soma_par + g(b));
    }

    return Is;
}

double dpm(double z) {
    /* Esta função auxilia no cálculo da integral da função densidade de probabilidade normal,
     * sendo ela f(z) = 1 / sqrt(2 * PI) * e^(-0.5 * z^2) 
     *
     * ao calcular a integral, como 1 / sqrt(2 * PI) é uma constante, podemos tirá-la para fora da integral,
     * restando e^(-0.5 * z^2)
     * 
     * e^(-0.5 * z^2) não tem primitiva conhecida, então é necessário aplicá-lo nos métodos do trapézio ou
     * do simpson repetidos.
     * 
     * Esta função facilita o calculo, retornando f(z) = e^(-0.5 * z^2). */

    return exp(-0.5 * z * z);
}

double calcular_probabilidade_normal(int opcao) {
    /* Esta função calcula a probablidade normal, definido pela integral definida de -1 a 1,96 de f(z) = 1 / sqrt(2 * PI) * e^(-0.5 * z^2).
     * Como 1 / sqrt(2 * PI) é uma constante, podemos separá-lo do restante da integral e multiplicar ambos no final. 
     * 
     * Assim, quebraremos a função em duas partes, A e B, sendo A a parte constante da função e B, o integrando. 
     *
     * O integrando não possui função primitiva conhecida, então precisaremos dos métodos do trápezio ou do simpson para calcular.
     * Desse modo, o parâmetro opcao serve para decidir qual método será usado nesse processo, sendo:
     
     * opcao = 1, método do trapézio
     * opcao = 2, método do simpson */

    double A, B;

    A = 1 / sqrt(2 * M_PI);

    switch (opcao) {
        case 1:
            B = integrar_trapezio(dpm, -1, 1.96, 100);
            break;
        case 2:
            B = integrar_simpson(dpm, -1, 1.96, 100);
            break;
        default:
            printf("Opcao invalida. Por favor, escolha 1 para usar o método do trapézio ou 2, para simpson.\n");
            exit(1);
    }

    return A * B;
}

double obter_erro_real_relativo(double Iaproximado) {
    /* Esta função calcula o erro real relativo percentual da integral da função de referência f(x) = x.e^x no intervalo [0,2].
     * 
     * O cálculo é o seguinte:
     * 
     * E = |(Iexato - Iaproximado) / Iexato| * 100 */

    double Iexato = exp(2) + 1;
    return fabs((Iexato - Iaproximado) / Iexato) * 100;
}

int main() {
    double resultado_trapezio, resultado_simpson, erro_estimado_trapezio, erro_estimado_simpson, m2, m4, Iexato = exp(2) + 1, a = 0, b = 2;
    int n = 100;

    printf("Metodo do Trapezio:\n\n");

    resultado_trapezio = integrar_trapezio(f, a, b, n);
    m2 = obter_m2(a, b);
    erro_estimado_trapezio = obter_erro_estimado(a, b, (b - a) / n, 2, m2);

    printf("Resultado da integral: %.10f\n", resultado_trapezio);
    printf("Erro estimado absoluto(Limite Teorico): %.10f\n", erro_estimado_trapezio);
    printf("Erro estimado relativo(Limite Teorico): %.10f\n", erro_estimado_trapezio / Iexato * 100);
    printf("M2: %.10f\n", m2);
    printf("Probabilidade normal (Trapezio): %.10f\n", calcular_probabilidade_normal(1));
    printf("Probabilidade normal de acordo com a literatura: 0.816223\n");
    printf("Diferença da probabildade normal: %.10f\n", fabs(calcular_probabilidade_normal(1) - 0.816223));
    printf("Erro real relativo percentual: %.10f%%\n", obter_erro_real_relativo(resultado_trapezio));

    printf("\n\n");

    printf("Metodo do Simpson:\n\n");

    resultado_simpson = integrar_simpson(f, a, b, n);
    m4 = obter_m4(a, b);
    erro_estimado_simpson = obter_erro_estimado(a, b, (b - a) / n, 4, m4);

    printf("Resultado da integral: %.10f\n", resultado_simpson);
    printf("Erro estimado absoluto (Limite Teorico): %.10f\n", erro_estimado_simpson);
    printf("Erro estimado relativo(Limite Teorico): %.10f\n", erro_estimado_simpson / Iexato * 100);
    printf("M4: %.10f\n", m4);
    printf("Probabilidade normal (Simpson): %.10f\n", calcular_probabilidade_normal(2));
    printf("Probabilidade normal de acordo com a literatura: 0.816223\n");
    printf("Diferença da probabildade normal: %.10f\n", fabs(calcular_probabilidade_normal(2) - 0.816223));
    printf("Erro real relativo percentual: %.10f%%\n", obter_erro_real_relativo(resultado_simpson));

    return 0;
}