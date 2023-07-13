#include "stack.h"
#include <iostream>


void PushDS(Stack& stack, int value)
{
	Element* pElement = new Element{};
	pElement->value = value;

	pElement->pNext = stack.pTop;
	stack.pTop = pElement;
	stack.count++;
}


void PopDS(Stack& stack)
{
	if (stack.count == 0) // ���Ұ� 1���϶� ��������� ���Ұ� 0���϶� ���°� ������ �ǹǷ�
	{
		std::cout << "STACK IS EMPTY" << std::endl;
	}

	Element* pPrevTop = stack.pTop;
	stack.pTop = pPrevTop->pNext; // �� ���� ���� �߻�
	stack.count--;
	delete pPrevTop;
}


void PrintDS(Stack& stack)
{
	Element* pElement = stack.pTop;

	while (pElement)
	{
		std::cout << pElement->value << std::endl;
		pElement = pElement->pNext;
	}
}


void DeleteAllDS(Stack& stack)
{
	Element* pElement = stack.pTop;
	Element* pNext;

	while (pElement)
	{
		pNext = pElement->pNext;
		delete pElement;
		pElement = pNext;
	}

	stack.count = 0;
	stack.pTop = nullptr;
	
}