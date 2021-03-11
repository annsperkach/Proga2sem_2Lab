#include "Source.h"

int main()
{
	int size = 0;
	char size1[20];
	Text text;
	while (size <= 0) {
		cout << "how many lines?" << endl;
		cin >> size1;
		size = atoi(size1);
		if (size != (int)size) {
			size = 0;
		}
	}
	MyString str1;
	string str;
	cin.ignore();
	for (int i = 0; i < size; i++) {
		getline(cin, str);
		char* arr = new char[str.size() + 1];
		arr = ToCharArr(str, arr);
		str1 = arr;
		delete[] arr;
		text.AddStr(str1);
	}
	menu(text);
}

void menu(Text& text) {
	int temp = 0;
	bool flag = true;
	cout << "1 - add a line to the text" << endl;
	cout << "2 - remove a line from the text" << endl;
	cout << "3 - search and delete the dublicated line" << endl;
	cout << "4 - get the length of the line" << endl;
	cout << "5 - clear the text" << endl;
	cout << "6 - menu" << endl;
	cout << "7 - finish the program" << endl;
	while (flag) {
		char temp1[20];
		while (temp <= 7) {
			cin >> temp1;
			temp = atoi(temp1);
			if (temp != (int)temp) {
				temp = 0;
			}
			else { break; }
		}
		if (temp == 1) {
			MyString str;
			string str1;
			cout << "add the line" << endl;
			cin.ignore();
			getline(cin, str1);
			char* arr = new char[str1.size() + 1];
			arr = ToCharArr(str1, arr);
			str = arr;
			delete[] arr;
			text.AddStr(str);
			text.Cout();
		}
		else if (temp == 2) {
			int index = 0;
			char temp2[20];
			while (index <= 0) {
				cout << "write the number of line to delete" << endl;
				cin >> temp2;
				index = atoi(temp2);
				if (index != (int)index) {
					index = 0;
				}
			}
			text.RemoveStr(index);
			text.Cout();
		}
		else if (temp == 3) {
			cout << "delete the duplicate lines:" << endl;
			text.DeleteCopyStr(0);
			text.Cout();
		}
		else if (temp == 4) {
			int length = text.FullLen();
			cout << "the length of the lines: " << length << endl;
			text.Cout();
		}
		else if (temp == 5) {
			text.Clear();
			text.Cout();
		}
		else if (temp == 6) {
			cout << "1 - add a line to the text" << endl;
			cout << "2 - remove a line from the text" << endl;
			cout << "3 - search and delete the dublicated line" << endl;
			cout << "4 - get the length of the line" << endl;
			cout << "5 - clear the text" << endl;
			cout << "6 - menu" << endl;
			cout << "7 - finish the program" << endl;
		}
		else if (temp == 7) {
			flag = false;
		}
	}
}

char* ToCharArr(string str, char* arr) {
	for (int i = 0; i < str.size(); i++) {
		arr[i] = str[i];
	}
	arr[str.size()] = '\0';
	return arr;
}
