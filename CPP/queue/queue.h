/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 17时14分39秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

class Customer{
private:
    long arrive; // arrival time for Customer
    int processtime; // processtime time for Customer
public:
    Customer(){ arrive = processtime = 0; }
    void set(long when);
    long when()const{ return arrive; }
    int ptime()const{ return processtime; }
};

typedef Customer Item; // typedef Customer to Item

class Queue{
private:
    struct Node{
        Item item;
        struct Node *next;
    };
    enum {Q_SIZE = 10};
    Node *front;    //pointer to front of Queue
    Node *rear;     //pointer to rear of Queue
    int items;      //current number of items in Queue
    const int qsize;    //maximum number of items in Queue
    Queue(const Queue &q):qsize(0){}
    Queue &operator=(const Queue &q){ return *this; }

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty()const;
    bool isfull()const;
    int queuecount()const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};

#endif
