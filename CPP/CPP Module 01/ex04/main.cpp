/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:16:52 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 18:20:34 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "sed.hpp"

int main(int argc, char **argv) {
  if (argc == 4) {
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
      std::cerr << "Error: Could not open file\n";
      return 1;
    }
    std::ofstream outFile(std::string(argv[1]) + ".replace");
    if (!outFile.is_open()) {
      std::cerr << "Error: Could not open file\n";
      return 1;
    }
    std::string line;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    while (getline(inFile, line)) {
      replaceString(line, s1, s2);
      outFile << line << '\n';
    }
    inFile.close();
    outFile.close();
  } else {
    std::cout << "Usage: <Program name> <Filename> <Search string> <Replace string>\n";
    return 1;
  }
  return 0;
}