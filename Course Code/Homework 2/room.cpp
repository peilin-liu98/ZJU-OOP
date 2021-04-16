#include <iostream>
#include <string>
#include "room.h"

using namespace std;

extern const int directions;
extern const string choices[directions];
extern bool default_exits[]; 


void exit_generator(bool* exit);


int sum(bool a[directions]){
    int sum = 0;
    for (int i=0;i<directions;i++)
    {
        sum += a[i];
    };
    return sum;
};

bool Room::explored() { return found; };

bool Room::get_status(int type){ return room_status[type]; };

void Room::set_type(string type) { 
    
    this->type = type; 
    if (type == "lobby"){
        room_status[0] = true;
    }
    else if (type == "monster"){
        room_status[2] = true;
    }
    else if (type == "princess"){
        room_status[1] = true;
    };

    };

void Room::set_exit(string direction, bool status) {
     exits[go2num(direction)] = status; 
     num_exits = sum(exits);
     };

void Room::init_exit() { 

    exit_generator(exits);
    found = 1;
    num_exits = sum(exits);    
    };

void Room::init_exit(string into) {
    
    //* ensure that the current room connects with the last one.
    int last_exit = go2num(into);
    exits[directions-1-last_exit] = 1;

    //* init the exits of the current room randomly
    exit_generator(exits);
    int num = rand_num(directions);
    int i = 0;
    for(i=0;i<num;i++)
    {
        exits[rand_num(directions)] = 1;
    };

    //* the current room has been explored
    found = 1;

    //* calc the number of exits
    num_exits = sum(exits);

};

void Room::print() {
    
    num_exits = sum(exits);
    int exit_count = 0;
    cout << "There are " << num_exits;
    if (num_exits == 1) {
        cout << " exit: ";
        for (int i=0;i<directions;i++){
            if(exits[i] == 1){
                cout << choices[i] << "." << endl;
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
                    cout << choices[i] << " and ";
                }
                else if (exit_count == num_exits){
                    cout << choices[i] << "." << endl;
                    break;
                }
                else{
                    cout << choices[i] << ", ";
                };
            };
        };
    };

};


void exit_generator(bool* exit){
    int num = rand_num(directions) + 1;
    int i = 0;
    for(i=0;i<num;i++)
    {
        exit[rand_num(directions)] = 1;
    };
};
