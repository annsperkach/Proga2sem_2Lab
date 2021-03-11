#include <iostream>
#include <string>
#include <iomanip> 
#include <cstdlib>
#pragma once
using namespace std;

class MyString
{
public:
	MyString();
	MyString(const char* str);
	~MyString();
	MyString(const MyString& other);
	MyString& operator =(const MyString& other);
	bool operator == (const MyString& other);
	MyString* Copy();
	void print();
	int Size();

private:
	char* str;
	int len;
	char _str;
};

class Text
{
public:
	Text();
	Text(MyString* str, int size);
	void AddStr(MyString& str);
	void RemoveStr(int index);
	int FullLen();
	MyString* Copy();
	void Cout();
	void Clear();
	void DeleteCopyStr(int index);
	~Text();

private:
	MyString* text;
	int size;
};

char* ToCharArr(std::string str, char* arr);
void menu(Text& text);
