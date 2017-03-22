/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:45:59 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:16:50 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_prec(va_list args)
{
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	return (str);
}

wchar_t *ls_prec(va_list args)
{
	wchar_t *wstr;

	wstr = va_arg(args, wchar_t*);
	if (wstr == NULL)
		wstr = (wchar_t*)"(null)";
	return (wstr);
}

void	flag_ls(va_list args, char *fmt, int *fin_size, FMT *f)
{
	setforprint(fmt, f);
	get_prec_min(f, fmt);
	f->arg.wct = ls_prec(args);
/*	f->arg_len = (int)ft_strlen(f->arg.s);
	f->arg_len = (f->arg_len < 0) ? 0 : f->arg_len;
	f->precision = (!f->precision || f->precision > f->arg_len) ?
	f->arg_len : f->precision;
*/
	*fin_size += (f->min_width > f->precision) ? f->min_width : f->precision;
	f->arg_len = f->precision ? f->precision : (int)ft_strlen(f->arg.s);

	//ft_print(f);
	free((void*)f);
}


void	flag_s(va_list args, char *fmt, int *fin_size, FMT *f)
{
	setforprint(fmt, f);
	get_prec_min(f, fmt);
	get_conversion(f, args);
	f->arg_len = (int)ft_strlen(f->arg.s);
	f->arg_len = (f->arg_len < 0) ? 0 : f->arg_len;
	f->precision = (!f->precision || f->precision > f->arg_len) ?
	f->arg_len : f->precision;
	*fin_size += (f->min_width > f->precision) ? f->min_width : f->precision;

	f->arg_len = f->precision ? f->precision : (int)ft_strlen(f->arg.s);

	ft_print(f);
	free((void*)f);
}
