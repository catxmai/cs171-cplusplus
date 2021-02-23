#pragma once


class IntStack {
public:
	IntStack(int stackSize=100);
	void reset();
	void push(int n);
	void push(int a[], size_t array_size);
	int pop();
	void pop(int a[], size_t n);
	bool is_full(); bool is_empty();
	void doubleCapacity();
	void doubleStackSize();
	size_t size(); size_t capacity();
	friend void printStack(IntStack* stack);
	~IntStack();
private:
	int* m_internalArray; size_t m_internalArraySize;
	int  m_headIndex;
	int  m_stackSize;
};



