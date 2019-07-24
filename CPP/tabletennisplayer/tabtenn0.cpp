/*************************************************************************
	> File Name: tabtenn0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 11时18分14秒
 ************************************************************************/

#include<iostream>
#include "tabtenn0.h"

using namespace std;

Tabletennisplayer::Tabletennisplayer(const string &fn, const string &ln, bool ht){
    firstname = fn;
    lastname = ln;
    hastable = ht;
}

void Tabletennisplayer::Name()const{
    cout << lastname << " , " << firstname;
}


RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : Tabletennisplayer(fn, ln, ht)
{
    rating = r; 
}

RatedPlayer::RatedPlayer(unsigned int r, const Tabletennisplayer &tp) : Tabletennisplayer(tp),rating(r)
{
    
}
