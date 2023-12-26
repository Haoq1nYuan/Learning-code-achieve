#include <iostream>
using namespace std;

class Base { 
	public:
/**********ERROR**********/
		virtual void display() const { 
			cout<<"Base::display"<< endl; 
		} 	
};

class Derive:public Base {  
	public: 
/**********ERROR**********/
		void display() const;   
		void display() { cout<<"Derive::display"<<endl; }
};

void Derive::display() const {  
	cout<<"Derive::display const"<<endl; 
}

/**********ERROR**********/
void Display(const Base &p){ 
	p.display();  
}

int main() { 
	Base b1; Derive d1;
/**********ERROR**********/
	const Derive d2; 
	b1.display(); d1.display(); d2.display(); 	 
	Display(b1); Display(d1); Display(d2); 
	return 0; 
}