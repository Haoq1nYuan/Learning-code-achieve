class Point { 
	public:
		Point(float xx,float yy): x(xx),y(yy) { } 	
		void moveTo(float newX,float newY) { x=newX,y=newY; } 	
	private:
		float x,y;
}; 

class Square {
	public:
		Square(float x=0.0,float y=0.0,float len=1.0):p(x,y) {
			length=len;
			circumference=4*length; 
		}
		void resetSquare(float newX,float newY,float newLen) {
			p.moveTo(newX,newY);
			length=newLen;
			circumference=4*length;
		}
		double getLen() { return length; }
		double getCircumference() { return circumference; }
		bool isEqual(Square &s) {
			if(length==s.length) return true;
			else return false;	
		}
	private:
		Point p;
		float length; 
		double circumference;
};



class Square {
	public:
		Square(float xx,float yy,float len) {
			x=xx,y=yy,length=len;
			area=length*length;
			circumference=4*length; 
		}
		void resetSquare(float newX,float newY,float newLen) {
			x=newX,y=newY,length=newLen;
			area=length*length;
			circumference=4*length;
		}
		float getLen(){
			return length;
		}
		double getArea() {
			return area; 
		}
		double getCircumference(){
			return circumference; 
		}
		bool isEqual(Square &s){
			if(this->length==s.length) return true;
			else return false;	
		}		
	private:
		float x,y,length; 
		double area,circumference;
};
