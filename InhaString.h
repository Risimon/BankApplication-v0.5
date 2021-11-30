#ifndef INHASTRING_H
#define INHASTRING_H
#include <iostream>

class InhaString {
private:
	char* m_msg;
	int m_len;
public:
	InhaString();
	InhaString(const char*);
	InhaString(const InhaString&);
	~InhaString();
	InhaString& operator=(const InhaString&);
	InhaString& operator+=(const InhaString&);
	friend InhaString operator+(const InhaString&, const InhaString&);
	friend bool operator==(const InhaString&, const InhaString&);
	friend std::ostream& operator<<(std::ostream&, const InhaString&);
	friend std::istream& operator>>(std::istream&, InhaString&);
};

#endif