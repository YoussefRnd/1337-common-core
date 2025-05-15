/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:12:28 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/05 02:57:53 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T *array, int size, void (*func)(T &)) {
  for (int i = 0; i < size; i++) {
    func(array[i]);
  }
}

template <typename T>
void print(T &i) {
  std::cout << i << std::endl;
}