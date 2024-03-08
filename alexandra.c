#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef struct
{
    char nume[50];
    int nr;
    float fr;
} cuvinte;

FILE *o;
void swap(cuvinte *a,cuvinte *b)
{
    cuvinte aux;
    strcpy(aux.nume,a->nume);
    aux.nr=a->nr;
    aux.fr=a->fr;
    strcpy(a->nume,b->nume);
    a->nr=b->nr;
    a->fr=b->fr;
    strcpy(b->nume,aux.nume);
    b->nr=aux.nr;
    b->fr=aux.fr;

}
void afis_nr(FILE* o,cuvinte* cuv,int n)
{
    for(int i=0;i<n;i++)
    {
        fprintf(o,"%s\n",cuv[i].nume);
    }

}
void afis_nr2(FILE* o,cuvinte* cuv,int n)
{
    for(int i=0;i<n;i++)
    {
        fprintf(o,"%s %d %f \n",cuv[i].nume,cuv[i].nr,cuv[i].fr);
    }

}
void sort_fr(FILE* o,cuvinte *cuv, int n)
{
    cuvinte a[1000];
    int i,j;
    float min=1.0;
    for(i = 0; i < n; i++)
    {
        if(cuv[i].fr<min)
        {
            min=cuv[i].fr;
        }

    }
    j=0;
    for(i=0;i<n;i++)
    {
       if(cuv[i].fr==min)
       {
           strcpy(a[j].nume,cuv[i].nume);
           a[j].nr=cuv[i].nr;
           a[j].fr=cuv[i].fr;

           j++;
       }
    }
    int m;
    m=j;
     for(i = 0; i < m-1; i++)
    {
        for(j = i+1; j < m; j++)
        {
            if(strcmp(a[i].nume,a[j].nume)>0)
            {
                swap(&a[i],&a[j]);

            }
        }
    }
    fprintf(o,"Fmin: %f\n",min);
    afis_nr(o,a,m);




}



void sort_nr(FILE* o,cuvinte *cuv, int n)
{
    cuvinte a[1000];
    int i,j;
    float max=0.0;
    for(i = 0; i < n; i++)
    {
        if(cuv[i].nr>max)
        {
            max=cuv[i].nr;
        }

    }
    j=0;
    for(i=0;i<n;i++)
    {
       if(cuv[i].nr==max)
       {
           strcpy(a[j].nume,cuv[i].nume);
           a[j].nr=cuv[i].nr;
           a[j].fr=cuv[i].fr;

           j++;
       }
    }
    int m;
    m=j;
     for(i = 0; i < m-1; i++)
    {
        for(j = i+1; j < m; j++)
        {
            if(strcmp(a[i].nume,a[j].nume)<0)
            {
                swap(&a[i],&a[j]);

            }
        }
    }
    fprintf(o,"Nr ap max: %f\n",max);
    afis_nr(o,a,m);




}
int nr_total(FILE* o,cuvinte* cuv, int n)
{
    int i,j,m;
    int t1,t2,t3;
    float f3;

    //modif vectorul in functie de nume si calc nr total nr ap si frecventa
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(cuv[i].nume,cuv[j].nume)==0)
               {
                   t1=cuv[i].nr/cuv[i].fr;
                   t2=cuv[j].nr/cuv[j].fr;
                   t3=t1+t2;
                  // printf("%s\n",cuv[i].nume);
                   //printf("%d\n",t3);
                   cuv[i].nr=cuv[i].nr+cuv[j].nr;
                  // printf("%d\n",cuv[i].nr);
                   f3=(float)cuv[i].nr/t3;
                   cuv[i].fr=f3;
                   //printf("%f\n",cuv[i].fr);
                   //printf("aa\n");
                   //stergem cuv[j]
                   int p;
                   for(p=j;p<n-1;p++)
                   {
                        strcpy(cuv[p].nume,cuv[p+1].nume);
                        cuv[p].nr=cuv[p+1].nr;
                        cuv[p].fr=cuv[p+1].fr;

                   }
                   n--;



               }
        }
    }
    //
    //afis_nr2(o,cuv,n);
    return n;

}
void bubble_sort(cuvinte* cuv,int n)
{
    int i,j;
     for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(cuv[i].nr<cuv[j].nr)
            {
                swap(&cuv[i],&cuv[j]);

            }
        }
    }
}
int partition(cuvinte* cuv, int low, int high) {
    int pivot = cuv[high].nr/cuv[high].fr;  // Alegem pivotul, în acest caz, ultimul element din subșir
    int i = (low - 1);      // Inițializăm indexul elementului mai mic decât pivot

    for (int j = low; j <= high - 1; j++) {
        // Dacă elementul curent este mai mic sau egal cu pivot, îl schimbăm cu elementul din stânga pivotului
        if (cuv[j].nr >= pivot) {
            i++;
            swap(&cuv[i], &cuv[j]);
        }
    }
    // Schimbăm pivotul cu elementul din dreapta lui
    swap(&cuv[i + 1], &cuv[high]);
    return (i + 1);
}
void quickSort(cuvinte* cuv, int low, int high) {
    if (low < high) {
        // Găsim pivotul și îl plasăm în poziția corectă
        int pi = partition(cuv, low, high);

        // Sortăm elementele înainte și după pivot
        quickSort(cuv, low, pi - 1);
        quickSort(cuv, pi + 1, high);
    }
}
void sort_nr_egale(cuvinte* cuv,int n)
{
    int i,j;
     for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(cuv[i].nr<cuv[j].nr)
            {
                swap(&cuv[i],&cuv[j]);

            }
            else if((cuv[i].nr==cuv[j].nr) && (strcmp(cuv[i].nume,cuv[j].nume)>0)){
                swap(&cuv[i],&cuv[j]);
            }

        }
    }
}
cuvinte cop(cuvinte* cuv,int n)
{
    return *cuv;
}



int main()
{

    FILE *f = fopen("random_ex1.csv", "r");
    o = fopen("out.txt", "w");
    if(f == NULL)
    {
        printf("eroare");
        return -1;
    }
    cuvinte cuv[1003],cuv2[1003];
    char linie[50];
    char s[50];
    char a[4];
    fscanf(f,"%s",s);
    int i = 0;
    while(fscanf(f,"%[^,],%d,%f\n",cuv[i].nume,&cuv[i].nr,&cuv[i].fr)!=EOF)
    {
        /*char* sep=strtok(linie,",");
        strcpy(cuv[i].nume,sep);
        sep=strtok(NULL,",");
        cuv[i].nr=atoi(sep);
        sep=strtok(NULL,",");
        cuv[i].fr=atof(sep);
        //fprintf(o,"%s %d %f \n",cuv[i].nume,cuv[i].nr,cuv[i].fr);
        */
        i++;

    }
    int n;
    n=i;



   // sort_fr(o,cuv,n);
   // sort_nr(o,cuv,n);
    n=nr_total(o,cuv,n);
    afis_nr2(o,cuv,n);
    for(i=0;i<n;i++)
    {
        cuv2[i]=cuv[i];
    }
    //afis_nr2(o,cuv2,n);
    clock_t begin=clock();
    bubble_sort(cuv,n);
    clock_t end=clock();
    double t1=((double)(end-begin)/CLOCKS_PER_SEC)*1000;
    begin=clock();
    quickSort(cuv2,0,n);
    end=clock();
    double t2=((double)(end-begin)/CLOCKS_PER_SEC)*1000;
    fprintf(o,"%.2f\n",t1);
    fprintf(o,"%.2f\n",t2);
    //bubble_sort(cuv,n);
    //sort_nr_egale(cuv,n);
    //afis_nr2(o,cuv,n);

    fclose(f);
    fclose(o);



    return 0;
}
