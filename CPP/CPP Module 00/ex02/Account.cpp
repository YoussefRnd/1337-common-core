/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:24:23 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/02 13:10:49 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  _accountIndex = _nbAccounts++;
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void) {
  _nbAccounts--;
  _totalAmount -= _amount;
  _totalNbDeposits -= _nbDeposits;
  _totalNbWithdrawals -= _nbWithdrawals;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::_displayTimestamp(void) {
  time_t rawTime;
  struct tm *timeInfo;
  char buffer[20];

  time(&rawTime);
  timeInfo = localtime(&rawTime);
  strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeInfo);
  std::cout << buffer << ' ';
}

int Account::getNbAccounts(void) {
  return _nbAccounts;
}

int Account::getTotalAmount(void) {
  return _totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
  if (_amount < withdrawal) {
    std::cout << ";withdrawal:refused\n";
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << '\n';
  return true;
}

int Account::checkAmount(void) const {
  return _amount;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
}
