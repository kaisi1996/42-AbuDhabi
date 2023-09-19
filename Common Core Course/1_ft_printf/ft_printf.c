/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:32:19 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/03/11 08:25:13 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converter(va_list args, char c, char flag)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == '%')
		count = ft_putchar('%');
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int), flag);
	else if (c == 'u')
		count = ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthexad(va_arg(args, unsigned int), c, flag);
	else if (c == 'p')
		count = ft_putaddress(va_arg(args, unsigned long));
	return (count);
}

int	loop3(const char *s, va_list args, int i, char flag)
{
	int	count;

	count = 0;
	while (s[i] != '\0')
	{
		flag = 'N';
		if (s[i] == '%')
		{
			while (s[i + 1] == ' ' || s[i + 1] == '+' || s[i + 1] == '#')
				flag = s[++i];
			count += ft_converter(args, s[++i], flag);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;
	char	flag;

	i = 0;
	va_start(args, s);
	flag = 'N';
	count = loop3(s, args, i, flag);
	va_end(args);
	return (count);
}

/*int main()
{
	//char *word = "HELLO";
	printf("\n%d\n", printf("%s ", "H"));
	//printf("\n%d\n\n", ft_printf("% s ", ""));
}*/
