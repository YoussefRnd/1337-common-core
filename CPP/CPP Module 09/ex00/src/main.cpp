/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:59:24 by yboumlak          #+#    #+#             */
/*   Updated: 2025/05/12 23:51:53 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc == 2) {
    try {
      BitcoinExchange bitcoinExchange;
      std::string filename = argv[1];
      bitcoinExchange.readExchangeRate("data.csv");
      bitcoinExchange.processInputFile(filename);
      
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  return 0;
}