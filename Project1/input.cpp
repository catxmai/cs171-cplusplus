// input.cpp : Simple (cooperative) user input

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main(int argc, char* argv[])
{
	cout << "Please type in an integer now...";
	int val = 0;
	// This may fail, in which case val will still be 0
	cin >> val;

	cout << "You typed in " << val << endl;

	cout << "Now enter several integers, separated by whitespace\nand type x when you finish" << endl;

	int sum = 0;

	// This reads until it fails, when user types something not
	// readable as an int (or eof in case of file redirection).
	while (cin >> val)
	{
		sum += val;
	}

	cout << "That adds up to " << sum << endl;
	return 0;
}

