

#ifndef MAIN_FUNCTIONS_H_
#define MAIN_FUNCTIONS_H_

#include "PrincipalFunctions.h"

typedef struct ARQ
{
	int qtdLinhas;
	int qtdMaxLinha;
	char** conteudo;
}ARQ;

void removeBarraN(char* array)
{
	array[strcspn(array, "\n")] = 0;
}

char** alocaArray(const int linhas, const int colunas)
{
	char** arrayTemp = (char**)malloc(sizeof(char*) * linhas);
	for (int i = 0; i < linhas; i++)
		arrayTemp[i] = (char*)malloc(sizeof(char) * colunas);

	return arrayTemp;
}

void preencherStruct(struct ARQ* arq1, const char* nomeArquivo, const int linhas, const int colunas)
{
	int ing = 0;
	FILE* arq = fopen(nomeArquivo, "r");
	arq1->qtdLinhas = linhas;
	arq1->qtdMaxLinha = colunas;
	arq1->conteudo = alocaArray(linhas, colunas);

	while (ing != linhas)
	{
		fgets(arq1->conteudo[ing], colunas, arq);
		removeBarraN(arq1->conteudo[ing]);
		ing++;
	}

	fclose(arq);
}

int buscaString(struct ARQ* arq1, const char* chave)
{
	for (int i = 0; i < (arq1->qtdLinhas); i++)
	{
		if (strcmp(arq1->conteudo[i], chave) == 0)
			return i;
	}

	return -1;
}

void selectionSort(struct ARQ* arq1)
{
	char temporario[arq1->qtdMaxLinha];
	for (int i = 0; i < arq1->qtdLinhas; i++)
	{
		for (int j = 0; j < arq1->qtdLinhas; j++)
		{
			if (strcmp(arq1->conteudo[i], arq1->conteudo[j]) < 0)
			{
				strcpy(temporario, arq1->conteudo[i]);
				strcpy(arq1->conteudo[i], arq1->conteudo[j]);
				strcpy(arq1->conteudo[j], temporario);
			}
		}
	}
}

int descobrirIndicePeloDiaDaSemana(char * diaDaSemana)
{
	if(!strcmp(diaDaSemana,"Domingo") || !strcmp(diaDaSemana,"domingo"))
		return 0;
	else if(!strcmp(diaDaSemana,"Segunda") || !strcmp(diaDaSemana,"segunda"))
		return 1;
	else if(!strcmp(diaDaSemana,"Terca") || !strcmp(diaDaSemana,"terca"))
		return 2;
	else if(!strcmp(diaDaSemana,"Quarta") || !strcmp(diaDaSemana,"quarta"))
		return 3;
	else if(!strcmp(diaDaSemana,"Quinta") || !strcmp(diaDaSemana,"quinta"))
		return 4;
	else if(!strcmp(diaDaSemana,"Sexta") || !strcmp(diaDaSemana,"sexta"))
		return 5;
	else if(!strcmp(diaDaSemana,"Sabado") || !strcmp(diaDaSemana,"sabado"))
		return 6;
}

void printEnumeradoDias(struct ARQ* arq1, int numLinhas)
{
	system("cls");
	for (int u = 0, n = 1; u != numLinhas - 1; u++, n++)
	{
		switch(n)
		{
			case 1:
				printf(" %d - [Domingo] - sessoes : %s\n", n, arq1->conteudo[u]);
				break;
			case 2:
				printf(" %d - [Segunda] - sessoes : %s\n", n, arq1->conteudo[u]);
				break;
			case 3:
				printf(" %d - [Terca] - sessoes : %s\n", n, arq1->conteudo[u]);
				break;
			case 4:
				printf(" %d - [Quarta] - sessoes : %s\n", n, arq1->conteudo[u]);
				break;
			case 5:
				printf(" %d - [Quinta] - sessoes : %s\n", n, arq1->conteudo[u]);
				break;
			case 6:
				printf(" %d - [Sexta] - sessoes : %s\n", n, arq1->conteudo[u]);
				break;
			case 7:
				printf(" %d - [Sabado] - sessoes : %s\n", n, arq1->conteudo[u]);
				break;
		}
	}
}

void printEnumerado(struct ARQ* arq1, int numLinhas)
{
	system("cls");
	for (int u = 0, n = 1; u != numLinhas - 1; u++, n++)
	{
		printf("[%d] %s\n", n, arq1->conteudo[u]);
	}
}

void modicaOuDeletaLinha(char* nomeDoArquivo, struct ARQ* arq1, int acaoDesignada, int linhaDaChave)
{
	char strNova[60];
	FILE* arq2;
	arq2 = fopen(nomeDoArquivo, "w");

	for (int i = 0; i < arq1->qtdLinhas; i++)
	{
		if (i + 1 == linhaDaChave)
		{
			if (acaoDesignada == 4 || acaoDesignada == 5)// "atualizar a linha"
			{
				printf("Digite a informacao atualizada: ");
				scanf(" %s", strNova);
				fprintf(arq2, "%s\n", strNova);
				continue;
			}
			if (acaoDesignada == 2 || acaoDesignada == 3)// "deletar a linha"
			{
				continue;
			}
		}

		fprintf(arq2, "%s\n", arq1->conteudo[i]);
	}
	fclose(arq2);
}

void geralConteudoArquivo(char* nomeDoArquivo, int acaoDesignada)
{
	system("cls");
	int linhaDaChave;

	FILE* arq;
	arq = fopen(nomeDoArquivo, "r");

	fseek(arq, 0L, SEEK_END);
	int conteudoArq = ftell(arq);
	rewind(arq);

	char leitor;
	int numLinhas = 1;

	while ((leitor = fgetc(arq)) != EOF)
	{
		if (leitor == '\n')
			numLinhas++;
	}

	rewind(arq);

	ARQ s_arq1;

	preencherStruct(&s_arq1, nomeDoArquivo, numLinhas - 1, conteudoArq);

	if(nomeDoArquivo!="Sessoes.txt")
		selectionSort(&s_arq1);

	if (acaoDesignada == 1)// 1 = "printEnumerado"
		{
			if(nomeDoArquivo=="Sessoes.txt")
				printEnumeradoDias(&s_arq1, numLinhas);
			else
				printEnumerado(&s_arq1, numLinhas);
		}

	else if (acaoDesignada == 3 || acaoDesignada == 5) //deletar/modificar localizando linha pelo nome
	{
		char strChave[60];
		if(nomeDoArquivo=="Sessoes.txt")
		{
			printEnumeradoDias(&s_arq1, numLinhas);

			printf(" Digite exatamente o dia deletar/modificar (ex: Domingo): ");

			scanf(" %s", strChave);

			linhaDaChave = descobrirIndicePeloDiaDaSemana(strChave) + 1;

		}
		else
		{
			printEnumerado(&s_arq1, numLinhas);

			printf(" Digite exatamente o que deseja deletar/modificar: ");
		
			scanf(" %s", strChave);

			linhaDaChave = buscaString(&s_arq1, strChave) + 1;

			if (linhaDaChave == -1)
				printf("digitou errado :(  ");
		}
		fclose(arq);
		modicaOuDeletaLinha(nomeDoArquivo, &s_arq1, acaoDesignada, linhaDaChave);
	}
	else if (acaoDesignada == 2 || acaoDesignada == 4) //deletar/modificar localizando linha pelo indice
	{
		if(nomeDoArquivo=="Sessoes.txt")
				printEnumeradoDias(&s_arq1, numLinhas);
			else
				printEnumerado(&s_arq1, numLinhas);

		printf(" Digite exatamente o numero do item que deseja deletar/modificar: ");
		scanf(" %d", &linhaDaChave);

		fclose(arq);
		modicaOuDeletaLinha(nomeDoArquivo, &s_arq1, acaoDesignada, linhaDaChave);
	}
	




	fclose(arq);
	printf("\n\n");
	system("pause");

}

#endif
