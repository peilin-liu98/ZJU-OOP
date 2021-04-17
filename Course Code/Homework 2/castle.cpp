#include <iostream>
#include <string>
#include "castle.h"

using namespace std;

int* pos_connect(int*p1, int*p2, int dim);
void array_copy(int*a, int*b);
void fix_walls(Room* room, int dim, bool ceil);

Room* Castle::get_room(int* pos) {
    return & rooms[pos[0]][pos[1]][pos[2]];
};

int Castle::get_status() { return game_status; };

void Castle::print() { 
    Room *temp = get_room(current_pos);
    (*temp).print(); 
};


void Castle::set_game(){
    Room* lobby = get_room(current_pos);
    Room* princess = get_room(pos_princess);
    Room* monster = get_room(pos_monster);

    (*lobby).set_type("lobby");
    (*princess).set_type("princess");
    (*monster).set_type("monster");

    (*lobby).init_exit();
    (*lobby).set_found();
    check_walls(current_pos);
    
    path_generator(current_pos, pos_princess);
    path_generator(current_pos, pos_monster);

    cout << "Welcome to the lobby. ";
    (*lobby).print();
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
    int trans_pos[dimensions]; //! definition problem
    array_copy(trans_pos, p1); //* OKay

    if (num_layer < 0){
        trans_pos[dim] = p2[dim];
        num_layer = -num_layer;
    }
    else;
    string direction = fordirect2go[dim];
    Room* temp_room = 0;
    temp_room = get_room(trans_pos);

    for (int i=0;i<num_layer;i++){
        (*temp_room).set_exit(direction, 1); //! connection problem
        trans_pos[dim] ++;   
        temp_room = get_room(trans_pos);
        (*temp_room).init_exit(direction);
   };
    
    trans_pos[dim] = p2[dim];
    p1 = trans_pos;
    return p1;
}


void Castle::go_to(string direction){
    int num = go2num(direction);
    int dim = num - dimensions;
    int step = 0;
    if (dim < 0){
        dim = -dim;
        dim --;
        step = -1;
    } 
    else{
        step = 1;
    };
    current_pos[dim] += step;

    //* Initialize the current room
    Room* temp = get_room(current_pos);
    //! room_status initilization fail

    if ((*temp).explored() == 0){

        if ((*temp).get_status(2) == true){
            game_status = -2;
        }
        else if ((*temp).get_status(1) == true){
            game_status = 1;
        };
        (*temp).init_exit(direction);
        (*temp).set_found();
        //* Fix the hole to the outside
        check_walls(current_pos); 
    }
    else{
        game_status += (*temp).get_status(0);     
    };
};


//* check whether there is an exit on the wall of the castle
void Castle::check_walls(int*pos){
    Room* temp = get_room(pos);
    for(int i=0;i<dimensions;i++){
        if (pos[i] == 0){
            fix_walls(temp, i, 0);
        }
        else if (pos[i] == box[i]){
            fix_walls(temp, i, 1);
        };
    };
};

//* fix the holes on the wall
void fix_walls(Room* room, int dim, bool ceil){
    string hole = walls[ceil][dim];
    (*room).set_exit(hole, 0);
};


void array_copy(int*a, int*b){
    for(int i=0;i<dimensions;i++){
        a[i] = b[i];
    };
};



