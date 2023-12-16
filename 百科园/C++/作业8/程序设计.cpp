/*******Begin*******/
class Date
{
	public:
		Date(int yy = 2023, int mm = 1, int dd = 1);
		void setDate(int newY, int newM, int newD);
		bool operator== (const Date &d) const;
		friend ostream &operator<< (ostream &out, const Date &d);
	protected:
		int year, month, day;
}; 

Date::Date(int yy, int mm, int dd)
{
	year = yy;
	month = mm;
	day = dd;
}

void Date::setDate(int newY, int newM, int newD)
{
	year = newY;
	month = newM;
	day = newD;
}

bool Date::operator== (const Date &d) const
{
	if (year == d.year && month == d.month && day == d.day) return true;
	else return false;
}
		
/*******End*********/

ostream & operator <<(ostream &out, const Date &d) { // 运算符<<重载 
	out << d.year << '-' << d.month << '-'<< d.day;
	return out;
} 


/*******Begin*******/
class Complex
{
	public:
		Complex(int r = 0, int i = 0): real(r), imag(i) {}
		Complex operator+ (const Complex &c) const;
		friend bool operator== (const Complex &c1, const Complex &c2);
		friend ostream& operator<< (ostream &out, const Complex &c);
	private:
		int real, imag;
};

Complex Complex::operator+ (const Complex &c) const
{
	return Complex(real + c.real, imag + c.imag);
}

bool operator== (const Complex &c1, const Complex &c2)
{
	if (c1.real == c2.real && c1.imag == c2.imag) return true;
	else return false;
}
/*******End*********/

ostream & operator <<(ostream &out, const Complex &c) {	//运算符<<重载函数实现
	out << "(" << c.real << ", " << c.imag << ")";
	return out;
}