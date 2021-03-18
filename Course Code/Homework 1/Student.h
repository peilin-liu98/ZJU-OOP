#include <string>

using namespace std;

class Student{

private:
    string student_name;
    string *personal_ls;            // Course Lists of Student
    int *personal_score;            // Grade Lists of Student
    int personal_num;               // Number of the Courses Someone Took
    float personal_sum;             // Sum of Scores of All Courses
    float peronal_avg;              // Aaverage of Scores of All Courses
    

public:
    // Initialization
    void init(string input_name, int max_num);

    // Process Input Record and Return Signal to Stop Input
    int input_record(string course_name, int course_score = 0);

    // Return the Name of Student
    string name();

    // Get Score of Assigned Course
    int get_score(string course_name);

    // Calc GPA
    float avg_score();

    // Free Allocated Space
    void clear();
};

