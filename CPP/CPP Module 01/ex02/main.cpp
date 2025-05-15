/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:21:51 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/03 20:29:46 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << &str << '\n';
  std::cout << &stringPTR << '\n';
  std::cout << &stringREF << "\n\n";

  std::cout << str << '\n';
  std::cout << *stringPTR << '\n';
  std::cout << stringREF << '\n';
}