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

//Merge Sort (폰노이만)
// Time Complexity : O(n log n)
// Space Complexity : O(n)

void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half+1 };
	int tempIndex{};

	while (i <= half && j <= end) // 양쪽 모두 값이 있을 동안
	{
		// 임시 배열에 작은거 가져옴
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	// 남아있는 것 병합

	while (i <= half) // 왼쪽에 남은 것 있으면
	{
		// 임시 배열에 이어붙임
		temp[tempIndex++] = input[i++];
	}
	while (j <= end) // 오른쪽에 남은 것 있으면
	{
		// 임시 배열에 이어붙임
		temp[tempIndex++] = input[j++];
	}

	// 임시 배열 -> 원래 배열로 복사
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

// Quicksort: Mergesort의 임시 배열이 필요하다는 단점을 보완, 메커니즘 자체는 큰 변동x
	// 1. 특정 원소를 피벗으로 지정
	// 2. 피벗보다 작은 값을 왼쪽으로, 큰 값을 오른쪽으로
	// 3. 피벗을 기준으로 분할
	// 4. 1 ~ 3을 반복
// Time Complexity : O(c n log n) : Mergesort와 동일 / c는 상수, 최악의 경우 n^2까지 갈 수 있음, 최선의 경우 O(n)까지 갈 수 있음
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
		QuickSort(input, left, j); // pivot은 값이 들어있어서 j, i를 넣은것이다
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