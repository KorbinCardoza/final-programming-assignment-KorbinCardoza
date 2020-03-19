#include "pch.h"
#include "CppUnitTest.h"

#include <utility>
#include <string>
#include "json_document.hpp"
#include "json_string_extensions.hpp"

using std::pair;
using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(MiniJsonParserTest)
	{
	public:
		TEST_METHOD(TestStart)
		{
			auto actual = vector<pair<string, string>>();
			const auto visit = [&actual](const string& key, const string& value) { actual.emplace_back(key, value); };

			auto key_value_pairs = JsonStringExtensions::GetKeyValuePairs(sample_json_);

			auto json_document = JsonDocument();

			for (const auto& pair : key_value_pairs)
			{
				//code below will throw an exception until implemented
				//json_document.Insert(pair.first, pair.second);
			}
		}

	private:

		const string sample_json_ =
R"({
"AString": "DoubleQuotedText",
"ABoolean": true,
"AnotherBoolean": false,
"AStringSetAsNull": null,
"AnInt": 123,
"ADouble": 3.1416,
"Array1": [1, 2, null, 4],
"Array2": ["An", "array", "of", "strings"],
"Array3": [3.14, 3.14, null, null],
})";
	};
}
