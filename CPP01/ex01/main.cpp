/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:06:07 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/05 00:20:10 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N (7);
	Zombie	*zombiePutin (zombieHorde(N, "Putin"));

	for (int i (0); i < N; i++)
		zombiePutin[i].announce();
	delete[] zombiePutin;
	return (0);
}
