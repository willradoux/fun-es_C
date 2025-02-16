#include <stdio.h>

int tratamentoDeExececao(){ 
    
    int valor;

    while (scanf("%d", &valor) != 1 || (valor = '.') && (valor = 0)) { 
        printf("Entrada inválida! Digite um número válido: ");
        while (getchar() != '\n');
    }
    return valor;
}

void conversao(){ 

    float F, C, celsius, fahrenheit;
    int escolha, refazerCalculo;

    printf("\n>>> || Conversão de temperatura || <<< \n\n");

    printf("Qual conversão deseja fazer?\n");

    while (refazerCalculo == 1){

        printf("1 - Celsius para Fahrenheit\n");
        printf("2 - Fahrenheit para Celsius\n");

        printf("\n");

        printf("Digite qual opcao deseja realizar: ");
        escolha = tratamentoDeExececao();
        
            if (escolha == 1){
                printf("\nDigite um valor para celsius: ");
                scanf("%f", &celsius);

                F = (celsius * 9/5) + 32;
                printf("\n%.2f°F\n\n", F);
            }else{
            printf("\nDigite um valor para fahrenheit: ");
            scanf("%f", &fahrenheit);

            C = (fahrenheit - 32) / 1.8;
            printf("\n%.2f C°\n\n", C);
        
        printf("Deseja refazer a conversao? 1 para refazer, 2 para voltar ao menu: ");
        while ((refazerCalculo = tratamentoDeExececao()) > 2){
            printf("Digite uma opcao válida: ");
        }
        
        printf("\n\n");
        }
    }
}

void calculoMedia(){ 

    int sequencia[5], maior = 0, menor = 0, soma = 0, i, j, k, l, m, refazerCalculo = 1;
    float media; 

    printf("\n>>> || Calculo de media e maior numero || <<<\n\n");

    while (refazerCalculo == 1){

        for (i = 0; i < 5; i++){
            printf("Digite 5 numeros INTEIROS em sequencia: ");
            sequencia[i] = tratamentoDeExececao();
        }

        printf("\n");
        for (j = 0; j < 5; j++){   
            printf("%d ", sequencia[j]);
        }

        printf("\n");

        for (k = 0; k < 5; k++){ 
            if (k==0){
                maior = sequencia[k]; 
            }
            if (sequencia[k]>maior){
                maior = sequencia[k];
            }
        }

        for (m = 0; m < 5; m++){ 
            if (m == 0){
                menor = sequencia[m];
            }
            if (sequencia[m] < menor){
                menor = sequencia[m];
            }
        }
        
        printf("\n");
        printf("O maior numero da sequencia: %d", maior);
        printf("\nO menor numero da sequencia: %d", menor);
        printf("\n");

        for(l = 0; l < 5; l++){
            soma = soma + sequencia[l];
        }

        media = soma / 5;

        printf("A media entre os numeros: %.2f", media);
        printf("\n\n");
        printf("Deseja refazer o calculo? 1 para refazer, 2 para voltar ao menu: ");

        while ((refazerCalculo = tratamentoDeExececao()) > 2){
            printf("Digite uma opcao válida: ");
        }

        printf("\n\n");
    }
}

void tabelaMultiplicacao(){ 

    int refazerCalculo = 1, i, j, numeroTabela;

    printf("\n>>> || Tabela de multiplicação || <<<\n\n");

    while (refazerCalculo == 1){

        printf("Digite o tamanho da tabela: ");
        numeroTabela = tratamentoDeExececao();

        if(numeroTabela <= 0){
            printf("Erro!, o tamanho da tabela deve ser maior que ZERO: ");
            continue;
        }

        printf("   |");
        for (i = 1; i <= numeroTabela; i++) {
            printf("%4d", i);
        }

        printf("\n----");
        for (i = 1; i <= numeroTabela; i++) {
            printf("----");
        }

        printf("\n");
        for (i = 1; i <= numeroTabela; i++) {
            printf("%2d |", i);
            for (j = 1; j <= numeroTabela; j++) {
                printf("%4d", i * j);
            }
            printf("\n");
        }
        
        printf("\nDeseja refazer o calculo? 1 para refazer, 2 para voltar ao menu: ");

        while ((refazerCalculo = tratamentoDeExececao()) > 2){
            printf("Digite uma opcao válida: ");
        }

        printf("\n\n");
    }
}

int main() {
    int opcao = 0;

    while (opcao != 4) {
        
        printf(">>>> || Menu de opcoes || <<<< \n\n");

        printf("1 - Conversão de Temperatura\n");
        printf("2 - Calculo de Media\n");
        printf("3 - Calculo de multiplicacao\n");
        printf("4 - Sair\n\n");

        printf("\nDigite qual opcao deseja realizar: ");

        while (scanf("%d", &opcao) > 4 || (opcao != 1)){
            printf("Invalido! Escolha uma das opcoes: ");
            while (getchar() != '\n');
        }
    
        switch (opcao) {
            case 1:
                conversao();
                break;
            case 2:
                calculoMedia();
                break;
            case 3:
                tabelaMultiplicacao();
                break;
            case 4:
                printf("\nVoce escolheu sair.\n\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n\n");
                break;
        }
    }
}
