/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:20:43 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/04 01:53:17 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/Base.hpp"
#include "../inc/C.hpp"

Base *generate(void) {
  std::srand(std::time(NULL));
  int random = std::rand() % 3;
  if (random == 0)
    return new A();
  else if (random == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }

  std::cout << "Unknown" << std::endl;
}

int main() {
  Base *base = generate();
  identify(base);
  identify(*base);
  delete base;
  return 0;
}