#include <iostream>
#include <string>
#include "room.h"

using namespace std;

const int max_level = 3;
const int max_length = 3;
const int max_width = 3;
const int border[] = {max_width, max_length, max_level};
const int dimensions = 3;
const string fordirect2go[] = {"west","north","up"};
const string backdirect2go[] = {"east", "south", "down"};
static const string *walls[] = {backdirect2go, fordirect2go};


class Castle{
    public:
        Castle(int* pos_m, int* pos_p, int* pos_lobby) : 
        pos_monster(pos_m), pos_princess(pos_p), current_pos(pos_lobby), game_status(0) {};
        void set_game();
        void path_generator(int* pos1, int* pos2);
        int* pos_connect(int*p1, int*p2, int dim);
        void go_to(string direction);
        void check_walls(int* pos);
        bool check_way(string direction);
        int get_status();
        void print();
        Room* get_room(int* pos);



    private:
        int* pos_monster;
        int* pos_princess;
        int* current_pos;
        int game_status;
        Room rooms[max_level][max_length][max_width];

};
