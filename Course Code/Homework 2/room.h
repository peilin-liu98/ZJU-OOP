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
        void init();                                    //* Init exits and room status
        void init_exit();                               //* Init exits for lobby
        void init_exit(string into);                    //* Init exits for go-into room
        void set_found();                               //* Indicating that player has visited the room
        bool explored() const;                          //* Return vlaue of found 
        void set_type(string settype);                  //* Room type("ordinary", "lobby", "princess", "monster")
        void set_type(int type);
        void set_exit(string direction, bool status);   //* Set the specific exit of one room open or closed
        bool get_status(int type) const;                //* Return Room Status 
        bool get_connection(int direction) const;       //* Check whether there is an exit to the specific direction
        void print();                                   //* Print Room Information

    private:
        string type;
        bool *exits;
        bool found;
        int num_exits;
        bool *room_status;
};

//* Return the index of one direction
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

