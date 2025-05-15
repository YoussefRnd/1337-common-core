/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:34:03 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/05 02:50:13 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>

template <typename T>
class Array {
  private:
    T *array;
    size_t arraySize;

  public:
    Array() : array(NULL), arraySize(0) {}

    Array(unsigned int n) : arraySize(n) {
      array = new T[arraySize];
    }

    ~Array() { delete[] array; }

    Array(Array const &src) : arraySize(src.arraySize) {
      array = new T[src.arraySize];
      for (size_t i = 0; i < src.arraySize; i++) {
        array[i] = src.array[i];
      }
    }

    Array &operator=(Array const &src) {
      if (this != &src) {
        delete[] array;
        arraySize = src.arraySize;
        array = new T[src.arraySize];
        for (size_t i = 0; i < src.arraySize; i++) {
          array[i] = src.array[i];
        }
      }
      return *this;
    }

    T &operator[](size_t i) {
      if (i >= arraySize) {
        throw std::out_of_range("Index out of range");
      }
      return array[i];
    }

    const T &operator[](size_t i) const {
      if (i >= arraySize) {
        throw std::out_of_range("Index out of range");
      }
      return array[i];
    }

    size_t size() const { return arraySize; }
};
