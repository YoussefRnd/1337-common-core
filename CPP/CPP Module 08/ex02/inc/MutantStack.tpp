/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:43:35 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/11 00:16:13 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

// Constructor
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack() {}

// Copy Constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

// Assignation Operator
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
  if (this != &other) {
    std::stack<T>::operator=(other);
  }
  return *this;
}

// Member Functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
  return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
  return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
  return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
  return std::stack<T>::c.rend();
}
