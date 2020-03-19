#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <string>
#include <vector>

#include "json_string_extensions.hpp"
#include "json_document.hpp"

using std::cin;
using std::string;


auto main() -> int
{
	{ // Put any code in this scope

		const string sample_json =
R"({
"Array1": [1, 2, 3, 4],
"String": "Hi Mom",
"True": true,
"False": false,
"NULL": null,
"Integer": 123,
"PI": 3.1416,
"Array2": [1, 2, null, 4] 
})";

		const string class_example_json =
R"({
"String": "Hi Mom",
"NULL": null,
"Integer": 123,
})";
		
		auto key_value_pairs = JsonStringExtensions::GetKeyValuePairs(sample_json);

		auto json_document = JsonDocument();
		
		for (auto& pair : key_value_pairs)
		{
			
			json_document.Insert(pair.first, pair.second);
		}
		
		cout << json_document.ToString();
	
	} // end of your code


	// Check for memory leaks
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	cin.get();
	return 0;
}
