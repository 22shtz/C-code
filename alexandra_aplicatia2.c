#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct resursa
{
    char id[10];
    char adresa[10];
    char descriere[50];
    int dimensiune;
    char stare[10];
    struct resursa *next;
} resursa;
struct resursa *list=NULL;
FILE*f;
int size=2;
resursa* insertResourceSorted(resursa* list, resursa* newResource)
{
    if (strcmp(list->id,newResource->id)>0)
    {
        newResource->next=list;
        return newResource;
    }

    resursa* current=list;
    while (current->next!=NULL && strcmp(current->next->id,newResource->id)<0)
    {
        current=current->next;
    }

    newResource->next=current->next;
    current->next=newResource;

    return list;
}
resursa* initializare(FILE *f)
{

    char linie[100], linie2[100];
    char* sep;
    char*s;
    char a[100];
    int n,poz=0,poz1=0,cnt=0;
    int ok=0;
    int m;
    int i,j;
    list=NULL;
    while(!feof(f))
    {
        fscanf(f,"%[^\n]\n",&linie);
        ok=0;
        poz=0;
        n=strlen(linie);
        resursa* newresursa=(resursa*)malloc(sizeof(resursa));
        for(i=0; i<n; i++)
        {
            if(linie[i]==';')
            {
                sep=";";
                ok=1;
            }
            if(linie[i]=='"')
            {
                poz=i;
            }
            linie2[i]=linie[i];
        }
        if(ok==0)
        {
            sep=",";
            s=strtok(linie2,sep);
            strcpy(newresursa->id,s);
            s=strtok(NULL,sep);
            strcpy(newresursa->adresa,s);
            for(i=0; i<poz; i++)
            {
                if(linie[i]=='"')
                {
                    poz1=i+1;
                    i=poz;
                }
            }
            j=0;
            for(i=poz1; i<poz; i++)
            {
                a[j]=linie[i];
                j++;
            }
            a[j]='\0';
            strcpy(newresursa->descriere,a);
            s=strtok(linie+poz+1,sep);
            newresursa->dimensiune=atoi(s);
            strcpy(newresursa->stare,"libera");

        }
        else
        {
            s=strtok(linie,sep);
            strcpy(newresursa->id,s);
            s=strtok(NULL,sep);
            strcpy(newresursa->adresa,s);
            s=strtok(NULL,sep);
            strcpy(newresursa->descriere,s);
            s=strtok(NULL,sep);
            newresursa->dimensiune=atoi(s);
            strcpy(newresursa->stare,"libera");
        }
        if(list==NULL)
        {
            list=newresursa;
        }
        else
        {
            list=insertResourceSorted(list,newresursa);
        }


    }


    return list;
}
resursa* alocare_resursa(resursa* list, resursa* newresursa)
{
    resursa*res=list;
    while(res->next!=NULL && strcmp(res->id,newresursa->id)!=0)
    {
        res=res->next;

    }
    strcpy(res->stare,"ocupata");

    return list;

}
resursa* dezalocare_resursa(resursa* list, resursa* newresursa)
{
    resursa*res=list;
    while(res->next!=NULL && strcmp(res->id,newresursa->id)!=0)
    {
        res=res->next;

    }
    strcpy(res->stare,"libera");

    return list;

}
void afisare_stare(resursa*newresursa)
{
    while(newresursa->next!=NULL)
    {
        printf("%s %s\n",newresursa->id,newresursa->stare);
        newresursa=newresursa->next;
    }
    printf("%s %s\n",newresursa->id,newresursa->stare);

}
resursa* eliberare_memorie(resursa* list)
{
    resursa* res=list;
    resursa* aux;
    while(res!=NULL)
    {
        aux=res->next;
        free(res);
        res=aux;
    }
    list=NULL;
    printf("NULL");
    return list;


}
resursa*res2=NULL;
resursa* adaugaNodAdresa(resursa* res2,char id1[], char adr[], char desc[], int dim, char stare[])
{
    resursa* nou,*tmp;
    nou = (resursa*)malloc(sizeof(resursa));


    strcpy(nou->id, id1);
    strcpy(nou->adresa, adr);
    strcpy(nou->descriere, desc);
    nou->dimensiune = dim;
    strcpy(nou->stare,stare);

    if(res2 == NULL || strcmp(res2->adresa, nou->adresa) >=0 )
    {
        nou->next = res2;
        res2 = nou;
    }
    else
    {
        tmp = res2;
        while(tmp->next != NULL && strcmp( (tmp->next)->adresa, nou->adresa) < 0 )
            tmp = tmp->next;

        nou->next = tmp->next;
        tmp->next = nou;
    }
    return res2;
}


resursa* val(resursa*current)
{
    while(current->next!=NULL){
        res2=adaugaNodAdresa(res2,current->id,current->adresa,current->descriere,current->dimensiune,current->stare);
        current=current->next;
    }
        res2=adaugaNodAdresa(res2,current->id,current->adresa,current->descriere,current->dimensiune,current->stare);
    return res2;

}
int VerificareDimensiuniResurse(resursa* res2) /** PT VERIFICAREA ADRESELOR SI DIMENSIUNII */
{
    long int a, b;
    resursa* tmp;
    int ok = 1;
    tmp = res2;
    if(tmp == NULL)
        printf("\nLISTA DE RESURSE E GOALA\n");
    else
    {
        while(tmp->next != NULL)
        {
            a = strtol(tmp->adresa, NULL, 16) + tmp->dimensiune; //update
            b = strtol(tmp->next->adresa, NULL, 16);
            if(a > b)
                ok = 0;
            printf("\t%s + dim%d: %d\t%s : %d\n",tmp->adresa , tmp->dimensiune , a , tmp->next->adresa , b);
            tmp = tmp->next;
        }
    }

    return ok;
}

void afisare(FILE*f,resursa*newresursa)
{
    while(newresursa->next!=NULL)
    {
        printf("%s %s %s %d %s\n",newresursa->id,newresursa->adresa,newresursa->descriere,newresursa->dimensiune,newresursa->stare);
        newresursa=newresursa->next;
    }
    printf("%s %s %s %d %s\n",newresursa->id,newresursa->adresa,newresursa->descriere,newresursa->dimensiune,newresursa->stare);

}
int main()
{
    if((f=fopen("ubuntu-22.csv","r"))!=NULL)
    {

        resursa* lista=initializare(f);
        afisare(f,lista);
        printf("aici");
        //lista=sort(lista);
        //afisare(f,lista);
        int choice;
        int ok=1;
        printf("Meniu:\n");
        printf("1. alocare resursa\n");
        printf("2. dezalocare resursa\n");
        printf("3. afisare stare\n");
        printf("4. eliberare memorie\n");
        printf("5.suprapunere\n");
        printf("Alege o optiune: ");
        while(ok)
        {
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                printf("Ai ales Optiunea alocare resursa.\n");
                lista=alocare_resursa(lista,lista->next);
                break;
            case 2:
                printf("Ai ales dezalocare resursa.\n");
                lista=dezalocare_resursa(lista,lista->next);
                break;
            case 3:
                printf("Ai ales afisare stare.\n");
                afisare_stare(lista);
                break;
            case 4:
                printf("Ai ales eliberare memorie.\n");
                lista=eliberare_memorie(lista);
                ok=0;
                break;
            case 5:{
                printf("Ai ales suprapunere.\n");
                resursa* b=val(lista);
                int ok=VerificareDimensiuniResurse(b);
                if(ok){
                    printf("nu se suprapun\n");
                }
                else {
                    printf("se suprapun");
                }
                break;

            }
            default:
                printf("Optiune invalida.\n");
            }
        }

    }
    else
    {
        printf("fisierul nu s a putut deschide");
    }
    fclose(f);


    return 0;
}
