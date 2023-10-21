#include <iostream>

using namespace std;

class Clock
{
    public:
        // 三种构造函数，后两者委托给第一个构造函数
        Clock(int initH, int initM, int initS): hour(initH), minute(initM), second(initS)
        {
            cout << "创建对象成功" << endl;
        }
        Clock(): Clock(0, 0, 0)
        {
            cout << "采用委托构造函数" << endl;
        }
        Clock(int initH): Clock(initH, 0, 0) 
        {
            cout << "采用委托构造函数" << endl;
        }

        void showTime()
        {
            cout << hour << ':' << minute << ':' << second << endl;
        }
        void setTime(int newH, int newM, int newS);
    private:
        int hour, minute, second;
};

inline void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}

// // 构造函数定义
// Clock::Clock(int initH, int initM, int initS): hour(initH), minute(initM), second(initS) 
// {
//     cout << "创建对象成功" << endl;
// }

// // 委托构造函数定义
// Clock::Clock(): Clock(0, 0, 0) 
// {
//     cout << "采用委托构造函数" << endl;
// }

// Clock::Clock(int initH): Clock(initH, 0, 0) 
// {
//     cout << "采用委托构造函数" << endl;
// }

int main ()
{
    Clock c(9);

    c.showTime();

    c.setTime(10, 20, 21);

    c.showTime();

    return 0;
}