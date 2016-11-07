#include <math.h>
#include "stdio.h"
#include <string.h>
/*（1）	取两个素数p=3，q=11；
（2）	计算n=p*q；
（3）	计算f(n)=(p-1)*(q-1)；
（4）	取e=3，e与f(n)互质，且1 < e < f(n)；
（5）	取d=7；
（6）	设计出一对公私密钥，加密密钥（公钥）为：KU =(e, n)，解密密钥（私钥）为：KR =(d, n)。7，33							3，33
（7）	明文为” dgut”，将明文信息数字化，并将每块两个数字分组。假定明文英文字母编码表为按字母顺序排列数值，即：
                              表1 字母与数字转换表
 
　　则” dgut”分组转换为：04，07，21，20。

（8）	明文加密，将” dgut”加密
　　用户加密密钥KU =(e, n) 将数字化明文分组信息（04，07，21，20）加密成密文。由 进行计算。

（9）	密文解密，将加密后的”dgut”进行加密
　　用户B收到密文，将其解密，解密密钥（私钥）为：KR =(d, n)，由 进行计算。

　　用户B得到明文信息为：04，07，21，20。根据上面的编码表将其转换为英文，我们又得到了恢复后的原文“dgut”。 

（10）	采用上述方法，实现对从键盘输入的任意长度英文字符串进行加密与解密

*/
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


