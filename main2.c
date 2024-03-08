//ex
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
struct ilst {
  intlist_t nxt;
  int el;
};

int isempty(intlist_t lst)
{
  return lst == NULL;
}
/*intlist_t empty(void)
{
  return NULL;
}*/


/*int head(intlist_t lst)
{
  return lst->el;
}

intlist_t tail(intlist_t lst)
{
  return lst->nxt;*/

intlist_t push(intlist_t lst,int el)
{
    lst=cons(el,lst);
    return lst;
}
int main()
{
    intlist_t lst;
    lst=empty();
    lst=push(lst,3);
    lst=push(lst,4);
    lst=push(lst,5);
    lst=push(lst,6);
    afisare(lst);
    printf("lista noua");
    int el;
    lst=adaugare(lst,7,&el);
    afisare(lst);
    partitie(lst,2);
    return 0;
 }
