#include <string>
using namespace std;


class Course
{
private:
    string name;
    int max;
    int min;
    int num;
    float sum;
    float avg;

public:

    // Initialize New Course
    void init(string course_name);

    // Record Scores and Calc Sum, Max, Min 
    void process(int course_score);

    // Return Name of Course
    string get_name();

    // Return Max, Min, Avg
    int max_score();
    int min_score();
    float avg_score();
};
