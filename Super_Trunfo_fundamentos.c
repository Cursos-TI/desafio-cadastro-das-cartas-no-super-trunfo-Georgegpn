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
unsigned long int populacao1, populacao2;
double area1, area2;
double pib1, pib2;
int pontosTuristicos1, pontosTuristicos2;
double densidade1, densidade2, pibPerCapita1, pibPerCapita2;
double superPoder1, superPoder2;

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
scanf("%lu", &populacao1);
printf("Área (em km²): ");
scanf("%lf", &area1);
printf("PIB (em reais): ");
scanf("%lf", &pib1);
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
scanf("%lu", &populacao2);
printf("Área (em km²): ");
scanf("%lf", &area2);
printf("PIB (em reais): ");
scanf("%lf", &pib2);
printf("Número de Pontos Turísticos: ");
scanf("%d", &pontosTuristicos2);

// Cálculo das propriedades
densidade1 = populacao1 / area1;
pibPerCapita1 = pib1 / populacao1;
superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0 / densidade1);

densidade2 = populacao2 / area2;
pibPerCapita2 = pib2 / populacao2;
superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0 / densidade2);

// Comparação das cartas
printf("\nComparação de Cartas:\n");
printf("População: Carta %d venceu (1)\n", populacao1 > populacao2 ? 1 : 2);
printf("Área: Carta %d venceu (1)\n", area1 > area2 ? 1 : 2);
printf("PIB: Carta %d venceu (1)\n", pib1 > pib2 ? 1 : 2);
printf("Pontos Turísticos: Carta %d venceu (1)\n", pontosTuristicos1 > pontosTuristicos2 ? 1 : 2);
printf("Densidade Populacional: Carta %d venceu (0)\n", densidade1 < densidade2 ? 1 : 2);
printf("PIB per Capita: Carta %d venceu (1)\n", pibPerCapita1 > pibPerCapita2 ? 1 : 2);
printf("Super Poder: Carta %d venceu (1)\n", superPoder1 > superPoder2 ? 1 : 2);

return 0;
}
