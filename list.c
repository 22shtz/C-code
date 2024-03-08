//ex
#include <stdlib.h>
#include<stdio.h>
#include "list.h"

struct ilst {
  intlist_t nxt;
  int el;
};

/*int isempty(intlist_t lst)
{
  return lst == NULL;
}
*/
intlist_t empty(void)
{
  return NULL;
}

int head(intlist_t lst)
{
  return lst->el;
}

intlist_t tail(intlist_t lst)
{
  return lst->nxt;
}

intlist_t cons(int el, intlist_t tl)
{
  intlist_t p = malloc(sizeof(struct ilst));
  if (!p) return NULL;
  p->el = el;
  p->nxt = tl;
  return p;
}

// returns tail, assignes *elp with head
intlist_t decons(intlist_t lst, int *elp)
{
  if (elp) *elp = lst->el;
  intlist_t tl = lst->nxt;
  free(lst);
  return tl;
}
/*intlist_t push(intlist_t lst,int el)
{
    lst=cons(el,lst);
    return lst;
}*/
intlist_t adaugare(intlist_t lst, int nr,int *el)
{
    intlist_t aux;
    aux=empty();
    while(lst)
    {
        lst=decons(lst,el);
        aux=cons(*el,aux);
    }
    aux=cons(nr,aux);
    while(aux)
    {
        aux=decons(aux,el);
        lst=cons(*el,lst);
    }
    return lst;
}
void afisare(intlist_t lst)
{
    intlist_t aux=lst;
    while(aux!=NULL)
    {
        printf("%d ",head(aux));
        aux=tail(aux);
    }
}
void partitie(intlist_t lst,int poz)
{
    int k=0;
    intlist_t aux=lst;
    intlist_t t1,t2;
    t1=empty();
    t2=empty();
    while(aux!=NULL && k<poz)
    {
        k++;
        t1=cons(head(aux),t1);

        aux=tail(aux);
    }

    while(aux!=NULL)
    {
        t2=cons(head(aux),t2);
        aux=tail(aux);
    }
    printf("cele 2 liste:");
    afisare(t1);
    printf(" si ");
    afisare(t2);

}
