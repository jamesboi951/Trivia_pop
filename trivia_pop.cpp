//
//  main.cpp
//  old_video_game
//
//  Created by James Boisvert on 8/19/19.
//  Copyright © 2019 James Boisvert. All rights reserved.
//
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <iterator>
using namespace std;


void base();
void gun();
void top();
void convert(string &s);
void trivia_bank(string &p1,int &y, int &z, int &p1gun);
void stick();

void weapons(string p1, int &p1gun){
    string y;
    map<string, int> yoto;
    string arr[6] = {"scar-H","TAR-21","m9","44 magnum"
        ,"jerkoff gun","anwar's gun"};
    
    yoto["scar-H"] = 20;
    yoto["TAR-21"] = 25;
    yoto["m9"] = 10;
    yoto["44 magnum"] = 15;
    yoto["jerkoff gun"] = 5;
    yoto["anwar's gun"] = 12;
    int x = (rand()%6) + 1;
    cout << p1 << " would you like to accept a " << yoto.find(arr[x])->first << "?" << endl;
    getline(cin,y);
    convert(y);
    if(y == "yes"){
        p1gun = yoto.find(arr[x])->second;
    }
}

void base(){
    cout << "---|---|" << endl;
    cout << "   |  " << endl;
    cout << "  / \\" << endl;
    cout << " /   \\" << endl;
}

void gun(){
    string g = "   |   -" ;
    for(int i = 0; i < 4; i++){
        g += "-";
    }
    cout << g;
}

void top(){
    cout << " -----" << endl;
    cout << " |   |" << endl;
    cout << " |   |" << endl;
    cout << " -----" << endl;
}

void convert(string &s){
    for(int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
}

void trivia_bank(string &p1,int &y, int &z, int &p1gun){
    string ans1, ans2;
    string arr[7] = {"What is the longest river in The United States?", "What is the longest river in Australia?", "Mario Kart is a video game series publish by which company?", "If a liquor is 100 proof how much alcohol does it contain by percentage?",
        "In the poker game Texas Hold’em, how many cards are dealt to each player?", "What color is the sky", "what is the magic number in blackjack?"};
    
    map<string, string> nig;
    
    nig["What is the longest river in The United States?"] = "the missisippi river";
    
    nig["What is the longest river in Australia?"] = "the murray river";
    
    nig["Mario Kart is a video game series publish by which company?"] = "nintendo";
    
    nig["If a liquor is 100 proof how much alcohol does it contain by percentage?"] = "50 percent";
    
    nig["In the poker game Texas Hold’em, how many cards are dealt to each player?"] = "two";
    
    nig["What color is the sky"] = "blue";
    
    nig["what is the magic number in blackjack?"] = "21";
    
    int x = (rand()%7) + 1;
    cout << p1 << ": " << nig.find(arr[x])->first;
    getline(cin, ans1);
    convert(ans1);
    if(ans1 == (nig.find(arr[x])->second)){
        weapons(p1,p1gun);
        z -= p1gun;
    }
    cout << "player one has " << z << " XP" << endl;
    cout << "player two has " << y << " XP" << endl;
    
}

void stick(){
    
    cout << " -----" << endl;
    cout << " |   |" << endl;
    cout << " |   |" << endl;
    cout << " -----" << endl;
    cout << "   |  " << endl;
    cout << "---|---" << endl;
    cout << "   |  " << endl;
    cout << "  / \\" << endl;
    cout << " /   \\" << endl;
}


int main()
{
    srand(time(NULL));
    int p1xp = 100;
    int p2xp = 100;
    int p1gun;
    int p2gun;
    string p1,p2;
    cout << "player one, enter your name";
    getline(cin, p1);
    cout << "player two, enter your name";
    getline(cin, p2);
    for(int i = 0; i < 10; i++){
        trivia_bank(p1,p1xp,p2xp,p1gun);
        trivia_bank(p2,p2xp,p1xp,p2gun);
        
    }
}
