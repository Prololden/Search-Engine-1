#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <nlohmann/json.hpp>
#include "Exceptions.h"

using json = nlohmann::json;

class ConverterJSON {
public:
	ConverterJSON() = default;
	std::vector<std::string> getTextDocuments();
	void getResponsesLimit();
	void putAnswers(std::vector<std::vector<std::pair<int, float>>>
		answers);
	void readConfig(std::filesystem::path path);
	void readRequests(std::filesystem::path path);
private:
	json config;
	std::vector<std::string> requests;
	json answers;
	int maxResponses = 5;
};