/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:15:17 by zatalbi           #+#    #+#             */
/*   Updated: 2026/05/11 19:48:47 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	tony ("Tony", 0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat	paul ("Paul", 150);

		paul.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat	chris ("Chris", 2);

		chris.incrementGrade();
		std::cout << chris;

		chris.incrementGrade();
		std::cout << chris;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
