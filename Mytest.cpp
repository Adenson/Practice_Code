* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//删除链表中等于给定值 val 的所有节点。
//
//示例 :
//
//输入 : 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val)
{
	ListNode* cur = head;
	ListNode* next = NULL;
	ListNode* prev = NULL;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			next = cur->next;
			free(cur);
			cur = NULL;
			cur = next;
			if (prev == NULL)
			{
				head = next;
			}
			else
			{
				prev->next = cur;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
void ShellSort(int* arr, int count)
{
	int gap = count;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < count - gap; i++)
		{
			if (arr[i + gap] < arr[i])
			{
				int tmp = arr[i + gap];
				int j = i;
				for (j; j >= 0 && tmp < arr[j]; j-=gap)
				{
					arr[j + gap] = arr[j];
				}
				arr[j + gap] = tmp;
			}
		}
	}
}

void SelectSort_single(int* arr, int count)
{
	int minNumIndex = 0;
	int start = 0;
	int end = count - 1;
	while (start <= end)
	{
		minNumIndex = start;
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[minNumIndex])
			{
				minNumIndex = i;
			}
		}
		swap(arr[start], arr[minNumIndex]);
		++start;
	}
}

void SelectSort_double(int* arr, int count)
{
	int minNum_index = 0;
	int maxNum_index = 0;
	int start = 0;
	int end = count - 1;
	while (start <= end)
	{
		minNum_index = maxNum_index = start;
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[minNum_index])
				minNum_index = i;
			if (arr[i] > arr[maxNum_index])
				maxNum_index = i;
		}
		swap(arr[start], arr[minNum_index]);
		if (maxNum_index == start)//防止逆序带来的影响
		{
			maxNum_index = end;
		}
		swap(arr[end], arr[maxNum_index]);
		start++;
		end--;
	}
}

void AdjustDown(int* arr,int root,int count)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child <= count - 1)
	{
		//向下调整算法有一个前提：左右子树必须是一个堆，才能调整。
		if (child +1 <= count -1 && arr[child + 1] > arr[child])//注意：child +1 <= count -1
		{
			child++;
		}
		//选出较大的那个孩子
		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}//如果孩子大于父亲，则交换
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int count)
{
	//排序之前先建堆，升序要建大堆
	for (int i = (count - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, count);
	}

	int num = count - 1;
	while (num)
	{
		swap(arr[0], arr[num]);
		AdjustDown(arr, 0, num);
		--num;
	}
}

void BubbleSort(int* arr, int count)
{
	while (--count)
	{
		for (int i = 0; i < count; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

int GetMidValue(int* arr, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (arr[left] < arr[right])
	{
		if (arr[mid] < arr[left])
		{
			return left;
		}
		else if (arr[mid] < arr[right])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (arr[mid] < arr[right])
		{
			return right;
		}
		else if (arr[mid] < arr[left])
		{
			return mid;
		}
		else
		{
			return left;
		}
	}
}

int QuickSortLR(int* arr, int left, int right)
{
	int mid = GetMidValue(arr,left,right);
	swap(arr[mid], arr[right]);
	int keyValue = arr[right];
	int keyindex = right;
	while (left < right)
	{
		while (arr[left] <= keyValue && left< right)
		{
			left++;
		}
		while (arr[right] >= keyValue && left < right)
		{
			right--;
		}
		swap(arr[left], arr[right]);
	}
	swap(arr[left], arr[keyindex]);
	return left;
}

int QuickSortHole(int* arr, int left, int right)
{
	int mid = GetMidValue(arr, left, right);
	swap(arr[mid], arr[right]);
	int keyValue = arr[right];
	int keyindex = right;
	while (left < right)
	{
		while (arr[left] <= keyValue && left< right)
		{
			left++;
		}
		arr[keyindex] = arr[left];
		while (arr[right] >= keyValue && left < right)
		{
			right--;
		}
		swap(arr[left], arr[right]);
	}
	arr[left] = keyValue;
	return left;
}

int QuickSortFB(int* arr, int left, int right)
{
	int keyIndex = GetMidValue(arr, left, right);
	swap(arr[keyIndex], arr[right]);
	int keyValue = arr[right];
	int prev = left - 1;//这里不能用0，应为还有递归
	int cur = left;//cur找小
	while (cur < right)
	{
		if (arr[cur] < keyValue)//如果cur找到比keyValue大的值就停下来
		{
			if (prev++ != cur)
			{
				prev++;
				swap(arr[prev], arr[cur]);
			}
		}
		cur++;
	}
	prev++;
	return prev;
}

void Test_QuickSort(int* arr,int left,int right)
{
	if (left >= right)
		return;
	int ret = QuickSortHole(arr, left, right);
	Test_QuickSort(arr, 0, ret - 1);
	Test_QuickSort(arr, ret + 1, right);
}
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int count = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, count);
	//ShellSort(arr, count);
	//SelectSort_single(arr, count);
	//SelectSort_double(arr, count);
	//HeapSort(arr, count);
	//BubbleSort(arr, count);
	int left = 0;
	int right = count - 1;
	Test_QuickSort(arr, left, right);
	for (auto& e : arr)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}