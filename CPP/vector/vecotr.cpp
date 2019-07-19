/*************************************************************************
	> File Name: vecotr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月19日 星期五 17时59分36秒
 ************************************************************************/

#include<iostream>
#include "vecotr.h"
//using namespace std;

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR{
    const double Rad_todeg = 45.0 / atan(1.0);

    void Vector::set_mag(){
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang(){
        if(x == 0.0 && y == 0.0){
            ang = 0.0;
        }
        else{
            ang = atan2(y, x);
        }
    }

    void Vector::set_y(){
        y = mag * sin(ang);
    }

    void Vector::set_x(){
        x = mag * cos(ang);
    }

    

}




