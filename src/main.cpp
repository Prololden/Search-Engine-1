#include "ConverterJSON.h"
#include "SearchEngine.h"
#include "InvertedIndex.h"
int main()
{
	std::filesystem::path cfg("config.json");
	std::filesystem::path req("requests.json");

	ConverterJSON cj;
	cj.getResponsesLimit();
	cj.readConfig(cfg);
	cj.readRequests(req);
	InvertedIndex idx;
	idx.updateDocumentBase(cj.getFiles());
	auto requests = cj.getRequests();
	SearchServer searchServer(idx);
	searchServer.setMaxResponses(cj.getResponsesLimit());
	auto answers = searchServer.search(requests);
	std::vector<std::vector<std::pair<int, float>>> result;
	for (size_t i = 0, ie = answers.size(); i != ie; ++i) {
		result.emplace_back();
		for (auto e : answers[i])
			result[i].push_back({ e.docId, e.rank });
	}
	cj.putAnswers(result);
}