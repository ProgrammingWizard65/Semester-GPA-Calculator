#include "Gpa.h"
using namespace std;


Gpa::Gpa():name("Default"),numOfCourse(0), average(0.0){}
Gpa::Gpa(string n):name(n),numOfCourse(0), average(0.0){}
Gpa::~Gpa(){cout << "Thank You :) " << name << endl;}




/***************** void menu function ******************/

void Gpa::menu(){
    cout << "Hello " << name << ". Welcome To The Program!" << endl;
    cout << "\n\t#1: Proceed To Calculate Semester GPA" << endl;
    cout << "\t#2: Quit" << endl;

}

/***************** int getChoice function ******************
 * Receives the choice from the user and validates their choice */


int Gpa::getChoice(){
    int input;
    cout << "\n\tWhich Option Would You Like To Select? ";
    cin >> input;
    while(input != 2 && input != 1){
        cout << "Invalid Choice Selection: Pick Again using #'s 1 or 2: ";
        cin >> input;
    }
    return input;
}

/***************** double getGrades function******************
 * Prompts The User How Many Courses They are Taken and what each course name is
 * Then prompts the user to enter in their numeric grade for each course
 * Then prints to the console the list of courses they are taking */


double Gpa::getGrades(){
    cout << "\nHow many courses are you taking at the moment that you have a grade for? ";
    cin >> numOfCourse;
     while(numOfCourse < 1){
        cout << "Must be taking at least 1 course, please enter again: ";
        cin >> numOfCourse;
    }
    
   
    cin.ignore();

    for(int i = 1; i <= numOfCourse; i++){
        cout << "What is the name of course " << i << ": ";
        string nameOfCourse;
        getline(cin, nameOfCourse);
        classNames.push_back(nameOfCourse);

    }

    double grade; //to keep track of the grades the user enters
    double total = 0.0; //the accumulator for the grades which will be divided to get the average

    cout << endl;
    cout << "You will now enter your grades for each course in numeric values (example: 87.52)" << endl;
    for(string i: classNames){
        cout << "Enter grade for " << i << ": ";
        cin >> grade;
        while(grade > 100.00 || grade < 0.0){
            cout << "Grade has to be between 0.0% and 100.00%, Please enter again: ";
            cin >> grade;
        }
        total += grade;
    }

    cout << "\nNumber Of Courses Being Taken: " << numOfCourse << endl;
    cout << "List Of Classes: " << endl;
    for(string i: classNames){
        cout << "\t" << i << endl;
    }
    classNames.clear();
    return total;
}

/***************** double calculations functon ******************
 * Computes The Average For the User's Grades to determine the gpa & letter grade */



void Gpa::calculations( double gradeTotal){
    average = gradeTotal/numOfCourse;
    cout << "\nYour Average For The Semester Is: " << average << "%. " << endl;
}


/***************** void gpa functions ******************
 * Depending on your average, this function will tell you the letter grade and gpa associated with your grade */


void Gpa::gpa(){
    if(average >= 97.0){
        cout << "Letter Grade: A+\nGPA = 4.0." << endl;
    }
    else if(average >= 93){
        cout << "Letter Grade: A\nGPA = 4.0." << endl;
    }
    else if(average >= 90){
        cout << "Letter Grade: A-\nGPA = 3.7. " << endl;
    }
    else if(average >= 87){
        cout << "Letter Grade: B+\nGPA = 3.3. " << endl;
    }
    else if(average >= 83){
        cout << "Letter Grade: B\nGPA = 3.0. " << endl;
    }
    else
        cout << "GPA is lower than 3.0." << endl;
    

}
