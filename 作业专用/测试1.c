#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
  int i=0,j=0;

  char key[50];        //key最大位数50位，但是还是只取16位

  char plaintext[100];   //明文

  char pGroup[10][10]; //明文组
 
  char keyGroup[16][17]; //密码组

  void encryption(char pGroup[10][10],char keyGroup[16][17]); 

  void decryption(char pGroup[10][10],char keyGroup[16][17]);
 
  void generateKey(char  key[50],char keyGroup[16][17]);

  void makeGroup(char plaintext[100],char pGroup[10][10]);
 
  memset(plaintext,0,sizeof(plaintext)/sizeof(char));

  memset(key,0,sizeof(key)/sizeof(char));

  memset(pGroup,0,sizeof(pGroup) / sizeof(char) );

  memset(keyGroup,0,sizeof(keyGroup) / sizeof(char) );

  printf("请输入明文\n");

  scanf("%s",plaintext);

  printf("请输入密码\n");

  scanf(" %s",key);

  generateKey(key,keyGroup);

  makeGroup(plaintext, pGroup);

   encryption(pGroup,keyGroup);

   printf("密文为：\n");

   for(i=0;i<10;i++)
   {
	   printf("%s",pGroup[i]);
   }

   printf("\n");

   decryption(pGroup,keyGroup);

	printf("明文为：\n");

   for(i=0;i<10;i++)
   {
	   printf("%s",pGroup[i]);
   }

   printf("\n");

  return 0;
}

void makeGroup(char plaintext[100],char pGroup[10][10])
{
    int i=0,j=0;

	int g_num=0;   //分组数
    
	int b_num=0;

	int n_num=0;

	int pLength=0;

	pLength = strlen(plaintext); 
    
	b_num = pLength % 8;

	n_num = 8 - b_num;

	g_num = pLength / 8 ;

	if(b_num != 0)
	{
		g_num += 1;

		for(i=0;i<n_num;i++)
		{
			plaintext[strlen(plaintext)] = n_num + '0';
		}
	}

	plaintext[strlen(plaintext)]='\0';
   
    for(i=0;i<g_num;i++)
	{
	   for(j=0;j<8;j++)
	   {
		  pGroup[i][j] = plaintext[i*8+j];

	   }

	  pGroup[i][8]='\0';

	}

}


void generateKey(char  key[50],char keyGroup[16][17])
{
	int i=0,j=0;  

	char keyadd[50]; //单个密码

	memset(keyadd,0,50);

	char last;

    while(strlen(key)<16)  //16*8=128bit
	{

		strcpy(keyadd,key);

		strcat (key,keyadd);
	}

   for(i=0;i<16;i++)    //获取不同的key，循环移位一bit
   {

	 last = key[15];   //最后一个
	  
	 for(j=15;j>0;j--)     //不用strlen获取长度了，因为是固定的
	 {
		   key[j]=key[j-1];
	 }
    
	 key[0] = last;     

	 memcpy(keyGroup[i],key,16*sizeof(char)); //一维数组叠加成为二维数组 
      
     keyGroup[i][16]='\0';     //密文矩阵
	  
   }
 
}

void f(char p[10],char key[17],int flag,int time)    //密钥固定16位
{

    int i=0,j=0;

	char LE[4];  //不用给多余空间，密码的大小是固定的

	char RE[4];

	char LE1[4];

	char RE1[4];
	
	strncpy(LE,p,4);

	strncpy(RE,p+4,4);

	strncpy(LE1,RE,4); 
    
	for(i=0;i<4;i++)
	{
		RE1[i] = RE[i]^key[4*i]^LE[i];  //按位异或
	}
   
	if(flag==0 && time == 15 || flag == 1 && time == 0)     //特殊处理（倒序）加密第16次和解密第16次
	{
		for(i=0;i<8;i++)
		{
		   if(i<4)
		   {
			 p[i]=RE1[i];
		   }
		   else
		   {
			 p[i]=LE1[i-4];
		   }
			
		}

	}
    else //正常处理
	{
		for(i=0;i<8;i++)
		{
		   if(i<4)
		   {
			 p[i]=LE1[i];
		   }
		   else
		   {

			 p[i]=RE1[i-4];

		   }
			
		}
	}
}


void loop(char pGroup[10],int flag,char keyGroup[16][17])         //flag=0为加密，flag=1为解密
{
	int i = 0;
	
   if(flag==0)
   {
 		 for(i=0;i<16;i++)
		 {
			f(pGroup,keyGroup[i],flag,i);  //循环16次，加密，密钥正向、
		 }

		 pGroup[8]='\0';
   }

  else	
  {

		for(i=15;i>-1;i--)
		{
			f(pGroup,keyGroup[i],flag,i);  //循环16次,解密，密钥倒过来
		}

		pGroup[8]='\0';

  }

}


void encryption(char pGroup[10][10],char keyGroup[16][17])    //加密
{   

     int i=0;

     int numP;

	numP = sizeof(pGroup[0]) / sizeof(char);  //求组数，行数

	for(i=0;i<numP;i++)
	{ 	
		loop(pGroup[i],0,keyGroup); //分组加密	
	} 

}

void decryption(char pGroup[10][10],char keyGroup[16][17])  //解密
{
   int i=0;

   int numP = 0;

   numP = sizeof(pGroup[0]) / sizeof(char);  //一维数组长度,以及知道列数是8
   
   for(i=0;i<numP;i++)
   {
	  loop(pGroup[i],1,keyGroup);
   }
}



