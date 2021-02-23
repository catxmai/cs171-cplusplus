#if !defined(TEXT_H_INCLUDED)
#define TEXT_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>


using std::string;
using std::ifstream;
using std::vector;
using std::pair;
using std::map;

typedef map<string, int> StringIntMap;
typedef map<int, int> IntPairMap;
typedef vector< pair < int, int > > IntPairVector;
typedef vector< pair < string, int > > StringIntVector;
class TextUtil
{

    public:
        TextUtil(const string& filename);
        IntPairVector wordLengths() const;
        size_t wordCount(const string& word) const;
        StringIntVector topNWords(size_t n) const;

    private:
       /* IntPairVector m_intVect;
        StringIntVector m_strVect;*/
        StringIntMap m_wordFrequencyMap;
        IntPairMap m_sizeFrequencyMap;
};

#endif // !defined(TEXT_H_INCLUDED)
