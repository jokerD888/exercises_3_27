#define _CRT_SECURE_NO_WARNINGS 1


//189. 旋转数组
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//进阶：
//尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

#include<stdio.h>

//rotate1,时间复杂度O(N*K)较高，耗时较多
//思路：先保存最后一个元素，其他的往后移动一位，再把保存的元素补放在nums[0]位置处
void rotate1(int* nums, int numsSize, int k)
{
	int i = 0;
	while (i < k)
	{
		//1 2 3 4 5 6 7
		int tmp = nums[numsSize - 1];//先保存最后一个元素
		//前(numsSize-1)个元素先后移动一位
		int j = 0;
		for (j = numsSize-1; j>0; j--)
		{
			nums[j] = nums[j - 1];
		}
		//再把所保存的最后一个元素放入首位置
		nums[0] = tmp;
		i++;
	}

}

//思路：先保存后K个元素，再将其余元素向后移动K位 
//注意：可能k>numsSize,若k>numsSize,那么可直接将k置为k-numsSize,即可。
//因为数组nums旋转numsSize 还是其本身
//时间复杂度：O(N)
//空间复杂度：O(K)
void rotate2(int* nums, int numsSize, int k)
{
	
	//int ret = 1;
	//int sign = 0;
	//while (ret)
	//{
	//	int i = 0;
	//	if (k > numsSize)
	//	{
	//		ret = k - numsSize;
	//		k = numsSize;
	//		sign = 1;
	//	}
	//	else if(sign)
	//	{
	//		k=ret;
	//		ret = 0;
	//	}
	//	else
	//	{
	//		ret = 0;
	//	}
	//	
	//	int* ps = NULL;
	//	//1 2 3 4 5 6 7
	//	ps = (int*)malloc(k * sizeof(int));
	//	for (i = 0; i < k; i++)
	//	{
	//		*(ps + i) = nums[numsSize - k + i];
	//	}
	//	for (i = numsSize - 1; i >= k; i--)
	//	{
	//		nums[i] = nums[i - k];
	//	}
	//	for (i = 0; i < k; i++)
	//	{
	//		nums[i] = *(ps + i);
	//	}
	//	free(ps);
	//	ps = NULL;
	//}

	//整理思路后发现，若k>numsSize,那么可直接将k置为k-numsSize,即可。
	//因为数组nums旋转numsSize 还是其本身
	//1 2 3 4 5 6 7
	//
		int i = 0;
		if (k > numsSize)
		{
			k = k%numsSize;
		}
		
		int* ps = NULL;
		ps = (int*)malloc(k * sizeof(int));
		for (i = 0; i < k; i++)
		{
			*(ps + i) = nums[numsSize - k + i];
		}
		for (i = numsSize - 1; i >= k; i--)
		{
			nums[i] = nums[i - k];
		}
		for (i = 0; i < k; i++)
		{
			nums[i] = *(ps + i);
		}
		free(ps);
		ps = NULL;

}

//最优法，三步逆置法
//第一步：前n-k个逆置，后k个逆置
//第二部：整体逆置
//时间复杂度：O（N）
//空间复杂度：O(1)
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		++left;
		--right;
	}
}
void rotate3(int* nums, int numsSize, int k)
{
	if (k > numsSize)
	{
		k %= numsSize;
	 }
	reverse(nums, 0, numsSize-k-1);
	reverse(nums, numsSize-k, numsSize-1);
	reverse(nums, 0, numsSize - 1);


}
int main(void)
{
	int nums[7] = { 1,2,3,4,5,6,7};
	int k = 5;
	rotate2(nums, 7, k);
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}


