#define _CRT_SECURE_NO_WARNINGS

int			e_vogal(char c)
{
	if ((c == 'A') || (c == 'a')) return 1;
	if ((c == 'E') || (c == 'e')) return 1;
	if ((c == 'I') || (c == 'i')) return 1;
	if ((c == 'O') || (c == 'o')) return 1;
	if ((c == 'U') || (c == 'u')) return 1;
	return 0;
}
