/*************************************************************************
	> File Name: brass.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 15时34分25秒
 ************************************************************************/

#include<iostream>
#include "brass.h"
using namespace std;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string &s, long an, double bal){
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt){
    if(amt < 0){
        cout << "Negative Deposit not allowed;" << "Deposit is cancelled.\n";
    }
    else{
        balance += amt;
    }
}

void Brass::Withdraw(double amt){
    format initialState = setFormat();
    precis prec = cout.precision(2);
    if(amt < 0){
        cout << "Withdraw amount must be positive; Withdraw canceled.\n";
    }
    else if(amt <= balance){
        balance -= amt;
    }
    else{
        cout << "Withdraw amout of $" << amt << "exceeds your balance.\n" << "Withdraw cancelled.\n";
    }

    restore(initialState, prec);
}

double Brass::Balance()const{
    return balance;
}

void Brass::ViewAcct()const{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client : " << fullName << endl;
    cout << "Account Number : " << acctNum << endl;
    cout << "Balance : $" << balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const string &s, long an, double bal, double m1, double r): Brass(s, an, bal){
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &bs, double m1, double r):Brass(bs){
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct()const{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();
    cout << "Maximum loan : $" << maxLoan << endl;
    cout << "Owed to bank : $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt){
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    //double bal = balance;// can use balance 
    if(amt <= bal){
        Brass::Withdraw(amt);
    }
    else if(amt <= bal + maxLoan - owesBank){
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance : $" << advance << endl;
        cout << "Finance charge : $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else{
        cout << "Credit limit exceeded. Transaction cancelled. \n";
    }
    restore(initialState, prec);
}

format setFormat(){
    return cout.setf(ios_base::fixed, ios_base::floatfield);
}

void restore(format f, precis p){
    cout.setf(f, ios_base::floatfield);
    cout.precision(p);
}


