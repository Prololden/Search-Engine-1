#include "ConverterJSON.h"
#include "SearchEngine.h"
#include "InvertedIndex.h"
int main()
{
	std::filesystem::path cfg("config.json");
	std::filesystem::path req("requests.json");

	ConverterJSON cj;
	try {
		cj.readConfig(cfg);
		cj.readRequests(req);
	}
	catch (ExceptionConfigEmpty e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (ExceptionRequestsEmpty e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}
	if (!cj.isConfigOpen() || !cj.isRequestsOpen())
		return 3;
	InvertedIndex idx;
	idx.updateDocumentBase(cj.getFiles());
	auto requests = cj.getRequests();
	SearchServer searchServer(idx);
	searchServer.setMaxResponses(cj.getResponsesLimit());
	auto answers = searchServer.search(requests);
	std::vector<std::vector<std::pair<int, float>>> result;
	size_t count = 0;
	for (size_t i = 0, ie = answers.size(); i != ie; ++i) {
		result.emplace_back();
		for (auto e : answers[i]) {
			result[i].push_back({ static_cast<int>(e.docId), e.rank });
			count++;
		}
	}
	try {
		cj.putAnswers(result);
	}
	catch (ExceptionAnswersNotOpen e) {
		std::cerr << e.what() << std::endl;
		return 4;
	}

	std::cout << "Searching finished. Put answers: " << count << "!" << std::endl;
}