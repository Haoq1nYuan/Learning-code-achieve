#include <iostream>

using namespace std;

class Date
{
    public:
        Date (int y, int m, int d): year(y), month(m), day(d) {}
        Date (Date &date)
        {
            year = date.year;
            month = date.month;
            day = date.day;
        }
        ~Date () {};
        void display () 
        {
            cout << year << ':' << month << ':' << day << endl;
        }
    private:
        int year, month, day;
};

class People
{
    public:
        People (int num, string s, int y, int m, int d, int i): birthday(y, m, d)
        {
            number = num;
            sex = s;
            id = i;
        }
        People (People &p): birthday(p.birthday)
        {
            number = p.number;
            sex = p.sex;
            id = p.id;
        }   
        ~People () {};
        void display () 
        {
            cout << "The birthday of " << sex << ' ' << number << " with id" << id << " is: ";
            birthday.display();
        }
    
    private:
        int number, id;
        string sex;
        Date birthday;
};

int main ()
{
    People p1(1001, "male", 2004, 5, 24, 358);
    People p2(1002, "female", 2003, 9, 17, 360);

    p1.display();
    p2.display();

    return 0;
}