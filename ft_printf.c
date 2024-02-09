/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakgun <atakgun@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:37:35 by atakgun           #+#    #+#             */
/*   Updated: 2024/02/09 16:03:24 by atakgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void checker(char s, va_list *args, int *len, int *i){

    if(s == 's')
        ft_string(va_arg(*args, char *), len);
    else if(s == 'd' || s == 'i')
        ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putcharacter_length(va_arg(*args, int), len);
	else if (s == '%')
		ft_putcharacter_length('%', len);
	else
		(*i)--;

    
}


int	ft_printf(const char *string, ...)
{
    int len;
    va_list args;
    int i;
    
    i = 0;
    len = 0;
    va_start(args, string);
    while(string[i]){

        if(string[i] == '%'){

            i++;
            checker(string[i], &args, &len, &i);
            i++;
        }
        else
        {

            ft_putcharacter_length(string[i], &len);
            i++;
        }


    }
    va_end(args);
    return(len);

}

int main(){

    int a;
    a = 5;

    ft_printf("%d", a);


}