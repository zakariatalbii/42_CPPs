/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:38:25 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/14 16:59:55 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vec;
	vec.push_back(13);
	vec.push_back(37);
	vec.push_back(42);
	vec.push_back(42);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Vector: " << *it << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	std::list<int>	lst;
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(5);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "List: " << *it << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	std::deque<int>	deq;
	deq.push_back(7);
	deq.push_back(11);
	deq.push_back(13);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 13);
		std::cout << "Deque: " << *it << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	const std::vector<int>	&cvec (vec);

	try
	{
		std::vector<int>::const_iterator it = easyfind(cvec, 37);
		std::cout << "Const Vector: " << *it << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		easyfind(vec, 101);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	std::vector<int> empty;

	try
	{
		easyfind(empty, 1);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
