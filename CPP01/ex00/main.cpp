/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:23:18 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/04 23:47:00 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombiePutin (newZombie("Putin"));

	zombiePutin->announce();
	randomChump("Trump");
	delete zombiePutin;
	return (0);
}
