/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:41:37 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/29 20:11:40 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: _vectorTime (0.),
	_dequeTime (0.)
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
	: _input (other._input),
	_vector (other._vector),
	_deque (other._deque),
	_vectorTime (other._vectorTime),
	_dequeTime (other._dequeTime)
{
}

PmergeMe::PmergeMe(int argc, char **argv)
	: _vectorTime (0.),
	_dequeTime (0.)
{
	_input.reserve(argc - 1);

	for (int i (1); i < argc; ++i)
	{
		if (!isDigits(argv[i]) || !addNum(argv[i]))
			throw std::runtime_error ("Error");
	}
}

PmergeMe::~PmergeMe()
{
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		_input = other._input;
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}

	return (*this);
}

bool	PmergeMe::isDigits(std::string const &str)	const
{
	if (str.empty())
		return (false);

	for (std::size_t i (0); str[i]; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}

	return (true);
}

bool	PmergeMe::addNum(std::string const &str)
{
	std::stringstream	ss (str);
	int	num;

	ss >> num;
	if (ss.fail()
		|| !ss.eof()
		|| num <= 0)
		return (false);

	_input.push_back(num);

	return (true);
}

PmergeMe::VectorPairs::VectorPairs(
	std::vector<int> const &vec,
	std::vector<std::size_t> const &idx)
	: partner (vec.size())
{
	largeIdx.reserve(idx.size() / 2);

	for (std::size_t i (0); i + 1 < idx.size(); i += 2)
	{
		std::size_t	a = idx[i];
		std::size_t	b = idx[i + 1];

		if (vec[a] > vec[b])
		{
			largeIdx.push_back(a);
			partner[largeIdx.back()] = b;
		}
		else
		{
			largeIdx.push_back(b);
			partner[largeIdx.back()] = a;
		}
	}
}

PmergeMe::VectorStraggler::VectorStraggler(std::vector<std::size_t> const &idx)
	: has (idx.size() % 2 != 0), id (0)
{
	if (has)
		id = idx.back();
}

void	PmergeMe::vectorJacobsthalOrder(
			std::vector<std::size_t> &order, std::size_t size)	const
{
	std::vector<std::size_t>	J;

	J.push_back(0);
	J.push_back(1);

	while (J.back() < size)
		J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);

	for (std::size_t i (1); i < J.size(); ++i)
	{
		for (std::size_t j (std::min(J[i], size));
			j > J[i - 1]; --j)
			order.push_back(j);
	}
}

std::size_t	PmergeMe::vector_lower_bound(
			std::vector<std::size_t> &mainChain,
			std::size_t end, int value)	const
{
	std::size_t	begin (0);
	std::size_t	last (end);

	while (begin < last)
	{
		std::size_t	mid (begin + (last - begin) / 2);

		if (_vector[mainChain[mid]] >= value)
			last = mid;
		else
			begin = mid + 1;
	}

	return (begin);
}

void	PmergeMe::insertVectorPend(
			std::vector<std::size_t> &mainChain,
			VectorPairs &pairs,
			std::vector<std::size_t> const &order)	const
{
	std::size_t	largeIdxSize (pairs.largeIdx.size());

	std::vector<std::size_t>	largePos (largeIdxSize);

	for (std::size_t i (0); i < largeIdxSize; ++i)
		largePos[i] = i;

	for (std::size_t i (0); i < order.size(); ++i)
	{
		std::size_t	id = order[i] - 1;

		std::size_t	largeId = pairs.largeIdx[id];
		std::size_t	smallId = pairs.partner[largeId];

		std::size_t end = largePos[id];
		int	value = _vector[smallId];

		std::size_t	pos = vector_lower_bound(mainChain, end, value);

		mainChain.insert(mainChain.begin() + pos, smallId);

		for (std::size_t i (0); i < largeIdxSize; ++i)
		{
			if (largePos[i] >= pos)
				++largePos[i];
		}
	}
}

void	PmergeMe::insertVectorStraggler(
			std::vector<std::size_t> &mainChain,
			VectorStraggler &straggler)	const
{
	if (straggler.has)
	{
		std::size_t end = mainChain.size();
		int	value = _vector[straggler.id];

		std::size_t	pos = vector_lower_bound(mainChain, end, value);

		mainChain.insert(mainChain.begin() + pos, straggler.id);
	}
}

void	PmergeMe::fordJohnsonSortVectorIdx(std::vector<std::size_t> &idx)	const
{
	if (idx.size() < 2)
		return ;
		
	VectorPairs		pairs (_vector, idx);
	VectorStraggler	straggler (idx);

	fordJohnsonSortVectorIdx(pairs.largeIdx);

	idx.clear();

	idx.insert(idx.end(),
		pairs.largeIdx.begin(), pairs.largeIdx.end());

	std::vector<std::size_t>	order;
	order.reserve(pairs.largeIdx.size());

	vectorJacobsthalOrder(order, pairs.largeIdx.size());

	insertVectorPend(idx, pairs, order);

	insertVectorStraggler(idx, straggler);
}

void	PmergeMe::fordJohnsonSortVector(void)
{
	std::vector<std::size_t>	idx;
	idx.reserve(_vector.size());

	for (std::size_t i (0); i < _vector.size(); ++i)
		idx.push_back(i);

	fordJohnsonSortVectorIdx(idx);

	_sortedVector.reserve(_vector.size());

	for (std::size_t i (0); i < idx.size(); ++i)
		_sortedVector.push_back(_vector[idx[i]]);
}

void	PmergeMe::processVector(void)
{
	std::clock_t	start = std::clock();

	_vector.assign(_input.begin(), _input.end());

	fordJohnsonSortVector();

	std::clock_t	end = std::clock();

	_vectorTime =
		static_cast<double>(end - start)
		* 1000000.0
		/ CLOCKS_PER_SEC;
}

PmergeMe::DequePairs::DequePairs(
	std::deque<int> const &deq,
	std::deque<std::size_t> const &idx)
	: partner (deq.size())
{
	for (std::size_t i (0); i + 1 < idx.size(); i += 2)
	{
		std::size_t	a = idx[i];
		std::size_t	b = idx[i + 1];

		if (deq[a] > deq[b])
		{
			largeIdx.push_back(a);
			partner[largeIdx.back()] = b;
		}
		else
		{
			largeIdx.push_back(b);
			partner[largeIdx.back()] = a;
		}
	}
}

PmergeMe::DequeStraggler::DequeStraggler(std::deque<std::size_t> const &idx)
	: has (idx.size() % 2 != 0), id (idx.back())
{
}

void	PmergeMe::dequeJacobsthalOrder(
			std::deque<std::size_t> &order, std::size_t size)	const
{
	std::deque<std::size_t>	J;

	J.push_back(0);
	J.push_back(1);

	while (J.back() < size)
		J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);

	for (std::size_t i (1); i < J.size(); ++i)
	{
		for (std::size_t j (std::min(J[i], size));
			j > J[i - 1]; --j)
			order.push_back(j);
	}
}

std::size_t	PmergeMe::deque_lower_bound(
			std::deque<std::size_t> &mainChain,
			std::size_t end, int value)	const
{
	std::size_t	begin (0);
	std::size_t	last (end);

	while (begin < last)
	{
		std::size_t	mid (begin + (last - begin) / 2);

		if (_deque[mainChain[mid]] >= value)
			last = mid;
		else
			begin = mid + 1;
	}

	return (begin);
}

void	PmergeMe::insertDequePend(
			std::deque<std::size_t> &mainChain,
			DequePairs &pairs,
			std::deque<std::size_t> const &order)	const
{
	std::size_t	largeIdxSize (pairs.largeIdx.size());

	std::deque<std::size_t>	largePos (largeIdxSize);

	for (std::size_t i (0); i < largeIdxSize; ++i)
		largePos[i] = i;

	for (std::size_t i (0); i < order.size(); ++i)
	{
		std::size_t	id = order[i] - 1;

		std::size_t	largeId = pairs.largeIdx[id];
		std::size_t	smallId = pairs.partner[largeId];

		std::size_t end = largePos[id];
		int	value = _deque[smallId];

		std::size_t	pos = deque_lower_bound(mainChain, end, value);

		mainChain.insert(mainChain.begin() + pos, smallId);

		for (std::size_t i (0); i < largeIdxSize; ++i)
		{
			if (largePos[i] >= pos)
				++largePos[i];
		}
	}
}

void	PmergeMe::insertDequeStraggler(
			std::deque<std::size_t> &mainChain,
			DequeStraggler &straggler)	const
{
	if (straggler.has)
	{
		std::size_t end = mainChain.size();
		int	value = _deque[straggler.id];

		std::size_t	pos = deque_lower_bound(mainChain, end, value);

		mainChain.insert(mainChain.begin() + pos, straggler.id);
	}
}

void	PmergeMe::fordJohnsonSortDequeIdx(std::deque<std::size_t> &idx)	const
{
	if (idx.size() < 2)
		return ;
		
	DequePairs		pairs (_deque, idx);
	DequeStraggler	straggler (idx);

	fordJohnsonSortDequeIdx(pairs.largeIdx);

	idx.clear();

	idx.insert(idx.end(),
		pairs.largeIdx.begin(), pairs.largeIdx.end());

	std::deque<std::size_t>	order;

	dequeJacobsthalOrder(order, pairs.largeIdx.size());

	insertDequePend(idx, pairs, order);

	insertDequeStraggler(idx, straggler);
}

void	PmergeMe::fordJohnsonSortDeque(void)
{
	std::deque<std::size_t>	idx;

	for (std::size_t i (0); i < _deque.size(); ++i)
		idx.push_back(i);

	fordJohnsonSortDequeIdx(idx);

	for (std::size_t i (0); i < idx.size(); ++i)
		_sortedDeque.push_back(_deque[idx[i]]);
}

void	PmergeMe::processDeque(void)
{
	std::clock_t	start = std::clock();

	_deque.assign(_input.begin(), _input.end());

	fordJohnsonSortDeque();

	std::clock_t	end = std::clock();

	_dequeTime =
		static_cast<double>(end - start)
		* 1000000.0
		/ CLOCKS_PER_SEC;
}

void	PmergeMe::printInput(void)	const
{
	std::size_t	size (_input.size());

	for (size_t i (0); i < size; ++i)
	{
		std::cout << _input[i];

		if (i + 1 < size)
			std::cout << ' ';
	}

	std::cout << '\n';
}

void	PmergeMe::printSortedVector(void)	const
{
	std::size_t	size (_sortedVector.size());

	for (size_t i (0); i < size; ++i)
	{
		std::cout << _sortedVector[i];

		if (i + 1 < size)
			std::cout << ' ';
	}

	std::cout << '\n';
}

void	PmergeMe::printSortedDeque(void)	const
{
	std::size_t	size (_sortedDeque.size());

	for (size_t i (0); i < size; ++i)
	{
		std::cout << _sortedDeque[i];

		if (i + 1 < size)
			std::cout << ' ';
	}

	std::cout << '\n';
}

double	PmergeMe::vectorTime(void)	const
{
	return (_vectorTime);
}

double	PmergeMe::dequeTime(void)	const
{
	return (_dequeTime);
}
