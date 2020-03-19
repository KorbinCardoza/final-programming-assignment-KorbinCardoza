#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <locale>
#include <iterator>

using std::list;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::stringstream;
using std::vector;
using std::istringstream;
using std::endl;

	// NOTE:  DO NOT IMPLEMENT THE FOLLOWING FUNCTIONS
	// They are implemented for you.  You can call JsonStringExtensions::GetKeyValuePairs
	// from main or your test

class JsonStringExtensions
{
public:
	static auto GetKeyValuePairs(const string& json)->vector<pair<string, string>>;
private:
	static auto Trim(std::string str)->std::string;
	static auto Split(const string& line, const char& delimeter, std::back_insert_iterator<vector<string>> result) -> void;
	static auto Split(const string& line, const char& delimeter)->pair<string, string>*;
};


#endif

