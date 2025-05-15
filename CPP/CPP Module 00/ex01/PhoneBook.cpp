/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:25:47 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/03 17:21:42 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <sstream>

void PhoneBook::setContact(int index, const ContactInfo& contact) {
  if (index >= 0 && index < 8) {
    contacts[index] = contact;
  }
}

ContactInfo PhoneBook::getContact(int index) {
  return contacts[index];
}

void PhoneBook::add(void) {
  ContactInfo contact;
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
  static int nextIndex = 0;

  std::cout << "Enter the first name: ";
  std::getline(std::cin, firstName);
  if (firstName.empty()) {
    std::cout << "First name cannot be empty. Please try again.\n";
    return;
  }
  contact.setFirstName(firstName);

  std::cout << "Enter the last name: ";
  std::getline(std::cin, lastName);
  if (lastName.empty()) {
    std::cout << "Last name cannot be empty. Please try again.\n";
    return;
  }
  contact.setLastName(lastName);

  std::cout << "Enter the nickname: ";
  std::getline(std::cin, nickname);
  if (nickname.empty()) {
    std::cout << "Nickname cannot be empty. Please try again.\n";
    return;
  }
  contact.setNickname(nickname);

  std::cout << "Enter the phone number: ";
  std::getline(std::cin, phoneNumber);
  if (phoneNumber.empty()) {
    std::cout << "Phone number cannot be empty. Please try again.\n";
    return;
  }
  contact.setPhoneNumber(phoneNumber);

  std::cout << "Enter the darkest secret: ";
  std::getline(std::cin, darkestSecret);
  if (darkestSecret.empty()) {
    std::cout << "Darkest secret cannot be empty. Please try again.\n";
    return;
  }
  contact.setDarkestSecret(darkestSecret);

  setContact(nextIndex, contact);
  nextIndex = (nextIndex + 1) % 8;

  std::cout << "Contact added successfully!\n";
}

std::string formatColumn(const std::string& str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  } else {
    return std::string(10 - str.length(), ' ') + str;
  }
}

void printContactSummary(ContactInfo contact, int index) {
  std::stringstream ss;
  ss << index;
  std::string str = ss.str();
  std::cout << "|" << formatColumn(str)
            << "|" << formatColumn(contact.getFirstName())
            << "|" << formatColumn(contact.getLastName())
            << "|" << formatColumn(contact.getNickname())
            << "|" << '\n';
}

void PhoneBook::search(void) {
  std::string input;
  int index;

  std::cout << "|" << formatColumn("Index")
            << "|" << formatColumn("First name")
            << "|" << formatColumn("Last name")
            << "|" << formatColumn("Nickname")
            << "|" << '\n';

  for (int i = 0; i < 8; ++i) {
    if (!getContact(i).getFirstName().empty())
      printContactSummary(getContact(i), i);
  }
  std::cout << "Enter the index of the contact you want to display: ";
  std::getline(std::cin, input);
  std::stringstream ss(input);
  if (ss >> index && ss.eof()) {
    if (index >= 0 && index < 8) {
      if (!getContact(index).getFirstName().empty())
        printContactSummary(getContact(index), index);
      else {
        std::cout << "Invalid index. Contact is empty.\n";
      }
    } else {
      std::cout << "Invalid index. Please enter a number between 0 and 7.\n";
    }
  } else {
    std::cout << "Invalid input. Please enter a single integer.\n";
  }
}

int main(void) {
  PhoneBook contact;
  std::string cmd;
  std::cout << "Welcome to the PhoneBook application!\n";
  std::cout << "Please enter one of the following commands:\n";
  std::cout << "1 - ADD: Add a new contact\n";
  std::cout << "2 - SEARCH: Search for a contact\n";
  std::cout << "3 - EXIT: Exit the application\n";
  while (true) {
    std::cout << "Enter your command: ";
    std::getline(std::cin, cmd);
    if (cmd == "1" || cmd == "ADD") {
      contact.add();
    } else if (cmd == "2" || cmd == "SEARCH") {
      contact.search();
    } else if (cmd == "3" || cmd == "EXIT") {
      std::cout << "Exiting the application. Goodbye!\n";
      return 0;
    } else {
      std::cout << "Invalid command. Please try again.\n";
    }
  }
  return 0;
}