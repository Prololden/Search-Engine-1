#include "SearchEngine.h"

std::vector<std::vector<RelativeIndex>> SearchServer::search(const
	std::vector<std::string>& queries_input) {
	std::vector<std::vector<RelativeIndex>> res;

	for (auto&& e : queries_input) {
		res.push_back(searchWord(e));
	}
	return res;
}

std::vector<RelativeIndex> SearchServer::searchWord(std::string searchString) {
	std::vector<RelativeIndex> res(maxResponses);
	std::transform(searchString.begin(), searchString.end(), searchString.begin(), tolower);

	std::istringstream str(searchString);
	std::vector<std::string> words = { std::istream_iterator<std::string>(str), std::istream_iterator<std::string>() };
	std::unordered_map<size_t, float> rel;
    float min = 0;

	for (auto& e : words) {
		for (auto& en : index.getWordCount(e)) {
			rel[en.docId] += en.count;
		}
	}

	if (rel.empty())
		return {};

    for (auto&& e : rel)
    {
        if (e.second > min) {
            RelativeIndex rdx = { e.first, e.second };

            for (size_t i = 0, ie = res.size(); i != ie; ++i)
            {
                if (e.second > res[i].rank) {
                    res.insert(res.begin() + i, rdx);
                    break;
                }
            }

            res.pop_back();
            min = res.back().rank;
        }
    }

    float max = res[0].rank;
    for (auto&& i : res)
    {
        i.rank /= max;
        std::stringstream ss;
        ss << std::setprecision(3) << i.rank;
        ss >> i.rank;
    }

	return res;
}

void SearchServer::setMaxResponses(int maxResponse) {
	maxResponses = maxResponse;
}