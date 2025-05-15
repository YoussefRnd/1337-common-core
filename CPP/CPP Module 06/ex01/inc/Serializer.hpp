/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 03:50:21 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/03 05:09:18 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer {
  private:
    // Constructors
    Serializer();

    // Destructor
    ~Serializer();

    // Copy Constructor
    Serializer(const Serializer &src);

    // Assignation Operator
    Serializer &operator=(const Serializer &src);

  public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};