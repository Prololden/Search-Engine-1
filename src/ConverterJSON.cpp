#include "ConverterJSON.h"

std::vector<std::string> ConverterJSON::GetTextDocuments() {
	return std::vector<std::string>();
}

int ConverterJSON::GetResponsesLimit() {
	return _config["config"]["max_responses"].is_null() ? 5 : _config["config"]["max_responses"].get<int>();
}

std::vector<std::string> ConverterJSON::GetRequests() {
	return std::vector<std::string>();
}

void ConverterJSON::putAnswers(
		std::vector<std::vector<std::pair<int, float>>> answers
	) {

}

void ConverterJSON::read_config(std::filesystem::path path) {
	try {
		if (!std::filesystem::exists(path))
			throw ExceptionConfigNotFound();
	}
	catch (ExceptionConfigNotFound e) {
		std::cerr << e.what() << std::endl;
	}
	std::ifstream f(path);
	f >> _config;
}

void ConverterJSON::read_requests(std::filesystem::path path) {
	try {
		if (!std::filesystem::exists(path))
			throw ExceptionRequestsNotFound();
	}
	catch (ExceptionRequestsNotFound e) {
		std::cerr << e.what() << std::endl;
	}
	std::ifstream f(path);
	f >> _requests;
}