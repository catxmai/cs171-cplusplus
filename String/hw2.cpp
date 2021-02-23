#include <iostream>
#include "String.h"
#include <string>

int main()
{
	
	{
		std::cout << "Hello" << std::endl;
		std::cout << "TEST CASE 1:" << std::endl;
		const String string;
		std::cout << string.length() << std::endl;
		std::cout << (string < "foo") << std::endl;
		std::cout << (string == "") << std::endl;
		
	}

    {
	    std::cout << std::endl << "TEST CASE 2:" << std::endl;
	    String ditty ("Are you sleeping?\n");
	    ditty += ditty;
	    String string2 = "Brother John?\n";
	    string2.append (string2);
	    String string3;
	    string3 = "Morning bells are ringing.\n";
	    string3 += string3;
	    String string4 ("Ding dang dong.\n");
	    string4.append (string4);
	    ((ditty += string2) += string3) += string4;
	    ditty += "\n";
	    ditty.append ("\n");
	    std::cout << ditty;
	    ditty = "";
	    ditty = String ('p', 0);
	    std::cout << ditty;
	    String verseA = " bottles of beer on the wall.\n";
	    String verseB = " bottles of beer.\nYou take one down, pass it around,\n";
	    String verse;
		  
	    for (int i = 99; i > 96; --i)
	    {
		    char number1 [3];
		    char number2 [3];
        sprintf (number1, "%d", i);
        sprintf (number2, "%d", i - 1);
		    verse = "\n";

		    verse.append (number1).append (verseA).append (number1).append (
			    verseB).append (number2).append (verseA);

		    ditty += verse;
	    }
		  
	    ditty.append (String ('z', 15));
	    ditty += "...\n";
	    std::cout << ditty;
	    std::cout << (ditty < ditty) << std::endl;
	    std::cout << (ditty < "99 bottles of beer on the wall.") << std::endl;
	    std::cout << (ditty < "") << std::endl;
	    std::cout << (ditty == ditty) << std::endl;
	    std::cout << ditty.length() << std::endl;
	    String copy (ditty);
	    ditty = ditty;
	    std::cout << (ditty == copy) << std::endl;
    }

	{

		std::cout << std::endl << "TEST CASE 3:" << std::endl;
		const String string("Substring test");
		std::cout << string.substr(0, 0) << std::endl;

		std::cout << string.substr(0, 0xFFFFFFFF) << std::endl;
		std::cout << string.substr(1, 0) << std::endl;
		std::cout << string.substr(1, 1) << std::endl;

		std::cout << string.substr(2, 7) << std::endl;
		std::cout << string.substr(7, 15) << std::endl;
		
		/*
		std::cout << string.substr(15, 5) << std::endl;


		std::cout << string.substr (15, 0xFFFFFFFF) << std::endl;


		*/
		int i;
		std::cin >> i;
	}
	
    
	return 0;
}
