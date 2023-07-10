#include <iostream> // #include <string> 이게 포함되어 있어서 지워도 무방하다
#include "SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp) // new는 있는데 delete가 없으므로 어디선가 delete를 해야함
{
    // 1)New 만들기 2)pTail->
    // 헤더 파일에 있는얘들을 초기화 하는 방법을 썼는데, 반대로 만들때 초기화 하는식으로 해도 되긴함. 선택의 문제
    
    Monster* element = new Monster;

    strcpy_s(element->name, NAME_LENGTH, name); // 배열에 배열을 대입할 수 없으므로.. 문자열을 복사. for쓰는것보다 더 쉽다
    element->hp = hp;
    // element->name = name; 같은거 안된다!
    
    if (list.pTail == nullptr)
    {
        list.pHead = element;
    }
    else
    {
        list.pTail->pNext = element; // list는 포인터가 아니라 참조형이므로 화살표가 아니라 .연산자 사용하는것, tail은 포인터라서 역참조 연산자 사용함. 이름에 p가 일일히 붙어있는거 확인하자

    }

    list.pTail = element;

    return element;
}

int GetMonsterCount(const MonsterList& list)
{
    Monster* p = list.pHead;
    int count{};

    while (p) // p != nullptr 랑 완전히 같은뜻이 된다!
    {
        count++;
        p = p->pNext;
    }
    
    return count;
}

void PrintMonsters(const MonsterList& list) // 바로위 카운팅의 원리와 비슷함
// 트래버스(순회)는 재귀로 만들면 편함
{
    Monster* p = list.pHead;

    while (p)
    {
        std::cout << p->name << ", " << p->hp << std::endl;
        p = p->pNext;
    }
}

void PrintMonstersR(Monster* pMonster)
{
    // base case
    if (pMonster == nullptr)
    {
        return;
    }

    
    std::cout << pMonster->name << ", " << pMonster->hp << std::endl;

    // recursive case
    PrintMonstersR(pMonster->pNext);
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
    Monster* p = list.pHead;

    while (p)
    {
         // stcrmp 이거 백준같은데서 되게 자주 나오는 기능
        
        //if (int i 0 ~문자열크기) -- 문자열도 배열이라서 아까 strcpy_s 처럼 일일히 for문으로 대조해보는거임
        //{
        //    name[i] != list.name[i]
        //}

        if (strcmp(p->name, name) == 0)
        {
            return p;
        }

        p = p->pNext;
    }
    return nullptr;
}

void DeleteAll(MonsterList& list)
{
    Monster* p = list.pHead;

    Monster* pNext{};

    while (p != nullptr)
    {
        pNext = p->pNext;
        delete p;


        p = pNext;
    }
    list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
    return false;
}
