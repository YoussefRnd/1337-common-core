/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 04:20:08 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/03 05:08:01 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

int main() {
  Data *data = new Data("Alien", 99);
  uintptr_t raw = Serializer::serialize(data);
  Data *ptr = Serializer::deserialize(raw);

  std::cout << "Name: " << ptr->name << std::endl;
  std::cout << "Age: " << ptr->age << std::endl;

  return 0;
}