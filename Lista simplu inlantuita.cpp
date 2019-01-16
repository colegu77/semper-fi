#include<stdio.h>
#include<stdlib.h>
typedef struct LISTA{
	int cheie;
	struct LISTA *urm;
}
lista;
lista *prim,*p,*q,*r;
int key;

void creare(void)
{
	prim=NULL;
	p=(lista*)malloc(sizeof(lista));
	printf("Introd cheia de inserat:");
	scanf("%d",&p->cheie);
	p->urm=NULL;
	prim=p;
}

void inserare_inceput(void)
{
	p=(lista*)malloc(sizeof(lista));
	printf("Introd cheia de inserat:");
	scanf("%d",&p->cheie);
	p->urm=prim;
	prim=p;
}

void inserare_sfarsit(void)
{
	for(p=prim;p->urm;p=p->urm);
	q=(lista*)malloc(sizeof(lista));
	printf("Introd cheia de inserat:");
	scanf("%d",&q->cheie);
	p->urm=q;
	q->urm=NULL;
}

void inserare_dupa(void)
{
	printf("Introd cheia dupa care inseram:");
	scanf("%d",&key);
	for(p=prim;p&&p->cheie!=key;p=p->urm);
	if(p)
	{
		q=(lista*)malloc(sizeof(lista));
		printf("Introd cheia de inserat:");
		scanf("%d",&q->cheie);
		q->urm=p->urm;
		p->urm=q;
	}
	else
		printf("Nu exista cheia specificata!\n");
}

void inserare_inainte(void)
{
	printf("Introd cheia inainte de care inseram:");
	scanf("%d",&key);
	for(p=prim;p&&p->cheie!=key;p=p->urm);
	if(p)
	{
		q=(lista*)malloc(sizeof(lista));
		q->cheie=p->cheie;
		q->urm=p->urm;
		printf("Introd cheia de inserat:");
		scanf("%d",&p->cheie);
		p->urm=q;
		printf("Cheia a fost inserata");
	}
	else
		printf("Nu exista cheia specificata!\n");
}

void traversare(void)
	{
		printf("Traversam lista:");
		for(p=prim;p;p=p->urm)
			printf("%d ",p->cheie);
		putchar('\n');
	}

void cautare(void)
{
	printf("Introduceti valoarea cautata:");
	scanf("%d",&key);
	for(p=prim;p&&p->cheie!=key;p=p->urm);
	if(p)
		printf("Valoarea a fost gasita!\n");
	else
		printf("Nu exista cheia specificata!\n");
}

void stergere_element(void)
{
	printf("Introduceti cheia de sters:");
	scanf("%d",&key);	
	r=NULL;
	for(p=prim;p&&p->cheie!=key;r=p,p=p->urm);
	if(p)
		if(p!=prim)
		{
			r->urm=p->urm;
			free(p);
		}
		else
		{
			prim=prim->urm;
			free(p);
			printf("Cheia a fost stearsa\n");
		}
		else
			printf("Nu exista cheia specificata!\n");
}

void stergere_lista(void)
{
	while(prim)
	{
		p=prim;
		prim=prim->urm;
		free(p);
	}
}

void main (void)
{
	int opt;
	while(opt)
	{
		printf("\n\n1.Creare:\n");
		printf("2.Insereaza la inceputul listei\n");
		printf("3.Inserare la sfarsitul listei\n");
		printf("4.Inserare dupa modul precizat de o cititre data\n");
		printf("5.Inserare inainte de modul precizat de o cititre data\n");
		printf("6.Traversarea listei:\n");
		printf("7.Cautarea unui element\n");
		printf("8.Stergerea unui element\n");
		printf("9.Stergerea intregii liste\n");
		printf("0.Iesire\n");
		printf("Introduceti optiunea dumneavoastra:"); scanf("%d",&opt);
		switch(opt)
		{
			case 1:{creare();break;}
			case 2:{inserare_inceput();break;}
			case 3:{inserare_sfarsit();break;}
			case 4:{inserare_dupa();break;}
			case 5:{inserare_inainte();break;}
			case 6:{traversare();break;}
			case 7:{cautare();break;}
			case 8:{stergere_element();break;}
			case 9:{stergere_lista();break;}
		}
	}
}
