#include "InhaString.h"

InhaString::InhaString() : m_msg{ nullptr }, m_len{ 0 } {}

InhaString::InhaString(const char* msg) {
	m_len = strlen(msg) + 1;
	m_msg = new char[m_len];
	strcpy_s(m_msg, m_len, msg);
}

InhaString::InhaString(const InhaString& str) {
	m_len = str.m_len;
	m_msg = new char[str.m_len];
	strcpy_s(m_msg, m_len, str.m_msg);
}

InhaString::~InhaString() {
	delete[] m_msg;
}

InhaString& InhaString::operator=(const InhaString& str) {
	if (this == &str)
		return *this;

	if (m_msg)
		delete[] m_msg;
	m_len = str.m_len;
	m_msg = new char[str.m_len];
	strcpy_s(m_msg, str.m_len, str.m_msg);
	return *this;
}

InhaString& InhaString::operator+=(const InhaString& str) {
	InhaString data;
	m_len = m_len + str.m_len - 1;
	data.m_msg = new char[m_len];
	strcpy_s(data.m_msg, m_len, m_msg);
	strcat_s(data.m_msg, m_len, str.m_msg);
	delete[] m_msg;
	m_msg = new char[m_len];
	strcpy_s(m_msg, m_len, data.m_msg);
	return *this;
}

InhaString operator+(const InhaString& str1, const InhaString& str2) {
	InhaString str{ str1.m_msg };
	str.m_len = str1.m_len + str2.m_len - 1;
	str.m_msg = new char[str.m_len];
	strcpy_s(str.m_msg, str.m_len, str1.m_msg);
	strcat_s(str.m_msg, str.m_len, str2.m_msg);
	return str;
}

bool operator==(const InhaString& str1, const InhaString& str2) {
	return strcmp(str1.m_msg, str2.m_msg);
}

std::ostream& operator<<(std::ostream& out, const InhaString& str) {
	out << str.m_msg;
	return out;
}

std::istream& operator>>(std::istream& in, InhaString& str) {
	char* data = new char[100];
	in >> data;
	str = InhaString{ data };
	delete[] data;
	return in;
}