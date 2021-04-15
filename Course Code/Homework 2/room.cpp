#include <iostream>
#include <string>
#include <cstdlib>
#include "room.h"

using namespace std;

extern const int directions;
extern const string choices[directions];
extern const bool lobby_exits[];
extern bool default_exits[]; 


int go2num(string go);
inline string num2go(int num);
inline int rand_num();                 //* generate the random number between 0 and 6
void array_copy(bool*a, const bool*b);


int sum(bool a[directions]){
    int sum = 0;
    for (int i=0;i<directions;i++)
    {
        sum += a[i];
    };
    return sum;
};

bool Room::explored() { return found; };

void Room::set_type(string type) { this->type = type; };

void Room::set_exit(string direction, bool status) {
     exits[go2num(direction)] = status; 
     num_exits = sum(exits);
     };

void Room::init_exit() { 

    array_copy(exits, lobby_exits);   
    found = 1;
    num_exits = sum(exits);    
    };

void Room::init_exit(string into) {
    

    //* array_copy(exits, default_exits);   
    
    //* ensure that the current room connects with the last one.
    int last_exit = go2num(into);
    exits[directions-1-last_exit] = 1;

    //* init the exits of the current room randomly
    int num = rand_num();
    int i = 0;
    for(i=0;i<num;i++)
    {
        exits[rand_num()] = 1;
    };

    //* the current room has been explored
    found = 1;

    //* calc the number of exits
    num_exits = sum(exits);

};

void Room::print() {

    int exit_count = 0;
    cout << "There are " << num_exits;
    if (num_exits == 1) {
        cout << " exit: ";
        for (int i=0;i<directions;i++){
            if(exits[i] == 1){
                cout << num2go(i) << "." << endl;
                break;
            };
        };
    }
    else {
        cout << " exits: ";
        for (int i=0;i<directions;i++){
            if(exits[i] == 1){
                exit_count ++;
                if (exit_count == num_exits - 1){
                    cout << num2go(i) << " and ";
                }
                else if (exit_count == num_exits){
                    cout << num2go(i) << "." << endl;
                    break;
                }
                else{
                    cout << num2go(i) << ", ";
                };
            };
        };
    };

};


int go2num(string go){
    int num = directions;
    while(num == directions){
        for(int i=0;i<directions;i++){
            if (choices[i] == go){
                num = i;
                break;
            }; 
        }; 
    }; 
    return num;
};

inline string num2go(int num){
    return choices[num];
};

inline int rand_num(){
    int random = rand() % directions;
    return random;
};

void array_copy(bool*a, const bool*b){
    for(int i=0;i<directions;i++){
        a[i] = b[i];
    };
};

