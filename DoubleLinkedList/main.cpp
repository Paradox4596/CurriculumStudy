#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
	MonsterList myList;

	CreateMonsterD(myList, "Demon", 100);
	CreateMonsterD(myList, "Wolf", 50);
	CreateMonsterD(myList, "Slime", 10);

	PrintMonstersD(myList);
	PrintMonstersRD(myList.pHead);
	std::cout << GetMonsterCountD(myList) << std::endl;

	Monster* pResult = FindMonsterD(myList, "Bear");
	if (pResult)
	{
		std::cout << pResult->name << " Found!" << std::endl;
	}
	else
	{
		std::cout << "Not Found!" << std::endl;
	}


	DeleteMonsterD(myList, "Slime");
	PrintMonstersD(myList);

	DeleteAllD(myList);
}