#pragma once

struct Element
{
	int value{};
	Element* pNext{};
};

struct Stack
{
	int count{};
	Element* pTop{}; // ������Ʈ�� ����Ű�� �����ͷ� 'ž'�� �ʿ�
};

void PushDS(Stack& stack, int value);
void PopDS(Stack& stack);
void PrintDS(Stack& stack);
void DeleteAllDS(Stack& stack);