#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Definição das variáveis
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[50], nomeCidade2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    int atributo1, atributo2;
    float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2, soma1, soma2;
    
    // Nomes dos atributos
    char *nomesAtributos[] = {"", "População", "Área", "PIB", "Densidade Populacional", "PIB per Capita"};

    // Entrada dos dados da Carta 1
    printf("Digite as informações da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    getchar();
    printf("Nome da Cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = 0;
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada dos dados da Carta 2
    printf("\nDigite as informações da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    getchar();
    printf("Nome da Cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo das propriedades
    densidade1 = populacao1 / area1;
    pibPerCapita1 = pib1 / populacao1;
    densidade2 = populacao2 / area2;
    pibPerCapita2 = pib2 / populacao2;

    // Menu para escolher os atributos de comparação
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n");
    scanf("%d", &atributo1);

    do {
        printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n");
        scanf("%d", &atributo2);
    } while (atributo2 == atributo1);

    // Função para pegar os valores dos atributos escolhidos
    float pegarValor(int atributo, int pop, float area, float pib, float densidade, float pibPC) {
        switch (atributo) {
            case 1: return pop;
            case 2: return area;
            case 3: return pib;
            case 4: return densidade;
            case 5: return pibPC;
            default: return 0;
        }
    }

    valor1_carta1 = pegarValor(atributo1, populacao1, area1, pib1, densidade1, pibPerCapita1);
    valor1_carta2 = pegarValor(atributo1, populacao2, area2, pib2, densidade2, pibPerCapita2);
    valor2_carta1 = pegarValor(atributo2, populacao1, area1, pib1, densidade1, pibPerCapita1);
    valor2_carta2 = pegarValor(atributo2, populacao2, area2, pib2, densidade2, pibPerCapita2);

    // Soma dos valores
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    // Exibir resultados
    printf("\nComparação de Cartas:\n");
    printf("%s: %s (%.2f) x %s (%.2f)\n", nomesAtributos[atributo1], nomeCidade1, valor1_carta1, nomeCidade2, valor1_carta2);
    printf("%s: %s (%.2f) x %s (%.2f)\n", nomesAtributos[atributo2], nomeCidade1, valor2_carta1, nomeCidade2, valor2_carta2);
    printf("Soma dos atributos: %s (%.2f) x %s (%.2f)\n", nomeCidade1, soma1, nomeCidade2, soma2);

    if (soma1 > soma2) {
        printf("Resultado: %s venceu!\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("Resultado: %s venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}