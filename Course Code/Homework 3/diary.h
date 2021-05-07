#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Diary{
    public:
    int search_date(int time) const;                                    //* check the date, return 0/1 
    void add_diary(int time, vector<string> & text);                    //* add new diary pair (time, text)
    vector<int> list_date(int begin = 0, int end = 99999999) const;     //* return the entities between the start and the end
    void show(int time) const;                                          //* show the text of the specified date
    int rm(int time);                                                   //* remove the diary pair, return 0/-1

    private:
    map<int, vector<string> > content;
    set<int> date;
};


static int string2time(string line){
    
    //* change type of time record from string to int
    //* e.g. "2021 04 22" -> 20210422

    stringstream t(line);
    vector<int> date;
    int time = 0;
    
    while(t >> time)
        date.push_back(time);

    time = date[0] * 10000 + date[1] * 100 + date[2];
    return time;

};

static void read_memory(Diary &d){
    
    //* read data from local file "diary.txt" and load it into object diary
    
    string line;
    int time = 0;
    vector<string> temp;
    ifstream filein("diary.txt");


    while(getline(filein,line))
    {
        if (line.empty() == true)
            break;
        time = string2time(line);
        while(getline(filein,line)){
            if (line.empty() == true){
                d.add_diary(time, temp);
                temp.clear();
                break;
            }
            else{
                temp.push_back(line);
            };
        };    
    };
    filein.close();
};

static void output(Diary &d){
    
    //* rewrite the local file "diary.txt" to store memory
    
    ofstream fileout;
    fileout.open("diary.txt");
    
    auto backup = cout.rdbuf();
    cout.rdbuf(fileout.rdbuf());

    vector<int> date(d.list_date());
    for(auto ptr=date.cbegin(); ptr!=date.cend(); ptr++)
        d.show(*ptr);  
    cout << endl;

    cout.rdbuf(backup);
    fileout.close();
};




