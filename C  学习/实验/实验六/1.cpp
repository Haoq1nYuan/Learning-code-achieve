#include <iostream>

using namespace std;

class Date
{
    public:
        Date(int yy = 2000, int mm = 1, int dd = 1)
        {
            year = yy;
            month = mm;
            day = dd;
        }
        void setDate(int newyy, int newmm, int newdd)
        {
            year = newyy;
            month = newmm;
            day = newdd;
        }
        bool operator== (const Date &date) const;
        friend ostream& operator<< (ostream &out, const Date&);
    private:
        int year, month, day;
};

bool Date::operator== (const Date &date) const
{
    if (year == date.year && month == date.month && day == date.day) return true;
    else return false;
}

ostream& operator<< (ostream &out, const Date &date)
{
    out << date.year << "-" << date.month << "-" << date.day << endl;
    return out;
}

int main ()
{       
    Date date1(2004, 5, 24), date2(2005, 4, 22), date3(2004, 5, 24); 

    cout << "date1: " << date1;
    cout << "date2: " << date2;
    cout << "date3: " << date3;

    cout << "Is date1 equals date2: " << (date1 == date2) << endl;
    cout << "Is date1 equals date3: " << (date1 == date3) << endl;

    return 0;
}