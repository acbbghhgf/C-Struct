/*************************************************************************
	> File Name: stone.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月22日 星期一 16时25分21秒
 ************************************************************************/

#include<iostream>
#include "stonewt.h"

using namespace std;

void display(const Stonewt &st, int n);

int main(){
    Stonewt incognito = 275;
    Stonewt wolfe(285, 7);
    Stonewt taft(21, 8);
    double result_d;
    int result_i;

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The Pressident weighed ";
    taft.show_lbs();
    incognito = 276.8;
    taft = 325;
    cout << "After dinnet, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinnet, the Pressident weighed ";
    taft.show_lbs();

    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "No stone left unearned\n";

    result_d = taft;
    result_i = taft;
    cout << "double taft -->" << result_d << ", int taft-->" << result_i << endl;

    return 0;
}

void display(const Stonewt &st, int n){
    for(int i = 0; i < n; i++){
        cout << "Wow ! ";
        st.show_stn();
    }
}

