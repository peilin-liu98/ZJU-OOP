#include <iostream>
#include <string>

using namespace std;


int main()
{
    int num = 10;                   //total number of students
    string name_ls[num];            //name list of students
    int score[3][num];              //table for recording scores
    int max[3] = {0, 0 ,0};         
    int min[3] = {5, 5, 5};
    float avg[3] = {0, 0, 0};
    int i,k,j;

    for (i=0; i<num; i++)
    {
        // input data ("name score1 score2 score3")
        cout << "Input the Student's Name: " << endl;
        cin >> name_ls[i]; 
        
        cout << "Input " << name_ls[i] << "'s Score1: " << endl;
        cin >> score[0][i];
        
        cout << "Input " << name_ls[i] << "'s Score2: " << endl;
        cin >> score[1][i];
        
        cout << "Input " << name_ls[i] << "'s Score3: " << endl;
        cin >> score[2][i];
        
        // calculate the sum of each subject score
        avg[0] += score[0][i];
        avg[1] += score[1][i];
        avg[2] += score[2][i];

        // find the maxmium and the minium of each subject score
        for (k=0; k<3; k++)
        {
            if (max[k] < score[k][i])
            {
                max[k] = score[k][i];
            };
            if (min[k] > score[k][i])
            {
                min[k] = score[k][i];
            }
        };

    };


    // output the title of the table 
    cout << "no" << "\t" << "name" << "\t" 
         << "score1" << "\t"
         << "score2" << "\t"
         << "score3" << "\t"
         << "average" << "\t"
         << endl;

    // output each item of the record
    for (j=0; j<num; j++)
    {
        cout << j+1 << "\t" 
             << name_ls[j] << "\t"
             << score[0][j] << "\t" 
             << score[1][j] << "\t" 
             << score[2][j] << "\t"
             << float((score[0][j] + score[1][j] + score[2][j]))/3 
             << endl;
    };

    // calculate the average score of each subject
    avg[0] = avg[0]/num;
    avg[1] = avg[1]/num;
    avg[2] = avg[2]/num;

    cout << "\t" << "average" << "\t" 
         << avg[0] << "\t"
         << avg[1] << "\t"
         << avg[2] << "\t"
         << endl;
 
    cout << "\t" << "min" << "\t" 
         << min[0] << "\t"
         << min[1] << "\t"
         << min[2] << "\t"
         << endl;

     cout << "\t" << "max" << "\t" 
         << max[0] << "\t"
         << max[1] << "\t"
         << max[2] << "\t"
         << endl;

       
    return 0;
}