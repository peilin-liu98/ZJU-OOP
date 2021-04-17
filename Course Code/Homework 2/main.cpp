#include <iostream>
#include <string>
#include "castle.h"

using namespace std;

extern const int dimensions;
extern int rand_num(int upper);
extern const int box[]; 
void pos_generator(int num, int (*pos)[dimensions]);
bool pos_check(int *pos1, int *pos2);

int main(){
    //* Game Setup
    
    //* Generate the postions of monster, princess and lobby

    const int num_character = 3;
    int (*pos)[dimensions] = new int[num_character][dimensions];
    

    //* Ensure that three positions generated randomly are different.
    int check = 1;
    while(check > 0){
        pos_generator(num_character, pos);
        check = pos_check(pos[0],pos[2]) + pos_check(pos[1], pos[2]) 
        + pos_check(pos[0], pos[1]); 
    };
    
    //* Test Data
    //* monster: pos[0][0] = 1; pos[0][1] = 3; pos[0][2] = 4;
    //* princess: pos[1][0] = 3; pos[1][1] = 2; pos[1][2] = 1;
    //* lobby: pos[2][0] = 1; pos[2][1] = 0; pos[2][2] = 2;


    pos[0][0] = 1; pos[0][1] = 3; pos[0][2] = 4;
    pos[1][0] = 3; pos[1][1] = 2; pos[1][2] = 1;
    pos[2][0] = 1; pos[2][1] = 0; pos[2][2] = 2;
    

    //* Initialize the Castle
    Castle castle(pos[0], pos[1], pos[2]);
    castle.set_game();
    delete[] pos;

    //* Set Flags for Game Status and Princess
    //* Four kinds of Game Status: 
    //* normal status(search for princess); death(meet monster); 
    //* servant mode(find princess); mission completed(back to lobby with princess)
    int flag = 0;                //* flag = 2 Mission Completed; flag = -2 Game Over.
    int princess = 0;            //* princess = 1 indicates that princess are guarded by you now.
    
    
    string command[2];

    while (flag != 2){
        
        cout << "Enter your command: " << endl;
        cin >> command[0] >> command[1];

        
        if (castle.check_way(command[1]) == 0){
            cout << "You Hit against the Wall!!! Please Choose Another Direction!!!" << endl;
        }
        else{
            castle.go_to(command[1]);
            flag = castle.get_status();
            if (flag < 0){
                cout << "Killed by the Monster. Game Over!" << endl;
                break;
            }
            else if (flag > 0 && princess == 0){
                cout << "Meet Princess. Try to Find the Way Out!" << endl;
                princess = 1;
            }; 
            castle.print();
        };   
    };  
    
    if (flag == 2){
         cout << "You Arrived the Lobby with Princess. Mission Completed!" << endl;
    };

    return 0;
}

void pos_generator(int num, int (*pos)[dimensions]){
    int i,j = 0;
    int random = 0;
    srand((unsigned)time(NULL));
    for (i=0;i<num;i++){
        for (j=0;j<dimensions;j++){
            random = rand() % border[j]; 
            pos[i][j] = random;
        };
    };
}

bool pos_check(int *pos1, int *pos2){
    bool flag = 1;
    for(int i=0;i<dimensions;i++){
        if(pos1[i] != pos2[i]){
            flag = 0;
            break;
        };
    };
    return flag;
}