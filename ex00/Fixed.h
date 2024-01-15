/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:31:45 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/14 21:49:21 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_FIXED
# define HPP_FIXED

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);
		int		getRawBits(void);
		void	setRawBits(int const raw);
	private:
		int					_fixedPointValue;
		static const int	_fractionBits;
};

#endif
