/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:54:10 by yboumlak          #+#    #+#             */
/*   Updated: 2025/03/05 00:58:12 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T min(T a, T b) {
  return (a < b ? a : b);
}

template <typename T>
T max(T a, T b) {
  return (a > b ? a : b);
}