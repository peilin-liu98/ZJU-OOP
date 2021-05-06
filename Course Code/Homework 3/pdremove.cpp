#include "diary.h"

using namespace std;

int main(int argc, char ** argv){

    string time = "";
    time = time + argv[1] + " " + argv[2] + " " +argv[3];
    int t = string2time(time);

    Diary d;
    read_memory(d);

    int flag = d.rm(t);
    (flag > 0) ? flag = 0 : flag = -1;
    cout << flag << endl;

    output(d);

    return 0;
}