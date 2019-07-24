/*************************************************************************
	> File Name: bank.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 17时57分11秒
 ************************************************************************/

#include<iostream>
#include "queue.h"
#include <ctime>
#include <cstdlib>
using namespace std;

const int MIN_PER_HR = 60;
bool newcustomer(double x); //is there a new customer


int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue." << endl;
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours:" << endl;
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours; // of cycles

    cout << "Enter the average number of customers per hours:" << endl;
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served, sum_line, line_wait;
    served = sum_line = line_wait = 0;
    int wait_time = 0;
    for(int cycle = 0; cycle < cyclelimit; cycle++){
        if(newcustomer(min_per_cust)){
            if(line.isfull()){
                turnaways++;
            }
            else{
                customers++;
                cout << " customers ++" << customers << endl;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if(wait_time <= 0 && !line.isempty()){
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            cout << "queue -- and served ++" << served << endl;
            served++;
        }
        if(wait_time > 0){
            wait_time--;
            cout << "wait_time --" << wait_time << endl;
        }
        sum_line += line.queuecount();
    }
    if(customers > 0){
        cout << "customers accepted : " << customers << endl;
        cout << " customers served : " << served << endl;
        cout << "       turnaways : " << turnaways << endl;
        cout << "average queue size :";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time:" << (double)line_wait / served << "minutes.\n";
    }
    else{
        cout << "No customers!\n";
    }
    cout << "Done." << endl;
    
    return 0;
}

bool newcustomer(double x){
    return ((std::rand()%100) * x / 30 < 1);
}

