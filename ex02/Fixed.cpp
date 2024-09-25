/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:13:05 by kfouad            #+#    #+#             */
/*   Updated: 2024/09/25 17:13:07 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    fixedPoint = 0;
};
Fixed::Fixed(const Fixed &old_fixed)
{
    *this = old_fixed;
};
Fixed::Fixed(const int par)
{
    fixedPoint = par << fra_bits;
};
Fixed::Fixed(const float par)
{
    fixedPoint = std::roundf(par * (1 << fra_bits));
};

int Fixed::toInt(void) const
{
    return (fixedPoint >> fra_bits);
};
float Fixed::toFloat(void) const
{
    return ((float)fixedPoint / (1 << fra_bits));
};

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
    out << other.toFloat();
    return out;
};

Fixed &Fixed::operator=(const Fixed &other)
{
    fixedPoint = other.getRawBits();
    return (*this);
};

bool Fixed::operator>(const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
};
bool Fixed::operator<(const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
};
bool Fixed::operator>=(const Fixed &other) const
{
    return (this->toFloat() >= other.toFloat());
};
bool Fixed::operator<=(const Fixed &other) const
{
    return (this->toFloat() <= other.toFloat());
};
bool Fixed::operator==(const Fixed &other) const
{
    return (this->toFloat() == other.toFloat());
};
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
};

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed fix(this->toFloat() + other.toFloat());
    return (fix);
};
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed fix(this->toFloat() - other.toFloat());
    return (fix);
};
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed fix(this->toFloat() * other.toFloat());
    return (fix);
};
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed fix(this->toFloat() / other.toFloat());
    return (fix);
};

Fixed Fixed::operator++(void)
{
    ++(this->fixedPoint);
    return (*this);
};
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(this->fixedPoint);
    return (temp);
};
Fixed Fixed::operator--(void)
{
    ++(this->fixedPoint);
    return (*this);
};
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    ++(this->fixedPoint);
    return (temp);
};

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1.toFloat() > fixed2.toFloat())
        return fixed2;
    return fixed1;
};
const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.toFloat() > fixed2.toFloat())
        return fixed2;
    return fixed1;
};
Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1.toFloat() > fixed2.toFloat())
        return fixed1;
    return fixed2;
};
const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.toFloat() > fixed2.toFloat())
        return fixed1;
    return fixed2;
};

int Fixed::getRawBits(void) const
{
    return fixedPoint;
};
void Fixed::setRawBits(int const raw)
{
    fixedPoint = raw;
};

Fixed::~Fixed(){};
