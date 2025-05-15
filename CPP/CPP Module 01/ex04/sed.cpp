/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:44:01 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 18:19:55 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void replaceString(std::string& line, std::string& toSearch, std::string& toReplaceWith) {
  size_t pos = 0;
  if (toSearch.empty()) {
    return;
  }
  while ((pos = line.find(toSearch, pos)) != std::string::npos) {
    line.erase(pos, toSearch.length());
    line.insert(pos, toReplaceWith);
    pos += toReplaceWith.length();
  }
}