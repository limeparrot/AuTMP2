#ifndef GRAPH_H
#define GRAPH_H


struct Uzel_LS // стурктура узла линейного списка
{
	int vname; // »ндекс узла в массиве 
	float c; // цена дуги
	Uzel_LS* next; // указатель на следующий смежный узел
};

struct Versh //список вершин
{
	char name; // им€ узла
	int parent; // »ндекс родител€
	bool visited; int mark; // ѕосещЄнность
	int dfn, fin;
};

struct Versh_LS
{
	Versh info;
	Uzel_LS* head; //ссылка на голову линейного списка смежных узлов
};

int vadd(char newName);

int eadd(char v, char w, float c);

int indexOfName(char NameSearch);

int edel(char v, char w);

int vdel(char delName);

int eEdit(char v, char w, float NewCount);

int vEdit(char v, char NewName);

int findAllCuts(Versh_LS* V_LS, int N);

#endif