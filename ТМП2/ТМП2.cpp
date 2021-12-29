#include <iostream>
#include <stdexcept>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
#include "Graph.h"

using namespace std;
const int lVl=10;
//Versh v[lVl];
Versh_LS V_LS[lVl];
int N = 0;
int vadd(char newName)
{
	if (N < lVl)
	{
		V_LS[N].info.name = newName;
		V_LS[N].info.mark = 0;
		V_LS[N].info.visited = false;
		V_LS[N].head = nullptr;
		N++;
		return 0;
	}
	else
	{
		cout << "Can't add new Uzel"; return -1;
	}
}

int vdel(char delName)
{
	for (int i = 0; i < N; i++)
	{
		if (indexOfName(delName) == V_LS[i].info.name) continue;
		edel(delName, V_LS[i].info.name);
		edel(V_LS[i].info.name, delName);
	}
	for (int i = indexOfName(delName); i < N-1; i++) {
		V_LS[i] = V_LS[i + 1];
	}
	N--;
	return 0;
}

int eadd(char v, char w, float c)
{
	Uzel_LS* p;
	p = new Uzel_LS;
	p->c = c;
	p->vname = indexOfName(w);
	p->next = V_LS[indexOfName(v)].head;
	V_LS[indexOfName(v)].head = p;
	return 1;
}

int edel(char v, char w)
{
	Uzel_LS *cur, *prev;
	for (cur = V_LS[indexOfName(v)].head, prev = nullptr; (cur); prev = cur, cur = cur->next)
	{
		if (cur->vname == indexOfName(w)) break;
	}
	if (cur)
	{
		if (prev)
			prev->next = cur->next;
		else
			V_LS[indexOfName(v)].head = cur->next;
		delete cur;
		return 1;
	}
	else return 0;
}

int indexOfName(char NameSearch)
{
	for (int i = 0;i < N; i++)
		if (V_LS[i].info.name == NameSearch)
		return i;
	return - 1;
}

int eEdit(char v, char w, float NewCount)
{
	Uzel_LS* cur, * prev;
	for (cur = V_LS[indexOfName(v)].head, prev = nullptr; (cur); prev = cur, cur = cur->next)
	{
		if (cur->vname == indexOfName(w)) break;
	}
	if (cur)
	{
		cur->c = NewCount;
		return 1;
	}
	else return 0;
}

int vEdit(char v, char NewName)
{
	for (int i = 0; i < N; i++)
	{
		Uzel_LS* a = V_LS[i].head;
		while (a)
		{
			if(V_LS[a->vname].info.name == v) V_LS[a->vname].info.name = NewName;
			a = a->next;
		}
		cout << endl;
	}
	V_LS[indexOfName(v)].info.name = NewName;
	return 0;
}

int findAllCuts(Versh_LS* V_LS, int N)
{
	int c;
	int arr[lVl];
	//cout << "0 -- ";
	for (int i = 1; i < lVl; i++) arr[i]=-1; arr[0] = 0;
	if (V_LS[0].head) {
		Uzel_LS* a = V_LS[0].head;
		while (a)
		{	
			cout << "(a," << V_LS[a->vname].info.name << ") ";
			a = a->next;
		}
		cout << endl;
	}

	int condition = pow(2, N-2);
	for (int i = 1; i < condition; i++) {
		int temp = i; c = 0;
		for (int j = 0; j < N-2; j++) {
			if (temp & 1) {    // это условие всегда даёт наиболее правую переменную
				arr[c+1]=j+1;
				c++;
			}
			temp = temp >> 1;  //сдвигаем переменную на 1 разряд
		}




		for (int i = 0; arr[i] != -1; i++)
		{
			
			Uzel_LS* a = V_LS[arr[i]].head;
			while (a)
			{	

				int k = 0;
				for (int j = 0; arr[j] != -1; j++)
				{
					if (a->vname == arr[j]){ k = 0; break;}

					k++;
				}

				if (k != 0) cout << "(" << V_LS[arr[i]].info.name << ", " << V_LS[a->vname].info.name << ") ";
				a = a->next;
			}
		}
		cout << endl;
		for (int i = 1; i < lVl; i++) arr[i] = -1;

	}
	
	//cout << endl; cout << endl;
	/*for (int i = 0; i<N; i++)
		{
			Uzel_LS* a = V_LS[i].head;
			while (a)
			{

				cout << "(" << V_LS[i].info.name << ", " << V_LS[a->vname].info.name << ") ";
				a = a->next;
			}
			cout << endl;
		}
	*/
	return 0;
}

void main()
{
	vadd('a'); //Source -----1example------
	vadd('b'); 
	vadd('c');
	vadd('d');
	vadd('q'); //End

	eadd('a', 'b', 10);
	eadd('a', 'c', 10);
	eadd('b', 'c', 10);
	eadd('b', 'd', 10);
	eadd('b', 'q', 10);
	eadd('c', 'q', 10);
	eadd('d', 'q', 10);
	eadd('d', 'c', 10);

	findAllCuts(V_LS, N); 
}
/*
	vadd('a'); //Source Example 2
	vadd('b');
	vadd('c');
	vadd('d');
	vadd('q'); //End
	eadd('a', 'b', 10);
	eadd('a', 'c', 10);
	eadd('a', 'd', 10);
	eadd('b', 'c', 10);
	eadd('b', 'q', 10);
	eadd('c', 'd', 10);
	eadd('c', 'q', 10);
	eadd('d', 'q', 10);
*/