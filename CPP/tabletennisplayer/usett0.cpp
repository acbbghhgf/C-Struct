/*************************************************************************
	> File Name: usett0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 11时23分15秒
 ************************************************************************/

#include<iostream>
#include "tabtenn0.h"

using namespace std;

int main(){
    Tabletennisplayer player1("Chuck", "Blizzard", true);
    Tabletennisplayer player2("Tara", "Boomdea", false);
    RatedPlayer player3(1140, "Mallory", "Duck", true);
    
    player3.Name();
    if(player3.HashTable()){
        cout << " : has a table.\n";
    }
    else{
        cout << " : hasn't a table.\n";
    }
    player3.Name();
    cout << "; Rating:" << player3.Rating() << endl;

    player1.Name();
    if(player1.HashTable()){
        cout << " : " << "has a table.\n";
    }
    else{
        cout << ": hasn't a table . \n";
    }
    player2.Name();
    if(player2.HashTable()){
        cout << ": has a table .\n";
    }
    else{
        cout << ": hasn't a table.\n";
    }

    RatedPlayer rplayer(1212, player1);
    cout << "Name :";
    rplayer.Name();
    cout << ": Rating" << rplayer.Rating() << endl;

    return 0;
}

