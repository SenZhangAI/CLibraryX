#ifndef CLX_ARIRH_H_
#define CLX_ARIRH_H_

//Arith前缀为了避免命名空间污染，这也不得已，毕竟没有namespace语法
//C 语言对于整数除法向零舍入还是向负无穷舍入定义不明确，此函数有助于堵住此漏洞
extern int Arith_max(int x, int y);
extern int Arith_min(int x, int y);
extern int Arith_div(int x, int y);
extern int Arith_mod(int x, int y);
extern int Arith_ceiling(int x, int y);
extern int Arith_floor(int x, int y);

#endif
// vim:ft=c
