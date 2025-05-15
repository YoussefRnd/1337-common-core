/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 04:06:51 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/11 00:34:10 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include "../inc/easyfind.hpp"

int main(void) {
  std::deque<int> vec;
  for (int i = 0; i < 10; i++)
    vec.push_back(i);
  try {
    easyfind(vec, 5);
    easyfind(vec, 10);
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}