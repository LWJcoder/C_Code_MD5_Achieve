

#include "stdafx.h"


char char_table[64] =
{
	 '.','/','0','1','2','3','4','5','6','7','8','9',
	 'a','b','c','d','e','f','g','h','i','j','k','l',
	 'm','n','o','p','q','r','s','t','u','v','w','x','y','z',
	 'A','B','C','D','E','F','G','H','I','J','K','L',
	 'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};

/*******************
*函数chartobit功能：将16进制数转换为二进制数
*参数char *DC：输入为8个字节的16进制数
*参数bool bitDC[]: 将转换后的二进制数存储在bitDC数组中返回
*************************/
void chartobit(char *DC, bool bitDC[])
{
	int i =0, bit = 32, size = 8,len = 4,DC_array=0;

	for(i = 0;i<size; i++){
		switch(DC[i]){
		case 'A':
			for(i = 0;i<len; i++){
				bitDC[DC_array] = false;
				++DC_array;
			}
			break;

		case 'B':
			result += 11*(16^(size-i-1));
			break;
		case 'C':
			result += 12*(16^(size-i-1));
			break;
		case 'D':
			result += 13*(16^(size-i-1));
			break;
		case 'E':
			result += 14*(16^(size-i-1));
			break;
		case 'F':
			result += 15*(16^(size-i-1));
			break;
		case '1':
		
			for(i = 0;i<len; i++){
				bitDC[DC_array] = false;
				++DC_array;
			}
			break;
		case '1':	
			for(i = 0;i<len; i++){
			
				if(len == 3){
					bitDC[DC_array] = true;
				}else{
					bitDC[DC_array] = false;
				}
				++DC_array;
			}
			break;
			
		case '2':
			result += 2*(16^(size-i-1));
			break;
		
		case '3':
			result += 3*(16^(size-i-1));
			break;
		case '4':
			result += 4*(16^(size-i-1));
			break;
		case '5':
			result += 5*(16^(size-i-1));
			break;
		case '6':
			result += 6*(16^(size-i-1));
			break;
		case '7':
			result += 7*(16^(size-i-1));
			break;
		case '8':
			result += 8*(16^(size-i-1));
			break;
		case '9':
			result += 9*(16^(size-i-1));
			break;
		default:
			exit(0);
			break;
		}
	
	}

	for(i = 0;i<bit; i++){
	
	}
}




/***********************************
*函数功能：将64位二进制数转换为字符串
*参数bitDC[]:输入为64位二进制数
*参数len:bitDC[]数组的长度
*参数str[]:返回的字符串数组
***********************************/
void trans(bool bitDC[], int len, char str[])
{
 //利用char_table[64]将64位二进制数转换为字符串
}