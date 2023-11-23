#include <iostream>

using namespace std;

class Person
{
    public:
        Person (int id, string name) 
        {
            input (id, name);
        }
        ~Person () {};
        void input (int id, string name)
        {
            ID = id;
            Name = name;
        }
        void display ()
        {
            cout << "ID: " << ID << " Name: " << Name << endl;
        }
    private:
        int ID;
        string Name;
};

class Student: virtual public Person
{   
    public:
        Student (int id, string name): Person(id, name) {};
        ~Student () {};
        void input (int num, float grade)
        {
            Class_num = num;
            Grade = grade;
        }
        void display ()
        {
            cout << "Class_num: " << Class_num << " Grade: " << Grade << endl;
        }
    private:
        int Class_num;
        float Grade;
};

class Teacher: virtual public Person
{
    public:
        Teacher (int id, string name): Person(id, name) {};
        ~Teacher () {};
        void input (string level, string department)
        {
            Level = level;
            Department = department;
        }
        void display ()
        {
            cout << "Level: " << Level << " Department: " << Department << endl;
        }
    private:
        string Level, Department;
};

class TeachAssistant: public Student, public Teacher
{
    public:
        TeachAssistant (int id, string name, int wage): Person(id, name), Student(id, name), Teacher(id, name), Wage(wage) {};
        ~TeachAssistant () {};
        void display ()
        {
            cout << "Wage: " << Wage << endl;
        }
    private:
        int Wage;
};

int main ()
{
    Student stu(1, "小张");
    Teacher tea(10, "王老师");

    stu.input(67, 98.2);
    tea.input("副高", "计网院");

    stu.Person::display();
    stu.display();
    cout << endl;

    tea.Person::display();
    tea.display();
    cout << endl;

    TeachAssistant ass(20, "刘恺", 3500);
    ass.Student::input(85, 87.3);
    ass.Teacher::input("助理", "商学院");
    ass.Person::display();
    ass.Student::display();
    ass.Teacher::display();
    ass.display();

    return 0;
}