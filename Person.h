#ifndef __Person_H__
#define __Person_H__

#include <string>
#include <iostream>

class Person
{
private:
    /* data */
    std::string name;
    int age;
    static int Number_of_persons;
public:
    Person();   
    ~Person();
    void Add_Record(std::string, int);
    Person Fetch_Record(void);
    void Print_Student(void);
    static int Return_Number_Of_Students();
};

enum class options{
    RECORD = 1,
    FETCH, 
    EXIT
};

#endif