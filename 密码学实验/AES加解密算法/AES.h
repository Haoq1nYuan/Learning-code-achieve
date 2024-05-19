#include <iostream>
using namespace std;
 
#ifndef _AES_H_
#define _AES_H_
 
// S盒
extern unsigned char S[256];
 
//逆S盒
extern unsigned char inv_S[256];
 
// AES-128轮常量
static const unsigned int rcon[10] = {
    0x01000000UL, 0x02000000UL, 0x04000000UL, 0x08000000UL, 0x10000000UL,
    0x20000000UL, 0x40000000UL, 0x80000000UL, 0x1B000000UL, 0x36000000UL
};
 
//列混淆时用到的正矩阵
extern unsigned char positive_matrix[4][4];
 
//逆列混淆时用到的逆正矩阵
extern unsigned char inv_positive_matrix[4][4];
 
//密钥扩展
extern unsigned int W[44];
 
//可输入明文的最大长度
static const int MAX_LENGTH=1e6;
 
//明文
extern unsigned char P[MAX_LENGTH];
//解密之后的明文
extern unsigned char De_P[MAX_LENGTH];
//分组后的128明文
extern unsigned char P128[16];
 
//密文
extern unsigned char C[MAX_LENGTH];
//分组后的128密文
extern unsigned char C128[16];
 
//将128明文转换为状态矩阵
void array_to_mat(unsigned char p[],unsigned char state_mat[][4]);
 
//将状态矩阵转换为128密文
void mat_to_array(unsigned char state_mat[][4],unsigned char c[]);
 
//将1个32位的密钥，转换为4个8位密钥
void key32_to_key8(unsigned int key32,unsigned char* key8);
 
//将4个8位的密钥，转换为1个32位密钥
unsigned int key8_to_key32(unsigned char* key8);
 
//字节替换
unsigned char SubBytes(unsigned char input);
 
//行位移
void ShiftRows(unsigned char state_mat[][4]);
 
//有限域上的乘法
unsigned char multi_finite_field(unsigned char a,unsigned char b);
 
//列混合
void MixColumns(unsigned char state_mat[][4]);
 
//轮密钥加，cnt标记这是第几轮循环
void AddRoundKey(unsigned char state_mat[][4],int cnt);
 
//密钥扩展时的T函数，cnt代表轮数
unsigned int T(unsigned int input,int cnt);
 
//密钥扩展函数
void KeyExpansion(unsigned char* init_key);
 
//加密
void encryption();
 
//解密方法如下
 
//逆字节替换
unsigned char Inv_SubBytes(unsigned char input);
 
//逆行位移
void Inv_ShiftRows(unsigned char state_mat[][4]);
 
//逆列混合
void Inv_MixColumns(unsigned char state_mat[][4]);
 
//逆轮密钥加，cnt标记这是第几轮循环
void Inv_AddRoundKey(unsigned char state_mat[][4],int cnt);
 
//解密
void decryption();
 
 
#endif