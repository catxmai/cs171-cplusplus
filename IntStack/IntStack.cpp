// IntStack.cpp :
//

#include <iostream>
#include "IntStack.h"
#include <assert.h>

IntStack::IntStack(int stackSize) {
	if (stackSize == 0){
		stackSize++;
	}
	m_internalArray = new int[stackSize];
	m_internalArraySize = stackSize;
	m_headIndex = -1;
	m_stackSize = stackSize;
}

void IntStack::push(int n) {
	if (is_full()) {
		doubleStackSize();
	}
	m_internalArray[++m_headIndex] = n;
}

void IntStack::push(int a[], size_t array_size) {
	for (int i = 0; i < array_size; i++) {
		push(a[i]);
	}
}

int IntStack::pop() {
	return m_internalArray[m_headIndex--];
}

void IntStack::pop(int a[], size_t n) {
	for (int i = 0; i < n; i++) {
		a[i] = pop();
	}
}

bool IntStack::is_full() {
	return size() == m_stackSize;
}

bool IntStack::is_empty() {
	return m_headIndex == -1;
}

//size is number of elements
size_t IntStack::size() {
	return m_headIndex + 1;
}

//size of internal array
size_t IntStack::capacity() {
	return m_internalArraySize;
}

void IntStack::doubleCapacity() {
	int* temp = new int[size()*2];
	for (int i = 0; i < size(); i++) {
		temp[i] = m_internalArray[i];
	}
	delete[] m_internalArray;
	m_internalArray = temp;
	m_internalArraySize = m_internalArraySize * 2;
}

//double stack size, if reach capacity, double internal array size
void IntStack::doubleStackSize() {
	m_stackSize = m_stackSize * 2;
	if (m_stackSize >= capacity()) {
		doubleCapacity();
	}
}

void IntStack::reset() {
	delete[] m_internalArray;
	m_internalArray = new int[1];
	m_internalArraySize = 1;
	m_headIndex = -1;
}

IntStack::~IntStack() {
	delete[] m_internalArray;
}

void printStack(IntStack* stack) {
	for (int i = stack->size(); i > 0; i--){
		std::cout << stack->m_internalArray[i-1] << std::endl;
	}
}
