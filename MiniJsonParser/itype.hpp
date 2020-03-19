#ifndef ITYPE_HPP
#define ITYPE_HPP
#include <string>
#include <vector>
using namespace std;
using std::string;

enum class Type
{
	kInteger, kDouble, kString, kBoolean, kArray
};

class IType
{
public:
	virtual ~IType() = default;
	virtual auto ToString()->string = 0 ;
	auto GetType()const->Type { return type_; }

protected:
		 Type type_{};
};


class Integer : public IType
{
public:
	Integer(const int* data)
		: data_(new int(*data)) {type_ =Type::kInteger;}
	~Integer() { delete data_; }
	auto ToString() -> string override
	{
		string str = (data_ != nullptr)
		? std::to_string(*data_) : "null";

		return str;
	}
private:
	int* data_{};
};

class Double : public IType
{
public:
	Double(const double* data)
		: data_(new double(*data)) {
		type_ = Type::kDouble;
	}
	~Double() { delete data_; }
	auto ToString() -> string override
	{
		string str = (data_ != nullptr)
			? std::to_string(*data_) : "null";

		return str;
	}
private:
	double* data_{};	
};

class String : public IType
{
public:
	String(const string* data)
		: data_(new string(*data)) {
		type_= (Type::kString);
	}
	~String() { delete data_; }
	auto ToString() -> string override
	{
		string str = (data_ != nullptr)
			? *data_: "null";

		return str;
	}
private:
	string* data_{};
};

class Boolean : public IType
{
public:
	Boolean(const bool* data)
		: data_(new bool(*data)) {
		type_ = (Type::kBoolean);
	}
	~Boolean() { delete data_; }
	auto ToString() -> string override
	{
		string str = (data_ != nullptr)
			? std::to_string(*data_) : "null";

		return str;
	}
private:
	bool* data_{};
};

class Array : public IType
{
public:
	Array(const vector<IType*> data)
		: data_(data) {
		type_ = (Type::kArray);
	}
			
	~Array()
	{
		auto i = 0;
		for (auto& doc : data_.end)
		{
			delete data_[i];
			++i;
		}
	}
	auto ToString() -> string override
	{
		size_t j = 0;
		for (auto& doc : data_.end)
		{
			string str = (data_[j] != nullptr)
				? std::to_string(*data_) : "null";

			return str;
		}
	}
private:
	vector<IType*> data_{};
};
#endif
