#include "ft_printf.h"

int main(void)
{
	char *test;

	test = "\xe0000";
	ft_printf("%S", "\xe0000");
	return (0);
}
