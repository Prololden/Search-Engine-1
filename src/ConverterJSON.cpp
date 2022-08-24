#include "ConverterJSON.h"

std::vector<std::string> ConverterJSON::getTextDocuments() {
	return std::vector<std::string>();
}

std::vector<std::string> ConverterJSON::getRequests() {
	return requests;
}

std::vector<std::string> ConverterJSON::getFiles() {
	return { config["files"].begin(), config["files"].end() };
}

void ConverterJSON::getResponsesLimit() {
	maxResponses = config["config"]["max_responses"].is_null() ? 5 : config["config"]["max_responses"].get<int>();
}

void ConverterJSON::putAnswers(
		std::vector<std::vector<std::pair<int, float>>> answers
	) {

}

void ConverterJSON::readConfig(std::filesystem::path path) {
	try {
		if (!std::filesystem::exists(path))
			throw ExceptionConfigNotFound();
	}
	catch (ExceptionConfigNotFound e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	std::ifstream f(path);
	f >> config;
	f.close();
}

void ConverterJSON::readRequests(std::filesystem::path path) {
	try {
		if (!std::filesystem::exists(path))
			throw ExceptionRequestsNotFound();
	}
	catch (ExceptionRequestsNotFound e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	std::ifstream f(path);
	json _requests;
	f >> _requests;
	requests = { _requests["requests"].begin(), _requests["requests"].end() };
	f.close();
}