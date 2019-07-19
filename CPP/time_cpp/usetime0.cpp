/*************************************************************************
	> File Name: usetime0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月19日 星期五 14时37分24秒
 ************************************************************************/

#include<iostream>
#include "mytime0.h"

//using namespace std;

int main(){
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();

    cout << "coding time = ";
    coding.Show();

    cout << "fixing time =";
    fixing.Show();

    total = coding + fixing;
    cout << "total time = ";
    total.Show();

    Time morefixing(3, 40);
    cout << "morefixing time =";
    morefixing.Show();

    total = total + morefixing;
    cout << "total + morefixing time =";
    total.Show();

    Time diff = total - coding;
    cout << "diff time = ";
    diff.Show();

    Time adjuestd = diff * 1.5;
    cout << "adjuestd time = ";
    adjuestd.Show();

    Time f_adjuestd = 1.5 * diff;
    cout << "f_adjuestd time = ";
    f_adjuestd.Show();
    cout << f_adjuestd << endl;

    return 0;
}

