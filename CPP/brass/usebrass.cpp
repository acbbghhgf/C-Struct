/*************************************************************************
	> File Name: usebrass.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 16时57分53秒
 ************************************************************************/

#include<iostream>
#include "brass.h"

using namespace std;

int main(){
    Brass Piggy("Porcelot pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio HOggy", 382288, 3000.00);

    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing $1000 into the Hogg Account: \n";
    Hoggy.Deposit(1000.0);
    cout << "New balance : $" << Hoggy.Balance() << endl;

    cout << "Withdraw $4200 from the Piggy Account :" << endl;
    Piggy.Withdraw(4200.00);
    cout << "Piggy Account balance : $" << Piggy.Balance() << endl;
    cout << "\n" << endl;
    
    cout << "Withdraw $4200 from the Hoggy Account: " << endl;
    Hoggy.Withdraw(4200.00);
    cout << "Hoggy Account balance : $" << Hoggy.Balance() << endl;
    cout << "\n" << endl;
    Hoggy.ViewAcct();

    return 0;
}

