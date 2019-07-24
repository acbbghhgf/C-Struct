/*************************************************************************
	> File Name: brass.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 14时55分01秒
 ************************************************************************/

#ifndef _BRASS_H
#define _BRASS_H

#include <string>

class Brass{
private:
    std::string fullName;
    long acctNum;
    double balance;
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance()const;
    virtual void ViewAcct()const;
    virtual ~Brass(){}
};

class BrassPlus : public Brass{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0, double m1 = 500, double r1 = 0.11125);
    BrassPlus(const Brass &bs, double m1, double r);
    virtual void ViewAcct()const;
    virtual void Withdraw(double amt);
    void ResetMax(double m){ maxLoan = m; }
    void ResetRate(double r){ rate = r; }
    void ResetOwes(){ owesBank = 0; }
};

#endif
