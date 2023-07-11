#pragma once

#include "Monster.h" // 우리가 만든 탑재용 파일은 큰따옴표를 씀

struct MonsterList
{
	// 시작이 누구인지 아는게 중요, 끝은 알면 더 좋음
	Monster* pHead{};
	Monster* pTail{};
};

// Create

Monster* CreateMonsterD(MonsterList& list, const char* name, const int hp); //const 붙인 이유: 바뀔일이 없음

// Count
int GetMonsterCountD(const MonsterList& list); // const 없어도 상관없지만.. 내용이 바뀌지 않는다는걸 보장해주는 효과

// Print
void PrintMonstersD(const MonsterList& list);
void PrintMonstersRD(Monster* pMonster); // 함수오버로딩이라 R은 안써도 무방

// Search
Monster* FindMonsterD(const MonsterList& list, const char* name);

// Delete All
void DeleteAllD(MonsterList& list);

// Delete Element
bool DeleteMonsterD(MonsterList& list, const char* name); // void로 만들어도 상관은 없는데 알려주는게 활용도가 높을테니 bool
