/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:06:07 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:01:41 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (!N)
		return ((Zombie *)0);

	Zombie	*zombie (new (std::nothrow) Zombie[N]);

	if (!zombie)
		return ((Zombie *)0);

	Zombie	tmp (name);

	for (int i (0); i < N; i++)
		zombie[i] = tmp;

	return (zombie);
}
