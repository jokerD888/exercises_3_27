#define _CRT_SECURE_NO_WARNINGS 1


//189. ��ת����
//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
//���ף�
//�������������Ľ�����������������ֲ�ͬ�ķ������Խ��������⡣
//�����ʹ�ÿռ临�Ӷ�Ϊ O(1) �� ԭ�� �㷨������������

#include<stdio.h>

//rotate1,ʱ�临�Ӷ�O(N*K)�ϸߣ���ʱ�϶�
//˼·���ȱ������һ��Ԫ�أ������������ƶ�һλ���ٰѱ����Ԫ�ز�����nums[0]λ�ô�
void rotate1(int* nums, int numsSize, int k)
{
	int i = 0;
	while (i < k)
	{
		//1 2 3 4 5 6 7
		int tmp = nums[numsSize - 1];//�ȱ������һ��Ԫ��
		//ǰ(numsSize-1)��Ԫ���Ⱥ��ƶ�һλ
		int j = 0;
		for (j = numsSize-1; j>0; j--)
		{
			nums[j] = nums[j - 1];
		}
		//�ٰ�����������һ��Ԫ�ط�����λ��
		nums[0] = tmp;
		i++;
	}

}

//˼·���ȱ����K��Ԫ�أ��ٽ�����Ԫ������ƶ�Kλ 
//ע�⣺����k>numsSize,��k>numsSize,��ô��ֱ�ӽ�k��Ϊk-numsSize,���ɡ�
//��Ϊ����nums��תnumsSize �����䱾��
//ʱ�临�Ӷȣ�O(N)
//�ռ临�Ӷȣ�O(K)
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

	//����˼·���֣���k>numsSize,��ô��ֱ�ӽ�k��Ϊk-numsSize,���ɡ�
	//��Ϊ����nums��תnumsSize �����䱾��
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

//���ŷ����������÷�
//��һ����ǰn-k�����ã���k������
//�ڶ�������������
//ʱ�临�Ӷȣ�O��N��
//�ռ临�Ӷȣ�O(1)
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


