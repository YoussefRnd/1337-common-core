/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:47:23 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/02 15:24:29 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

#include "ContactInfo.hpp"

class PhoneBook {
 private:
  ContactInfo contacts[8];

 public:
  void setContact(int index, const ContactInfo &contact);
  ContactInfo getContact(int index);
  void add(void);
  void search(void);
};

#endif