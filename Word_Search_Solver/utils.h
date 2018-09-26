#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cassert>
#include <sstream>
#include <vector>
#include <algorithm>
#include <locale>
#include <set>
#include <sstream>
#include <iomanip>
#include <utility>      // std::pair, std::make_pair
using namespace std;

struct FileOperations {
  static std::string readFileIntoString(const char* fileName) {
    std::fstream textFile;
    std::string puzzleString;
    textFile.open(fileName);
    if(textFile.is_open()) {
      char c;
      int i=0;
      while(textFile >> noskipws >> c) {
        puzzleString += c;
      }
    }
    textFile.close();
    return puzzleString;
  }

  static std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while(std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
    }
    return tokens;
  }

  static std::vector<std::string> readFileIntoStringArray(const char* fileName) {
    std::fstream textFile;
    std::string word = "", wordArray = "";
    textFile.open(fileName);
    if (textFile.is_open()) {
      while(textFile >> word) {
        wordArray += word + " ";
      }
    }
    std::vector<std::string> result = split(wordArray, ' ');
    return result;
  }

  static std::string to_upper(std::string str) {
    std::locale loc;
    std::string result = "";
    for(int i=0; i<str.length(); i++)
      result += toupper(str[i], loc);
    return result;
  }

  static void save_words_to_file(std::vector<std::pair<std::string, std::pair<std::pair<int,int>, std::pair<int,int>>>> word_list) {
    std::ofstream ofile;
    ofile.open("Solved.txt", ofstream::app);
    if(ofile.is_open()){
      std::vector<std::pair<std::string, std::pair<std::pair<int,int>, std::pair<int,int>>>>::iterator it;
      stringstream ss;
      ss <<"\nFound Words\n\n";
      ss <<"Word\t\t\t Word Start\t\t\t Word End\n";
      for(it = word_list.begin(); it  != word_list.end(); it++) {
        ss << it->first;
        pair<pair<int,int>, pair<int,int>> coords = it->second;
        ss <<"\t\t\t["<<coords.first.first<<", "<<coords.first.second<<"]";
        ss <<"\t\t\t["<<coords.second.first<<", "<<coords.second.second<<"]\n";
      }
      ofile << ss.str();
    }
    ofile.close();
  }

};

#endif //UTILS_H
