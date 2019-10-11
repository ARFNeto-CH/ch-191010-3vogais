#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int		e_vogal(char);
int		teste_original3(char*);

//
// esta versao corrigida para a versao original do 
// autor do topico
//

//int main()
//{
//	// primeiras linhas de teste
//	char* linha1 = "      teste aaaaa AEITEstetee";
//	char* linha2 = "  testeee";
//	char* linha3 = "teste testea testea";
//	char* linha4 = "               ";
//	char* linha5 = "";
//	char* linha6 = "aaaaa aaa";
//	char* linha7 = "  aaaaa aaa              ";
//
//	teste_original3(linha1);
//	teste_original3(linha2);
//	teste_original3(linha3);
//	teste_original3(linha4);
//	teste_original3(linha5);
//	teste_original3(linha6);
//	teste_original3(linha7);
//
//	return 0;
//}


int teste_original_corrigido(char* teste)
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
