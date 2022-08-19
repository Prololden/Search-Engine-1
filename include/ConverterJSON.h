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
	std::vector<std::string> GetTextDocuments();
	int GetResponsesLimit();
	std::vector<std::string> GetRequests();
	void putAnswers(std::vector<std::vector<std::pair<int, float>>>
		answers);
	void read_config(std::filesystem::path path);
	void read_requests(std::filesystem::path path);
private:
	json _config;
	json _requests;
	json _answers;
};