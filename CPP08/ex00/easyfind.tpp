/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:29:00 by zatalbi           #+#    #+#             */
/*   Updated: 2026/07/14 17:09:17 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator	easyfind(T &c, int i)
{
	typename T::iterator	it;
	it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
		throw std::runtime_error ("No occurrence found");
	return (it);
}

template <typename T>
typename T::const_iterator	easyfind(const T &c, int i)
{
	typename T::const_iterator	it;

	it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
		throw std::runtime_error ("No occurrence found");
	return (it);
}
