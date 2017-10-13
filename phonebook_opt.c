#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"
#include <stdint.h>

static node* head=NULL;

uint32_t hash(char * s)
{
    uint32_t hash = 0;

    for(; *s; ++s) {
        hash += *s;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

entry *findName(char lastName[], entry *pHead)
{
    node *cur=head;
    unsigned long wanted_hash_v=hash(lastName);

    for (;;) {
        if (cur == NULL) {
            return NULL;
        }
        if (cur->hash_v == wanted_hash_v) {
            return cur->data;
        }

        if (wanted_hash_v > cur->hash_v) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return NULL;
}

entry* append(char lastName[], entry *e)
{
    node* new_node= malloc(sizeof(node));

    new_node->data= malloc(sizeof(entry));
    strcpy(new_node->data->lastName, lastName);
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->hash_v=hash(lastName);

    //insert in
    node *cur=head;
    if (head == NULL) {
        head = new_node;
        return NULL;
    }
    for (;;) {
        //printf("cur:%s new:%s\n",cur->data->lastName, new_node->data->lastName);
        if (new_node->hash_v > cur->hash_v) {
            if (cur->right == NULL) {
                cur->right = new_node;
                return NULL;
            } else {
                cur = cur->right;
            }
        } else {
            if (cur->left == NULL) {
                cur->left = new_node;
                return NULL;
            } else {
                cur = cur->left;
            }
        }
    }
    return NULL;
}
