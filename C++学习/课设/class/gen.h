#pragma once

#include <string>
#include <iomanip>
using std::string;

class gen
{
    protected:
        string __id, __title, __author, __rating;
        // 作品（基类）：编号、标题、作者、评级。

    public:
        gen(string m_id, string m_title, string m_author, string m_rating): 
        __id(m_id), __title(m_title), __author(m_author), __rating(m_rating) {}

        string id();
        string title();
        string author();
        string rating();
        void edit(string, string, string, string);
};

string gen::id()
{
    return __id;
}

string gen::title()
{
    return __title;
}

string gen::author()
{
    return __author;
}

string gen::rating()
{
    return __rating;
}

void gen::edit(string m_id, string m_title, string m_author, string m_rating)
{
    __id = m_id;
    __title = m_title;
    __author = m_author;
    __rating = m_rating;
}