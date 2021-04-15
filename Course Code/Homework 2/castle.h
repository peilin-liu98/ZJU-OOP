#include <iostream>
#include <string>
#include "room.h"

using namespace std;

const int max_level = 50;
const int max_length = 50;
const int max_width = 50;


class Castle{
    public:
        Castle(int* pos_m, int* pos_p, int* pos_lobby) : 
            pos_monster(pos_m), pos_princess(pos_p), current_pos(pos_lobby) {};
        void set_flag();
        void path_generator(int* pos1, int* pos2);
        int* pos_connect(int*a, int*b, int dim);
        void go_to(string direction);
        void check_walls(int* pos);
        Room* get_room(int* pos);



    private:
        int* pos_monster;
        int* pos_princess;
        int* current_pos;
        Room rooms[max_level][max_length][max_width];

};
