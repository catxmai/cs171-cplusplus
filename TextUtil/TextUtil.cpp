#include "TextUtil.h"
#include <algorithm>
#include <regex>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;
using std::sort;

typedef StringIntMap::const_iterator StrMapIter;
typedef IntPairMap::const_iterator IntMapIter;


TextUtil::TextUtil(const string& filename) {
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Failed to open file: " << filename << endl;
	}
	string word;
	std::regex regexp("[A-Za-z].*[A-Za-z]");
	std::smatch match;
	while (file >> word) {
		if (std::regex_search(word, match, regexp)) {
			string temp;
			temp = match[0];
			//cout << "match is " << temp << std::endl;
			m_wordFrequencyMap[temp]++;
			m_sizeFrequencyMap[temp.length()]++;
		}
	}
	file.close();
}

IntPairVector TextUtil::wordLengths() const {
	IntPairVector result;

	for (IntMapIter mapIter = m_sizeFrequencyMap.begin();
		mapIter != m_sizeFrequencyMap.end();
		++mapIter) {
		result.push_back(std::make_pair(mapIter->first, mapIter->second));
	}
	return result;
}

size_t TextUtil::wordCount(const string& word) const {
	StrMapIter result = m_wordFrequencyMap.find(word);
	if (result == m_wordFrequencyMap.end())
		return 0;
	return m_wordFrequencyMap.at(word);
}

bool compareValue(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

StringIntVector TextUtil::topNWords(size_t n) const {
	StringIntVector topN(n);

	std::partial_sort_copy(
		m_wordFrequencyMap.begin(),
		m_wordFrequencyMap.end(),
		topN.begin(),
		topN.end(),
		compareValue);
		
	return topN;
}