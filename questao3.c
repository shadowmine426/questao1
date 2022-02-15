#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Marcos Luiz Landim Junqueira
15/02/2022   
*/
//tamanho do vetor de char para receber do usuario
const int tamanho=100;

//funcoes
int numAnagrama (char anag[]);
int fatorial (int n);
int vletrasIguais (char anag[]);
int pletrasIguais (char anag[]);


int main(int argc, char *argv[])
{

    char anagrama[tamanho];

    printf ("Este programa é um programa que ira calcular o anagrama de uma palavra\n\n");
    printf ("Informe uma palavra de no maximo 5 caracteres: >");
    gets(anagrama);

    //tratar condição caso o usuário digite uma palavra maior que 5
    if ( strlen(anagrama) > 5 ){

        system("cls");
        system("color 81");
        printf("\n\n\n\n\n\n\n\n\n\n\nERRO!!! Este programa so funciona com palavras\n\nque tenhao 5 caracteres apenas!!\n\n");
        system("Pause");

    return 1;
    }

    //exibir numero de anagramas possiveis
     printf ("Numero de anagramas possiveis: %d \n\n",numAnagrama(anagrama));

    system("PAUSE");
    return 0;
}

//funcao que retorna o numero de anagrama possiveis de se montar
int numAnagrama (char anag[]){

    int c=0;

    //verificar letras iguais
    if(vletrasIguais(anag)== 0){
       c=strlen(anag);
       c=fatorial(c);
    }
    else {

    pletrasIguais(anag);

    }

    return c;


}

//Funcao que retorna o fatorial
int fatorial (int n)
{
    int result;

    if(n < 0 ) return -1; //erro
    if(n == 0 || n == 1) return 1;
    result = fatorial(n-1) * n;

    return result;
}

//funcao para verificar se exixte letrars iguais na palavra
//caso não tenha a funcao retorna numero 0;
int vletrasIguais (char anag[]){

    int ret=0;

    for (int i = 0; i < strlen(anag); i++){
         for (int j = 0; j < strlen(anag); j++){
             if(anag==anag[j]){
                ret++;
             }
         }
         if(ret==1)
            ret=0;
    }

    return ret;

}

int pletrasIguais (char anag[]){
    int i, j, *v, tam, fat, denominador=1;
    char *palavra;

    tam=strlen(anag);
    palavra=(char*)malloc(sizeof(char)*tam);
    strcpy(palavra,anag);

    v=(int*)malloc(sizeof(int)*tam);

    for(i=0;i<tam;i++)
        v[i]=1;

    for(i=0; i<tam; i++){
        if(palavra[i]!='$')
            for(j=0; j<tam; j++){
                if ((palavra[i]==palavra[j])&&(i!=j)){
                    v[i]++;
                    palavra[j]='$';
                }
            }
    }
    for(i=0;i<tam;i++){
        fat=fatorial(v[i]);
        denominador=denominador*fat;
    }

    return denominador;
  