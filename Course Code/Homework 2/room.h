#include <string>

using namespace std;

const int directions = 6;
const string choices[directions] = {"down","south", "east", "west","north","up"};
const bool lobby_exits[] = {0,0,0,1,1,1};
static bool default_exits[] = {0,0,0,0,0,0}; 

class Room {

    public:
        Room() : type("ordinary"), found(0), num_exits(0), exits(default_exits) 
        {};
        void init_exit(string into);
        void init_exit();
        bool explored();
        void set_type(string type);
        void set_exit(string direction, bool status);
        void print();

    private:
        string type;
        bool *exits;
        bool found;
        int num_exits;
};
