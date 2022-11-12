#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

////				只有一个元素出现一次
////int main()
////{
////	int arr[] = { 1,2,3,4,5,1,2,3,4 };
////	int i = 0;
////	int len = sizeof(arr)/sizeof(int);
////	int tmp = 0;
////	while (len--)
////	{
////		tmp ^= arr[i];
////		i++;
////	}
////	printf("%d", tmp);
////	return 0;
////}
//
////			2个元素出现一次
////int main()
////{
////	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };	// 全部异或得3，011
////			//		1 1 3 3		5 
////			//	   001   011	101
//////与011异或后	   010   000    110
////// 					2      0     6
////			//		2 2 4 4		6	
////			//	   010   100    110
//////				   001   111    101
//////				    1     7      5
////	int i = 0;
////	int len = sizeof(arr) / sizeof(int);
////	int tmp = 0;
////	while (len--)
////	{
////		tmp ^= arr[i];
////		i++;
////	}
////	printf("%d", tmp);
////	return 0;
////}
//
//int main()
//{
//    int nums[] = { 1,2,3,4,5,1,2,3,4,6 };
//    int len = sizeof(nums) / sizeof(int);
//    int* p;
//    int *p1=singleNumbers(&nums, len, p);
//    printf("%d", *p1);
//    return 0;
//}
//
//int* singleNumbers(int* nums, int numsSize, int* returnSize) 
//{
//    int ret = 0;//只出现一次的两个数的异或结果
//    int x = 0;//出现一次的数
//    int y = 0;//出现一次的数
//    int j = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ret = ret ^ nums[i];//出现两次的数字异或为零,只剩下出现一次数字异或后的结果
//        // 3 011 - 1
//    }
//    for (; j < 32; j++)
//    {       // ret =1
//        if (ret & (1 << j))//找到出现一次数组的分离位j(可将原数组分为两组:第j位为0的为一组;第j为1的为一组)
//            break;
//    }
//    for (int k = 0; k < numsSize; k++)
//    {
//        if (nums[k] & (1 << j))
//        {
//            x = x ^ nums[k];//出现两次的数异或为0,只剩x
//        }
//        else
//        {
//            y = y ^ nums[k];//出现两次的数异或为0，只剩y
//        }
//
//    }
//    int* arr = (int*)malloc(sizeof(int) * 2);
//    arr[0] = x;
//    arr[1] = y;
//    *returnSize = 2;
//    return arr;
//}

void FindNumsAppearOnce(int data[],int length, int* num1, int* num2)
{
	if (data -= NULL || length < 2)
		return;
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR); 

	*num1 = *num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (IsBit1(data[j], indexOf1))
			*num1^= data[j];
		else
			*num2 ^= data[j];
	}
}

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}
bool IsBit1(int num, unsigned int indexBit)
{
			num = num >> indexBit;
		return (num & 1);
	
}