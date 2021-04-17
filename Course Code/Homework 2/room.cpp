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
int sum(bool a[directions]);

Room::~Room(){
    delete[] exits;
    delete[] room_status;
};

bool Room::explored() const { return found; };

void Room::set_found() { found = 1; };

bool Room::get_status(int type) const { return room_status[type]; };

bool Room::get_connection(int direction) const { return exits[direction]; };

void Room::set_type(string settype) { 
    
    type = settype; 
    if (type == "lobby"){
        room_status[0] = true;
    };
    if (type == "monster"){
        room_status[2] = true;
    };
    if (type == "princess"){
        room_status[1] = true;
    };

    };

void Room::set_type(int type) {

    room_status[type] = true;

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
    int from_gate = directions - 1 - last_exit;
    exits[from_gate] = 1;

    //* init the exits of the current room randomly
    exit_generator(exits);

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
    int num = 6;
    int i = 0;
    int random = 0;
    srand((unsigned)time(NULL));
    for(i=0;i<num;i++)
    {
        random = rand() % directions;
        exit[random] = 1;
    };
};

void array_copy(bool*a, const bool *b, int size){
    for(int i=0;i<size;i++){
        a[i] = b[i];
    };
}

int sum(bool a[directions]){
    int sum = 0;
    for (int i=0;i<directions;i++)
    {
        sum += a[i];
    };
    return sum;
};
