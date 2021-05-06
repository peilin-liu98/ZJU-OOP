#include "diary.h"

using namespace std;

int main(int argc, char** argv){

    string time = "";
    time = time + argv[1] + " " + argv[2] + " " +argv[3];

    Diary d;
    read_memory(d);

    int t = string2time(time);
    d.show(t);

    return 0; 
}