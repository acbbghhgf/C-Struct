/*************************************************************************
	> File Name: stringbad.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 09时47分08秒
 ************************************************************************/

#include<iostream>
#include <cstring>
#include "stringbad.h"
using namespace std;

int Stringbad::num_strings = 0;

Stringbad::Stringbad(const char *a){
    len = strlen(a);
    str = new char[len + 1];
    strcpy(str, a);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object Created"<< endl;
}

Stringbad::Stringbad(const Stringbad &s){
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    num_strings++;
    cout << "copy Stringbad : " << str << endl;
}

Stringbad::Stringbad(){
    len = 4;
    str = new char[4];
    strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object Created"<< endl;
}

Stringbad::~Stringbad(){
    cout << "\"" << str << "\" object deleted." << endl;
    --num_strings;
    cout << "num_strings :" << num_strings << " left." << endl;
    delete []str;
}

Stringbad &Stringbad::operator=(const Stringbad &st){
    if(this == &st){
        return *this;
    }
    delete []str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    num_strings++;
    cout << "=== Stringbad : " << str << endl;
    return *this;
    
}

Stringbad &Stringbad::operator=(const char *s){
    delete []str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

bool operator<(const Stringbad &st1, const Stringbad &st2){
    return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const Stringbad &st1, const Stringbad &st2){
    return (strcmp(st1.str, st2.str) > 0);
}

bool operator==(const Stringbad &st1, const Stringbad &st2){
    return (strcmp(st1.str, st2.str) == 0);
}

char &Stringbad::operator[](int i){
    return str[i];
}

const char &Stringbad::operator[](int i)const{
    return str[i];
}

std::ostream &operator<<(std::ostream &os, const Stringbad &st){
    cout << "string :" << st.str << ", num_strings : " << st.num_strings;
    return os;
}

std::istream &operator>>(std::istream &is, Stringbad &st){
    char temp[Stringbad::CINLIM];
    is.get(temp, Stringbad::CINLIM);
    if(is){
        st = temp;
    }
    while( is && is.get() != '\n' ){
        continue;
    }
    return is;
}

