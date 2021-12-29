#ifndef GRAPH_H
#define GRAPH_H


struct Uzel_LS // ��������� ���� ��������� ������
{
	int vname; // ������ ���� � ������� 
	float c; // ���� ����
	Uzel_LS* next; // ��������� �� ��������� ������� ����
};

struct Versh //������ ������
{
	char name; // ��� ����
	int parent; // ������ ��������
	bool visited; int mark; // ������������
	int dfn, fin;
};

struct Versh_LS
{
	Versh info;
	Uzel_LS* head; //������ �� ������ ��������� ������ ������� �����
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