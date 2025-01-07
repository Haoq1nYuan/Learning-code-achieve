class Point
{
	public:
		Point(float xx, float yy): x(xx), y(yy) {}
		float getX() const {return x;}
		float getY() const {return y;}
		void moveTo(float newX, float newY) 
		{
			x = newX;
			y = newY;
		}
	private:
		float x, y;
};

class Rectangle
{
	public:
		Rectangle(float x1 = 0.0, float y1 = 0.0, float x2 = 3.0, float y2 = 4.0): p1(x1, y1), p2(x2, y2)
		{
			area = abs(x1 - x2) * abs(y1 - y2);
			circumference = 2 * (abs(x1 - x2) + abs(y1 - y2));
		}
		void resetRect(float newX1, float newY1, float newX2, float newY2)
		{
			p1.moveTo(newX1, newY1);
			p2.moveTo(newX2, newY2);
			area = abs(newX1 - newX2) * abs(newY1 - newY2);
			circumference = 2 * (abs(newX1 - newX2) + abs(newY1 - newY2));
		}
		double getArea() {return area;}
		double getCircumference() {return circumference;}
		bool isSquare() {return abs(p1.getX() - p2.getX()) == abs(p1.getY() - p2.getY());}
	private:
		Point p1, p2;
		double area, circumference;
};



class Date { 
	public:		
		Date(int yy=2023,int mm=1,int dd=1): year(yy), month(mm), day(dd) {}
		void setDate(int newY,int newM,int newD)
		{
			year = newY;
			month = newM;
			day = newD;
		}
		void showDate() const; // 显示（输出）当前日期，输出格式为"年-月-日" 
		bool operator== (const Date &d) const 
		{
			return year == d.year && month == d.month && day == d.day;
		}
		friend istream& operator>> (istream& in, Date &);
	protected:
		int year,month,day;  // 日期的年、月、日 
};

istream& operator>> (istream& in, Date &d)
{
	in >> d.year >> d.month >> d.day;
	return in;
}