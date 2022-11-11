#include "Gpa.h"
using namespace std;

int main(){
    cout << fixed << setprecision(2);


    string name;
    

    int choice;
    do{
        cout << "What is Your Name? ";
        getline(cin, name);
        Gpa one(name);

        //display menu
        one.menu();

        //get user's choice
         choice = one.getChoice();
        if(choice == 1){

            //get the amount of courses the user takes and prompt the user for the grade of each class
            double total = one.getGrades();
        
            //Take The total & divide it by the number of courses entered in
            one.calculations(total);
            

            //calculate GPA
            one.gpa();

            cout << "\nPress Enter To Prompt Menu When Ready: ";
            cin.get();
            cin.get();
            
            
            
        }
        
    }while(choice != 2);


    return 0;

}