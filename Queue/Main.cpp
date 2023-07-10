#include<iostream>

// FIFO
// "Circular QUEUE" 리니어 배열의 앞뒤가 막혀있다는 단점을 극복
// Data Structure
	//연관된 변수들을 묶어서 구조화시키는 것

const int QUEUE_SIZE{ 10 };

enum Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	QUIT = 3
};

struct Queue
{
	int container[QUEUE_SIZE]{};
	int head{};
	int tail{};
};

void PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl;
	std::cout << "[1] ENQUEUE" << std::endl;
	std::cout << "[2] DEQUEUE" << std::endl;
	std::cout << "[3] QUIT" << std::endl;
	std::cout << "--------" << std::endl;
}

void PrintQueue(Queue& queue)
{
	int i = queue.head;

	if (queue.head == queue.tail)
	{
		std::cout << "Empty!" << std::endl;
		return;
	}

	while (i != queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE; // 헤드 다음부터 출력
		std::cout << queue.container[i] << " " << std::endl;
	}

	std::cout << "--------" << std::endl;
}

void EnQueue(Queue& queue, int value)
{
	if ( (queue.tail + 1) % QUEUE_SIZE == queue.head)
	{
		std::cout << "QUEUE is FULL!" << std::endl;
		return;
	}

	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	queue.container[queue.tail] = value;
}

void DeQueue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "QUEUE is already Empty!" << std::endl;
		return;
	}

	queue.head = (queue.head + 1) % QUEUE_SIZE;
}

int main()
{
	Queue myQueue;

	PrintInfo();

	int command{};
	while (true)
	{
		PrintQueue(myQueue);

		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case ENQUEUE:
			{
				int value;
				std::cout << "\tvalue : ";
				std::cin >> value;
				EnQueue(myQueue, value);
			}
				break;

			case DEQUEUE:
				DeQueue(myQueue);
				break;

			case QUIT:
				return 0; // 주의,확인
				break;

			default:
				std::cout << "잘못된 명령입니다." << std::endl;
				break;
		}
	}
	return 0;
}