#if !defined(EVIL_HANGMAN)
#define EVIL_HANGMAN

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <cctype>
#include <locale>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::vector;
using std::pair;
using std::map;
using std::list;
using std::set;
using std::string;


typedef map< string, set < string > > StringSetMap;

class EvilHangman {
public: 
	EvilHangman(const vector<string>& dictionary, unsigned int wordLength, unsigned int maxGuess);
	EvilHangman(const string& dictionaryFileName, unsigned int wordLength, unsigned int maxGuess);
	unsigned int record(const char& guess);
	friend void playOneRound(EvilHangman* dummy);
	
	inline set<string> words() const{ return m_currentWords; };
	inline size_t guessesLeft() const{ return m_numberGuessLeft; };
	inline set<char> guesses() const{ return m_guessedLetter; };
	inline string currentPattern() const{ return m_currentPattern; };


private:
	void init(const vector<string>& dictionary, unsigned int wordLength, unsigned int maxGuess);
	unsigned int m_wordLength, m_numberGuessLeft;
	string m_currentPattern;
	set<char> m_guessedLetter;
	set<string> m_currentWords;
	StringSetMap oneWordProcessing(const char& guess);
	unsigned int findBestPattern(const StringSetMap& myMap);
	inline string lowerCase(const string& str) const {
		string result = str;
		std::transform(result.begin(), result.end(), result.begin(), ::tolower);
		return result;
	};
	inline char asciiLowerCase(const char& chr) const {
		char temp = chr;
		return char(tolower(temp));
	};
};

#endif

