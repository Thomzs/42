#include "libfts.h"

void	test_bzero(void)
{
	char str[10] = "123456789";
	
	printf("BZERO\n");
	printf("before: [%s]\n", str);
	ft_bzero(str, 0);
	printf("with 0 -- [%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
			str[0], str[1], str[2], str[3], str[4], str[5], str[6],
			str[7], str[8]);
	ft_bzero(str, 5);
	printf("with 5 -- [%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
			str[0], str[1], str[2], str[3], str[4], str[5], str[6],
			str[7], str[8]);
	ft_bzero(str, 10);
	printf("with 10 -- [%c][%c][%c][%c][%c][%c][%c][%c][%c]\n\n",
			str[0], str[1], str[2], str[3], str[4], str[5], str[6],
			str[7], str[8]);
}

void	test_strcat(void)
{
	char str[20] = "Hello";
	printf("STRCAT\n");
	printf("\"Hello\" + \" world !\": %s\n", ft_strcat(str, " world !"));
	char str2[20] = "";
	printf("\"\" + \"BONSOIR\": %s\n\n", ft_strcat(str2, "BONSOIR"));
}

void	test_isalpha(void)
{
	char *str = "J'41ME L3S PatAtes !";
	printf("IS ALPHA\nstr: [%s]\n", str);
	while (*str)
	{
		printf("[%c]: %d\n", *str, ft_isalpha(*str));
		str++;
	}
	printf("\n");
}

void	test_isdigit(void)
{
	char *str = "J'41ME L3S PatAtes !";
	printf("IS DIGIT\nstr: [%s]\n", str);
	while (*str)
	{
		printf("[%c]: %d\n", *str, ft_isdigit(*str));
		str++;
	}
	printf("\n");
}

void	test_isalnum(void)
{
	char *str = "J'41ME L3S PatAtes !";
	printf("IS ALNUM\nstr: [%s]\n", str);
	while (*str)
	{
		printf("[%c]: %d\n", *str, ft_isalnum(*str));
		str++;
	}
	printf("\n");
}

void	test_isascii(void)
{
	printf("IS ASCII\n");
	for (int i = -10; i <= 140; i++)
		printf("[%d]: %d\n", i, ft_isascii(i));
	printf("\n");
}

void	test_isprint(void)
{
	printf("IS PRINT\n");
	for (int i = 0; i <= 127; i++)
		printf("[%d]: %d\n", i, ft_isprint(i));
	printf("\n");
}

void	test_islower(void)
{
	char *str = "J'AiMe LeS PaTAtEs";
	printf("ISLOWER\n");
	while (*str)
	{
		printf("[%c]: %d\n", *str, ft_islower(*str));
		str++;
	}
	printf("\n");
}

void	test_isupper(void)
{
	char *str = "J'AiMe LeS PaTAtEs";
	printf("ISUPPER\n");
	while (*str)
	{
		printf("[%c]: %d\n", *str, ft_isupper(*str));
		str++;
	}
	printf("\n");
}

void	test_toupper(void)
{
	char *str = "J'AiMe LeS PaTAtEs";
	char *str2;
	int i = -1;

	if (!(str2 = (char*)malloc(sizeof(char) * 19)))
		exit(1);
	strcpy(str2, str);
	printf("TOUPPER\nbefore: [%s]\n", str2);
	while (str2[++i])
		str2[i] = ft_toupper(str2[i]);
	printf("After: [%s]\n\n", str2);
	free(str2);
}

void	test_tolower(void)
{
	char *str = "J'AiMe LeS PaTAtEs";
	char *str2;
	int i = -1;

	if (!(str2 = (char*)malloc(sizeof(char) * 19)))
		exit(1);
	strcpy(str2, str);
	printf("TOLOWER\nbefore: [%s]\n", str2);
	while (str2[++i])
		str2[i] = ft_tolower(str2[i]);
	printf("After: [%s]\n\n", str2);
	free(str2);
}

void	test_strlen(void)
{
	char *str = "J'AiMe LeS PaTAtEs";
	printf("STRLEN\nstr: [%s]\nstrlen: %zu | ft_strlen: %zu\n",
			str, strlen(str), ft_strlen(str));
	printf("str: NULL\nft_strlen: %zu\n\n", ft_strlen(NULL));
}

void	test_puts(void)
{
	char *str = "J'aime les patates";
	printf("PUTS\nstring: [%s]\nft_puts: [", str);
	fflush(stdout);
	ft_puts(str);
	printf("]\n\n");
}

void	test_memset(void)
{
	char *str = "J'aime les patates";
	char *str2;

	if (!(str2 = (char*)malloc(sizeof(char) * 19)))
		exit(1);
	strcpy(str2, str);
	printf("MEMSET\nbefore: [%s]\n", str2);
	printf("c: \'c\' n: 10 after: [%s]\n\n", ft_memset(str2, 'c', 10));
	free(str2);
}

void	test_memcpy(void)
{
	char *str = "J'aime les patates";
	char *str2;
	char *str3 = "Little change";

	if (!(str2 = (char*)malloc(sizeof(char) * 19)))
		exit(1);
	strcpy(str2, str);
	printf("MEMCPY\nbefore: [%s] substring: [%s]\n", str2, str3);
	printf("c: \'c\' n: 10 after: [%s]\n\n", ft_memcpy(str2, str3, 10));
	
}

void	test_lib(void)
{
	test_bzero(); //CHECK NULL
	test_strcat(); //CHECK NULL
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_islower();
	test_isupper();
	test_toupper();
	test_tolower();
	test_strlen();
	test_puts();
	test_memset();
	test_memcpy();
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;	
//	if (ac > 1)
//		test_cat(av[1]);
	test_lib();
	return (0);
}
