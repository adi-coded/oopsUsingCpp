#include <iostream>
#include <cstring>
#include <cctype>       
using namespace std;

class MyString {
    char    *str;
    public:
    MyString() {
        str = new char[1];
        str[0] = '\0';         
    }
    MyString(const char* s) {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }
    MyString(const MyString& from) {
        str = new char[strlen(from.str)+1];
        strcpy(str, from.str);
    }
    ~MyString() {delete[] str;}

    MyString operator+(const MyString& op2) const {
        int len = strlen(str) + strlen(op2.str) + 1;
        char*    new_str = new char[len];
        strcpy(new_str, str);
        strcat(new_str, op2.str);
        MyString    temp(new_str);      
        delete[] new_str;
        return temp;
    }

    MyString& operator=(const MyString& right) { 
        if (this != &right) {                  
            delete[] str;
            str = new char[strlen(right.str)+1];
            strcpy(str, right.str);
        }
        return *this;           
    }

    bool operator<=(const MyString& right) const {    
        return strcmp(str, right.str) <= 0;
    }

    const char* getstring() const {return str;}  
    void show() const {cout << str << endl;}
    int length() const {return strlen(str);}
    void toLower() {
        for (int i=0; str[i] != '\0'; i++)
            str[i] = tolower(str[i]);
    }
    void toUpper() {
        for (int i=0; str[i] != '\0'; i++)
            str[i] = toupper(str[i]);
    }
};

int main() {
    MyString s1;
    MyString s2("Hello");
    MyString s3(" World!");
    MyString s4 = s2 + s3;      

    s4.show();
    s4 = s3 + s2;
    s4.show();
    if (s2 <= s3)
        cout << s2.getstring() << endl;
    else
        cout << s3.getstring() << endl;
    s2.toLower();
    s2.show();
    s2.toUpper();
    s2.show();
}
