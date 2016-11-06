#include <math.h>
#include "stdio.h"
#include <string.h>

	int e = 3,
		p = 3,
		q = 11,
		n = 33,
		d = 7;


//实现加解密公式的代码（m是明文，e为公钥或私钥，n为N=p*q）
//返回值c为密文

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
	//加密的
}
//将输入字符转化为数字
void num2Str(int decode){
	char a;
	decode += 96;
	a = decode;
	printf("decode: %d", decode);
	printf("解密结果为：");
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
	//加密	
		result = rsa(toNum(myStr[i],i), e,n);
		printf("加密结果： %d", result);
		//解密
		decode = rsa(result, d, n);
		num2Str(decode);

	}

}



void main(){

	char myStr[] = "dgut";
	de_encode(myStr);
	//输入字符加密

	

}


