#include <iostream> // #include <string> �̰� ���ԵǾ� �־ ������ �����ϴ�
#include "SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp) // new�� �ִµ� delete�� �����Ƿ� ��𼱰� delete�� �ؾ���
{
    // 1)New ����� 2)pTail->
    // ��� ���Ͽ� �ִ¾���� �ʱ�ȭ �ϴ� ����� ��µ�, �ݴ�� ���鶧 �ʱ�ȭ �ϴ½����� �ص� �Ǳ���. ������ ����
    
    Monster* element = new Monster;

    strcpy_s(element->name, NAME_LENGTH, name); // �迭�� �迭�� ������ �� �����Ƿ�.. ���ڿ��� ����. for���°ͺ��� �� ����
    element->hp = hp;
    // element->name = name; ������ �ȵȴ�!
    
    if (list.pTail == nullptr)
    {
        list.pHead = element;
    }
    else
    {
        list.pTail->pNext = element; // list�� �����Ͱ� �ƴ϶� �������̹Ƿ� ȭ��ǥ�� �ƴ϶� .������ ����ϴ°�, tail�� �����Ͷ� ������ ������ �����. �̸��� p�� ������ �پ��ִ°� Ȯ������

    }

    list.pTail = element;

    return element;
}

int GetMonsterCount(const MonsterList& list)
{
    Monster* p = list.pHead;
    int count{};

    while (p) // p != nullptr �� ������ �������� �ȴ�!
    {
        count++;
        p = p->pNext;
    }
    
    return count;
}

void PrintMonsters(const MonsterList& list) // �ٷ��� ī������ ������ �����
// Ʈ������(��ȸ)�� ��ͷ� ����� ����
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
         // stcrmp �̰� ���ذ������� �ǰ� ���� ������ ���
        
        //if (int i 0 ~���ڿ�ũ��) -- ���ڿ��� �迭�̶� �Ʊ� strcpy_s ó�� ������ for������ �����غ��°���
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
