/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:41:53 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 19:28:10 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal *animals[10];

  for (int i = 0; i < 10; i++) {
    if (i < 5)
      animals[i] = new Cat();
    else
      animals[i] = new Dog();
  }

  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }
  return 0;
}