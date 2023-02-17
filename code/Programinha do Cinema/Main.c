#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "Functions.h"
#include "PrincipalFunctions.h"

//------------------------------------------------------------------------------------------------------------------//

int main()
{		
	FILE * filmes ; 
	    filmes = fopen("Filmes.txt","a"); //caso não exista cria o arquivo
		fclose(filmes); 

	FILE * sessoes ; 
		sessoes = fopen("Sessoes.txt","a");
		fclose(sessoes);
	
	FILE * precos ;
		precos = fopen("Precos.txt","a");
		fclose(precos);

	FILE * promocao;
		promocao = fopen("Promocao.txt","a");
		fclose(promocao);

Inicio:

	system("cls");
	for (;;)
	{
		int pivo = 0;

		printf
		(" Bem-vindo ao programinha: Cineminha do Edigar :) \n Selecione uma opcao digitando o valor x -> [x]: \n"
			"  [1] Filmes em Cartaz\n"
			"  [2] Dias e horarios das Sessoes\n"
			"  [3] Produtos e Precos \n"
			"  [4] Promocao da Semana \n  .\n  .\n  .\n  .\n"
			"  [9] Sair\n"
		);
		scanf(" %d", &pivo);

		for (;;)
		{
			system("cls");
			switch (pivo)
			{
			case 1:
				filmesPrincipal();
				break;
			case 2:
				sessoesPrincipal();
				break;
			case 3:
				precosPrincipal();
				break;
			case 4:
				promocaoPrincipal();
				break;
			case 9:
				return 0;
			}
			goto Inicio;
		}
	}

	return 0;
}