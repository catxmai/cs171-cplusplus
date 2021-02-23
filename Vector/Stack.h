// Stack.h: interface and implementation for the Stack class template.
//
//////////////////////////////////////////////////

#if !defined(STACK_H_INCLUDED)
#define STACK_H_INCLUDED

#include<iostream>
using std::cerr;
using std::cout;
using std::endl;

template < class T >
class Stack;

template <class T>
void printStack(Stack<T>* pStack);

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& pStack);


template < class T >
class Stack
{
    friend void printStack <>(Stack<T>*);
    friend std::ostream& operator<< <>(std::ostream& os, const Stack<T>& pStack);

public:
    Stack<T>();
    explicit Stack<T>(unsigned int n);
    Stack<T>(const Stack<T>& other);
    ~Stack<T>();
    Stack<T>& operator= (const Stack<T>& other);

    inline int size() const { return m_top; }
    inline bool is_empty() const { return m_top == 0; }
    inline int allocSize() const { return m_alloc; }

    T pop();
    void push(const T& item);
    inline void reset() { m_top = 0; };
private:
    void init(unsigned int size);
    void ensureSize(unsigned int size);
    void doubleSize();
    inline bool is_full() const { return m_top >= m_alloc; }

    unsigned int m_alloc;
    unsigned int m_top;
    T* m_stack;
    static const unsigned int DEFAULT_ALLOC;
};


// Could be inline in class declaration, but here's how this looks if you do it 
// externally
template <class T>
const unsigned int Stack<T>::DEFAULT_ALLOC = 100;

template <class T>
Stack<T>::Stack()
{
    init(DEFAULT_ALLOC);
}


template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& pStack)
{
    return os;
}

template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    init(DEFAULT_ALLOC);
    *this = other;
}

template <class T>
Stack<T>::Stack(unsigned int n)
{
    if (n < DEFAULT_ALLOC)
    {
        n = DEFAULT_ALLOC;
    }
    init(n);
}


template <class T>
Stack<T>::~Stack()
{
    delete[] m_stack;
}


template <class T>
void Stack<T>::init(unsigned int size)
{
    m_top = m_alloc = 0;
    m_stack = 0;
    ensureSize(size);
}

template <class T>
void Stack<T>::push(const T& item)
{
    if (is_full())
    {
        doubleSize();
    }
    m_stack[m_top++] = item;
}


template <class T>
T Stack<T>::pop()
{
    if (is_empty())
    {
        cerr << "Pop failed, stack is empty." << endl;
        return T();
    }
    return m_stack[--m_top];
}


template <class T>
Stack<T>& Stack<T>::operator= (const Stack<T>& other)
{
    if (this == &other) return *this;
    ensureSize(other.m_top);

    for (unsigned int i = 0; i < other.m_top; i++)
    {
        m_stack[i] = other.m_stack[i];
    }
    m_top = other.m_top;
    return *this;
}















template <class T>
void Stack<T>::ensureSize(unsigned int size)
{
    if (m_alloc >= size)
        return;
    T* pNewStack = new T[size];

    for (unsigned int i = 0; i < m_top; i++)
    {
        pNewStack[i] = m_stack[i];
    }
    delete[] m_stack;
    m_alloc = size;
    m_stack = pNewStack;
}


template <class T>
void Stack<T>::doubleSize()
{
    ensureSize(m_alloc * 2);
}


template <class T>
void printStack(Stack<T>* pStack)
{
    cout << "Stack with " << pStack->size() << " elements: " << endl;
    for (unsigned int i = 0; i < pStack->m_top; i++)
    {
        if ((i % 10) == 0)
            cout << endl;
        cout << pStack->m_stack[i] << " ";
    }
    cout << endl;
}

#endif // !defined(STACK_H_INCLUDED)
