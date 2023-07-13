#include "stack.h"

int main()
{
	Stack myStack;

	PushDS(myStack, 1);
	PushDS(myStack, 2);
	PushDS(myStack, 3);

	PrintDS(myStack);

	PopDS(myStack);
	PrintDS(myStack);

	DeleteAllDS(myStack);
	PrintDS(myStack);

	PopDS(myStack);
}