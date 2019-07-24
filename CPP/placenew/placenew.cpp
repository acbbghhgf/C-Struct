/*************************************************************************
	> File Name: placenew.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 16时17分46秒
 ************************************************************************/

#include<iostream>
#include "placenew.h"
using namespace std;

int main(){
    char *buffer = new char[BUF];
    Justtesting *pc1, *pc2;
    
    pc1 = new (buffer) Justtesting;
    pc2 = new Justtesting("Heap1", 20);

    cout << "Memory block addresses: "<< "buffer :" << (void *)buffer << endl;
    cout << "Heap1 : "<< pc2 << endl;
    cout << "Memory contents: " << pc1 << ": " << endl;
    pc1->show();
    cout << pc2 << ":" << endl;
    pc2->show();

    Justtesting *pc3, *pc4;
    pc3 = new (buffer) Justtesting("Bad Idea", 6);
    pc4 = new Justtesting("Heap2", 10);

    cout << "Memory contents:" << pc3 << ":" << endl;
    pc3->show();
    cout << pc4 << ":" << endl;
    pc4->show();

    delete pc2;
    delete pc4;
    delete [] buffer;
    cout << "Done\n";

    return 0;

}

