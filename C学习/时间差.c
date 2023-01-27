#include <stdio.h>
int main()
{
    int hour1,minute1;
    int hour2,minute2;

    scanf("%d %d",&hour1,&minute1);
    scanf("%d %d",&hour2,&minute2);

    int ih=hour1-hour2;
    int im=minute1-minute2;

    if(ih>0){
        if(im<0){
            im=60+im;
            ih-=ih;
        }else{
            im=im;
            ih=ih;
        }
        
    }else if(im<0){
            im=-im;
            ih=-ih;
        }else{
            im=60-im;
            ih-=ih;
        }

    printf("时间差为%2d小时%d分钟。\n",ih,im);
    return 0;
}