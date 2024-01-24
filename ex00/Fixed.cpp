/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:41:47 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/24 13:06:04 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int	Fixed::_fractionBits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = other._fixedPointValue;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = rhs._fixedPointValue;
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}
