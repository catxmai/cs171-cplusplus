#include <iostream>
#include "IntStack.h"

const size_t ARRAY_SIZE = 201;
#define COUNTOF(x) (sizeof (x) / sizeof (x[0]))

int main()
{
	/*{
		std::cout << "TEST CASE 1:" << std::endl;
		IntStack stack(0);
		std::cout << stack.is_empty() << std::endl;
		std::cout << stack.size() << std::endl;
		stack.push(1);
		stack.push(3);
		std::cout << "About to print stack" << std::endl;
		printStack(&stack);
		std::cout << "Finished printing stack" << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.is_empty() << std::endl;
		std::cout << stack.pop() << std::endl;
		stack.reset();
		std::cout << stack.size() << std::endl;
		std::cout << stack.is_empty() << std::endl;
	}

	{
		std::cout << std::endl << "TEST CASE 2:" << std::endl;
		IntStack stack(150);
		std::cout << stack.is_empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.capacity() << std::endl;
		stack.push(7);
		stack.push(10);
		stack.doubleCapacity();
		std::cout << stack.capacity() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.is_empty() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.is_empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.capacity() << std::endl;
	}

	{
		std::cout << std::endl << "TEST CASE 3:" << std::endl;
		IntStack stack;
		stack.doubleCapacity();
		std::cout << stack.capacity() << std::endl;
		std::cout << stack.is_empty() << std::endl;
		stack.reset();

		int values[ARRAY_SIZE];
		size_t i;

		for (i = 0; i < COUNTOF(values); ++i)
		{
			values[i] = i;
			stack.push(i);
		}

		std::cout << stack.size() << std::endl;
		std::cout << stack.capacity() << std::endl;
		std::cout << "About to pop entire stack" << std::endl;

		for (i = 0; i < COUNTOF(values); ++i)
		{
			std::cout << stack.pop() << std::endl;
		}

		std::cout << "Finished popping entire stack" << std::endl;
		std::cout << stack.is_empty() << std::endl;
		stack.push(values, 0);
		std::cout << stack.is_empty() << std::endl;
		stack.push(values, 1);
		std::cout << stack.pop() << std::endl;
		std::cout << stack.is_empty() << std::endl;
		stack.push(values, COUNTOF(values));
		int* values2 = new int[ARRAY_SIZE * 2];
		values2[ARRAY_SIZE * 2 - 2] = 8;
		values2[ARRAY_SIZE * 2 - 1] = 5;
		stack.pop(values2, 0);
		stack.pop(values2, 1);
		stack.pop(&(values2[1]), ARRAY_SIZE - 1);
		std::cout << values2[ARRAY_SIZE * 2 - 2] << std::endl;
		std::cout << values2[ARRAY_SIZE * 2 - 1] << std::endl;
		std::cout << "About to output both value arrays" << std::endl;

		for (i = 0; i < COUNTOF(values); ++i)
		{
			std::cout << values[i] << ' ' << values2[i] << std::endl;
		}

		std::cout << "Finished output of both value arrays" << std::endl;
		delete[] values2;
		values2 = 0;
		stack.push(values, COUNTOF(values));
		stack.push(values, COUNTOF(values));
		std::cout << stack.size() << std::endl;
	}*/

	{
		char* newP = new char[50];
		char strg[] = "this is a string";
		char* ptrr = strg;
		memset(newP, 'a', 1);
		//char* ptr = newP++;
		memcpy(newP++, ptrr, strlen(strg));
		std::cout << newP << std::endl;
	}

	return 0;
}