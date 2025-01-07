#include <iostream>

using namespace std;

class employee
{
    public:
        employee(string name, int grade);
        ~employee() {};
        virtual void pay()=0;
        virtual void promote(int increment = 0) { grade += increment; }
        virtual void display()=0;
    protected:
        string name;
        int no;
        int grade;
        double Payl;
        static int MaxNo;
};

int employee::MaxNo = 1000;

employee::employee(string name, int grade)
{
    this->name = name;
    this->no = MaxNo;
    this->grade = grade;
    this->Payl = 0;
    MaxNo += 1;
}

class salesman: virtual public employee
{
    public:
        salesman(string name, int grade, double sales);
        void pay();
        void promote(int);
        void display();
    protected:
        double CommRate;
        double sales;
};

salesman::salesman(string name, int grade, double sales): employee(name, grade)
{
    this->CommRate = 0.04;
    this->sales = sales;
}

void salesman::pay()
{
    Payl = sales * CommRate;
}

void salesman::promote(int x)
{
    grade += x;
}

void salesman::display()
{
    cout << "姓名：" << name << " 编号：" << no << " 级别：" << grade << " 当月薪水：" << Payl << " 销售额：" << sales << endl;
}

class technician: public employee
{
    public:
        technician(string name, int grade, int hours);
        void pay();
        void promote(int);
        void display();
    private:
        int hourlyPay;
        int workHours;
};

technician::technician(string name, int grade, int hours): employee(name, grade)
{
    this->workHours = hours;
    this->hourlyPay = 100;
}

void technician::pay()
{
    Payl = workHours * 100;
}

void technician::promote(int x)
{
    grade += x;
}

void technician::display()
{
    cout << "姓名：" << name << " 编号：" << no << " 级别：" << grade << " 当月薪水：" << Payl << " 工作时间：" << workHours << endl;
}

class manager: virtual public employee
{
    public:
        manager(string name, int grade);
        void pay();
        void promote(int);
        void display();
    protected:
        double monthlyPay;
};

manager::manager(string name, int grade): employee(name, grade)
{
    this->monthlyPay = 10000;
}

void manager::pay()
{
    Payl = monthlyPay;
}

void manager::promote(int x)
{
    grade += x;
}

void manager::display()
{
    cout << "姓名：" << name << " 编号：" << no << " 级别：" << grade << " 当月薪水：" << Payl << endl;
}

class salesmanager: public manager, public salesman
{
    public:
        salesmanager(string name, int grade, int sales);
        void pay();
        void promote(int);
        void display();
    protected:
        double monthlyPay;
};

salesmanager::salesmanager(string name, int grade, int sales): employee(name, grade), manager(name, grade), salesman(name, grade, sales)
{
    this->monthlyPay = 6000;
    this->CommRate = 0.005;
}

void salesmanager::pay()
{
    Payl = monthlyPay + sales * CommRate;
}

void salesmanager::promote(int x)
{
    grade += x;
}

void salesmanager::display()
{
    cout << "姓名：" << name << " 编号：" << no << " 级别：" << grade << " 当月薪水：" << Payl << " 销售额：" << sales << endl;
}

int main ()
{	
    manager m1("胡强", 4);
	technician t1("莫非", 3, 200);
	salesmanager sm1("海棠", 3, 87000);
	salesman s1("小白", 1, 87000);
    employee *emp[4] = {&m1, &t1, &sm1, &s1};

    for(int i = 0; i < 4; i++)
    {	
        cout << "提升" << i << "级" << endl;
        emp[i]->promote(i);
        emp[i]->pay();
        emp[i]->display();
    }
    
    return 0;
}
