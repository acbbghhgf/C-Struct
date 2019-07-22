/*************************************************************************
	> File Name: stonewt.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月22日 星期一 15时39分32秒
 ************************************************************************/

#ifndef _STONEWT_H
#define _STONEWT_H

class Stonewt{
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();

    void show_lbs()const;
    void show_stn()const;

    operator int();
    operator double();
};

#endif
