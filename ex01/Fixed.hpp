/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:26 by kfouad            #+#    #+#             */
/*   Updated: 2024/09/25 17:07:11 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed
{
private:
    int fixed_Point;
    const static int bit_fractional = 8;

public:
    Fixed();
    Fixed(const Fixed &copy_fixed);
    Fixed(const int par);
    Fixed(const float par);
    Fixed &operator=(const Fixed &copy);
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
    ~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &copy);
#endif