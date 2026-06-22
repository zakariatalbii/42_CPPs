/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:16:47 by zatalbi           #+#    #+#             */
/*   Updated: 2026/06/22 20:51:55 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base	*generate(void)
{
	int	i (rand() % 3);

	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "p: A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "p: B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "p: C\n";
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "p: A\n";
    }
	catch (std::exception &e)
	{
    }
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "p: B\n";
    }
	catch (std::exception &e)
	{
    }
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "p: C\n";
    }
	catch (std::exception &e)
	{
    }
}
