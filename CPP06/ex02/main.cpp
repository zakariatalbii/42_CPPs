/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:16:47 by zatalbi           #+#    #+#             */
/*   Updated: 2026/06/22 21:04:51 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.hpp"
#include <ctime>

int	main(void)
{
	srand(time(NULL));

	Base	*ptr (generate());
	Base	&ref (*ptr);

	identify(ptr);
	identify(ref);

	delete ptr;

	return (0);
}
