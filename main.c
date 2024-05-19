#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char modelo[50];
  char marca[50];
  char placa[50];
  int ano;
  char cor[50];
}carros;

main(){
  int tamanho, novotamanho, escolha, x, cont, remover;
  carros *automoveis, *aux;
  system("clear");
  printf("Digite o número iniciais de automóveis: ");
  scanf("%i", &tamanho);
  getchar();
  automoveis = malloc(tamanho*sizeof(carros));
  for(x = 0; x < tamanho; x++){
    printf("\nDigite o modelo do automóvel: ");
    gets(automoveis[x].modelo);
    printf("Digite a marca do automóvel: ");
    gets(automoveis[x].marca);
    printf("Digite a placa do automóvel: ");
    gets(automoveis[x].placa);
    printf("Digite o ano de fabricação: ");
    scanf("%d", &automoveis[x].ano);
    getchar();
    printf("Digite a cor do automóvel: ");
    gets(automoveis[x].cor);
  }
  system("clear");
  do{
    printf("Escolha uma das opções\n[0] - Inserir automóvel\n[1] - Remover automóvel\n[2] - Mostrar automóveis\n[3] - Alterar dados\n[4] - Sair do programa\n");
    scanf("%i", &escolha);
    getchar();
    switch(escolha){
      case 0:
        novotamanho = tamanho + 1;
        automoveis = realloc(automoveis, novotamanho*sizeof(carros));
        system("clear");
        printf("Digite o modelo do automóvel: ");
        gets(automoveis[tamanho].modelo);
        printf("Digite a marca do automóvel: ");
        gets(automoveis[tamanho].marca);
        printf("Digite a placa do automóvel: ");
        gets(automoveis[tamanho].placa);
        printf("Digite o ano de fabricação: ");
        scanf("%d", &automoveis[tamanho].ano);
        getchar();
        printf("Digite a cor do automóvel: ");
        gets(automoveis[tamanho].cor);
        tamanho = novotamanho;
        printf("\n");
      break;
      case 1:
        cont = 0;
        printf("\nDigite a posição absoluta do veículo que deseja deletar: ");
        scanf("%i", &remover);
        getchar();
        if(remover >= tamanho){
          printf("Posição inválida");
          getchar();
          system("clear");
        } else{
          novotamanho = tamanho - 1;
          aux = malloc(novotamanho*sizeof(carros));
          for(x = 0; x < tamanho; x++){
            if(remover != x){
              strcpy(aux[cont].modelo, automoveis[x].modelo);
              strcpy(aux[cont].marca, automoveis[x].marca);
              strcpy(aux[cont].placa, automoveis[x].placa);
              aux[cont].ano = automoveis[x].ano;
              strcpy(aux[cont].cor, automoveis[x].cor);
              cont++;
            }
          }
          free(automoveis);
          automoveis = aux;
          tamanho--;
          system("clear");
        }
      break;
      case 2:
        system("clear");
        printf("//--Automóveis--// \n");
        for(x = 0; x < tamanho; x++){
          if(automoveis[x].ano != 0){
            printf("Posição absoluta: %i\n", x);
            printf("Modelo: %s\nMarca: %s\nPlaca: %s\nAno de fabricação: %i\nCor: %s\n", automoveis[x].modelo, automoveis[x].marca, automoveis[x].placa, automoveis[x].ano, automoveis[x].cor);
            printf("--------\n");
          }
        }
        printf("\n");
      break;
      case 3:
        printf("\nDigite a posição absoluta do veículo que deseja alterar uma informação: ");
        scanf("%i", &remover);
        getchar();
        if(remover >= tamanho){
          printf("\nPosição inválida");
          getchar();
        } else{
          printf("\nEscolha que informação deseja alterar: \n[0] - Modelo\n[1] - Marca\n[2] - Placa\n[3] - Ano de fabricação\n[4] - Cor\n");
          scanf("%i", &x);
          getchar();
          printf("\n");
          switch(x){
            case 0:
              printf("Modelo atual: %s\nNovo modelo: ", automoveis[remover].modelo);
              gets(automoveis[remover].modelo);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 1:
              printf("Marca atual: %s\nNova marca: ", automoveis[remover].marca);
              gets(automoveis[remover].marca);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 2:
              printf("Placa atual: %s\nNova placa: ", automoveis[remover].placa);
              gets(automoveis[remover].placa);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 3:
              printf("Ano de fabricação atual: %i\nNovo ano: ", automoveis[remover].ano);
              scanf("%d", &automoveis[remover].ano);
              getchar();
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 4:
              printf("Cor atual: %s\nNova cor: ", automoveis[remover].cor);
              gets(automoveis[remover].cor);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
          }
        }
        system("clear");
      break;
      case 4:
        printf("\nFinalizando programa\n");
        getchar();
      break;
      default:
        printf("\nEscolha inválida\n\n");
    }
  }while(escolha != 4);
}