#include <gtest/gtest.h>
using namespace std;

// SDBM��Ŀʹ�õĹ�ϣ���������ƶ����е����ݼ��кܺõطֲ��ԡ�
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

// RSHash ��������Robert Sedgwicks
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

// Justin Sobel����Ļ���λ�ĺ��� 
unsigned int JSHash(char *str)  
{  
    unsigned int hash = 1315423911;  
   
    while (*str)  
    {  
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  

// Peter J. Weinberger��������������������
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

// Unixϵͳ����㷺ʹ�õĹ�ϣ����
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

// Kernighan��Dennis�ڡ�The C programming language���������
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

// Daniel J. Bernstein��comp.lang.c�ʼ��б��з���ģ��Ǿ��Ϊֹ�Ƚϸ�Ч�Ĺ�ϣ����֮һ
unsigned int DJBHash(char *str)  
{  
    unsigned int hash = 5381;  
   
    while (*str)  
    {  
        hash += (hash << 5) + (*str++);  
    }  
   
    return (hash & 0x7FFFFFFF);  
}  
   
// Arash Partow���������㷨�����ƾ��кܺõطֲ���  
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