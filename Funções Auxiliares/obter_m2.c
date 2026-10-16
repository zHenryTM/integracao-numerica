float obter_m2(float a, float b) {
    /* Esta função recebe a e b, que determinam o intervalo [a,b], calcula e retorna M2,
     * um parâmetro usado para concluir a estimativa de erro do cálculo de uma integral pelo
     * método do trapézio repetido.

     * m2 = max(f"(x)), a <= x <= b.
     * f(x) = x.e^x, logo f"(x) = e^x(2 + x) */


	float m2;

	for (int x = a; x <= b; x++)
    {
		float temp = pow(2.71828, x) * (2 + x);

		if (x == a || temp > m2)
            m2 = temp;
	}

	return m2;
}
