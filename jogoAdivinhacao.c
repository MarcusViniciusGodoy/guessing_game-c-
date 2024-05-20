#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int segundos = time(0);
	srand(segundos);
	
	int n_grande = rand();
	
	int numero_secreto = n_grande % 100;
	int palpite;
	int tentativas = 1;
	double pontos = 1000;
	
	printf("*******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
	printf("*******************************************\n");
	
	while(1){
		printf("\n");
		printf("Tentativa %d\n", tentativas);
		printf("Qual é o seu palpite? ");
		scanf("%d", &palpite);
		printf("Seu palpite foi %d\n", palpite);
		
		if(palpite < 0){
			printf("Você não pode digitar números negativos!\n");
			continue;
		}
	
	
		int acertou = (palpite == numero_secreto);
		int menor = (palpite < numero_secreto);
	
		if(acertou){
			printf("Parabéns! Você acertou.\n");
			break;
		}
		else if(menor){
			printf("Que pena! Você errou.\n");
			printf("Seu palpite e menor que o numero secreto.\n");
		}else{
			printf("Que pena! Você errou.\n");
			printf("Seu palpite e maior que o numero secreto.\n");
		}
		tentativas++;
		
		double pontos_perdidos = abs(palpite - numero_secreto) / (double)2;
		pontos = pontos - pontos_perdidos;
	}
	
	printf("Fim de jogo!\n");
	printf("Você acertou em %d tentativas!\n", tentativas);
	printf("Total de pontos: %.1f\n", pontos);
}
