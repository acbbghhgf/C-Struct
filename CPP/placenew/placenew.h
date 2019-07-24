/*************************************************************************
	> File Name: placenew.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 16时10分56秒
 ************************************************************************/

#ifndef _PLACENEW_H
#define _PLACENEW_H

#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class Justtesting{
private:
    string words;
    int number;
public:
    Justtesting(const string &s = "just testing", int n = 0){
        words = s;
        number = n;
        cout << words << " constructed\n";
    }
    ~Justtesting(){
        cout << words << ", " << number << "destroyed." << endl;
    }
    void show()const{ cout << words << " ," << number << endl; }
};

#endif
