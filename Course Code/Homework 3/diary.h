#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Diary{
    public:
    int search_date(int time) const;
    void add_diary(int time, vector<string> & text);  //* 同时修改map与set
    vector<int> list_date(int begin = 0, int end = 99999999) const;
    void show(int time) const;
    int rm(int time);

    private:
    map<int, vector<string> > content;
    set<int> date;
};


int string2time(string line){

    stringstream t(line);
    vector<int> date;
    int time = 0;
    
    while(t >> time)
        date.push_back(time);

    time = date[0] * 10000 + date[1] * 100 + date[2];
    return time;

};

void read_memory(Diary &d){

    string line;
    int time = 0;
    vector<string> temp;

    while(getline(cin,line))
    {
        time = string2time(line);
        while(getline(cin,line)){
            if (line.empty() == true){
                d.add_diary(time, temp);
                break;
            }
            else{
                temp.push_back(line);
            };
        };    
    };
};

void output(Diary &d){
    
    vector<int> date(d.list_date());
    for(auto ptr=date.cbegin(); ptr!=date.cend(); ptr++)
        d.show(*ptr);
};




