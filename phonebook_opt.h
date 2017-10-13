#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define OPT 1
/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
// #define OPT 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOL_DETAIL *dNext;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __BST {
    long hash_v;
    struct __BST *left;
    struct __BST *right;
    struct __PHONE_BOOK_ENTRY *data;
} node;


entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
