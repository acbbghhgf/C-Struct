/*************************************************************************
	> File Name: randwalk.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月22日 星期一 11时45分56秒
 ************************************************************************/

#include<iostream>
#include <cstdlib>
#include <ctime>
#include "vecotr.h"

using namespace std;


int main(){
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): " << endl;

    while(cin >> target){
        cout << "Enter step length : ";
        if(!(cin >> dstep)){
            break;
        }

        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps ++;
        }
        cout << "After " << steps << "steps, the subject has the following location: " << endl;
        cout << result << endl;
        result.polar_mod();
        cout << "or \n" << result << endl;
        cout << "Average outward distance per step = " << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit):" << endl;
    }

    cout << "Bye !" << endl;
    cin.clear();
    while(cin.get() != '\n'){
        continue;
    }

    return 0;
}
