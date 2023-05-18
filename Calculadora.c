#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu();
int escolhas(int opcao);
int decimalBinario();

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

    printf("1 - Conversão de Decimal para Binário\n");
    printf("2 - Conversão de Binário para de Decimal\n");
    printf("3 - Conversão de Binário para Hexadecimal\n");
    printf("4 - Conversão de Hexadecimal para Binário\n");
    printf("5 - Conversão de Hexadecimal para Decimal\n");
    printf("6 - Conversão de Decimal para Hexadecimal\n");
    printf("0 - Sair\n\n");

    printf("Escolha uma das opções: ");
    scanf("%d", op);

    escolhas(op);

  } while (op =! 0);

}

int escolhas(int opcao) {
  switch (opcao) {
  case 1:
    //decimalBinario();
    break;
  case 2:
    //binarioDecimal();
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
