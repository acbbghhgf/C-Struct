/*************************************************************************
	> File Name: stonewt.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月22日 星期一 15时46分47秒
 ************************************************************************/

#include<iostream>
#include "stonewt.h"
using namespace std;

Stonewt::Stonewt(double lbs){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn;
}

Stonewt::Stonewt(){
    stone = pds_left = 0.0;
    pounds = 0;
}

Stonewt::~Stonewt(){
}

void Stonewt::show_lbs()const{
    cout << "stone :"<< stone << ", pds_left :" << pds_left <<"pounds.\n";
}

void Stonewt::show_stn()const{
    cout << pounds << " pounds.\n";
}

Stonewt::operator int(){
    return int(pounds + 0.5);
}

Stonewt::operator double(){
    return double(pounds);
}

