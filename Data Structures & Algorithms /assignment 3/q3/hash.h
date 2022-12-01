#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

typedef struct Item* i;
typedef struct Bucket* bu;
typedef struct HashTable* ht;

struct Item{
    int key;
    int frequency;
    i next;
};

struct Bucket{
    i items;
};

struct HashTable{
    int a, b, countBucket;
   // long long int search, insert; //
    bu buckets; 
};

ht init_hash_table(int a, int b, int countBucket);
ht insert(ht H, int key);
bool search(ht H, int key);
ht Delete(ht H, int key);
void print_table(ht H);
int getHash(ht H, int n);


#endif
