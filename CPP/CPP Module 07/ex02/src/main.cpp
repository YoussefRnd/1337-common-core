/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:23:55 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/05 02:53:51 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Array.hpp"

int main(void) {
  Array<int> emptyArray;
  std::cout << "Empty array size: " << emptyArray.size() << '\n';

  Array<int> intArray(5);
  std::cout << "Int array size: " << intArray.size() << '\n';

  for (size_t i = 0; i < intArray.size(); i++) {
    intArray[i] = i;
  }

  std::cout << "Int array elements: ";
  for (size_t i = 0; i < intArray.size(); i++) {
    std::cout << intArray[i] << ' ';
  }
  std::cout << '\n';

  try {
    std::cout << "Trying to access an element out of range: " << intArray[6] << '\n';
  } catch (std::out_of_range &e) {
    std::cerr << e.what() << '\n';
  }

  Array<std::string> stringArray(3);
  stringArray[0] = "Hello";
  stringArray[1] = "World";
  stringArray[2] = "!";

  std::cout << "String array elements: ";
  for (size_t i = 0; i < stringArray.size(); i++) {
    std::cout << stringArray[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}