/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:38:54 by zatalbi           #+#    #+#             */
/*   Updated: 2026/01/22 18:57:19 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* animal[6];
	// Animal	k;

	for (int i (0); i < 3; i++)
		animal[i] = new Dog();
	for (int i (3); i < 6; i++)
		animal[i] = new Cat();

	{
		Cat	tmpCat (*(Cat *)i);
		Dog	tmpDog;

		tmpDog = *(Dog *)j;
	}

	std::cout << j->getType() << '\n';
	std::cout << i->getType() << '\n';
	i->makeSound();
	j->makeSound();

	for (int i (0); i < 6; i++)
		delete animal[i];
	delete i;
	delete j;

	return 0;
}
