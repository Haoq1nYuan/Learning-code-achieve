#pragma once

class book: public gen
{
    protected:
        string __publisher, __ISBN;
        int __pages;
        // 书籍：出版社、ISBN号、总页数。

    public:
        book(string m_id = "", string m_title = "", string m_author = "", string m_rating = "", string m_publisher = "", string m_ISBN = "", int m_pages = 0):
        gen(m_id, m_title, m_author, m_rating), __publisher(m_publisher), __ISBN(m_ISBN), __pages(m_pages) {}
        book(const book &b): gen(b.__id, b.__title, b.__author, b.__rating), __publisher(b.__publisher), __ISBN(b.__ISBN), __pages(b.__pages) {}

        friend std::ostream& operator<< (std::ostream &out, const book &);

        string publisher();
        string ISBN();
        int pages();
        void edit(string, string, string, string, string, string, int);
};

std::ostream& operator<< (std::ostream &out, const book &d)
{
    using std::left;
    out << left << std::setw(10) << d.__id << left << std::setw(20) << d.__title << left << std::setw(20) << d.__author << left
        << std::setw(10) << d.__rating << left << std::setw(20) << d.__publisher << left << std::setw(20) << d.__ISBN << left << std::setw(10) << d.__pages;
    return out;
}

string book::publisher()
{
    return __publisher;
}

string book::ISBN()
{
    return __ISBN;
}

int book::pages()
{
    return __pages;
}

void book::edit(string m_id, string m_title, string m_author, string m_rating, string m_publisher, string m_ISBN, int m_pages)
{
    gen::edit(m_id, m_title, m_author, m_rating);
    __publisher = m_publisher;
    __ISBN = m_ISBN;
    __pages = m_pages;
}