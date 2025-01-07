#include <iostream>  
using namespace std;  

class A { 
		int x,y; 
	public: 
 		A(int a,int b) { x=a, y=b; } 
		void show() { cout<<x<<", "<<y<<endl; } 
}; 

class B: virtual protected A {
		int k; 
  	public: 
		B(int a,int b,int c):A(a,b) { k=c; } 
		void show() { cout<<k<<endl; }  
}; 


/**********FILL**********/
class C: virtual public A {  // 此处必须是公有继承
		int m; 
	public: 
		C(int a,int b,int c): A(a,b) { m=c; } 
		void show() { cout<<m<<endl; } 
}; 


/**********FILL**********/
class D: public B, public C {
		int n; 
	public: 
/**********FILL**********/
		D(int a,int b,int c,int d, int e): A(a, b), B(a,b,c), C(a,b,d) { n=e; }
		void show() { cout<<n<<endl; } 
};
 
int main() { 
	D d(1,3,5,7,9); 
/**********FILL**********/
	d.A::show(); 
	d.B::show();
	d.C::show();
	d.show(); 
	return 0; 
}