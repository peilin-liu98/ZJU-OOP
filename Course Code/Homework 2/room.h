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
        void init_exit(string into);
        void init_exit();
        void set_found();
        bool explored();
        void set_type(string type);
        void set_exit(string direction, bool status);
        bool get_status(int type); 
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


static int rand_num(int upper){
    //* upper cannot be achieved
    int random = 0;
    srand((unsigned)time(NULL));
    random = rand() % upper;
    return random;
};

