#ifndef JSON_DOCUMENT_HPP
#define JSON_DOCUMENT_HPP
#include "ijson_document.hpp"
#include "itype.hpp"
#include <vector>

class JsonDocument : public IJsonDocument
{
public:
	// Your canonical member functions here


	// Member functions you need to override from the interface
	auto Insert(const string& key, const string& value) noexcept(false) -> void override;
	auto Remove(const string& key) noexcept(false) -> void override;
	auto ToString() noexcept -> string override;
	auto Traverse(const function<void(const string& key, const string& value)>& visit) -> void override;
	~JsonDocument() override;

private:
	vector<pair<string, IType*>> document;
};


inline auto JsonDocument::Insert(const string& key, const string& value) noexcept(false) -> void
{
	IType* data = nullptr;
	if (value.find('\"', 0) == string::npos)
	{
		data = new String(&value);
	}
	else if (value.find('.', 0) == string::npos)
	{
		double  double_value = std::stod(value);
		data = new Double(&double_value);
	}
	else if (!value.empty() && isdigit(value[0]) != 0)
	{
		auto isInteger = false;
		
			int interger_value = std::stoi(value);
			data = new Integer(&interger_value);		
	}
	else if(value.find(true))
	{
		
	}

	document.emplace_back(key, data);
	//1. Determine what value is.
}

inline auto JsonDocument::Remove(const string& key) noexcept(false) -> void
{
	size_t j = 0;
	for (auto i = document.begin(); i != document.end(); ++i)
	{
		if (document[j] == key)
		{
			document.erase(i);
		}
		++j;
	}

}

inline auto JsonDocument::ToString() noexcept -> string
{
	string var = "{";
	for (auto& doc : document)
	{
		var += doc.first;
		var += " : ";
		var +=  doc.second->ToString();
	}
	var += "}";
	return var;
	
}

inline auto JsonDocument::Traverse(const function<void(const string & key, const string & value)>& visit) -> void
{
	for (auto& doc : document)
	{
		visit(doc.first, doc.second->ToString());	
	}
}

inline JsonDocument::~JsonDocument()
{
	for (auto& doc : document)
	{
		delete doc.second;
	}
}
#endif
