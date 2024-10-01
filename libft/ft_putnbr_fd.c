#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	result;

	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	result = (nb % 10) + '0';
	ft_putchar_fd(result, fd);
}
