/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:06:07 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/08 02:14:05 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N (7);
	Zombie	*zombiePutin (zombieHorde(N, "Putin"));

	if (!zombiePutin)
		return (1);
	for (int i (0); i < N; i++)
		zombiePutin[i].announce();
	delete[] zombiePutin;
	return (0);
}
