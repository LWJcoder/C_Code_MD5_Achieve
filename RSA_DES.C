#include <math.h>
#include "stdio.h"
#include <string.h>

	int e = 3,
		p = 3,
		q = 11,
		n = 33,
		d = 7;


//ʵ�ּӽ��ܹ�ʽ�Ĵ��루m�����ģ�eΪ��Կ��˽Կ��nΪN=p*q��
//����ֵcΪ����

int rsa(int m, int e, int n)
{
	int c=1;
	int b=e+1;
	while(b!=1)
	{
		c=c*m;
		c=c%n;
		b--;
	}
 
	return c;
	//���ܵ�
}
//�������ַ�ת��Ϊ����
void num2Str(int decode){
	char a;
	decode += 96;
	a = decode;
	printf("decode: %d", decode);
	printf("���ܽ��Ϊ��");
	printf("%c\n", a);
}

int toNum(char a, int i){
	int result;
	result = a;
  //  
	if(result >=65 && result<= 90) //A-Z
	{
		result -= 64; 
	}//a-z
	else if(result>=97 && result<= 122){
		result -= 96;
	}

	return result;
	
	

}

de_encode(char myStr[]){
	int i=0, result,decode;
	int len = strlen(myStr);
	printf("len: %d",len);
	for(i = 0;i<len;i++){
	//����	
		result = rsa(toNum(myStr[i],i), e,n);
		printf("���ܽ���� %d", result);
		//����
		decode = rsa(result, d, n);
		num2Str(decode);

	}

}



void main(){

	char myStr[] = "dgut";
	de_encode(myStr);
	//�����ַ�����

	

}

