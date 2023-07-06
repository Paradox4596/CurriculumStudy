#include<iostream>

// LIFO

const int STACK_SIZE{ 10 };

enum Command // 상수보다 더 사용하기 좋음
{
	PUSH = 1,
	POP = 2,
	QUIT = 3
};


// 이 struct가 자료구조, 즉 두가지 변수를 한가지로 묶는것이 핵심
struct Stack
{
	int container[STACK_SIZE]{};
	int topIndex{-1}; // 0이 아님! -1이어야함
};

void PrintInfo()
{
	   std::cout << "<STACK>" << std::endl;
	   std::cout << "[1] push" << std::endl;
	   std::cout << "[2] pop" << std::endl;
	   std::cout << "[3] quit" << std::endl;
}

void PrintStack(Stack& stack)
{
	std::cout << "---- stack ----" << std::endl;

	// 과한 안전장치는 오히려 좋다. 안죽는 프로그램이 더 중요!
	if (stack.topIndex < 0)
	{
		std::cout << "Empty!!" << std::endl;
		return;
	}

	for (int i = stack.topIndex; i >= 0; i--) //for문의 순서중요! 왼쪽 위부터 오른쪽 으로 1,2,4 다음줄은 3 순서임
	{
		std::cout << stack.container[i] << std::endl;
	}

	std::cout << "---------------" << std::endl;
}

void Push(Stack& stack, int value)
{
	// i > 0 && i < size
	if (stack.topIndex >= STACK_SIZE - 1)
	{
		std::cout << "Stack is FULL!!" << std::endl;
		return;
	}

	stack.container[++stack.topIndex] = value;
}

void Pop(Stack& stack)
{
	
	if (stack.topIndex < 0)
	{
		std::cout << "Stack is already empty!" << std::endl;
		return;
	}

	stack.topIndex--;
}

int main()
{
	Stack myStack;

	PrintInfo();

	int command{};

	while (true)
	{
		PrintStack(myStack);

		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case PUSH:
			{	// 이 안에서만 value를 쓸 수 있게 중괄호 처리
				int value{};
				std::cout << "\tinput value : ";
				std::cin >> value;
				Push(myStack, value);
				break;
			}

		case POP:
			Pop(myStack);
			break;

		case QUIT:
			return 0;
			break;

		default:
			std::cout << "잘못된 명령입니다." << std::endl;
			break;
		}
	}
}