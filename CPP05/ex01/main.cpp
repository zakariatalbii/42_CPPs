/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:15:17 by zatalbi           #+#    #+#             */
/*   Updated: 2026/05/11 19:54:24 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	f ("f", 0, 1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Form		f ("f", 1, 1);
		Bureaucrat	b ("b", 2);

		std::cout << f;

		b.signForm(f);
		b.incrementGrade();
		b.signForm(f);

		std::cout << f;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
