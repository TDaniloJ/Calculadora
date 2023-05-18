#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#define MAX 50

int menu();
int escolhas(int opcao);
int decimalBinario();
int binarioDecimal();

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  menu();

}

int menu() {

  int op;

  do {

    printf("#########################################\n");
    printf("#  Calculadora de decimal para binario  #\n");
    printf("#########################################\n\n");

    printf("Aviso:Arquivo ainda esta em fase de teste.\n\n");

    printf("1 - Conversão de Decimal para Binario\n");
    printf("2 - Conversão de Binario para de Decimal\n");
    printf("3 - Conversão de Binario para Hexadecimal\n");
    printf("4 - Conversão de Hexadecimal para Binario\n");
    printf("5 - Conversão de Hexadecimal para Decimal\n");
    printf("6 - Conversão de Decimal para Hexadecimal\n");
    printf("0 - Sair\n\n");

    printf("Escolha uma das opções: ");
    scanf("%d", &op);

	system("cls");
	
    escolhas(op);
    
    system("cls");
	
  } while (op != 0);
  
  

}

int escolhas(int opcao) {
  switch (opcao) {
  case 1:
    decimalBinario();
    break;
  case 2:
    binarioDecimal();
    break;
  case 3:
    //binarioHexadecimal();
    break;
  case 4:
    //hexadecimalBinario();
    break;
  case 5:
    //hexadecimalDecimal();
    break;
  case 6:
    //decimalHexadecimal();
    break;
 
  default:
    printf("Opção escolha esta invalida, Tente novamente!");
    break;
  }
}

int decimalBinario() {
	int num, decimal;
	int vet_bin[MAX];
	int i = 0, j;
	int aux_num = num;
	char sair = 's';

	do{
	
	    printf("##########################\n");
	    printf("#  Decimal para Binario  #\n");
	    printf("##########################\n\n");
		
		printf("Informe um numero em decimal: ");
		scanf("%d", &num);
		
		
		while(num > 0) {
			vet_bin[i] = num % 2;
			i++;
			num = num / 2;
		}
		
		printf("\nO Valor de Decimal: %d", aux_num);
		
		printf("\nO valor de Binario: ");
	
		for(j = i - 1; j >= 0; j--) {
			printf("%d", vet_bin[j]);
		}
		printf("\n");
		
		printf("\nDeseja Fazer novamente? (s/n): ");
		scanf("%c", &sair);
		
		
	
	}while(sair == 's');
	
	getche();
}

int binarioDecimal() {
	int decimal = 0, i = 0, resto, binario;
	
	//printf("Informe um numero em binario: ");
	//scanf("%d" &num);
	
	while(binario != 0) {
	    resto = binario % 10;
	    binario /= 10;
	    decimal += resto * pow(2, i);
	    ++i;
	}
	
	printf("O Valor de %d em decimal é %d", decimal);
	
	printf("\nPara Volta para o menu aperte (Enter).");
	
	getche();
	
	return 0;
}
