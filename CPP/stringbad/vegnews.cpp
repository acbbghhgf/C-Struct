/*************************************************************************
	> File Name: vegnews.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 10时08分26秒
 ************************************************************************/

#include<iostream>
#include "stringbad.h"
using namespace std;

void callme1(Stringbad &);
void callme2(Stringbad);

int main(){
    cout << "start an inner block\n";
    Stringbad headline1("Celery stalks at Midnight,");
    Stringbad headline2("Lettuce prey.");
    Stringbad sports("Spinach leaves bowl for Dollars.");

    cout << "headline1:" << headline1 << endl;
    cout << "headline2:" << headline2 << endl;
    cout << "sports:" << sports << endl;

    callme1(headline1);
    cout << "headline1 callme1 after:" << headline1 << endl;
    cout << "Initialize one object to another:\n";
    Stringbad sailor = sports;
    cout << "sailor :" << sailor << endl;
    cout << "Assign one object to another:\n";
    Stringbad knot;
    knot = headline1;
    cout << "knot :" << knot << endl;
    callme2(headline2);
    Stringbad str1, str2, str3;
    cout << "Please input str1, str2 , str3: " << endl;
    cin >> str1 >> str2 >> str3;
    cout << "str1: " << str1 << ", str2: " << str2 << ", str3: " << str3 << endl;

    cout << "headline1 callme2 after:" << headline2 << endl;
    cout << "Initialize one object to another:\n";
    cout << "Exiting the block ." << endl;
    cout << "End of main()\n";

    return 0;
}

void callme1(Stringbad &rsb){
    cout << "Stringbad passed by reference:" << endl;
    cout << "         \"" << rsb << "\"\n";
}

void callme2(Stringbad sb){
    cout << "Stringbad passed by valuere:" << endl;
    cout << "         \"" << sb << "\"\n";
}

