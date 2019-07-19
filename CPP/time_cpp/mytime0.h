/*************************************************************************
	> File Name: mytime0.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月19日 星期五 14时20分42秒
 ************************************************************************/

#ifndef _MYTIME0_H
#define _MYTIME0_H

#include <iostream>

class Time{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time &t)const;
    Time operator+(const Time &t)const;
    Time operator-(const Time &t)const;
    Time operator*(double n)const;
    void Show()const;
    friend Time operator*(double m, const Time &t);
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
};

//Time operator*(double m, const Time &t);// use no-friend func;
#endif
