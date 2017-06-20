#include <gtest/gtest.h>
using namespace std;

// SDBM项目使用的哈希函数，声称对所有的数据集有很好地分布性。
unsigned int SDBMHash(char* str)
{
	unsigned int hash = 0;   
    while (*str)  
    {  
        // equivalent to: hash = 65599*hash + (*str++);  
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;  
    }  
   
    return (hash & 0x7FFFFFFF);  
}

// RSHash 其作者是Robert Sedgwicks
unsigned int RSHash(char* str)
{
	unsigned int a = 63689;
	unsigned int b = 378551;
	unsigned int hash = 0; 
	
	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

// Justin Sobel提出的基于位的函数 
unsigned int JSHash(char *str)  
{  
    unsigned int hash = 1315423911;  
   
    while (*str)  
    {  
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  

// Peter J. Weinberger在其编译器著作中提出的
unsigned int PJWHash(char *str)  
{  
    unsigned int BitsInUnignedInt	= (unsigned int)(sizeof(unsigned int) * 8);  
    unsigned int ThreeQuarters		= (unsigned int)((BitsInUnignedInt  * 3) / 4);  
    unsigned int OneEighth			= (unsigned int)(BitsInUnignedInt / 8);  
    unsigned int HighBits			= (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);  
    unsigned int hash				= 0;  
    unsigned int test				= 0;  
   
    while (*str)  
    {  
        hash = (hash << OneEighth) + (*str++);  
        if ((test = hash & HighBits) != 0)  
        {  
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));  
        }  
    }  
   
    return (hash & 0x7FFFFFFF);  
} 

// Unix系统上面广泛使用的哈希函数
unsigned int ELFHash(char *str)  
{  
    unsigned int hash = 0;  
    unsigned int x  = 0;  
   
    while (*str)  
    {  
        hash = (hash << 4) + (*str++);  
        if ((x = hash & 0xF0000000L) != 0)  
        {  
            hash ^= (x >> 24);  
            hash &= ~x;  
        }  
    }  
   
    return (hash & 0x7FFFFFFF);  
} 

// Kernighan和Dennis在《The C programming language》中提出的
unsigned int BKDRHash(char *str)  
{  
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..  
    unsigned int hash = 0;  
   
    while (*str)  
    {  
        hash = hash * seed + (*str++);  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  

// Daniel J. Bernstein在comp.lang.c邮件列表中发表的，是距今为止比较高效的哈希函数之一
unsigned int DJBHash(char *str)  
{  
    unsigned int hash = 5381;  
   
    while (*str)  
    {  
        hash += (hash << 5) + (*str++);  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// Arash Partow提出了这个算法，声称具有很好地分布性  
unsigned int APHash(char *str)  
{  
    unsigned int hash = 0;  
    int i;  
   
    for (i=0; *str; i++)  
    {  
        if ((i & 1) == 0)  
        {  
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));  
        }  
        else  
        {  
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));  
        }  
    }  
   
    return (hash & 0x7FFFFFFF);  
}

TEST(Algo,tStringHash)
{	
	unsigned int hash = SDBMHash("hello world!");
	hash = RSHash("hello world!");
	hash = JSHash("hello world!");
	hash = PJWHash("hello world!");
	hash = ELFHash("hello world!");
	hash = BKDRHash("hello world!");
	hash = DJBHash("hello world!");
	hash = APHash("hello world!");

}