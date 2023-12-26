#pragma once

class drawing: public gen
{
    protected:
        string __region;
        double __length, __width;
        // 图画：所属国家、画的长和宽。

    public:
        drawing(string m_id = "", string m_title = "", string m_author = "", string m_rating = "", string m_region = "", double m_length = 0, double m_width = 0):
        gen(m_id, m_title, m_author, m_rating), __region(m_region), __length(m_length), __width(m_width) {}
        drawing(const drawing &d): gen(d.__id, d.__title, d.__author, d.__rating), __region(d.__region), __length(d.__length), __width(d.__width) {}

        friend std::ostream& operator<< (std::ostream &out, const drawing &);

        string region();
        double length();
        double width();
        void edit(string, string, string, string, string, double, double);
};

std::ostream& operator<< (std::ostream &out, const drawing &d)
{
    using std::left;
    out << left << std::setw(10) << d.__id << std::setw(20) << d.__title << std::setw(20) << d.__author << std::setw(10) 
        << d.__rating << std::setw(20) << d.__region << std::setw(20) << d.__length << std::setw(10) << d.__width;
    return out;
}

string drawing::region()
{
    return __region;
}

double drawing::length()
{
    return __length;
}

double drawing::width()
{
    return __width;
}

void drawing::edit(string m_id, string m_title, string m_author, string m_rating, string m_region, double m_length, double m_width)
{
    gen::edit(m_id, m_title, m_author, m_rating);
    __region = m_region;
    __length = m_length;
    __width = m_width;
}
