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
	_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::Fixed(const int fpn): _fixedPointValue(roundf(fpn << _fractionBits)) {
}

Fixed::Fixed(const float fpn): _fixedPointValue(roundf(fpn * pow(2, _fractionBits))) {
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	_fixedPointValue = rhs._fixedPointValue;
	return (*this);
}

Fixed::~Fixed(void) {
}

int	Fixed::getRawBits(void) {
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
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

bool	Fixed::operator>(const Fixed &rhs) {
	if (_fixedPointValue > rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &rhs) {
	if (_fixedPointValue < rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &rhs) {
	if (_fixedPointValue >= rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &rhs) {
	if (_fixedPointValue <= rhs._fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &rhs) {
	if (_fixedPointValue == rhs._fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &rhs) {
	if (_fixedPointValue != rhs._fixedPointValue)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &rhs) {
	Fixed	tmp;
	
	tmp._fixedPointValue = _fixedPointValue + rhs._fixedPointValue;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &rhs) {
	Fixed	tmp;
	
	tmp._fixedPointValue = _fixedPointValue - rhs._fixedPointValue;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &rhs) {
	Fixed	tmp;

	tmp._fixedPointValue = _fixedPointValue * rhs._fixedPointValue >> _fractionBits;
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &rhs) {
	Fixed	tmp;

	tmp._fixedPointValue = _fixedPointValue /= rhs._fixedPointValue >> _fractionBits;
	return (tmp);
}

Fixed	&Fixed::operator++() {
	++_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed copy = *this;

	++_fixedPointValue;
	return (copy);
}

Fixed	&Fixed::operator--() {
	_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed copy = *this;

	--_fixedPointValue;
	return (copy);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a._fixedPointValue < b._fixedPointValue) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a._fixedPointValue > b._fixedPointValue) ? a : b);
}
