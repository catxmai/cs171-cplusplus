
#if !defined(VECTOR_H_INCLUDED)
#define VECTOR_H_INCLUDED
#include <string>
#include<iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

template < class T > class Vector;

template <class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v);

template <class T>
class Vector
{
    friend std::ostream& operator<< <>(std::ostream& os, const Vector<T>& v);

public:
    Vector<T>();
    ~Vector<T>();
    void push(T n);
    void push(T a[], int array_size);
    void clear();
    T operator[] (unsigned int index) const;
    T& operator[] (unsigned int index);
    T sum() const;
    void setAt(unsigned int index, const T& item);
    void setAtGrow(unsigned int index, const T& item);
    void minimize();

    inline int size() const { return m_tail; }
    inline bool is_empty() const { return m_tail == 0; }
    inline size_t memUsage() const { return m_alloc; }

private:
    void init(unsigned int size);
    void ensureSize(unsigned int size);
    void doubleSize();
    inline bool is_full() const { return m_tail >= m_alloc; }
    void assertIndex(unsigned int pos) const;

    unsigned int m_alloc;
    unsigned int m_tail;
    T* m_vector;
    static const unsigned int DEFAULT_ALLOC;
};


// Could be inline in class declaration, but here's how this looks if you do it 
// externally
template <class T>
const unsigned int Vector<T>::DEFAULT_ALLOC = 100;

template <class T>
Vector<T>::Vector()
{
    init(DEFAULT_ALLOC);
}

template <class T>
Vector<T>::~Vector()
{
    delete[] m_vector;
}

template <class T>
std::ostream& operator<< <>(std::ostream& os, const Vector<T>& v)
{
    Vector<T> temp = v;
    string items;

    /*for (int i = 0; i < temp.m_tail; ++i) {
        items.append(std::to_string(temp.m_vector[i]));
        items += ",";
    }*/
    os << "S(" << temp.m_tail << "," << temp.m_alloc << ")[";
    for (int i = 0; i < temp.m_tail; ++i) {
        os << temp.m_vector[i] << ",";
    }
    os << "]";
    return os;
}

template <class T>
void Vector<T>::init(unsigned int size)
{
    m_tail = m_alloc = 0;
    m_vector = 0;
    ensureSize(size);
}

template <class T>
void Vector<T>::push(T n)
{
    if (is_full()) {
        doubleSize();
    }
    //cout << "malloc" << m_alloc << "tail" << m_tail;
    m_vector[m_tail++] = n;
}

template <class T>
void Vector<T>::push(T a[], int array_size)
{
    for (int i = 0; i < array_size; ++i) {
        push(a[i]);
    }
}

template <class T>
void Vector<T>::clear() {
    init(DEFAULT_ALLOC);
}

template<class T>
T Vector<T>::operator[](unsigned int index) const
{
    assertIndex(index);
    return m_vector[index];
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    assertIndex(index);
    return m_vector[index];
}

template<class T>
void Vector<T>::setAt(unsigned int index, const T& item)
{
    assertIndex(index);
    m_vector[index] = item;
}

template<class T>
void Vector<T>::setAtGrow(unsigned int index, const T& item)
{
    while (m_alloc < index) {
        doubleSize();
    }
    m_vector[index] = item;
    m_tail = ++index;
}

//template <class T>
//std::ostream& operator<<(std::ostream& os, const Vector<T>& v)


template <class T>
void Vector<T>::assertIndex(unsigned int pos) const {
    if (pos < 0 || pos >= m_tail || m_tail == 0)
        throw std::out_of_range("index out of range");
}

template <class T>
void Vector<T>::minimize() {
    if (m_tail > m_alloc)
        return;
    m_tail = m_tail == 0 ? 1 : m_tail;
    T* pNewVector = new T[m_tail];
    for (unsigned int i = 0; i < m_tail; ++i)
    {
        pNewVector[i] = m_vector[i];
    }
    delete[] m_vector;
    m_alloc = m_tail;
    m_vector = pNewVector;
}

template <class T>
void Vector<T>::ensureSize(unsigned int size)
{
    if (m_alloc >= size)
        return;
    T* pNewVector = new T[size];

    for (unsigned int i = 0; i < m_tail; ++i)
    {
        pNewVector[i] = m_vector[i];
    }
    delete[] m_vector;
    m_alloc = size;
    m_vector = pNewVector;
}

template <class T>
void Vector<T>::doubleSize()
{
    ensureSize(m_alloc * 2);
}

template <class T>
T Vector<T>::sum() const {
    T sum = T();
    for (unsigned int i = 0; i < m_tail; ++i) {
        sum += m_vector[i];
    }
    return sum;
}


#endif // !defined(VECTOR_H_INCLUDED)