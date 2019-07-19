/*************************************************************************
	> File Name: mytime0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月19日 星期五 14时25分22秒
 ************************************************************************/

#include "mytime0.h"


Time::Time(){
    hours = minutes = 0;
}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
}

void Time::AddMin(int m){
    minutes = minutes + m;
    hours += (minutes / 60);
    minutes = minutes % 60;
}

void Time::AddHr(int h){
    hours = hours + h;
    hours = hours % 24;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time &t)const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours;
    sum.hours += sum.minutes / 60;
    sum.minutes = sum.minutes % 60;
    return sum;
}

Time Time::operator+(const Time &t)const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours;
    sum.hours += sum.minutes / 60;
    sum.minutes = sum.minutes % 60;
    return sum;
}

Time Time::operator-(const Time &t)const{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double n)const{
    Time result;
    long totalminutes = hours * n * 60 + minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

/* Time operator*() use no-friend func */
//Time operator*(double m, const Time &t){
//    return t * m;
//}

Time operator*(double m, const Time &t){
    Time result;
    long totalminutes = t.hours * m * 60 + t.minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time &t){
    os << t.hours << "hours," << t.minutes << "minutes";
    return os;
}

void Time::Show()const{
    std::cout << hours << "hours, "<< minutes << "minutes" << std::endl;
}

