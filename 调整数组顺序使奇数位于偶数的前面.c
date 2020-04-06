/*
调整数组顺序使奇数位于偶数的前面
题目描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。
扩展：并保证奇数和奇数，偶数和偶数之间的相对位置不变。
解题思路：
双指针：首尾移动
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int ReorderOddEven(int *pData, unsigned int length)
{
    if(*pData=='\0')
        return 0;

    int *pBegin = pData;
    int *pEnd = pData+length-1;

    while(pBegin<pEnd)
    {
        //向后移动pBeign，直到遇到偶数
        while(pBegin<pEnd && (*pBegin & 0x1) != 0)
            pBegin++;

        //向前移动pEnd，直到它指向奇数
        while(pBegin<pEnd && (*pEnd & 0x1) == 0)
            pEnd--;

        if(pBegin<pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }

    return *pData;
}


void main()
{
    //定义函数
    int ReorderOddEven(int *pData, unsigned int length);

    int a[] = {1,2,3,4,5};
    int len = 5;
    ReorderOddEven(a, len);

    int i;
    for(i=0; i<len; i++)
        printf("%d ",a[i]);
    printf("\n");

    system("pause");
}