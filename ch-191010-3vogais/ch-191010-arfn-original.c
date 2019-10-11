#define _CRT_SECURE_NO_WARNINGS
#include	"memory.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>


int			e_vogal(char);


int			main(int argc, char** argv)
{
	int			maior_tamanho = 512;		// limite do vetor
	char		palavra[9];				// um byte a mais pro 0
	short		ip = 0;					// ponteiro na palavra
	char		c;						// o caracter lido
	int			nVogais = 0;			// conta as vogais
	int			emPalavra = 0;			// indica se esta em uma palavra

	printf(
		"Entre com a FRASE e tecle ENTER\
 para ver a contagem de palavras com 3 ou mais vogais\n\nFrase:");

	do
	{
		if (ip >= maior_tamanho)
			c = '\n';					// nao cabe mais: insere um ENTER		
		else
		    c = (char) fgetc(stdin);	// ou continua lendo
			
		switch (c)
		{

		case ' ':
		case '\t':
			// espaco em branco ou TAB
			if (emPalavra != 0)
			{	// um espaco: acabou a palavra
				emPalavra = 0;			// agora acabou a palavra
				palavra[ip] = 0;		// termina a string
				if (nVogais > 2)			// essa sim
				{
					printf("%s\n", palavra);
				}	// end if
				nVogais = 0;
				ip = 0;
			}	// end if
			break;

		case '\n':
		case EOF:
			// fim da linha ou do arquivo ENTER ou CONTROL Z
			// espaco em branco ou TAB
			if (emPalavra == 1)
			{	// fim da entrada: acabou a palavra
				palavra[ip] = 0;		// termina a string
				if (nVogais > 2)			// essa sim
					printf("%s\n", palavra);
			}	// end if
			return 0;

		default:
			// leu alguma coisa, nao branco
			if (emPalavra == 0)
			{	// primeira letra de uma palavra nova
				ip = 1;					// ponteiro da palavra
				palavra[0] = c;			// salva a primeira letra
				emPalavra = 1;			// agora em uma palavra
				if (e_vogal(c))
					nVogais = 1;		// comecou com vogal ja
				else
					nVogais = 0;		// ok continua lendo
			}
			else
			{	// continua na palavra
				palavra[ip] = c;		// salva a primeira letra
				ip = ip + 1;
				if (e_vogal(c))
					nVogais = nVogais + 1;		// comecou com vogal ja
			}
		}	// end switch()
	} while (1);
	return 0;
}	// end main()

