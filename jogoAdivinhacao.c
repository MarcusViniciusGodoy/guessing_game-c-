#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	printf("*******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
	printf("*******************************************\n");

	int segundos = time(0);
	srand(segundos);
	
	int n_grande = rand();
	
	int numero_secreto = n_grande % 100;
	int palpite;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;
	
	int nivel;
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil (2) Médio (3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);
	
	int numero_tentativas;
	
	switch(nivel){
		case 1:
			numero_tentativas = 20;
			break;
		case 2:
			numero_tentativas = 15;
			break;
		default:
			numero_tentativas = 6;
			break;
	}
	
	for(int i=1; i<=numero_tentativas; i++){
		printf("\n");
		printf("Tentativa %d\n", tentativas);
		printf("Qual é o seu palpite? ");
		scanf("%d", &palpite);
		printf("Seu palpite foi %d\n", palpite);
		
		if(palpite < 0){
			printf("Você não pode digitar números negativos!\n");
			continue;
		}
	
	
		acertou = (palpite == numero_secreto);
		int menor = (palpite < numero_secreto);
	
		if(acertou){
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
	
	if (acertou){
		printf("Você ganhou!\n");
		printf("Você acertou em %d tentativas!\n", tentativas);
		printf("Total de pontos: %.1f\n", pontos);
	}else{
		printf("Você perdeu! Tente novamente.\n");
	}
	
	
	
}
