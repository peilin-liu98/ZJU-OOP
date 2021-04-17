#include <iostream>
#include <string>
#include "castle.h"

using namespace std;

extern const int dimensions;
extern int rand_num(int upper);
extern const int box[]; 
void pos_generator(int num, int (*pos)[dimensions]);

int main(){
    //* Game Setup
    
    //* Generate the postions of monster, princess and lobby

    const int num_character = 3;
    int (*pos)[dimensions] = new int[num_character][dimensions];
    pos_generator(num_character, pos);
    
    //* Test Data
    //* pos[0][0] = 4; pos[0][1] = 4; pos[0][2] = 2;
    //* pos[1][0] = 1; pos[1][1] = 4; pos[1][2] = 2;
    //* pos[2][0] = 3; pos[2][1] = 4; pos[2][2] = 2;
    

    //* Initialize the Castle
    Castle castle(pos[0], pos[1], pos[2]);
    castle.set_game();
    delete[] pos;

    //* Game Flag for princess
    int flag = 0;
    int princess = 0;
    //* {meet monster; lost princess; find princess; escape with princess;} 
    string command[2];

    while (flag != 2){
        cout << "Enter your command: " << endl;
        cin >> command[0] >> command[1];
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
    
    if (flag == 2){
         cout << "You Arrived the Lobby with Princess. Mission Completed!" << endl;
    };

   

    return 0;
}

void pos_generator(int num, int (*pos)[dimensions]){
    int i,j = 0;
    for (i=0;i<num;i++){
        for (j=0;j<dimensions;j++){
            pos[i][j] = rand_num(box[j] + 1);
        };
    };
}
