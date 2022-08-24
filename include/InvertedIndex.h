#pragma once

#include <filesystem>
#include <map>
#include <string>
#include <vector>

using freqType = std::map<std::string, std::vector<Entry>>;

struct Entry {
	size_t docId, count = 0;
	bool operator ==(const Entry& other) const {
		return (docId == other.docId &&
			count == other.count);
	}
};

class InvertedIndex {
public:
	InvertedIndex() = default;
	void updateDocumentBase(std::vector<std::string> inputDocs);

private:
	freqType getWordsInFile(std::string filepath, int idDoc);
	std::vector<std::string> docs;
	freqType freqDict;
};