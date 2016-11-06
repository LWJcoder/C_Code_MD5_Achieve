# C_Code_Security
DES.C

（1）	根据提供的用户名name=” HELLO”和口令password=”12345678”；

（2）	生成两个随机数：R1与 R2,  0<=R1<=63，0<=R2<=63
（3）	将R1与R2转换为对应的字符串（盐值）st_salt=”ab”；
（4）	拼接pwd=st_salt||password, pwd=”ab12345678”;

（5）	用pwd作为密钥：Des_SetKey(pwd);用DP[]="HELLODES";作为明文；
（6）	循环加密25次；结果为64位的二进制串bitDC；
（7）	将bitDC转换为字符串str=”CkAmmju10k. ”；

（8）	拼接pwd=st_salt||str, pwd=”abCkAmmju10k.”;

（9）	将name与pwd的值存储到文件password.txt;存储的格式为” HELLO: abCkAmmju10k.”

（10）将name与password变量改为main函数变量；password.exe username password
RSA_DES.C

（1）	取两个素数p=3，q=11；
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
