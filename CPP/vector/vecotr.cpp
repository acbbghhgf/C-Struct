/*************************************************************************
	> File Name: vecotr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月19日 星期五 17时59分36秒
 ************************************************************************/

#include<iostream>
#include <cmath>
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

    Vector::Vector(){
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL){
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else{
            cout << "Incorrect 3rd argument to Vector() ...\n";
            cout << "Vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form){
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL){
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else{
            cout << "Incorrect 3rd argument to Vector() ...\n";
            cout << "Vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector(){
    }

    void Vector::polar_mod(){
        mode = POL;
    }

    void Vector::rect_mod(){
        mode = RECT;
    }

    Vector Vector::operator+(const Vector &b)const{
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b)const{
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-()const{
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n)const{
        return Vector(x * n, y * n);
    }

    Vector operator*(double m, const Vector &b){
        return b * m;
    }
    
    std::ostream &operator<<(std::ostream &os, const Vector &b){
        if(b.mode == Vector::RECT){
            os << "(x,y) = (" << b.x << "," << b.y << ")";
        }
        else if(b.mode == Vector::POL){
            os << "(m,a) = (" << b.mag << "," << b.ang << ")";
        }
        else{
            os << "Vector object mode is invalid";
        }
        return os;
    }

}




