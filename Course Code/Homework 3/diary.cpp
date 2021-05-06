#include "diary.h"
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

int Diary::search_date(int time) const {
    int flag = (date.find(time) == date.end() ? 0:1);
    return flag;
};

void Diary::add_diary(int time, vector<string> & text) {
    content.insert({time, text});
    date.insert(time);
};

vector<int> Diary::list_date(int begin, int end) const {

    vector<int> d_ls;
    for (auto ptr=date.lower_bound(begin); ptr!=date.upper_bound(end); ptr++)
        d_ls.push_back(*ptr);

    return d_ls;
};

void Diary::show(int time) const {

    auto ptr = content.find(time);
    const vector<string> &text = (*ptr).second;

    string t = to_string(time);
        cout << t.substr(0,4) << " "
             << t.substr(4,2) << " "
             << t.substr(6) << endl;

    for (auto p=text.begin(); p!=text.end(); p++)
        cout << *p << endl;

    cout << endl;
};

int Diary::rm(int time) {
    
    int num1 = date.erase(time);
    int num2 = content.erase(time);

    if (num1 != num2)
        cout << "Something goes wrong! Check the program." << endl;

    return num1;

}



