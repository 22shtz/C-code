
#ifndef _INTLIST_H
#define _INTLIST_H

typedef struct ilst *intlist_t;

intlist_t empty(void);
//int isempty(intlist_t lst);
//int head(intlist_t lst);
//intlist_t tail(intlist_t lst);
intlist_t cons(int el, intlist_t tl);
intlist_t adaugare(intlist_t lst, int nr,int *el);
// for freeing memory only: splits first element from tail, returns tail
// if elp non-NULL, store value of head there
//intlist_t decons(intlist_t lst, int *elp);
//intlist_t push(intlist_t lst,int nr);
void afisare(intlist_t lst);
void partitie(intlist_t lst,int poz);
#endif
