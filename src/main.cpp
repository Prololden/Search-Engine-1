#include "ConverterJSON.h"
#include "SearchEngine.h"
int main()
{
	std::filesystem::path cfg("config.json");
	std::filesystem::path req("requests.json");

	if (!std::filesystem::exists(cfg)) {
		std::cerr << "Config file not found" << std::endl;
		return 1;
	}

	if (!std::filesystem::exists(req)) {
		std::cerr << "Requests file not found" << std::endl;
		return 1;
	}

	ConverterJSON CJson;
	std::cout << "Max: " << CJson.GetResponsesLimit() << std::endl;
}