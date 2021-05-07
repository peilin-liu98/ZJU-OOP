#include "diary.h"

using namespace std;

int main(int argc, char** argv){

    string time = "";
    time = time + argv[1] + " " + argv[2] + " " +argv[3];
    int t = string2time(time);
    // int t = 20210508;

    //* Load Memory
    Diary d;
    read_memory(d);

    //for(auto p:d.list_date())
    //  cout << p << endl;
    
    vector<string> text;
    string line;

    if(d.search_date(t) != 0)
        d.rm(t);

    while(getline(cin, line)){
        if (line == ".")
            break;
        else
            text.push_back(line);
    };

    d.add_diary(t, text);
    

    output(d);

    return 0;
}
