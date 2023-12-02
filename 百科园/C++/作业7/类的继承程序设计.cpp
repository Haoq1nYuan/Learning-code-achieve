class Point 
{
	public:
		Point (float xx, float yy): x(xx), y(yy) {} 
		float getX () const { return x; }
		float getY () const { return y; }
		void setX (float newX) { x = newX; }
		void setY (float newY) { y = newY; } 
	private:
		float x, y;
};

class Square: protected Point
{
	public:
		Square (float x = 0.0, float y = 0.0, float len = 1.0): Point(x, y), length(len), circumference(4 * len) {}
		float getX () const { return Point::getX(); }
		float getY () const { return Point::getY(); }
		float getLen () const { return length; }
		float getCircumference () const { return circumference; }
		void moveTo (float newX, float newY) 
		{
			setX(newX);
			setY(newY);
		} 
		double dist (const Square &s) const 
		{
			float lx = getX() - s.getX();
			float ly = getY() - s.getY(); 
			return sqrt(lx * lx + ly * ly);
		}
	private:
		float length;
		double circumference;
};