/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:27:37 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/02 15:05:19 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>

#include <iostream>

void uppercase(char *str) {
  for (int i = 0; str[i]; ++i) {
    str[i] = std::toupper(str[i]);
  }
}

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      uppercase(argv[i]);
      std::cout << argv[i];
    }
  } else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}