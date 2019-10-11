#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int		e_vogal(char);
int		teste_original1();
int		teste_original2();
int		teste_original3(char*);
int		teste_original4();


// 
// as versoes originais
//

//
// primeiro post do autor do topico
int teste_original1()
{
	char		str[80];
	char		str2[80];
	int i, j, tam, qt;
	i = 0;
	j = 0;
	qt = 0;
	// copia linha de teste sem usar strcpy()
	char* linha1 = "      teste aaaaa AEITEstetee";
	char* linha2 = "teste";
	char* linha3 = "teste testea testea";
	i = strlen(linha1);
	for (j = 0; j <= i; j++)
		str[j] = linha1[j];
	printf("Linha de teste:\n[%s]\n", str);
	printf(" 0....*....0....*....0....*....0....*....0....*....0....*....0]\n");
	printf("           1         2         3         4         5         6]\n");
	/*
		j = 0;
		printf("digite a sequencia de strins: ");
		fgets(str, 80, stdin); // frase digitada
	*/
	//if (!qt) return 0;
	for (j = 0; j < 20; j++) {
		str2[j] = '\0';
	}
	i = 0;
	j = 0;

	while (str[i] != '\0')
	{
		while (str[i] != ' ') {
			str2[j] = str[i]; // copiando as palavras para um vetor 
			i = i + 1;
		}
		while (str[i] == ' ') {
			i = i + 1;
		}
		tam = strlen(str2);

		for (j = 0; j < tam; j++) {
			if (str2[j] == 'a' || str2[j] == 'e' || str2[j] == 'i' || str2[j] == 'o' || str2[j] == 'u') {
				qt = qt + 1;
			}
		}
		if (qt >= 3) {
			printf("palavra %s\n", str2);
		}

		for (j = 0; j < 20; j++) {
			str2[j] = '\0';
		}
		j = 0;
		qt = 0;


	}

	return 0;
}


// arfneto
// inicio apneas com o loop externo
int teste_original2()
{
	char		str[80];
	int i, j, qt;
	i = 0;
	j = 0;
	qt = 0;
	// primeiras linhas de teste
	char* linha1 = "      teste aaaaa AEITEstetee";
	char* linha2 = "  testeee";
	char* linha3 = "teste testea testea";
	// copia uma
	i = strlen(linha2);
	for (j = 0; j <= i; j++)
		str[j] = linha2[j];
	//
	short t_str = (short)strlen(str);
	short ix = 0;
	printf("\n\nLinha de teste - tamanho = %d:\n\n[%s]\n", t_str, str);
	printf(" 0....*....0....*....0....*....0....*....0....*....0....*....0]\n");
	printf("           1         2         3         4         5         6]\n");
	while (str[ix] != '\0')
	{
		printf("[%d/%d]=[%c] (%d em decimal)\n", ix, t_str, str[ix], str[ix]);
		ix++;
	}
	return 0;
}


// arfneto
// programa ok usando a estrutura original
int teste_original3(char * teste)
{
	char		str[80];
	char		str2[80];
	int i, j, qt;
	i = 0;
	j = 0;
	qt = 0;

	// copia uma
	strcpy(str, teste);
	short t_str = (short)strlen(str);
	short ix = 0;
	printf("\n\nLinha de teste - tamanho = %d:\n\n[%s]\n", t_str, str);
	printf(" 0....*....0....*....0....*....0....*....0....*....0....*....0]\n");
	printf("           1         2         3         4         5         6]\n");

	int			em_palavra = 0;			// quando 1 indica que esta em uma palavra
	int			i_str2 = 0;				// indice para a palavra
	int			nVogais = 0;


	while (str[ix] != '\0')
	{
		//printf("[%d/%d]=[%c] (%d em decimal)\n", ix, t_str, str[ix], str[ix]);

		if (str[ix] == ' ')
		{	// estaria  em uma palavra ja?
			if (em_palavra == 0)
			{	
				// um espaco: nao faz nada
			}
			else
			{	// estava lendo uma palavra: acabou
				em_palavra = 0;			// agora acabou a palavra
				str2[i_str2] = 0;		// termina a string
				if (nVogais > 2)		// essa sim
				{
					printf("%s\n", str2);
				}	// end if
			}	// end if
		}
		else
		{	// entao aqui tem uma letra
			if (em_palavra == 0)
			{	// primeira letra de uma palavra nova
				nVogais = 0;			// zera o contador
				str2[0] = str[ix];		// salva a primeira letra
				i_str2 = 1;				// inicio da palavra
				em_palavra = 1;			// agora em uma palavra
				if (e_vogal(str[ix]))
					nVogais = 1;		// comecou com vogal ja
				else
					nVogais = 0;		// ok continua lendo
			}
			else
			{	// continua na palavra
				str2[i_str2] = str[ix];	// salva a primeira letra
				i_str2 = i_str2 + 1;
				if (e_vogal(str[ix]))
					nVogais = nVogais + 1;		// comecou com vogal ja
			}	// end if
		}	// end if

		ix++;							// segue adiante na linha 
	}	// end while(str[ix])


	// aqui acabou a linha mas pode
	// ter uma palavra sem terminar
	if (em_palavra == 1)
	{
		str2[i_str2] = 0;		// termina a string
		if (nVogais > 2)		// essa sim
		{
			printf("%s\n", str2);
		}	// end if
	}
	return 0;
}


//
// versao revisada pelo autor original. ainda nao funciona
int teste_original4()
{
	char * str = "caixa jujuba casa bar telefone marinha melao";
	char str2[20];
	int i, j, tam, qt;
	i = 0;
	j = 0;
	qt = 0;
	for (j = 0; j < 20; j++) {
		str2[j] = '\0';
	}

	//printf("digite a sequencia de strinsca: ");
	//fgets(str, 80, stdin); // frase digitada
	printf("frase %s", str);
	while (str[i] != '\0') {
		j = 0;
		while (str[i] != ' ') {
			str2[j] = str[i]; // copiando as palavras para um vetor

			i = i + 1;
			j = j + 1;
		}
		if (str[i] == ' ') {
			str2[j] = '\0';
			i = i + 1;
		}
		tam = strlen(str2);
		for (j = 0; j < tam; j++) {
			if (str2[j] == 'a' || str2[j] == 'e' || str2[j] == 'i' || str2[j] == 'o' || str2[j] == 'u') {
				qt = qt + 1;
			}
		}
		if (qt >= 3) {
			printf("palavra: %s\n", str2);
		}
		qt = 0;

	}
	return 0;
}

