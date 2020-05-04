int QuickSortLR(int* arr,int left, int right)
{
	int keyValue = arr[right];
	while (left < right)
	{
		while (arr[left] < keyValue && left < right)
		{
			++left;
		}
		while (arr[right] > keyValue && left < right)
		{
			--right;
		}
		swap(arr[left], arr[right]);
	}
	swap(arr[left], keyValue);
	return left;
}

int QuickSortHole(int* arr, int left, int right)
{
	int keyValue = arr[right];
	while (left < right)
	{
		while (arr[left] < keyValue && left < right)
		{
			++left;
		}
		arr[right] = arr[left];
		while (arr[right] > keyValue && left < right)
		{
			--right;
		}
		arr[left] = arr[right];
	}
	swap(arr[left], keyValue);
	return left;
}


void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int retNum = QuickSortHole(arr, left, right);
	QuickSort(arr, left, retNum - 1);
	QuickSort(arr, retNum + 1, right);
}
int main()
{
	int arr[] = { 1, 8, 5, 6, 3, 4, 7, -1, -2 ,100};
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	QuickSort(arr, left, right);
	for (auto e : arr)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}