#include<iostream> 
#include<fstream> 
#include<string> 
#include "TextUtil.h"

using std::string;
using std::endl;
using std::cout;

int main()
{
	vector<string> testFiles;
	testFiles.push_back("hw4.cpp");
	testFiles.push_back("file2.txt");
	for (std::vector<string>::const_iterator fileIter = testFiles.begin();
		fileIter != testFiles.end();
		fileIter++)
	{
		cout << "****************************************************" << endl;
		cout << "      Results for file: " << *fileIter << endl;
		cout << "****************************************************" << endl;
		TextUtil tu(*fileIter);

		IntPairVector lengths = tu.wordLengths();
		for (IntPairVector::const_iterator iter = lengths.begin(); iter != lengths.end(); iter++)
		{
			cout << iter->second << " words of length " << iter->first << endl;
		}

		vector<string> lookForMe;
		lookForMe.push_back("trailing");
		lookForMe.push_back("ten");
		lookForMe.push_back("the");

		for (std::vector<string>::const_iterator lookIter = lookForMe.begin();
			lookIter != lookForMe.end();
			lookIter++)
		{
			size_t count = tu.wordCount(*lookIter);
			cout << "Found " << count << " occurrances of [" << *lookIter << "]" << endl;
		}

		StringIntVector mostSeen;
		mostSeen = tu.topNWords(10);

		for (StringIntVector::const_iterator topIter = mostSeen.begin();
			topIter != mostSeen.end();
			topIter++)
		{
			cout << topIter->first << " seen " << topIter->second << " times" << endl;
		}
	}

	return 0;
}