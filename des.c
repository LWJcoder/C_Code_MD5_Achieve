
// Password.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DES.H"
#include "Trans.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
 char DP[]="HELLODES"; //64bit的字符串
 char DC[8]="";        //DC存储DES加密后的结果
 char str[20]="";      //str存储转换后的11个字符
 bool bitDC[64]={0};   //bitDC为存储64位的二进制位串
 int i=0;
 
 //name与password用于测试
 //（1）提供的用户名name=HELLO和口令password=12345678
 char* name="HELLO";
 char* password="12345678";

 name = argv[1];
 password = argv[2];
 printf("name = %s  password = %s \n",name,password);


 printf("Before encrypting: ");
 for( i=0; i<8; i++)
 {
	 printf("%c", DP[i]);
 }
 printf("\n");

 // 请同学们在此处实现对口令撒盐的代码
 //（2）	生成两个随机整数：R1与 R2,  0<=R1<=63，0<=R2<=63
 int a,b;
 srand((unsigned int)time(NULL));
 a=rand()%63;
 b=rand()%63;
 //（3）	将R1与R2转换为对应的字符串，即查找char_table数组，
 //         例如R1=12，R2=13,那么所得的字符为char_table[12]='a',char_table[13]='b',所以盐值st_salt=”ab”；
 char st_salt[3] ="";
 char temp[3] = "";
 st_salt[0] = char_table[a];
 st_salt[1] = char_table[b];
 temp[0] = st_salt[0];
 temp[1] = st_salt[1];
 //（4）	拼接pwd=st_salt||password, pwd=”ab12345678”;
 password = strcat(st_salt,password);
 //（5）	用pwd作为密钥：Des_SetKey(pwd);

 //设置密钥
 Des_SetKey(password);
 
 //清空DC
 memset(DC, 0, sizeof(DC));

 //第6步到第7步已经实现了，可以直接略过
 //（6）	循环加密25次；结果为64位的二进制串bitDC；
 //（7）	将bitDC转换为字符串str=”CkAmmju10k. ”；
 
 //运行加密算法1次
 Des_Run(DC, DP, ENCRYPT);

 //运行加密算法24次
 for(i=0;i<24;i++)
 {
	Des_Run(DC, DC, ENCRYPT);
 }
 
 //将DC打印输出为16进制的数
 printf("The result of encrypting: ");
 printHex(DC, 8);

 //将加密后的口令DC变换为64位的二进制位串
 //用bitDC存储64位的二进制位串
 chartobit(DC, bitDC );
 
 //将64位二进制数转换为11个字符的字符串
 trans(bitDC, str, 64); 

 printf("The result of 11 chars, str=%s\n", str);


 //同学们需要在此处实现第8到第9步，将加密的结果保存到文件
 //（8）	拼接pwd=st_salt||str, pwd=”abCkAmmju10k.”;
 password = strcat(temp,str);
 //（9）	将name与pwd的值存储到文件password.txt;存储的格式为” HELLO: abCkAmmju10k.”
 FILE *pwfile;
 pwfile = fopen("password.txt","w");
 fputs(name,pwfile);
 fputs(":", pwfile);
 fputs(password,pwfile);
 fputs("\n", pwfile);
 fclose(pwfile);

 //实现第10步：
 //（10）将name与password变量改为main函数变量：password.exe username password
 //	name=argv[1];
 //	password=argv[2];
 
 return 0;
}
