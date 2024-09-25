/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:13:42 by kfouad            #+#    #+#             */
/*   Updated: 2024/09/25 16:26:10 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
};

Fixed::Fixed(const Fixed &copy_fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy_fixed;
};

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    (*this).fixed_point = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
};

void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
    std::cout << "setRawBits member function called" << std::endl;
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};