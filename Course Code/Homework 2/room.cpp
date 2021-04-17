#include <iostream>
#include <string>
#include "room.h"

using namespace std;

extern const int num_type;
extern const int directions;
extern const string choices[directions];
extern const bool default_exits[]; 
extern const bool default_status[];


void exit_generator(bool* exit);
void array_copy(bool*a, const bool*b, int size);
int sum(bool a[directions]){
    int sum = 0;
    for (int i=0;i<directions;i++)
    {
        sum += a[i];
    };
    return sum;
};

Room::~Room(){
    delete[] exits;
    delete[] room_status;
};

bool Room::explored() { return found; };

void Room::set_found() { found = 1; };

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

void Room::init(){
    exits = new bool[directions];
    room_status = new bool[num_type];
    array_copy(exits, default_exits, directions);
    array_copy(room_status, default_status, num_type);
};


void Room::init_exit() { 

    exit_generator(exits);
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
    //* (Binomial[x-1,5] + Binomial[x-1,4] + Binomial[x-1,3] + Binomial[x-1,2])/Binomial[6-1+x,x]
    int num = 30;
    int i = 0;
    for(i=0;i<num;i++)
    {
        exit[rand_num(directions)] = 1;
    };
};


void array_copy(bool*a, const bool *b, int size){
    for(int i=0;i<size;i++){
        a[i] = b[i];
    };
}