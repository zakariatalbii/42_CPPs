/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:59:19 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 17:51:38 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

PhoneBook::PhoneBook()
	: index (0), count (0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	std::cout << "first name: ";
	if (!contact[count].set(0))
		return ;

	std::cout << "last name: ";
	if (!contact[count].set(1))
		return ;

	std::cout << "nickname: ";
	if (!contact[count].set(2))
		return ;

	std::cout << "phone number: ";
	if (!contact[count].set(3))
		return ;

	std::cout << "darkest secret: ";
	if (!contact[count].set(4))
		return ;

	count++;
	if (count == 8)
		count = 0;

	if (index < 8)
		index++;
}

void	PhoneBook::search()	const
{
	int	in;

	if (!index)
		std::cout << "\tThe phonebook is empty.\n\n";
	else
	{
		std::cout << '|'
				<< std::setw(10) << "index" << '|'
				<< std::setw(10) << "first name" << '|'
				<< std::setw(10) << "last name" << '|'
				<< std::setw(10) << "nickname" << '|'
				<< '\n';

		for (int i (0); i < index; i++)
		{
			std::cout << '|'
				<< std::setw(10) << i << '|'
				<< tenChar(contact[i].get(0)) << '|'
				<< tenChar(contact[i].get(1)) << '|'
				<< tenChar(contact[i].get(2)) << '|'
				<< '\n';
		}

		std::cout << '\n';

		in = promptIndex(index + 47);
		if (in < 0)
			return ;

		std::cout << "first name: " << contact[in].get(0) << '\n'
				<< "last name: " << contact[in].get(1) << '\n'
				<< "nickname: " << contact[in].get(2) << '\n'
				<< "phone number: " << contact[in].get(3) << '\n'
				<< "darkest secret: " << contact[in].get(4) << "\n\n";
	}
}
