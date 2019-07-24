/*************************************************************************
	> File Name: tabtenn0.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 11时13分02秒
 ************************************************************************/

#ifndef _TABTENN0_H
#define _TABTENN0_H

#include <string>
using std::string;

class Tabletennisplayer{
private:
    string firstname;
    string lastname;
    bool hastable;
public:
    Tabletennisplayer(const string &fn = "none", const string &ln = "none", bool ht = false);
    void Name()const;
    bool HashTable()const{ return hastable; }
    void ResetTable(bool v){ hastable = v; }
};

class RatedPlayer: public Tabletennisplayer{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string &fn = "none", const string &ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const Tabletennisplayer &tp);
    unsigned int Rating()const{ return rating; }
    void ResetRating(unsigned int r){ rating = r; }
};

#endif
