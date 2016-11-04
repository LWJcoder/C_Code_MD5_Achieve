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
