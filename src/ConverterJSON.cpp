#include "ConverterJSON.h"

std::vector<std::string> ConverterJSON::GetTextDocuments() {
	return std::vector<std::string>();
}

int ConverterJSON::GetResponsesLimit() {
	std::filesystem::path cfg("config.json");
	std::ifstream file(cfg);
	json settings;

	file >> settings;

	return settings["config"]["max_responses"].is_null() ? 5 : settings["config"]["max_responses"].get<int>();
}

std::vector<std::string> ConverterJSON::GetRequests() {
	return std::vector<std::string>();
}

void ConverterJSON::putAnswers(
		std::vector<std::vector<std::pair<int, float>>> answers
	) {

}