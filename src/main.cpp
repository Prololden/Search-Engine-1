#include "ConverterJSON.h"
#include "SearchEngine.h"
int main()
{
	std::filesystem::path cfg("config.json");
	std::filesystem::path req("requests.json");

	ConverterJSON cj;
	cj.getResponsesLimit();
	cj.readConfig(cfg);
	cj.readRequests(req);
}