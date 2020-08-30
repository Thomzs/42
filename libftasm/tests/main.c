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

void	test_lib(void)
{
	test_bzero();
	test_strcat();
	test_isalpha();
	test_isdigit();
	test_isalnum();
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
