#include "EvilHangman.h"
#include <ctype.h>

typedef StringSetMap::const_iterator StrSetMapIter;

EvilHangman::EvilHangman(const vector<string>& dictionary, unsigned int wordLength, unsigned int maxGuess)
{
    init(dictionary, wordLength, maxGuess);
}

EvilHangman::EvilHangman(const string& dictionaryFileName, unsigned int wordLength, unsigned int maxGuess)
{
    ifstream file(dictionaryFileName);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << dictionaryFileName << endl;
    }
    string word;
    vector<string> dict;
    while (file >> word)
    {
        dict.push_back(word);
    }
    file.close();
    init(dict, wordLength, maxGuess);
}

void EvilHangman::init(const vector<string>& dictionary, unsigned int wordLength, unsigned int maxGuess)
{
    m_currentPattern = "";
    m_wordLength = wordLength;
    m_numberGuessLeft = maxGuess;

    //adding words by length specified
    for (string i : dictionary) {
        if (i.length() == wordLength)
            m_currentWords.insert(lowerCase(i));
    }
    //create pattern
    m_currentPattern.assign(wordLength, '-');
}

unsigned int EvilHangman::record(const char& guess)
{
    char tempGuess = asciiLowerCase(guess);
    if (m_numberGuessLeft < 1 || m_currentWords.size() == 0)
        throw std::invalid_argument("Guess < 1 or word list null");
   /* if (m_guessedLetter.count(guess) && m_currentWords.size()==0)
        throw std::invalid_argument("Already used character");*/

    int occurence;

    m_guessedLetter.insert(tempGuess);
    --m_numberGuessLeft;
    StringSetMap myMap = oneWordProcessing(tempGuess);
    occurence = findBestPattern(myMap);

    return occurence;
}

//process one word: sorting its pattern into a map
//return a map of patterns mapped to a set of words
StringSetMap EvilHangman::oneWordProcessing(const char& guess)
{
    string patternTemp = "";
    StringSetMap myMap;

    for (string i : m_currentWords) {

        patternTemp = "";
        //sorting words into its respective pattern, eg golf, guess = 'o', pattern = "-o--"
        for (unsigned j = 0; j < i.length(); ++j) {
            if (i.at(j) == guess)
                patternTemp += guess;
            else patternTemp += "-";
        }

        //create a map where key = pattern, value = set of words matching the pattern
        if (myMap.count(patternTemp))
            myMap[patternTemp].insert(i);
        else {
            set<string> tempSet;
            tempSet.insert(i);
            myMap[patternTemp] = tempSet;
        }
    }
    return myMap;
}

unsigned int EvilHangman::findBestPattern(const StringSetMap& myMap)
{
    string bestPattern = "";
    string temp = "";
    unsigned tempSize = 0;
    unsigned occurence = 0;

    //finding the pattern that has the most words
    for (StrSetMapIter mapIter = myMap.begin();
        mapIter != myMap.end();
        ++mapIter) {
        string key = mapIter->first;
        set<string> val = mapIter->second;
        if (val.size() > tempSize) {
            tempSize = val.size();
            bestPattern = mapIter->first;
        }
    }

    // merging currentPattern and the best pattern in each round
    for (unsigned j = 0; j < m_wordLength; ++j) {
        if (m_currentPattern.at(j) != '-')
            temp += m_currentPattern.at(j);
        if (bestPattern.at(j) != '-') {
            temp += bestPattern.at(j);
            ++occurence; //counting the occurence of the guessed character    
        }
        else if (m_currentPattern.at(j) == '-' && bestPattern.at(j) == '-')
            temp += "-";
    }
    //update the game fields
    m_currentPattern = temp;
    m_currentWords = myMap.at(bestPattern);

    return occurence;
}

void playOneRound(EvilHangman* dummy)
{
    cout << "EVIL HANGMAN GAME" << endl;
    string filename;
    unsigned int wordLength, maxGuess, dictSize = 0;
    
    while (dictSize == 0) {
        cout << "Enter dictionary file name: " << endl;
        cin >> filename;
        cout << "Enter word length: " << endl;
        cin >> wordLength;
        cout << "Enter how many number of guesses allowed: " << endl;
        cin >> maxGuess;
        EvilHangman evil(filename, wordLength, maxGuess);
        set<string> words = evil.words();
        dictSize = words.size();
    }
    EvilHangman evil(filename, wordLength, maxGuess);
    bool continueGame = true;
    while (evil.guessesLeft() > 0 && continueGame) {
        set<char> guesses = evil.guesses();
        cout << endl;
        cout << endl;
        cout << " You have guessed: ";
        for (char i : guesses)
        {
             cout << i;
        }
        cout << endl << "current pattern: " << evil.currentPattern() << endl;
        cout << "Remaining guesses: " << evil.guessesLeft() << endl;
        cout << "Your guess?" << endl;
        char ch;
        cin >> ch;
        if (guesses.find(ch) != guesses.end()) {
            cout << "You already guessed that" << endl;
        }
        else if (!isalpha(ch)) {
            cout << "Only character guesses" << endl;
        }
        else {
            int count = evil.record(ch);
            if (count == 0) {
                cout << "Sorry, there are no " << ch << "'s" << endl;
            }
            else if (count == 1) {
                cout << "Yes, there is one " << ch << endl;
            }
            else {
                cout << "Yes, there are " << count << " " << ch << "'s" << endl;
            }
        }
        continueGame = evil.currentPattern().find('-') != std::string::npos;
    }
    bool lose = evil.currentPattern().find('-') != std::string::npos;
    if (lose) {
        cout << "Sorry you lose!" << endl;
    }
    else {
        cout << "You won!" << endl;
    }
    
}


