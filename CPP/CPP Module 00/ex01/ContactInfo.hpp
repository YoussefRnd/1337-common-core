/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:24:35 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/02 15:22:16 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTINFO_HPP
#define CONTACTINFO_HPP

#include <string>

class ContactInfo {
 private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

 public:
  void setFirstName(const std::string &firstName) { this->firstName = firstName; }
  void setLastName(const std::string &lastName) { this->lastName = lastName; }
  void setNickname(const std::string &nickname) { this->nickname = nickname; }
  void setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
  void setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }

  std::string getFirstName(void) { return firstName; }
  std::string getLastName(void) { return lastName; }
  std::string getNickname(void) { return nickname; }
  std::string getPhoneNumber(void) { return phoneNumber; }
  std::string getDarkestSecret(void) { return darkestSecret; }
};

#endif
