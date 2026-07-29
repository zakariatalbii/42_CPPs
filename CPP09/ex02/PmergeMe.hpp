/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:35 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/29 19:55:41 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <deque>
# include <stdexcept>
# include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	_input;

		std::vector<int>	_vector;
		std::deque<int>		_deque;

		std::vector<int>	_sortedVector;
		std::deque<int>		_sortedDeque;

		double	_vectorTime;
		double	_dequeTime;

		bool	isDigits(std::string const &str)	const;
		bool	addNum(std::string const &str);

		struct VectorPairs
		{
			std::vector<std::size_t>	largeIdx;
			std::vector<std::size_t>	partner;

			VectorPairs(
				std::vector<int> const &vec,
				std::vector<std::size_t> const &idx);
		};

		struct VectorStraggler
		{
			bool		has;
			std::size_t	id;

			VectorStraggler(std::vector<std::size_t> const &idx);
		};

		void		vectorJacobsthalOrder(
						std::vector<std::size_t> &order, std::size_t size)	const;
		std::size_t	vector_lower_bound(
						std::vector<std::size_t> &mainChain,
						std::size_t end, int value)	const;
		void		insertVectorPend(
						std::vector<std::size_t> &mainChain,
						VectorPairs &pairs,
						std::vector<std::size_t> const &order)	const;
		void		insertVectorStraggler(
						std::vector<std::size_t> &mainChain,
						VectorStraggler &straggler)	const;
		void		fordJohnsonSortVectorIdx(std::vector<std::size_t> &idx)	const;
		void		fordJohnsonSortVector(void);

		struct DequePairs
		{
			std::deque<std::size_t>	largeIdx;
			std::deque<std::size_t>	partner;

			DequePairs(
				std::deque<int> const &deq,
				std::deque<std::size_t> const &idx);
		};

		struct DequeStraggler
		{
			bool		has;
			std::size_t	id;

			DequeStraggler(std::deque<std::size_t> const &idx);
		};

		void		dequeJacobsthalOrder(
						std::deque<std::size_t> &order, std::size_t size)	const;
		std::size_t	deque_lower_bound(
						std::deque<std::size_t> &mainChain,
						std::size_t end, int value)	const;
		void		insertDequePend(
						std::deque<std::size_t> &mainChain,
						DequePairs &pairs,
						std::deque<std::size_t> const &order)	const;
		void		insertDequeStraggler(
						std::deque<std::size_t> &mainChain,
						DequeStraggler &straggler)	const;
		void		fordJohnsonSortDequeIdx(std::deque<std::size_t> &idx)	const;
		void		fordJohnsonSortDeque(void);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &other);

		void		processVector(void);
		void		processDeque(void);

		void		printInput(void)	const;
		void		printSortedVector(void)	const;
		void		printSortedDeque(void)	const;

		double		vectorTime(void)	const;
		double		dequeTime(void)	const;
	};

#endif