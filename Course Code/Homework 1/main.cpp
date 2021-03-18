#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include "Student.h"
#include "Course.h"

using namespace std;

void input_record(Student* s, Course* c, int* course_num, int* len);
void course_check(Course*c, int* course_num, string c_name, int c_score);
int main()
{

    int max_student = 256;      // the Maxium Number of Student Record
    int max_course = 256;       // the Maxium Number of Course Record
    int max_select = 32;        // the Maxium Number of Courses One can Take
    int max_length = 8;         // Record the Maxium Length of String for Table Format
    string table = "";

    Student* s_ls = new Student[max_student];
    int student_num = 0;

    Course* c_ls = new Course[max_course];
    int course_num = 0;

    cout << "Note: Please Input 'END' for Course Name or Student Name " 
         << "to Stop Record Input, Any Number for Course Score" << endl;



// Input Record

    string student_name;
    while(true)
    {
        cout << "Please Input the Student's Name: ";
        cin >> student_name;
        if (student_name == "END") break;
        else
        {
            // Initialize Student Object
            s_ls[student_num].init(student_name, max_select); 
            if (student_name.length() > max_length) max_length = student_name.length();
            // Begin to Record (Name, Score) Item
            input_record(&s_ls[student_num], c_ls, &course_num, &max_length);
            student_num ++;
          }
    };

//Output Data in Table Format

    int len = 1;
    len = max_length/8 + 1;

    // Make Format
    int l;
    for(l=0;l<len;l++)
    {
        table += "\t";
    }
    max_length = 8 * l;


    ofstream file("./out.txt");
    // Output Course List in First Row
    int k,p = 0;
    file << "no" << table << "name" << table;
    
    string course_name;
    string course_ls[course_num];
    float course_reord[3][course_num];
    for (k=0;k<course_num;k++)
    {
        course_name = c_ls[k].get_name();
        file << left << setw(max_length) << course_name ; 

        // Record Data for Max, Min, Avg Rows
        course_reord[0][k] = c_ls[k].avg_score();
        course_reord[1][k] = c_ls[k].min_score();
        course_reord[2][k] = c_ls[k].max_score();
    };
    file << "average" << table << endl;


    // Output Student's Record
    int score = 0;
    for (p=0;p<student_num;p++)
    {
        file << p+1 << table << s_ls[p].name()
             << table;//setw(max_length - s_ls[p].name().length());
        for (k=0;k<course_num;k++)
        {
            course_name = c_ls[k].get_name();
            score = s_ls[p].get_score(course_name);
            if (score == -1){
                file << "Nan" << table;
            }
            else{
                file << score << table;
            };
        };
        file << s_ls[p].avg_score() << table << endl;
    };

    // Output Max, Min, Avg Rows
    string summary[3] = {"average","min","max"};
    int j = 0;
    for(j=0;j<3;j++)
    {
        file << table << summary[j] << table;
        for (k=0;k<course_num;k++)
        {
            file << course_reord[j][k] << table;
        };
        file << endl;
    };


// Free Allocated Space
    for (p=0;p<student_num;p++)
    {
        s_ls[p].clear();
    };

    delete[] s_ls;
    delete[] c_ls;

    return 0;

}


// Input Course Information into Student Object and Do Course Check
void input_record(Student* s, Course* c, int* course_num, int* len)
{
    string s_course;
    int s_score = 0;
    int end = 0;

    if (s_course.length() > *len) *len = s_course.length();

    while(true)
    {
        cout << "Please Input the Course " << (*s).name() << " Took " 
             << "and the Corresponding Score: Seperated with WhiteSpace: ";
        cin >> s_course >> s_score;

        end = (*s).input_record(s_course, s_score);
        if (end == 1) break;
        // Do Course Check
        else course_check(c, course_num, s_course, s_score);
    };
}


// Check Course for Avoiding Redundancy and Update Score Record
void course_check(Course*c, int* course_num, string c_name, int c_score)
{
    int k = 0;
    int check = 0;

    for (k=0;k<*course_num;k++)
    {
        if (c[k].get_name() == c_name)
        {
            // Course Already in Record,
            check = 1;
            // Update Score
            c[k].process(c_score);
            break;
        };
    };

    // Add New Course
    if (check == 0)
    {
        c[*course_num].init(c_name);
        c[*course_num].process(c_score);
        *course_num = *course_num + 1;
    };

}



























