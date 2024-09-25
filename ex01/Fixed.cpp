/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:36:43 by kfouad            #+#    #+#             */
/*   Updated: 2024/09/25 17:07:58 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed_Point = 0;
};
Fixed::Fixed(const Fixed &copy_fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy_fixed;
};
Fixed::Fixed(const int par)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_Point = par << bit_fractional;
};

Fixed::Fixed(const float par)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_Point = std::roundf(par * (1 << bit_fractional));
};

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_Point = copy.getRawBits();
    return (*this);
}
int Fixed::toInt(void) const
{
    return (fixed_Point >> bit_fractional);
};

float Fixed::toFloat(void) const
{
    return ((float)fixed_Point / (float)(1 << bit_fractional));
};


std::ostream &operator<<(std::ostream &out, const Fixed &copy)
{
    out << copy.toFloat();
    return out;
}

int Fixed::getRawBits(void) const
{
    return fixed_Point;
};

void Fixed::setRawBits(int const raw)
{
    fixed_Point = raw;
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};