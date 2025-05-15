/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:17:34 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/09 11:53:37 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {
 private:
  int fixedPoint;
  static const int FractionalBits = 8;

 public:
  Fixed();
  ~Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(const int raw);
};
