/*************************************************************************
	> File Name: vecotr.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月19日 星期五 17时48分38秒
 ************************************************************************/

#ifndef _VECOTR_H
#define _VECOTR_H

#include <iostream>

namespace VECTOR
{
    class Vector{
    public:
        enum Mode{RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval()const{ return x; }
        double yval()const{ return y; }
        double magval()const{ return mag; }
        double angval()const{ return ang; }
        void polar_mod();
        Vector operator+(const Vector &b)const;
        Vector operator-(const Vector &b)const;
        Vector operator-()const;
        Vector operator*(double n)const;

        friend Vector operator*(double m, const Vector &b);
        friend std::ostream & operator<<(std::ostream &os, const Vector &b);
    };
}



#endif
