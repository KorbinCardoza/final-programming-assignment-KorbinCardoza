#ifndef I_JSON_DOCUMENT
#define I_JSON_DOCUMENT

#include <string>
#include <functional>
using std::string;
using std::function;

class IJsonDocument
{
public:
	virtual auto Insert(const string& key, const string& value) noexcept(false) -> void = 0;
	virtual auto Remove(const string& key) noexcept(false) -> void = 0;
	virtual auto Traverse(const function<void(const string& key, const string& value)>& visit) -> void = 0;
	virtual auto ToString() noexcept -> string = 0;

	virtual ~IJsonDocument() = default;
};



#endif