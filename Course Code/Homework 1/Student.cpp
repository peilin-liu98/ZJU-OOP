#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

//Initialization with the Student's name
void Student::init(string input_name, int max_num)
{
    student_name = input_name;
    personal_num = 0;
    personal_sum = 0;
    personal_ls = new string[max_num];
    personal_score = new int[max_num];
};


string Student::name() {
    return student_name;
};


float Student::avg_score()
{
    peronal_avg = personal_sum/personal_num;
    return peronal_avg;
};


void Student::clear()
{
    delete[] personal_ls;
    delete[] personal_score;
};


int Student::input_record(string course_name, int course_score)
{
    int end = 0;
    if (course_name == "END")
    {
        end = 1;
    }
    else
    {
        personal_ls[personal_num] = course_name;
        personal_score[personal_num] = course_score;
        personal_num ++;
        personal_sum += course_score; 
    };

    return end;
};


int Student::get_score(string course_name)
{
    int id;
    int id_score = -1;
    for(id=0;id<personal_num;id++)
    {
        if (personal_ls[id] == course_name)
        {
            id_score = personal_score[id];
            break;
        }
    };
    return id_score;
};
