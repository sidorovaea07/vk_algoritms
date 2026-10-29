#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <vector>
#include <string>


struct HashNode 
{
    int key;
    int value;
    HashNode* next;
    HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
};

class SimpleHashMap 
{
private:
    static const int BUCKET_COUNT = 10007;
    std::vector<HashNode*> table;

    int hashFunction(int key) 
    {
        return std::abs(key) % BUCKET_COUNT;
    }

public:
    SimpleHashMap() 
    {
        table.resize(BUCKET_COUNT, nullptr);
    }

    ~SimpleHashMap() 
    {
        for (int i = 0; i < BUCKET_COUNT; ++i) 
        {
            HashNode* entry = table[i];
            while (entry != nullptr) 
            {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
    }

    void insert(int key, int value) 
    {
        int hashValue = hashFunction(key);
        HashNode* prev = nullptr;
        HashNode* entry = table[hashValue];

        while (entry != nullptr && entry->key != key) 
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) 
        {
            entry = new HashNode(key, value);
            if (prev == nullptr) 
                table[hashValue] = entry;
            else 
                prev->next = entry;
            
        } 
        else
            entry->value = value;
    }

    bool find(int key, int& value) 
    {
        int hashValue = hashFunction(key);
        HashNode* entry = table[hashValue];

        while (entry != nullptr) 
        {
            if (entry->key == key) 
            {
                value = entry->value;
                return true;
            }
            entry = entry->next;
        }
        return false;
    }
};

#endif // STRUCTURES_H
