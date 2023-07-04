#include<iostream>

void Print(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;

	value1 = value2;
	value2 = temp;
}

// SequentialSort
// Time Complexity : O(n^2)
// Space Complexity : 0(1) / O(n)
void SequentialSort(int input[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}

}

// Selection Sort
// Time Complexity : O(n^2)
// Space Complexity : O(n)
void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		int minIndex = i;
		for (int j = i + 1 ; j < size; j++)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[minIndex]);
			}
		}
	}

}


// Bubble Sort
// Time Complexity : O(n^2)
// Space Complexity : O(n)
void BubbleSort(int input[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (input[j] > input[j+1])
			{
				Swap(input[j], input[j + 1]);
			}
		}
	}
}


// Insertion Sort
// Time Complexity : O(n^2)
// Space Complexity : O(n)
void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		int target = input[i];

		while (--j >= 0 && target < input[j])
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
	}
	
}

//Merge Sort (�����̸�)
// Time Complexity : O(n log n)
// Space Complexity : O(n)

void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half+1 };
	int tempIndex{};

	while (i <= half && j <= end) // ���� ��� ���� ���� ����
	{
		// �ӽ� �迭�� ������ ������
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	// �����ִ� �� ����

	while (i <= half) // ���ʿ� ���� �� ������
	{
		// �ӽ� �迭�� �̾����
		temp[tempIndex++] = input[i++];
	}
	while (j <= end) // �����ʿ� ���� �� ������
	{
		// �ӽ� �迭�� �̾����
		temp[tempIndex++] = input[j++];
	}

	// �ӽ� �迭 -> ���� �迭�� ����
	tempIndex = 0;
	for (int i = start; i <= end; i++)
	{
		input[i] = temp[tempIndex++];
	}
}

void MergeSort(int input[], int start, int end, int temp[])
{
	// base case
	if (start >= end)
	{
		return;
	}

	int half = (start + end) / 2;

	// recursive case
	MergeSort(input, start, half, temp);
	MergeSort(input, half+1, end, temp);

	// Merge
	Merge(input, start, half, end, temp);
	
	
}

// Quicksort: Mergesort�� �ӽ� �迭�� �ʿ��ϴٴ� ������ ����, ��Ŀ���� ��ü�� ū ����x
	// 1. Ư�� ���Ҹ� �ǹ����� ����
	// 2. �ǹ����� ���� ���� ��������, ū ���� ����������
	// 3. �ǹ��� �������� ����
	// 4. 1 ~ 3�� �ݺ�
// Time Complexity : O(c n log n) : Mergesort�� ���� / c�� ���, �־��� ��� n^2���� �� �� ����, �ּ��� ��� O(n)���� �� �� ����
// Space Complexity : O(n)

void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
	{
		QuickSort(input, left, j); // pivot�� ���� ����־ j, i�� �������̴�
	}
	if (i < right)
	{
		QuickSort(input, i, right);
	}
}

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	//
	//SequentialSort(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	//BubbleSort(array, ARRAY_SIZE);
	//InsertionSort(array, ARRAY_SIZE);

	/*int tempArray[ARRAY_SIZE]{};

	MergeSort(array, 0, ARRAY_SIZE - 1, tempArray);*/

	QuickSort(array, 0, ARRAY_SIZE - 1);

	Print(array, ARRAY_SIZE);
}