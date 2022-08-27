#include "InvertedIndex.h"
#include "Exceptions.h"

freqType InvertedIndex::getFreqDict() {
	return freqDict;
}

void InvertedIndex::updateDocumentBase(std::vector<std::string> inputDocs) {
	std::vector<std::future<freqType>> res;
	for (size_t i = 0, ie = inputDocs.size(); i != ie; ++i) {
		res.push_back(
			std::async(
				&InvertedIndex::getWords,
				this,
				inputDocs[i],
				static_cast<int>(i)
			)
		);
	}
	for (size_t i = 0, ie = inputDocs.size(); i != ie; ++i) {
		auto r = res[i].get();
		for (auto&& item : r) {
			auto key = item.first;
			auto vec = item.second;
			freqDict[key].insert(freqDict[key].end(), vec.begin(), vec.end());
		}
	}
}
std::vector<Entry> InvertedIndex::getWordCount(const std::string& word) const {
	std::vector<Entry> res{};
	auto it = freqDict.find(word);
	if (it == freqDict.end())
		return res;
	for (auto e : it->second)
		res.push_back(e);
	return res;
}

freqType InvertedIndex::getWords(std::string filepath, int idDoc) const {
	try {
		if (!std::filesystem::exists(filepath))
			throw ExceptionFileNotFound();
	}
	catch (ExceptionFileNotFound e) {
		std::cerr << e.what() << std::endl;
		return freqType();
	}
	freqType res;
	std::ifstream file(filepath);
	if (file.is_open()) {
		std::istream_iterator<std::string> it(file);
		while (it != std::istream_iterator<std::string>()) {
			std::string word = *it;
			std::transform(word.begin(), word.end(), word.begin(), tolower);
			if (res.find(word) == res.end()) {
				res[word].push_back({ idDoc, 0 });
			}
			res[word][0].count++;
			it++;
		}
		file.close();
	}
	return res;
}