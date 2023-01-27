#include<stdio.h>
struct date{
    int month;
    int year;
    int day;
};
int main(int argc,char * argv[]){
    struct date today,day;
    today=(struct date){10,11,2022};
    day=today;
    struct date *pDate=&today;
    //scanf("%d",&today.month);
    //today.day=10;
    //today.month=11;
    //today.year=2022;
    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    printf("Today's date is %i-%i-%i.\n",day.year,day.month,day.day);
    printf("%p\n",pDate);
    return 0;
}
