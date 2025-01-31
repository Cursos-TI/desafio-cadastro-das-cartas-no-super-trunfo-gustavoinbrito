#include <stdio.h>

// Estrutura para representar um país
typedef struct {
    char nome[50];
    int populacao;
    int area;
    double pib;
    double idh;
} Pais;

// Função para criar um país
Pais criarPais(char *nome, int populacao, int area, double pib, double idh) {
    Pais pais;
    intscpry(pais.nome, nome);
    pais.populacao = populacao;
    pais.area = area;
    pais.pib = pib;
    pais.idh = idh;
    return pais;
}

// Função para imprimir os atributos de um país
void imprimirPais(Pais pais) {
    printf("Nome: %s\n", pais.nome);
    printf("População: %d\n", pais.populacao);
    printf("Área: %d km²\n", pais.area);
    printf("PIB: R$ %.2f trilhões\n", pais.pib);
    printf("IDH: %.2f\n", pais.idh);
}

// Função para comparar dois países com base em um atributo
int compararPaises(Pais pais1, Pais pais2, char *atributo) {
    if (strcmp(atributo, "populacao") == 0) {
        return pais1.populacao - pais2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        return pais1.area - pais2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        return pais1.pib - pais2.pib;
    } else if (strcmp(atributo, "idh") == 0) {
        return pais1.idh - pais2.idh;
    }
    return 0;
}

int main() {
    // Criar países
    Pais brasil = criarPais("Brasil", 212000000, 8515000, 2.06, 0.759);
    Pais estadosUnidos = criarPais("Estados Unidos", 331000000, 9834000, 22.67, 0.924);
    Pais china = criarPais("China", 1439000000, 9597000, 16.14, 0.761);

    // Imprimir países
    printf("País 1:\n");
    imprimirPais(brasil);
    printf("\nPaís 2:\n");
    imprimirPais(estadosUnidos);
    printf("\nPaís 3:\n");
    imprimirPais(china);

    // Comparar países
    char atributo[20];
    printf("\nEscolha um atributo para comparar (populacao, area, pib, idh): ");
    scanf("%s", atributo);

    int resultado = compararPaises(brasil, estadosUnidos, atributo);
    if (resultado > 0) {
        printf("\nO Brasil tem o maior valor no atributo %s.\n", atributo);
    } else if (resultado < 0) {
        printf("\nOs Estados Unidos têm o maior valor no atributo %s.\n", atributo);
    } else {
        printf("\nOs dois países têm o mesmo valor no atributo %s.\n", atributo);
    }

    return 0;
}