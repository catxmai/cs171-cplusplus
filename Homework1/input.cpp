// input.cpp : Simple (cooperative) user input

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main(int argc, char* argv[])
{

	cout << "Enter several integers, separated by whitespace\nand type x when you finish" << endl;

	int sum = 0;
	int val = 0;
	int count = 0;

	// This reads until it fails, when user types something not
	// readable as an int (or eof in case of file redirection).
	while (cin >> val)
	{
		sum += val;
		count++;
	}

	cout << "The average is " << (sum/count) << endl;
	return 0;
}


