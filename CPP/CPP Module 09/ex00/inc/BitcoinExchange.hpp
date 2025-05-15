/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:05:58 by yboumlak          #+#    #+#             */
/*   Updated: 2025/05/12 23:52:56 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <fstream>

class BitcoinExchange {
  public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    std::map<std::string, double> getExchangeRate() const ;
    void readExchangeRate(const std::string &filename);
    std::map<std::string, double> parseInputFile(std::string &filename);
    void calculateExchangeRate(const std::map<std::string, double> &inputData);
    void processInputFile(const std::string &filename);
  private:
    std::map<std::string, double> exchangeRate;
};