#pragma once

#include "gen.h"

class disc: public gen
{
    protected:
        string __producer, __time, __duration;
        // 视频光盘：生产商、生产时间、视频时长。

    public:
        disc(string m_id = "", string m_title = "", string m_author = "", string m_rating = "", string m_producer = "", string m_time = "", string m_duration = ""):
        gen(m_id, m_title, m_author, m_rating), __producer(m_producer), __time(m_time), __duration(m_duration) {}
        disc(const disc &d): gen(d.__id, d.__title, d.__author, d.__rating), __producer(d.__producer), __time(d.__time), __duration(d.__duration) {}

        friend std::ostream& operator<< (std::ostream &out, const disc &);

        string producer();
        string time();
        string duration();
        void edit(string, string, string, string, string, string, string);
};

std::ostream& operator<< (std::ostream &out, const disc &d)
{
    using std::left;
    out << left << std::setw(10) << d.__id << std::setw(20) << d.__title << std::setw(20) << d.__author << std::setw(10)
        << d.__rating << std::setw(20) << d.__producer << std::setw(20) << d.__time << std::setw(10) << d.__duration;
    return out;
}

string disc::producer()
{
    return __producer;
}

string disc::time()
{
    return __time;
}

string disc::duration()
{
    return __duration;
}

void disc::edit(string m_id, string m_title, string m_author, string m_rating, string m_producer, string m_time, string m_duration)
{
    gen::edit(m_id, m_title, m_author, m_rating);
    __producer = m_producer;
    __time = m_time;
    __duration = m_duration;
}