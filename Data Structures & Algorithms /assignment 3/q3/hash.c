#include<stdio.h>
#include<stdlib.h>
#include"hash.h"
#include<stdbool.h>
ht init_hash_table(int a, int b, int countBucket)
{
    ht H = malloc(sizeof(struct HashTable));
    H->a = a;
    H->b = b;
    H->countBucket = countBucket;
    H->buckets = malloc(sizeof(bu)*countBucket);
    for (int j = 0; j < countBucket; j++)
    {
        H->buckets[j].items = NULL;
    }

   // H->insert = 0; //
   // H->search = 0; //

    return H;
}
ht insert(ht H, int key)
{
    //long long in = 1; //
    int x = getHash(H, key);
    i t = H->buckets[x].items;
    if(t == NULL)
    {
       // in++; //
        i temp = malloc(sizeof(struct Item));
        temp->next = NULL;
        temp->key = key;
        temp->frequency = 1;
        H->buckets[x].items = temp;
       // H->insert = H->insert + in; //
        return H;
    }
    while (t != NULL)
    {
      //  in++; //
        if(t->key == key)
        {
         //   H->insert = H->insert + in; //
            t->frequency++;
            return H;
        }
        if(t->next == NULL) break;
        t = t->next;
    }
    i temp = malloc(sizeof(struct Item));
    temp->next = NULL;
    temp->key = key;
    temp->frequency = 1;
    t->next = temp;
   // H->insert = H->insert + in; //
    return H;
}
bool search(ht H, int key)
{
    //long long se = 1; //
    int x = getHash(H, key);
    i t = H->buckets[x].items;
    while (t != NULL)
    {
        // se++; //
        if(t->key == key)
        { 
       //     H->search = H->search + se; //
            return true;
        }
        if(t->next == NULL) break;
        t = t->next;
    }
   // H->search = H->search + se; //
    return false;
}
ht Delete(ht H, int key)
{
    int x = getHash(H, key);
    i t = H->buckets[x].items;
    if(t == NULL) return H;
    if(t->key == key)
    {
        if(H->buckets[x].items->frequency == 1) H->buckets[x].items = t->next;
        else H->buckets[x].items->frequency = H->buckets[x].items->frequency - 1;
        return H;
    }
    while (t->next != NULL)
    {
        if(t == NULL) return H;
        if(t->next->key == key)
        {
            if(t->next->frequency == 1)t->next = t->next->next;
            else t->next->frequency = t->next->frequency - 1;
        }
        if(t->next == NULL) return H;
        t = t->next;
    }
    return H;
}
void print_table(ht H)
{
    if(H == NULL) return;
    for (int j = 0; j < H->countBucket; j++)
    {
        int ch = 1;
        i t = H->buckets[j].items;
        printf("bucket %d -->  ", j+1);
        while (t != NULL)
        {
            printf("key: %d frequency: %d ", t->key, t->frequency);
            t = t->next;
            ch = 0;
        }
        if(ch) printf("this bucket is empty");
        printf("\n");
    }
}
int getHash(ht H, int key)
{
    return ((H->a * key) + H->b) % H->countBucket;
}
