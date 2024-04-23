#include "Person.h"

Person::Person(/* args */)
{
    name = "";
    age = 0;
}

Person::~Person()
{
    std::cout << "Person was deleted: " << "\n";
}
void Person::Add_Record(std::string Local_String, int Local_Age)
{
    Number_of_persons++;
    name = Local_String;
    age = Local_Age;
}
Person Person::Fetch_Record(void)
{
    Person Local_Variable;
    Local_Variable.name = name;
    Local_Variable.age = age;
    return Local_Variable;
}
void Person::Print_Student(void)
{
    if(name.empty())
    {
        std::cout <<"No user found: "<<"\n";
    }
    else
    {
        std::cout <<"User Name : "<< name << "\n";
        std::cout << "User Age : "<< age << "\n";
    }

}

int Person::Return_Number_Of_Students()   // to acces static variable 
{
    return Number_of_persons;
}

int Person::Number_of_persons = 0; // initialize static variable 
