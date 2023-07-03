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

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	//
	//SequentialSort(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	BubbleSort(array, ARRAY_SIZE);

	Print(array, ARRAY_SIZE);
}