

//define the class HASH
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

#ifndef HASH_H
#define HASH_H


class Hash{
    private:
    int static const size_HashTable=10;
    struct item
    {
        string key;
        item * next;
    };
    item *hashtable[size_HashTable];
    public:
    Hash();
    int Hash_Function(string Key);
    void Hash_AddItem(string key);
    void Hash_DisplayTable(void);
};








#endif //HASH_H