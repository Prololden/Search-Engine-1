#pragma once

#include <map>
#include <string>
#include <vector>


struct Entry {
	size_t doc_id, count;
	bool operator ==(const Entry& other) const {
		return (doc_id == other.doc_id &&
			count == other.count);
	}
};

class InvertedIndex {
public:
	InvertedIndex() = default;
	void updateDocumentBase(std::vector<std::string> inputDocs);
	std::vector<Entry> getWordCount(const std::string& word);

private:
	std::vector<std::string> docs;
	std::map<std::string, std::vector<Entry>> freqDict;
};