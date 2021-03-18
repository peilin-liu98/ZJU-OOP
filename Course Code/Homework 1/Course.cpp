#include <string>
#include "Course.h"
using namespace std;


void Course::init(string course_name)
{
    name = course_name;
    max = 0;
    min = 5;
    sum = 0;
    num = 0;
};


void Course::process(int course_score)
{
    if (course_score > max) max = course_score;
    if (course_score < min) min = course_score;
    sum += course_score;
    num ++;
};
    
string Course::get_name()
{
    return name;
};


int Course::max_score()
{
    return max;
};


int Course::min_score()
{
    return min;
};


float Course::avg_score()
{
    avg = sum/num;
    return avg;
};
