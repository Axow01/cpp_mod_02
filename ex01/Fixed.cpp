/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:41:47 by mmarcott          #+#    #+#             */
/*   Updated: 2024/01/15 13:29:42 by mmarcott         ###   ########.fr       */
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
	*this = other;
}

Fixed::Fixed(const int fpn): _fixedPointValue(fpn << _fractionBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fpn): _fixedPointValue(fpn * pow(2, _fractionBits)) {
	std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat(void) const {
	return ((float)_fixedPointValue / (float)(1 << _fractionBits));
}

int	Fixed::toInt(void) const {
	return ((_fixedPointValue ^ _fractionBits) >> _fractionBits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &ptr) {
	os << ptr.toFloat();
	return (os);
}
