#include "EvilHangman.h"

int main()
{
	{
		/*vector<string> vectstr = { "apple", "apple", "ApPle", "yogurt", "jesus", "banana", "abcde" };
		EvilHangman eh(vectstr, 5, 10);

		set<string> words = eh.words();
		cout << words.size() << endl;
		for (string i : words)
		{
			cout << " words is " << i << endl;
		}
		int count = eh.record('A');
		eh.record('p');
		eh.record('h');
		cout << count << endl;
		cout << eh.guessesLeft() << endl;
		cout << eh.currentPattern() << endl;
		set<char> guesses = eh.guesses();
		for (char i : guesses)
		{
			cout << " guesses is " << i << endl;
		}*/
	}

	{
		EvilHangman evil("dictionary.txt", 5, 10);
		//set<string> words = evil.words();
		//cout << words.size() << endl;
		////for (string i : words)
		////{
		////	cout << " words is " << i << endl;
		////}
		//int count = evil.record('A');
		//cout << count << endl;
		//cout << evil.guessesLeft() << endl;
		//cout << evil.currentPattern() << endl;
		//set<char> guesses = evil.guesses();
		//for (char i : guesses)
		//{
		//	cout << " guesses is " << i << endl;
		//}
		playOneRound(&evil);
	}


	return 0;
}