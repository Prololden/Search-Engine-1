#include "ConverterJSON.h"
#include "SearchEngine.h"
#include "InvertedIndex.h"
int main()
{
	std::filesystem::path cfg("../config.json");
	std::filesystem::path req("../requests.json");

	ConverterJSON cj;
	cj.getResponsesLimit();
	cj.readConfig(cfg);
	cj.readRequests(req);
	InvertedIndex idx;
	idx.updateDocumentBase(cj.getFiles());
	auto t = idx.getWordCount(cj.getRequests()[0]);
	std::cout << t[0].docId << " " << t[0].count << std::endl;
}