/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:01:16 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/17 19:30:38 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

int			key_release(int keycode, t_keyboard *keyboard)
{
	ft_putstr("Key Release : ");
	ft_putnbr(keycode);
	ft_putstr("\n");

	keyboard->key[keycode] = 0;

	return (1);	
}

int			key_press(int keycode, t_keyboard *keyboard)
{
	ft_putstr("Key Press : ");
	ft_putnbr(keycode);
	ft_putstr("\n");

	keyboard->key[keycode] = 1;
	return (1);	
}

t_keyboard	*new_keyboard(void)
{
	t_keyboard	*keyboard;

	keyboard = (t_keyboard*)malloc(sizeof(t_keyboard));
	ft_bzero(keyboard, sizeof(t_keyboard));
	return (keyboard);
}

void		destroy_keyboard(t_keyboard *keyboard)
{
	free(keyboard);
}
