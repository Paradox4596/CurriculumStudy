#pragma once

#include "Monster.h" // �츮�� ���� ž��� ������ ū����ǥ�� ��

struct MonsterList
{
	// ������ �������� �ƴ°� �߿�, ���� �˸� �� ����
	Monster* pHead{};
	Monster* pTail{};
};

// Create

Monster* CreateMonsterD(MonsterList& list, const char* name, const int hp); //const ���� ����: �ٲ����� ����

// Count
int GetMonsterCountD(const MonsterList& list); // const ��� ���������.. ������ �ٲ��� �ʴ´ٴ°� �������ִ� ȿ��

// Print
void PrintMonstersD(const MonsterList& list);
void PrintMonstersRD(Monster* pMonster); // �Լ������ε��̶� R�� �Ƚᵵ ����

// Search
Monster* FindMonsterD(const MonsterList& list, const char* name);

// Delete All
void DeleteAllD(MonsterList& list);

// Delete Element
bool DeleteMonsterD(MonsterList& list, const char* name); // void�� ���� ����� ���µ� �˷��ִ°� Ȱ�뵵�� �����״� bool
