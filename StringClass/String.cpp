#include <stdlib.h>
#include <string.h>
#include "String.h"


String::String()
{
    init();
}

String::String(const char* s)
{
    init();
    append(s);
}

String::String(const String& s)
{
    init();
    append(s);
}

String::String(char ch, size_t count /* = 1 */)
{
    init();
    ensureSize(count);
    memset(m_buffer, ch, count);
    m_length = count;
}

String::~String()
{
    delete[] m_buffer;
}

std::ostream& operator<< (std::ostream& os, const String& s)
{
    String temp = s;
    // Add null terminator so we can use ostream's char* output operator
    temp.ensureSize(temp.m_length + 1);
    temp.m_buffer[temp.m_length] = 0;
    os << "S(" << temp.m_length << "," << temp.m_bufSize
        << ")[" << temp.m_buffer << "]";
    return os;
}

void String::init()
{
    m_buffer = NULL;
    m_length = 0;
    m_bufSize = 0;
}

void String::ensureSize(size_t size)
{
    if (size <= m_bufSize)
    {
        return;
    }

    char* pNew = new char[size];
    memcpy(pNew, m_buffer, m_length);
    m_bufSize = size;
    delete[] m_buffer;
    m_buffer = pNew;
}

String& String::append(const char* other) {
    size_t newLen = m_length + strlen(other);
    ensureSize(newLen);
    memcpy(m_buffer + m_length, other, strlen(other));

    m_length = newLen;
    return *this;
}

String& String::append(const String& other) {
    size_t newLen = m_length + other.length();
    ensureSize(newLen);
    memcpy(m_buffer + m_length, other.m_buffer, other.length());

    m_length = newLen;
    return *this;
}

size_t String::length() const {
    return m_length;
}

String String::substr(size_t start, size_t numChars) const {
    assertIndex(start);
    size_t numCh = (start + numChars > m_length) ? m_length - start : numChars; //avoid out of range
    char* subCh = new char[numCh];

    for (int i = start; i < start + numCh; ++i) {

    }
    return String(subCh);
}

char String::char_at(size_t pos) const {
    assertIndex(pos);
    return m_buffer[pos];
}

char& String::char_at(size_t pos) {
    assertIndex(pos);
    return m_buffer[pos];
}

void String::assertIndex(size_t pos) const {
    if (pos < 0 || pos >= m_length || m_length == 0)
        throw std::out_of_range("index out of range");
}

char String::operator[] (size_t pos) const {
    return m_buffer[pos];
}

char& String::operator[] (size_t pos) {
    return m_buffer[pos];
}

String& String::operator+= (const String& other) {
    return append(other);
}

String& String::operator+= (const char* other) {
    return append(other);
}

String& String::operator= (const String& other) {
    return String(other);
}

bool String::operator== (const String& other) {
    if (m_length != other.m_length)
        return false;
    for (size_t i = 0; i < m_length; ++i) {
        if (char_at(i) != other.char_at(i))
            return false;
    }
    return true;
}

bool String::operator< (const String& other) {
    int len = (m_length < other.m_length) ? m_length : other.m_length;

    for (int i = 0; i < len; ++i) {
        if (char_at(i) < other.char_at(i))
            return true;
        else return false;
    }
    return (len > m_length) ? true : false; //should cover the case of ==
}

