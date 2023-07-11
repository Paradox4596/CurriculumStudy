#include <iostream>
#include "DoubleLinkedList.h"


Monster* CreateMonsterD(MonsterList& list, const char* name, const int hp)
{
    Monster* element = new Monster;
    Monster* preElement = element;

    strcpy_s(element->name, NAME_LENGTH, name);
    element->hp = hp;

    if (list.pTail == nullptr)
    {
        list.pHead = element;
    }
    else
    {
        list.pTail->pNext = element; // 흐름 생성
        list.pTail->pPrevious = preElement;
    }


    list.pTail = element; // 포인터가 가리키는 경로의 변경
    

    return element;
}

int GetMonsterCountD(const MonsterList& list)
{
    Monster* p = list.pHead;
    int count{};

    while (p)
    {
        count++;
        p = p->pNext;
    }

    return count;
}

void PrintMonstersD(const MonsterList& list)
{
    Monster* p = list.pHead;

    while (p)
    {
        std::cout << p->name << ", " << p->hp << std::endl;
        p = p->pNext;
    }
}

void PrintMonstersRD(Monster* pMonster)
{
    if (pMonster == nullptr)
    {
        return;
    }


    std::cout << pMonster->name << ", " << pMonster->hp << std::endl;

    PrintMonstersRD(pMonster->pNext);
}

Monster* FindMonsterD(const MonsterList& list, const char* name)
{
    Monster* p = list.pHead;

    while (p)
    {
        if (strcmp(p->name, name) == 0)
        {
            return p;
        }

        p = p->pNext;
    }
    return nullptr;
}

void DeleteAllD(MonsterList& list)
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
    Monster* pElement = list.pHead;
    Monster* pPrevious{};
    Monster* pNext{};

    while (pElement)
    {
        if (strcmp(pElement->name, name) == 0)
        {
            break;
        }

        pPrevious = pElement;
        pElement = pElement->pNext;
        pNext = 
    }

    if (!pElement)
    {
        return false;
    }

    if (list.pHead == list.pTail)
    {
        list.pHead = list.pTail = nullptr;
    }
    else if (pPrevious == nullptr)
    {
        list.pHead = pElement->pNext;
    }
    else if (pElement == list.pTail)
    {
        list.pTail = pPrevious;
        pPrevious->pNext = nullptr;
    }
    else
    {
        pPrevious->pNext = pElement->pNext;
    }

    delete pElement;  // 공통된 작업이라 빼내서 아래에서 1번만 하면 깔끔함

    return true;
}
