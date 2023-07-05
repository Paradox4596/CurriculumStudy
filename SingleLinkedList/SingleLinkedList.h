#pragma once

#include "Monster.h" // 우리가 만든 탑재용 파일은 큰따옴표를 씀

struct MonsterList
{
	// 시작이 누구인지 아는게 중요, 끝은 알면 더 좋음
	Monster* pHead;
	Monster* pTail;
};