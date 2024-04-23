/*
    Author : Mohamed El Nabawy 
    Date : 23/4/2024

    Project name : Sign up application 
*/
#include <iostream>
#include <array>
#include <string>
#include "Person.h"
using namespace std;
/*      constans        */
constexpr int NUMBER_OF_STUDENTS = 100;  // maximum number of students
bool EXIT_PROGRAM = 1;   // flag

/*      prototypes      */
void Show_Message(void);          // this funtion print messeges for user to select process
std::istream & operator >>(std::istream &, options &);   // operator overloading for cin for (enum data type)

int main()
{
    array <Person, NUMBER_OF_STUDENTS> Students;  // to store all data for all students
    options Op;
    string Local_string = "";
    int Local_age = 0;
    int iterator = -1;
    int User_Id = 0;

    while(EXIT_PROGRAM)
    {
        Show_Message();
        cout <<"Enter Option: ";
        cin >> Op;   // make operator over loading function 
        cout << "\n";
        switch (Op)
        {
        case options::RECORD:
            if(iterator > NUMBER_OF_STUDENTS-1)      // if array space is used  
            {
                cout << "not enough space : " <<"\n";
            }
            else
            {
                cout <<"Please enter your name and age"<<"\n";
                cout <<"Name: ";
                cin >> Local_string;
                cout << "Age: ";
                cin >> Local_age;
                Students[++iterator].Add_Record(Local_string, Local_age);
                cout <<"\n";
            }   
            break;
        case options::FETCH:        // get specific studen's data 
            cout << "Please Enter user ID: "<<"\n";
            cout << "User ID: ";
            cin >> User_Id;
            if(User_Id >= NUMBER_OF_STUDENTS)
            {
                cout << "User Not exist in system(out of bound)"<<"\n";
            }
            else
            {
                Person Local_Variable = Students[User_Id].Fetch_Record();
                Local_Variable.Print_Student();
            }
            break;
        case options::EXIT:        // exit program 
            EXIT_PROGRAM = 0;
            break;
        default:
            cout << "Invalid option, please try again: " <<"\n";
            break;
        }
    }

}


/*         fucntions body      */
void Show_Message(void)
{
    cout << "Please select an option: "<< "\n";
    cout << "1: Add Record:"<<"\n";
    cout << "2: Fetch Record:" <<"\n";
    cout << "3: Exit:" << "\n";
}

std::istream & operator >>(std::istream & In_stream, options & result)
{
    int In_option;
    In_stream >> In_option;

    result = static_cast<options>(In_option);
    return In_stream;
}
