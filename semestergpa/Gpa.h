#ifndef GPA_H
#define GPA_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


class Gpa{

    public:
    //Constructors
    Gpa();
    Gpa(string n);
    ~Gpa();
    
    
    void menu();
    int getChoice();
    double getGrades();
    void calculations( double);
    void gpa();

    private:
    string name;//to get the user's name
    int numOfCourse; //to get the user's number of courses
    double average;
    vector<string>classNames{};//to store the courses taken by the user
};

#endif