/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:43:57 by yboumlak          #+#    #+#             */
/*   Updated: 2025/05/12 23:50:54 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : exchangeRate(other.exchangeRate) {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    this->exchangeRate = other.exchangeRate;
  }
  return *this;
}

std::map<std::string, double> BitcoinExchange::getExchangeRate() const {
  return exchangeRate;
}

bool isValidDateFormat(const std::string &date) {
  std::istringstream dateStream(date);
  std::string yearStr, monthStr, dayStr;

  if (std::getline(dateStream, yearStr, '-') &&
      std::getline(dateStream, monthStr, '-') &&
      std::getline(dateStream, dayStr)) {
    std::istringstream yearStream(yearStr), monthStream(monthStr), dayStream(dayStr);
    int year, month, day;
    yearStream >> year;
    monthStream >> month;
    dayStream >> day;

    if (!yearStream.fail() && !monthStream.fail() && !dayStream.fail() &&
        year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
      return true;
    }
  }

  return false;
}

std::map<std::string, double> BitcoinExchange::parseInputFile(std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  std::map<std::string, double> inputData;
  std::string line;
  bool isFirstLine = true;

  while (std::getline(file, line)) {
    if (isFirstLine) {
      isFirstLine = false;
      continue;
    }

    std::istringstream lineStream(line);
    std::string date;
    std::string valueStr;

    if (std::getline(lineStream, date, '|') && std::getline(lineStream, valueStr)) {
      date.erase(date.find_last_not_of(" \t") + 1);
      valueStr.erase(0, valueStr.find_first_not_of(" \t"));

      if (!isValidDateFormat(date)) {
        std::cerr << "Error: Invalid date format in line: " << line << std::endl;
        continue;
      }

      std::istringstream valueStream(valueStr);
      double value;
      valueStream >> value;

      if (valueStream.fail() || !valueStream.eof()) {
        std::cerr << "Error: Invalid value format in line: " << line << std::endl;
        continue;
      }

      else if (value < 0) {
        std::cerr << "Error: Negative value in line: " << line << std::endl;
        continue;
      }

      else if (value > 1000) {
        std::cerr << "Error: Value too large in line: " << line << std::endl;
        continue;
      }

      inputData[date] = value;

    } else {
      std::cerr << "Error: Invalid line format: " << line << std::endl;
    }
  }

  return inputData;
}

void BitcoinExchange::readExchangeRate(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  std::string line;
  bool isFirstLine = true;

  while (std::getline(file, line)) {
    if (isFirstLine) {
      isFirstLine = false;
      continue;
    }

    std::istringstream lineStream(line);
    std::string key;
    std::string valueStr;

    if (std::getline(lineStream, key, ',') && std::getline(lineStream, valueStr)) {
      std::istringstream valueStream(valueStr);
      double value;
      valueStream >> value;

      if (valueStream.fail() || !valueStream.eof()) {
        std::cerr << "Error: Invalid rate format in line: " << line << std::endl;
        continue;
      }

      exchangeRate[key] = value;

    } else {
      std::cerr << "Error: Invalid line format: " << line << std::endl;
    }
  }
}

void BitcoinExchange::calculateExchangeRate(const std::map<std::string, double> &inputData) {
  std::map<std::string, double>::const_iterator it;
  for (it = inputData.begin(); it != inputData.end(); ++it) {
    std::string date = it->first;
    double value = it->second;

    std::map<std::string, double>::const_iterator rateIt = exchangeRate.lower_bound(date);
    if (rateIt != exchangeRate.end()) {
      double rate = rateIt->second;
      std::cout << date << " => " << value << " = " << value * rate << std::endl;
    } else {
      std::cerr << "Error: No exchange rate found for date: " << date << std::endl;
    }
  }
}

void BitcoinExchange::processInputFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  std::string line;
  bool isFirstLine = true;

  while (std::getline(file, line)) {
    if (isFirstLine) {
      isFirstLine = false;
      continue;
    }

    std::istringstream lineStream(line);
    std::string date;
    std::string valueStr;

    if (std::getline(lineStream, date, '|') && std::getline(lineStream, valueStr)) {
      date.erase(date.find_last_not_of(" \t") + 1);
      valueStr.erase(0, valueStr.find_first_not_of(" \t"));

      if (!isValidDateFormat(date)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        continue;
      }

      std::istringstream valueStream(valueStr);
      double value;
      valueStream >> value;

      if (valueStream.fail() || !valueStream.eof()) {
        std::cerr << "Error: bad input => " << line << std::endl;
        continue;
      }

      if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        continue;
      }

      if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        continue;
      }

      // Find the exchange rate for the date
      std::map<std::string, double>::const_iterator rateIt = exchangeRate.lower_bound(date);
      if (rateIt != exchangeRate.end()) {
        double rate = rateIt->second;
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
      } else {
        std::cerr << "Error: No exchange rate found for date: " << date << std::endl;
      }

    } else {
      std::cerr << "Error: Invalid line format: " << line << std::endl;
    }
  }
}
