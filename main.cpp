/* Michael-Andre Odusami */
//This program tells the user their average for the semester using the number of courses they take and the grade they received for it. 
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void menu();
int getChoice();
double getGrades(int&, vector<string>& classNames);
double calculations(int, double);
void gpa(double);

int main(){
    cout << fixed << setprecision(2);
    cout << "This Program Calculates Your Semester GPA" << endl;
    cout << "-----------------------------------------" << endl;

    int choice; //whether the user wants to quit the program or not
    double total; //getting the total amount from the user's grades added up
    int numOfCourse; //to get the user's number of courses
    double average;
    vector<string>classNames{};

    do{
        //display menu
        menu();

        //get user's choice
        choice = getChoice();
        if(choice == 1){

            //get the amount of courses the user takes and prompt the user for the grade of each class
            total = getGrades(numOfCourse, classNames);
        
            //Take The total & divide it by the number of courses entered in
            average = calculations(numOfCourse,total);
            cout << "\nYour Average For The Semester Is: " << average << "%. " << endl;

            //calculate GPA
            gpa(average);

            cout << "\nPress Enter To Prompt Menu When Ready: ";
            cin.get();
            cin.get();
            classNames.clear();
            
            
        }
        
    }while(choice != 2);


    return 0;

}

/***************** void menu function ******************/

void menu(){
    cout << "\n\t#1: Proceed To Calculate Semester GPA" << endl;
    cout << "\t#2: Quit" << endl;

}

/***************** int getChoice function ******************
 * Receives the choice from the user and validates their choice */


int getChoice(){
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


double getGrades(int &courses, vector<string>& classNames){
    cout << "\nHow many courses are you taking at the moment that you have a grade for? ";
    cin >> courses;
    cin.ignore();

    for(int i = 1; i <= courses; i++){
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

    cout << "\nNumber Of Courses Being Taken: " << courses << endl;
    cout << "List Of Classes: " << endl;
    for(string i: classNames){
        cout << "\t" << i << endl;
    }
    return total;
}

/***************** double calculations functon ******************
 * Computes The Average For the User's Grades to determine the gpa & letter grade */



double calculations(int courses, double gradeTotal){
    double average = gradeTotal/courses;
    return average;

}


/***************** void gpa functions ******************
 * Depedning on your average, this function will tell you the letter grade and gpa associated with your grade */


void gpa(double avg){
    if(avg >= 97.0){
        cout << "Letter Grade: A+\nGPA = 4.0." << endl;
    }
    else if(avg >= 93){
        cout << "Letter Grade: A\nGPA = 4.0." << endl;
    }
    else if(avg >= 90){
        cout << "Letter Grade: A-\nGPA = 3.7. " << endl;
    }
    else if(avg >= 87){
        cout << "Letter Grade: B+\nGPA = 3.3. " << endl;
    }
    else if(avg >= 83){
        cout << "Letter Grade: B\nGPA = 3.0. " << endl;
    }
    else
        cout << "GPA is lower than 3.0." << endl;
    

}
