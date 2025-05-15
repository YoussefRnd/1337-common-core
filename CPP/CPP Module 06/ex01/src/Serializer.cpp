/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 04:14:26 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/03 05:13:09 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

// Constructors
Serializer::Serializer() {}

// Destructor
Serializer::~Serializer() {}

// Copy Constructor
Serializer::Serializer(const Serializer &src) {
  *this = src;
}

// Assignation Operator
Serializer &Serializer::operator=(const Serializer &src) {
  if (this != &src) {
    *this = src;
  }
  return *this;
}

// Static methods
uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}