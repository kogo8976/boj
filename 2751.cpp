#include <iostream>
using namespace std;

#define swap(a, b) {int t = a; a = b; b = t; }

int arr[1000000];
int sorted[1000000];

void merge(int* arr, int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}
	for (l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void merge_sort(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int	main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	merge_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return (0);
}
