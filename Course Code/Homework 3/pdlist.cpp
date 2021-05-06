#include "diary.h"

using namespace std;

int main(int argc, char** argv){

    int beg, tail;
    if(argv[1] == ""){
       beg = 0;
       tail = 99999999; 
    }
    else{
        string start = "", end = "";
        start = start + argv[2] + " " + argv[3] + " " +argv[4];
        end = end + argv[6] + " " + argv[7] + " " +argv[8];
        beg = string2time(start);
        tail = string2time(end);
    }
    Diary d;
    read_memory(d);

    const vector<int> & ls(d.list_date(beg, tail));
    for (auto p=ls.cbegin(); p!=ls.cend(); p++)
        cout << *p << endl;
    
    return 0;
}
