#include "Source.h"

MyString::MyString() {
	MyString::str = nullptr;
	len = 0;
}
MyString::MyString(const char* str) {
	len = strlen(str);
	this->str = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		this->str[i] = str[i];
	}
	this->str[len] = '\0';
}
MyString::~MyString() {
	delete[] this->str;
}

MyString::MyString(const MyString& other) {
	len = strlen(other.str);
	this->str = new char[len + 1];

	for (int i = 0; i < len; i++) {
		this->str[i] = other.str[i];
	}
	this->str[len] = '\0';
}

MyString& MyString::operator =(const MyString& other) {
	if (this->str != nullptr) {
		delete[] str;
	}

	int len1 = strlen(other.str);
	this->str = new char[len1 + 1];

	for (int i = 0; i < len1; i++) {
		this->str[i] = other.str[i];
	}
	this->str[len1] = '\0';
	len = strlen(this->str);
	return*this;
}

void MyString::print() {
	cout << str;
}

int MyString::Size() {
	return len;
}


Text::Text() {
	text = nullptr;
	size = 0;
}

Text::Text(MyString* str, int size) {
	this->size = size;
	this->text = new MyString[size];
	for (int i = 0; i < size; i++)
		this->text[i] = str[i];
}

void Text::AddStr(MyString& str) {
	MyString* copy = Copy();
	delete[] text;
	size++;
	text = new MyString[size];
	for (int i = 0; i < size - 1; i++)
		text[i] = copy[i];
	delete[] copy;
	text[size - 1] = str;
}

void Text::RemoveStr(int index) {
	MyString* copy = Copy();
	delete[] text;
	size--;
	index--;
	text = new MyString[size];
	for (int i = 0; i < index; i++)
		text[i] = copy[i];
	for (int i = index; i < size; i++)
		text[i] = copy[i + 1];
	delete[] copy;
}

MyString* Text::Copy() {
	MyString* text1 = new MyString[size];
	for (int i = 0; i < size; i++)
		text1[i] = text[i];
	return text1;
}

int Text::FullLen() {
	int length = 0;
	for (int i = 0; i < size; i++)
		length += text[i].Size();
	return length;
}

void Text::Cout() {
	cout << "Our lines: " << endl;
	for (int i = 0; i < size; i++) {
		text[i].print();
		cout << endl;
	}
}

void Text::Clear() {
	delete[] text;
	text = nullptr;
	size = 0;
}

bool MyString::operator == (const MyString& other) {
	if (len == other.len) {
		for (int i = 0; i < len; i++) {
			if (str[i] != other.str[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

void Text::DeleteCopyStr(int index) {
	if (index >= 0 && size > 1) {
		int counter = 0,
			correction = 0;

		MyString basic = text[index];
		for (int i = 0; i < size; i++) {
			if (i != index && basic == text[i])
				counter++;
		}

		if (counter > 0) {
			MyString* lines = new MyString[size];
			for (int i = 0; i < size; i++)
				lines[i] = text[i];

			delete[]text;

			text = new MyString[size - counter];
			int i = 0,
				push = 0;
			while (i < size) {
				if (i != index && basic == lines[i])
					correction++;
				else if (push + correction < size) {
					text[push] = lines[push + correction];
					push++;
				}
				i++;
			}
			delete[]lines;
			size = size - counter;
		}
	}
}

Text::~Text()
{
	delete[] this->text;
}
