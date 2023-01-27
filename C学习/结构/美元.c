#include<stdio.h>

int amount[]={1,5,10,25,50};
char *name[]={"penny","nickel","dime","quater","half-dollar"};

struct{
    int amount;
    char *name;
}coins[]={
    {1,"penny"},
    {5,"nickel"},
    {10,"dime"},
    {25,"quarter"},
    {50,"half-dollar"},
};

int main(){
    int k;
    scanf("%d",&k);
    for(int i;i<sizeof(coins)/sizeof(coins[0]);i++){
        if(k==coins[i].amount){
            printf("%s\n",coins[i].name);
            break;
        }
    }
    return 0;
}