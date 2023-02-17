#ifndef MAIN_PRINCIPALFUNCTIONS_H_
#define MAIN_PRINCIPALFUNCTIONS_H_
#include "Functions.h"

void filmesPrincipal()
{
	for(;;)
	{
		FILE* filmes;

		system("cls");

		int pivo_Filmes = 0;
		printf
		(" Voce esta na aba: Filmes em Cartaz...\n Selecione uma opcao digitando o valor x -> [x]: \n"
			"  [1] Listar todos os filmes em cartaz\n"
			"  [2] Adicionar filme\n"
			"  [3] Remover filme \n"
			"  [4] Atualizar nome do filme \n"
			"  [5] Voltar\n"
		);

		scanf(" %d", &pivo_Filmes);
		if (pivo_Filmes == 5)
			break;

		char texto[40];
		char i;
		int escolha;
		switch (pivo_Filmes)
		{
		case 1:
			geralConteudoArquivo("Filmes.txt", 1); //1 = "printEnumerado"
			break;

		case 2:
			filmes = fopen("Filmes.txt", "a");

			printf("Escreva o nome do filme (sem espacos, usando '_' ou '-'): ");
			scanf("%s", &texto);
			fprintf(filmes, "%s\n", texto);

			fclose(filmes);
			break;

		case 3:
			system("cls");
			printf(
				"Como voce prefere localizar o filme a ser removido?\n"
				"[2] Digitando o valor x -> [x]..\n"
				"[3] Digitando o nome exato.\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Filmes.txt", escolha);
			break;

		case 4:
			system("cls");
			printf(
				"Como voce prefere localizar o filme a ser atualizado?\n"
				"[4] Digitando o  valor x -> [x]..\n"
				"[5] Digitando o nome exato.\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Filmes.txt", escolha);
			break;
		}

	}
}

void sessoesPrincipal()
{
  for(;;)
	{
	  FILE* sessoes;
    	system("cls");
    
	  int pivo_Sessoes = 0;
	  printf
	  (" Voce esta na aba: Dias e horarios das sessoes...\n Selecione uma opcao digitando o valor x -> [x]: \n"
		  "  [1] Listar todos dias e suas sessoes \n"
		  "  [2] Adicionar sessoes\n"
		  "  [3] Remover sessoes \n"
		  "  [4] Atualizar sessoes \n"
		  "  [5] Voltar\n"
	  );

    scanf(" %d", &pivo_Sessoes);
		if (pivo_Sessoes == 5)
			break;

		char texto[40];
		char i;
		int escolha;
		switch (pivo_Sessoes)
		{
		case 1:
			geralConteudoArquivo("Sessoes.txt", 1); //1 = "printEnumerado"
			break;

		case 2:
			 sessoes = fopen("Sessoes.txt", "a");

			printf("Escreva os horarios das sessoes (sem espacos, usando '_' ou '-', ex: 16hrs-19hrs-22hrs): ");
			scanf("%s", &texto);
			fprintf( sessoes, "%s\n", texto);

			fclose(sessoes);
			break;

		case 3:
			system("cls");
			printf(
				"Como voce prefere localizar o dia e as sessoes que serão removidas?\n"
				"[2] Digirando o valor x -> x - [dia da semana]\n"
				"[3] Digitando o nome exato do dia .\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Sessoes.txt", escolha);
			break;

		case 4:
			system("cls");
			printf(
				"Como voce prefere localizar o dia e as sessoes que serão atualizadas?\n"
				"[4] Digirando o valor x -> x - [dia da semana]\n"
				"[5] Digitando o nome exato do dia (ex: Domingo).\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Sessoes.txt", escolha);
			break;
		}
   }
}

void precosPrincipal()
{
  for(;;)
	{
	  FILE* precos;
	  system("cls");

	  int pivo_Precos = 0;
	  printf
	  (" Voce esta na aba Produtos e Precos...\n Selecione uma opcao digitando o valor x -> [x]: \n"
		  "  [1] Exibir todos os produtos do cinema e seus precos\n"
		  "  [2] Adicionar algum produto e seu preco\n"
		  "  [3] Remover algum produto \n"
		  "  [4] Atualizar algum produto e seu preco \n"
		  "  [5] Voltar\n"
	  );

    scanf(" %d", &pivo_Precos);
		if (pivo_Precos == 5)
			break;

		char texto[40];
		char i;
		int escolha;
		switch (pivo_Precos)
		{
		case 1:
			geralConteudoArquivo("Precos.txt", 1); //1 = "printEnumerado"
			break;

		case 2:
			 precos = fopen("Precos.txt", "a");

			printf("Escreva o produto e seu preco (sem espacos, usando '_' ou '-', ex: Pipoca_Media----R$15,00): ");
			scanf("%s", &texto);
			fprintf( precos, "%s\n", texto);

			fclose(precos);
			break;

		case 3:
			system("cls");
			printf(
				"Como voce prefere localizar o dia e as sessoes que serão removidas?\n"
				"[2] Pelo valor x -> [x].\n"
				"[3] Seu nome exato.\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Precos.txt", escolha);
			break;

		case 4:
			system("cls");
			printf(
				"Como voce prefere localizar o dia e as sessoes que serão atualizadas?\n"
				"[4] Pelo valor x -> [x].\n"
				"[5] Seu nome exato.\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Precos.txt", escolha);
			break;
		}
  }
}

void promocaoPrincipal()
{
  for(;;)
	{
		FILE* promocao;

		system("cls");

		int pivo_Promocao = 0;
		printf
		(" Voce esta na aba Promocao da Semana...\n Selecione uma opcao digitando o valor x -> [x]: \n"
			"  [1] Listar promocao(oes) da semana\n"
			"  [2] Adicionar promocao da semana\n"
			"  [3] Remover promocao da semana \n"
			"  [4] Atualizar promocao da semana \n"
			"  [5] Voltar\n"
		);

		scanf(" %d", &pivo_Promocao);
		if (pivo_Promocao == 5)
			break;

		char texto[40];
		char i;
		int escolha;
		switch (pivo_Promocao)
		{
		case 1:
			geralConteudoArquivo("Promocao.txt", 1); //1 = "printEnumerado"
			break;

		case 2:
			 promocao = fopen("Promocao.txt", "a");

			printf("Escreva o dia de promocao (sem espacos, usando '_' ou '-', ex: Terca-(06/12)-Todos_pagam_meia!!!): ");
			scanf("%s", &texto);
			fprintf( promocao, "%s\n", texto);

			fclose(promocao);
			break;

		case 3:
			system("cls");
			printf(
				"Como voce prefere localizar o dia e as sessoes com promocao que serão removidas?\n"
				"[2] Pelo valor x -> x - [dia da semana] .\n"
				"[3] Seu descricao completa.\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Promocao.txt", escolha);
			break;

		case 4:
			system("cls");
			printf(
				"Como voce prefere localizar o dia e as sessoes com promocao que serão atualizadas?\n"
				"[4] Pelo valor x -> x - [dia da semana].\n"
				"[5] Sua descricao completa.\n");

			scanf(" %d", &escolha);
			geralConteudoArquivo("Promocao.txt", escolha);
			break;
		}
	}
}

#endif