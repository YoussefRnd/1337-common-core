/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:43:29 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/11 00:31:35 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
void easyfind(T& container, int i) {
  typename T::iterator it = std::find(container.begin(), container.end(), i);
  if (it != container.end()) {
    std::cout << "Element found" << '\n';
  } else {
    throw std::runtime_error("Element not found");
  }
}