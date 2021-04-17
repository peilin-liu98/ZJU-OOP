#include <string>
#include <time.h>

using namespace std;

const int num_type = 3;
const int directions = 6;
const string choices[directions] = {"down","south", "east", "west","north","up"};
const bool default_exits[] = {0,0,0,0,0,0};
const bool default_status[] = {0, 0, 0}; 

class Room {

    public:
        Room() : type("ordinary"), found(0), num_exits(0) { init();};
        ~Room();
        void init();
        void init_exit();
        void init_exit(string into);
        void set_found();
        bool explored() const;
        void set_type(string settype);
        void set_type(int type);
        void set_exit(string direction, bool status);
        bool get_status(int type) const;
        bool get_connection(int direction) const; 
        void print();

    private:
        string type;
        bool *exits;
        bool found;
        int num_exits;
        bool *room_status;
};

static int go2num(string go){
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

