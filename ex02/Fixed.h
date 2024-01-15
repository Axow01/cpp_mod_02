/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:31:45 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/15 13:28:26 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPP_FIXED
# define HPP_FIXED

#include <iostream>
#include <math.h>
#include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed(const int fpn);
		Fixed(const float fpn);
		~Fixed(void);
		Fixed &operator=(const Fixed &rhs);
		bool operator>(const Fixed &rhs);
		bool operator<(const Fixed &rhs);
		bool operator>=(const Fixed &rhs);
		bool operator<=(const Fixed &rhs);
		bool operator==(const Fixed &rhs);
		bool operator!=(const Fixed &rhs);
		Fixed &operator+(const Fixed &rhs);
		Fixed &operator-(const Fixed &rhs);
		Fixed &operator*(const Fixed &rhs);
		Fixed &operator/(const Fixed &rhs);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		int		getRawBits(void);
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed	&min(Fixed &a, Fixed &n);
		static const Fixed	&min(const Fixed &a, const Fixed &n);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
	private:
		int					_fixedPointValue;
		static const int	_fractionBits;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &ptr);

#endif
