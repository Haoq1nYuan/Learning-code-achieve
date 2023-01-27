#include <stdio.h>

#include <math.h>

float f1(float x)
                    
{scanf("%f",&x);

return x;

}

void f2(double x)

{printf("%lf\n",x);

}

void f(float a,float b,float c)     

{ double x1, x2;

    //void f2(double x);                        

x1=(-b+sqrt(b*b-4*a*c))/2/a;

x2=(-b-sqrt(b*b-4*a*c))/2/a;

f2(x1);             

f2(x2);                

}



int main() {

 float a=0,b=0,c=0;

 a=f1(a);

 if(a!=0) 

 {b=f1(b);

  c=f1(c);

  f(a,b,c);                 

 }

 else printf("不是一个二次方程\n");

 return 0;

}