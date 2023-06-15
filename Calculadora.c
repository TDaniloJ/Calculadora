#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <conio.h>
#define MAX 50

int menu();
int escolhas(int opcao);
void decimalBinario();
int binarioDecimal();
int binarioHexadecimal();
int hexadecimalBinario();
int hexadecimalDecimal();
int decimalHexaDecimal();

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  system("title Calculadora de Conversão");

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
    binarioHexadecimal();
    break;
  case 4:
    hexadecimalBinario();
    break;
  case 5:
    hexadecimalDecimal();
    break;
  case 6:
    decimalHexaDecimal();
    break;
 
  default:
    printf("Opção escolha esta invalida, Tente novamente!");
    break;
  }
}

void decimalBinario() {
  int decimal;
  int binario[MAX];
  int indice = 0;
  char op;

 do {
    
  printf("Digite um número decimal: ");
  scanf("%d", &decimal);

  if (decimal == 0) {
    printf("0");
    return;
  }

  while (decimal > 0) {
    binario[indice] = decimal % 2;
    decimal /= 2;
    indice++;
  }

  for (int i = indice - 1; i >= 0; i--) {
    printf("%d", binario[i]);
  }

  system("pause");
  system("cls");

  printf("Deseja Fazer um novo Calculo? (s/n): ");
  scanf("%c", &op);
  //fflush(stdin);

  system("pause");

 }while (toupper(op) == 'S');
}

int binarioDecimal() {
    long long binario;
    int decimal = 0, expoente = 0;

    printf("Digite um número binário: ");
    scanf("%lld", &binario);

    int decimal = binarioParaDecimal(binario);

    printf("O número em decimal é: %d\n", decimal);

       

    while (binario != 0) {
        int digito = binario % 10;
        decimal += digito << expoente;
        expoente++;
        binario /= 10;
    }
}

int binarioHexadecimal(){
    char binario[20];
    int decimal = 0, expoente = 0, i;
    int tamanho = strlen(binario);
    char hexadecimal[20];


    printf("Digite um número binário: ");
    scanf("%s", binario);

    char* hexadecimal = binarioParaHexadecimal(binario);

    printf("O número em hexadecimal é: %s\n", hexadecimal);


    // Converte o número binário para decimal
    for (i = tamanho - 1; i >= 0; i--) {
        decimal += (binario[i] - '0') << expoente;
        expoente++;
    }

    // Converte o número decimal para hexadecimal
    sprintf(hexadecimal, "%X", decimal);
}

int hexadecimalBinario(){
    char hexadecimal[20];
    int tamanho = strlen(hexadecimal);
    char binario[20];
    int indice = 0;


    printf("Digite um número hexadecimal: ");
    scanf("%s", hexadecimal);

    char* binario = hexadecimalParaBinario(hexadecimal);

    if (binario != NULL) {
        printf("O número em binário é: %s\n", binario);
    }

    // Converte cada dígito hexadecimal para binário
    for (int i = 0; i < tamanho; i++) {
        switch (hexadecimal[i]) {
            case '0':
                strcat(binario, "0000");
                break;
            case '1':
                strcat(binario, "0001");
                break;
            case '2':
                strcat(binario, "0010");
                break;
            case '3':
                strcat(binario, "0011");
                break;
            case '4':
                strcat(binario, "0100");
                break;
            case '5':
                strcat(binario, "0101");
                break;
            case '6':
                strcat(binario, "0110");
                break;
            case '7':
                strcat(binario, "0111");
                break;
            case '8':
                strcat(binario, "1000");
                break;
            case '9':
                strcat(binario, "1001");
                break;
            case 'A':
            case 'a':
                strcat(binario, "1010");
                break;
            case 'B':
            case 'b':
                strcat(binario, "1011");
                break;
            case 'C':
            case 'c':
                strcat(binario, "1100");
                break;
            case 'D':
            case 'd':
                strcat(binario, "1101");
                break;
            case 'E':
            case 'e':
                strcat(binario, "1110");
                break;
            case 'F':
            case 'f':
                strcat(binario, "1111");
                break;
            default:
                printf("Caractere hexadecimal inválido: %c\n", hexadecimal[i]);
                return NULL;
        }
    }
}

int hexadecimalDecimal(){
    char hexadecimal[20];
    int tamanho = strlen(hexadecimal);
    int decimal = 0;
    int expoente = 1;

    printf("Digite um número hexadecimal: ");
    scanf("%s", hexadecimal);

    int decimal = hexadecimalParaDecimal(hexadecimal);

    if (decimal != -1) {
        printf("O número em decimal é: %d\n", decimal);
    }


    // Converte cada dígito hexadecimal para decimal
    for (int i = tamanho - 1; i >= 0; i--) {
        int valor;
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            valor = hexadecimal[i] - '0';
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            valor = hexadecimal[i] - 'A' + 10;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            valor = hexadecimal[i] - 'a' + 10;
        } else {
            printf("Caractere hexadecimal inválido: %c\n", hexadecimal[i]);
            return -1;
        }

        decimal += valor * expoente;
        expoente *= 16;
    }
}

int decimalHexaDecimal(){
    int decimal;
    char hexadecimal[20];
    int indice = 0;

    printf("Digite um número decimal: ");
    scanf("%d", &decimal);

    while (decimal != 0) {
        int resto = decimal % 16;

        if (resto < 10)
            hexadecimal[indice] = resto + '0';
        else
            hexadecimal[indice] = resto - 10 + 'A';

        decimal /= 16;
        indice++;
    }

    printf("O número em hexadecimal é: ");

    for (int i = indice - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }

    printf("\n");
}