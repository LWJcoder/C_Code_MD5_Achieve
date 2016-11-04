
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
 char DP[]="HELLODES"; //64bit���ַ���
 char DC[8]="";        //DC�洢DES���ܺ�Ľ��
 char str[20]="";      //str�洢ת�����11���ַ�
 bool bitDC[64]={0};   //bitDCΪ�洢64λ�Ķ�����λ��
 int i=0;
 
 //name��password���ڲ���
 //��1���ṩ���û���name=HELLO�Ϳ���password=12345678
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

 // ��ͬѧ���ڴ˴�ʵ�ֶԿ������εĴ���
 //��2��	�����������������R1�� R2,  0<=R1<=63��0<=R2<=63
 int a,b;
 srand((unsigned int)time(NULL));
 a=rand()%63;
 b=rand()%63;
 //��3��	��R1��R2ת��Ϊ��Ӧ���ַ�����������char_table���飬
 //         ����R1=12��R2=13,��ô���õ��ַ�Ϊchar_table[12]='a',char_table[13]='b',������ֵst_salt=��ab����
 char st_salt[3] ="";
 char temp[3] = "";
 st_salt[0] = char_table[a];
 st_salt[1] = char_table[b];
 temp[0] = st_salt[0];
 temp[1] = st_salt[1];
 //��4��	ƴ��pwd=st_salt||password, pwd=��ab12345678��;
 password = strcat(st_salt,password);
 //��5��	��pwd��Ϊ��Կ��Des_SetKey(pwd);

 //������Կ
 Des_SetKey(password);
 
 //���DC
 memset(DC, 0, sizeof(DC));

 //��6������7���Ѿ�ʵ���ˣ�����ֱ���Թ�
 //��6��	ѭ������25�Σ����Ϊ64λ�Ķ����ƴ�bitDC��
 //��7��	��bitDCת��Ϊ�ַ���str=��CkAmmju10k. ����
 
 //���м����㷨1��
 Des_Run(DC, DP, ENCRYPT);

 //���м����㷨24��
 for(i=0;i<24;i++)
 {
	Des_Run(DC, DC, ENCRYPT);
 }
 
 //��DC��ӡ���Ϊ16���Ƶ���
 printf("The result of encrypting: ");
 printHex(DC, 8);

 //�����ܺ�Ŀ���DC�任Ϊ64λ�Ķ�����λ��
 //��bitDC�洢64λ�Ķ�����λ��
 chartobit(DC, bitDC );
 
 //��64λ��������ת��Ϊ11���ַ����ַ���
 trans(bitDC, str, 64); 

 printf("The result of 11 chars, str=%s\n", str);


 //ͬѧ����Ҫ�ڴ˴�ʵ�ֵ�8����9���������ܵĽ�����浽�ļ�
 //��8��	ƴ��pwd=st_salt||str, pwd=��abCkAmmju10k.��;
 password = strcat(temp,str);
 //��9��	��name��pwd��ֵ�洢���ļ�password.txt;�洢�ĸ�ʽΪ�� HELLO: abCkAmmju10k.��
 FILE *pwfile;
 pwfile = fopen("password.txt","w");
 fputs(name,pwfile);
 fputs(":", pwfile);
 fputs(password,pwfile);
 fputs("\n", pwfile);
 fclose(pwfile);

 //ʵ�ֵ�10����
 //��10����name��password������Ϊmain����������password.exe username password
 //	name=argv[1];
 //	password=argv[2];
 
 return 0;
}
