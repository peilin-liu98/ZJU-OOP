#include <iostream>
#include <string>
#include "castle.h"
#define dimensions 3

using namespace std;

extern const int max_level;
extern const int max_length;
extern const int max_width;
const string dim2go[] = {"west","north","up"};
const string floor2go[] = {"east", "south", "down"};
const string *walls[] = {floor2go, dim2go};

int* pos_connect(int*p1, int*p2, int dim);
void array_copy(int*a, int*b);
void fix_walls(Room* room, int dim, bool ceil);

Room* Castle::get_room(int* pos) {
    return & rooms[pos[0]][pos[1]][pos[2]];
};


void Castle::set_flag(){
    Room* lobby = get_room(current_pos);
    Room* princess = get_room(pos_princess);
    Room* monster = get_room(pos_monster);

    (*lobby).set_type("lobby");
    (*princess).set_type("princess");
    (*monster).set_type("monster");

    (*lobby).init_exit();
};

//* generate path from pos1 to pos2
void Castle::path_generator(int* pos1, int* pos2){
    int* transition_pos = 0;
    transition_pos = pos_connect(pos1, pos2, 0);
    transition_pos = pos_connect(transition_pos, pos2, 1);
    transition_pos = pos_connect(transition_pos, pos2, 2);
}


int* Castle::pos_connect(int*p1, int*p2, int dim){
    int num_layer = p2[dim] - p1[dim];
    int *trans_pos;
    array_copy(trans_pos, p1);

    if (num_layer < 0){
        trans_pos[dim] = p2[dim];
        num_layer = -num_layer;
    }
    else;
    string direction = dim2go[dim];
    Room* temp_room = 0;
    for (int i=0;i<num_layer;i++){
        trans_pos[dim] ++;
        temp_room = get_room(trans_pos);
        (*temp_room).set_exit(direction, 1);
    }

    trans_pos[dim] = p2[dim];
    return trans_pos;
}


void Castle::go_to(string direction){

    
};


//* check whether there is an exit on the wall of the castle
void Castle::check_walls(int*pos){
    Room* temp = get_room(pos);
    int box[] = {max_width, max_length, max_level};
    for(int i=0;i<dimensions;i++){
        if (pos[i] == 0){
            fix_walls(temp, i, 0);
        }
        else if (pos[i] == box[i]){
            fix_walls(temp, i, 1);
        };
    };
};

//* fix the hole on the wall
void fix_walls(Room* room, int dim, bool ceil){
    
    
};


void array_copy(int*a, int*b){
    for(int i=0;i<dimensions;i++){
        a[i] = b[i];
    };
};



