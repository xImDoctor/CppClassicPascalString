#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class ClassicalPascalString {
	char* data;
	int lenght;
	
public:
	//Конструктор по умолчанию
	ClassicalPascalString() {
		data = NULL;
		lenght = 0;
	}

	//Конструктор
	ClassicalPascalString(const char* data) { 
		lenght = strlen(data) + 1;
		this->data = new char[lenght];

		memcpy(this->data, data, lenght);
#ifdef _DEBUG
		cout << endl;
		cout << "[Debug] Written data is" << this->data << endl;
		cout << "[Debug] Created string's lenght is " << lenght << endl;
		cout << "[Debug] Creation is successful" << endl;
#endif
	}

	//Конструктор копирования
	ClassicalPascalString(const ClassicalPascalString& other_str) {
		lenght = other_str.lenght;
		data = new char[lenght];
		
		memcpy(data, other_str.data, lenght);
#ifdef _DEBUG
		cout << endl;
		cout << "[Debug] Copied data is " << data << endl;
		cout << "[Debug] New string's lenght is " << lenght << endl;
		cout << "[Debug] Copy is successful" << endl; 
#endif
	}

	//Деструктор
	~ClassicalPascalString() {
		delete[] data;
#ifdef _DEBUG
		cout << endl;
		cout << "[Debug] Destruction is successful" << endl;
#endif
	}

	//Присваивание новой строки существующей
	ClassicalPascalString& operator=(const ClassicalPascalString& other_str) {
		if (this != &other_str) {
			delete[] data;

			lenght = other_str.lenght;
			data = new char[lenght];

			memcpy(data, other_str.data, lenght);
		}
		return *this;
	}

	ClassicalPascalString operator+(const ClassicalPascalString& second_str) {
		ClassicalPascalString temp = *this;
		char* tmp_data = new char[temp.lenght];
		memcpy(tmp_data, temp.data, temp.lenght);
		delete[] temp.data;

		//set new buffer and copy values
		int new_lenght = temp.lenght + second_str.lenght - 1;
		temp.data = new char[new_lenght];
		memcpy(temp.data, tmp_data, temp.lenght);
		delete[] tmp_data;
		memcpy(temp.data + temp.lenght - 1, second_str.data, second_str.lenght);

		temp.lenght = new_lenght;
		return temp;
	}

	char& operator[](int index){
		if (index < 0 || index > lenght - 1) {
			cerr << "[Error] Index was out of bounds" << endl;
			return data[0];
		}
		else if (index == 0) {
			static char no_ptr = '\0';
			cout << "Lenght is " << len();
			return no_ptr;
		}

		return data[index - 1];
	}

	friend ostream& operator<<(ostream &os, ClassicalPascalString& str) {
		if (str.data)
			os << str.data;
		return os;
	}

	//Длина строки
	int len() {
		return lenght;
	}

	//Преобразование в строку языка C++ (string)
	string toString() {
		string str;

		for (int i = 0; i < lenght; i++) {
			str += data[i];
		}
#ifdef _DEBUG
		cout << "[Debug] Coverted data is " << str << endl;
		cout << "[Debug] Lenght is " << str.length() << endl;
#endif
		return str;
	}
};



int main() {

	ClassicalPascalString str1("Very fun string123");
	ClassicalPascalString str2("Very very fun string456");
	ClassicalPascalString result;
	result = str1 + " " + str2;
	cout << result << endl;
	cout << str1 << " " << str2 << endl;
	cout << str1[0] << " or " << str1.len() << endl;

	string newstr = str2.toString();
	cout << newstr << endl;

	cout << str1[1] << str1[2] << endl;

	str2 = str1;
	cout << str2 << endl;

	ClassicalPascalString _pas = "Hello, world!";
	cout << _pas << endl;

	return 0;
}