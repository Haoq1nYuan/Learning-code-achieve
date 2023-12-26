Course::Course(int n)
{
	score = new float[n];
	credit = 0;
	count = 0;
	average = 0;
	this -> n = n;
} 

Course::~Course() { delete[] score; }

void Course::input()
{
	cin >> number >> name >> credit;
	for (int i = 1; i <= n; i++) cin >> score[i];
}

void Course::process()
{
	max = score[1], min = score[1];
	for (int i = 1; i <= n; i++)
	{
		average += score[i];
		if (min > score[i]) min = score[i];
		if (max < score[i]) max = score[i];
		if (score[i] < 60) count ++;
	}
	average /= n;
}



class Point
{
	public:
		Point(float xx, float yy): x(xx), y(yy) {}
		float getX() const {return x;}
		float getY() const {return y;}
		void setX(float newX) {x = newX;}
		void setY(float newY) {y = newY;}
	private:
		float x = 0, y = 0;
};

class Circle: public Point
{
	public:
		Circle(float x = 0.0, float y = 0.0, float r = 1.0): Point(x, y), radius(r) {}
		void moveTo (float newX, float newY) 
		{
			setX(newX);
			setY(newY);
		}
		float getRadius() const { return radius; }
		double getCircumference() const { return 3.14159 * 2 * radius;}
		double getArea() const {return 3.14159 *radius * radius;}
		double dist (const Circle &c) const 
		{
			return sqrt((Point::getX() - c.getX()) * (Point::getX() - c.getX()) + (Point::getY() - c.getY()) * (Point::getY() - c.getY()));
		}
		bool isEqual(const Circle &c) const {return radius == c.getRadius();}
	private:
		float radius = 0;
};