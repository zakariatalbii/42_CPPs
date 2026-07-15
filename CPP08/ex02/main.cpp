/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:38:25 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/15 22:24:12 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include "MutantStack.hpp"

void	printStack(MutantStack<int> &stack)
{
	for (MutantStack<int>::iterator	it (stack.begin()); it != stack.end(); ++it)
		std::cout << *it << '\n';
}

int	main(void)
{
	MutantStack<int>	mstack;

	std::cout << "Empty: " << std::boolalpha << mstack.empty() << '\n';

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << '\n';

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << '\n';

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	printStack(mstack);

	MutantStack<int>	copy (mstack);

	printStack(copy);

	MutantStack<int>	assign;
	assign = mstack;

	printStack(assign);

	std::stack<int>	s (mstack);

	std::cout << "std::stack top: " << s.top() << '\n'
		<< "std::stack size: " << s.size() << '\n';

	while (!mstack.empty())
	{
		std::cout << "pop: " << mstack.top() << '\n';
		mstack.pop();
	}

	std::cout << "Empty after pop: " << mstack.empty() << '\n';

	MutantStack<std::string>	words;

	words.push("THE ");
	words.push("WORLD ");
	words.push("IS ");
	words.push("YOURS.");

	for (MutantStack<std::string>::iterator	sit (words.begin()); sit != words.end(); ++sit)
		std::cout << *sit;
	std::cout << '\n';

	return (0);
}
