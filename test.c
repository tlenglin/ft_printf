#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <inttypes.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int main(void)
{
	//unsigned char c;
	int i;
	void	*p;

	p = &i;
	i = 45;
	// write(1, &i, 1);
	/*c = 50;
	write(1, &c, 2);*/
	// unsigned long n;
	//
	// n = 9223372036854775808;
	// printf("%7d 7d\n", -123456);
	// printf("%.7d .7d\n", -123456);
	// printf("%+.7d +.7d\n", -123456);
	// printf("%0+.7d 0+.7d\n", -123456);
	// printf("%-+.7d -+.7d\n", -123456);
	// printf("%0 .7d 0 .7d\n", -123456);
	// printf("%- .7d - .7d\n", -123456);
	// printf("%0+7d 0+7d\n", -123456);
	// printf("%-+7d -+7d\n", -123456);
	// printf("%0 7d 0 7d\n", -123456);
	// printf("%- 7d - 7d\n", -123456);
	// printf("%0+7.7d 0+7.7d\n", -123456);
	// printf("%-+7.7d -+7.7d\n", -123456);
	// printf("%0 7.7d 0 7.7d\n", -123456);
	// printf("%- 7.7d - 7.7d\n", -123456);
	// printf("%0+8.7d 0+8.7d\n", -123456);
	// printf("%-+8.7d -+8.7d\n", -123456);
	// printf("%0 8.7d 0 8.7d\n", -123456);
	// printf("%- 8.7d - 8.7d\n", -123456);
	// printf("%0+7.8d 0+7.8d\n", -123456);
	// printf("%-+7.8d -+7.8d\n", -123456);
	// printf("%0 7.8d 0 7.8d\n", -123456);
	// printf("%- 7.8d - 7.8d\n", -123456);
	// printf("%-12.7d - 7.8d\n", -123456);
	// printf("%lu = int\n", sizeof(int));
	// printf("%lu = char\n", sizeof(char));
	// printf("%lu = short int\n", sizeof(short int));
	// printf("%lu = long\n", sizeof(long));
	// printf("%lu = long long\n", sizeof(long long));
	// printf("%lu = intmax\n", sizeof(intmax_t));
	// printf("%lu = size_t\n", sizeof(size_t));
	// printf("%7d 7d\n", -123456);
	// printf("%.d .7d\n", -123456);
	// printf("%+.d +.7d\n", -123456);
	// printf("%0+.d 0+.7d\n", -123456);
	// printf("%-+.d -+.7d\n", -123456);
	// printf("%0 .d 0 .7d\n", -123456);
	// printf("%- .d - .7d\n", -123456);
	// printf("%0+7d 0+7d\n", -123456);
	// printf("%-+7d -+7d\n", -123456);
	// printf("%0 7d 0 7d\n", -123456);
	// printf("%- 7d - 7d\n", -123456);
	// printf("%0+7.d 0+7.7d\n", -123456);
	// printf("%-+7.d -+7.7d\n", -123456);
	// printf("%0 7.d 0 7.7d\n", -123456);
	// printf("%- 7.d - 7.7d\n", -123456);
	// printf("%0+8.d 0+8.7d\n", -123456);
	// printf("%-+8.d -+8.7d\n", -123456);
	// printf("%0 8.d 0 8.7d\n", -123456);
	// printf("%- 8.d - 8.7d\n", -123456);
	// printf("%0+7.d 0+7.8d\n", -123456);
	// printf("%-+7.d -+7.8d\n", -123456);
	// printf("%0 7.d 0 7.8d\n", -123456);
	// printf("%- 7.d - 7.8d\n", -123456);
	// printf("%-12.d - 7.8d\n", -123456);
	// printf("%x-x\n", 128);
	// printf("%0.5x-.5x\n", 128);
	// printf("%09.5x-5x\n", 128);
	// printf("%.5x-.5x\n", 128);
	// printf("%5x-5x\n", 128);
	// printf("%5.5x-5.5x\n", 128);
	// printf("%6.5x-6.5x\n", 128);
	// printf("%5.6x-5.6x\n", 128);
	// printf("%#5.5x-5.5x\n", 128);
	// printf("%#09.x-6.5x\n", 128);
	// printf("%#09x-6.5x\n", 128);
	// printf("%#5.6x-5.6x\n", 128);
	// printf("%o-x\n", 128);
	// printf("%0.5o-.5x\n", 128);
	// printf("%09.5o-5x\n", 128);
	// printf("%.5o-.5x\n", 128);
	// printf("%5o-5x\n", 128);
	// printf("%5.5o-5.5x\n", 128);
	// printf("%6.5o-6.5x\n", 128);
	// printf("%5.6o-5.6x\n", 128);
	// printf("%#5.5o-5.5x\n", 128);
	// printf("%#09.o-6.5x\n", 128);
	// printf("%#09o-6.5x\n", 128);
	// printf("%#5.6o-5.6x\n", 128);
	// printf("%#d", 213);
	// printf("%.3s-\n", "coucou");
	// printf("%3s-\n", "coucou");
	// printf("%4.3s-\n", "coucou");
	// printf("%3.4s-\n", "coucou");
	// printf("%p-p\n", p);
	// printf("%8p-8p\n", p);
	// printf("%20p-15p\n", p);
	// printf("%-20p-15p\n", p);
	// printf("%5%-5\n");
	// printf("%2%-5\n");
	// printf("%-5%--5\n");
	// printf("%05%-05\n");
	// printf("%.5%-.5\n");
	// printf("%+5%-+5\n");
	// printf("% 5%- 5\n");
	// printf("%#5%-#5\n");
	// printf("%05.9%-05.9\n");
	// char * str;
	// str = "écoute\n";
	// ft_putstr(str);
	// printf("%3%-3\n");
	// printf("%+3%-+3\n");
	// printf("% 3%- 3\n");
	// printf("%-3%--3\n");
	// printf("%03%-03\n");
	// printf("%0-3%-0-3\n");
	// printf("%0+ #3%-0+ #3\n");
	// printf("%-+ #3%-0+ #3\n");
	//
	// printf("%.3%-.3\n");
	// printf("%+.3%-+.3\n");
	// printf("% .3%- .3\n");
	// printf("%-.3%--.3\n");
	// printf("%0.3%-0.3\n");
	// printf("%0-.3%-0-.3\n");
	// printf("%0+ #.3%-0+ #.3\n");
	// printf("%-+ #.3%-0+ #.3\n");
	//
	// printf("%3.3%-3.3\n");
	// printf("%+3.3%-+3.3\n");
	// printf("% 3.3%- 3.3\n");
	// printf("%-3.3%--3.3\n");
	// printf("%03.3%-03.3\n");
	// printf("%0-3.3%-0-3.3\n");
	// printf("%0+ #3.3%-0+ #3.3\n");
	// printf("%-+ #3.3%-0+ #3.3\n");
	//printf("%d", printf("%s", "î"));
	//printf("2%ls\n", L"liberté");

	// printf("%p-p\n", p);
	// printf("%-p--p\n", p);
	// printf("%6p-6p\n", p);
	// printf("%-6p--6p\n", p);
	// printf("%20p-20p\n", p);
	// printf("%-20p--20p\n", p);
	// printf("%hp-hp\n", p);
	// printf("%hhp-hhp\n", p);
	// printf("%lp-lp\n", p);
	// printf("%llp-llp\n", p);
	// printf("%zp-zp\n", p);
	// printf("%jp-jp\n", p);

	printf("%c-\n", L'é');
	printf("%1c-\n", L'é');
	printf("%3c-\n", L'é');
	printf("%-3c-\n", L'é');
	printf("%C-\n", 'é');
	printf("%1C-\n", 'é');
	printf("%5C-\n", 'é');
	printf("%-5C-\n", 'é');

	return (0);
}
