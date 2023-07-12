#pragma once

struct Element
{
	int value{};
	Element* pNext{};
};

struct Stack
{
	int count{};
	Element* pTop{}; // 엘리멘트를 가리키는 포인터로 '탑'이 필요
};

void PushDS(Stack& stack, int value);
void PopDS(Stack& stack);
void PrintDS(Stack& stack);
void DeleteAllDS(Stack& stack);