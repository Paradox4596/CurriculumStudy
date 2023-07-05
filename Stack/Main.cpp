#include<iostream>

// LIFO

const int STACK_SIZE{ 10 };

enum Command // ������� �� ����ϱ� ����
{
	PUSH = 1,
	POP = 2,
	QUIT = 3
};


// �� struct�� �ڷᱸ��, �� �ΰ��� ������ �Ѱ����� ���°��� �ٽ�
struct Stack
{
	int container[STACK_SIZE]{};
	int topIndex{-1}; // 0�� �ƴ�! -1�̾����
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

	// ���� ������ġ�� ������ ����. ���״� ���α׷��� �� �߿�!
	if (stack.topIndex < 0)
	{
		std::cout << "Empty!!" << std::endl;
		return;
	}

	for (int i = stack.topIndex; i >= 0; i--) //for���� �����߿�! ���� ������ ������ ���� 1,2,4 �������� 3 ������
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
			{	// �� �ȿ����� value�� �� �� �ְ� �߰�ȣ ó��
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
			std::cout << "�߸��� ����Դϴ�." << std::endl;
			break;
		}
	}
}