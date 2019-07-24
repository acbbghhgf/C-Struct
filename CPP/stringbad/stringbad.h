/*************************************************************************
	> File Name: stringbad.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 09时44分00秒
 ************************************************************************/

#ifndef _STRINGBAD_H
#define _STRINGBAD_H

#include <iostream>

class Stringbad{
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    Stringbad(const char *a);
    Stringbad(const Stringbad &s);
    Stringbad();
    ~Stringbad();
    Stringbad &operator=(const Stringbad &st);
    Stringbad &operator=(const char *s);

    char &operator[](int i);
    const char &operator[](int i)const;

    friend std::ostream &operator<<(std::ostream &os, const Stringbad &st);
    friend std::istream &operator>>(std::istream &is, Stringbad &st);
    friend bool operator<(const Stringbad &st1, const Stringbad &st2);
    friend bool operator>(const Stringbad &st1, const Stringbad &st2);
    friend bool operator==(const Stringbad &st1, const Stringbad &st2);
};

#endif
