#include<iostream>
using namespace std;

 struct NODE
{
	int info;
	NODE *next;
};
		 NODE *list=NULL;
		void insert(NODE *&list ,int x)		 // create ordered list
		{
			NODE *p = list, *q = list, *r;
			r = new(NODE); r->info = x;			// create new node
			r->next = NULL;
			while (p != NULL && x > p->info)	// find the insertion place
			{
				q = p; p = p->next;
			}
			if (p == list)						 //x is the first info
			{
				list = r; r->next = p;
			}
			else if (p == NULL)					//x is the last info
			{
				q->next = r;
			}
			else						//x is neither first nor last info
			{
				r->next = p; q->next = r;
			}
		}

		void unionSet(NODE *a,NODE *b, NODE *&u) //return Union of 2 ordered lists
		{
			
			while (a != NULL && b != NULL)		//both lists contain number
			{
				if (a->info < b->info)			//a is smaller,insert and point to next
				{
					insert(u, a->info); a = a->next;
				}
				else if (b->info < a->info)		//a is larger,insert b and point to next
				{
					insert(u, b->info); b = b->next;
				}
				else
				{
					insert(u, a->info); a = a->next; b = b->next; //insert a and point to next nums
				}
			}
			while (a != NULL)					 //list b is empty, insert rest of a
			{
				insert(u, a->info); a = a->next;
			}
			while (b != NULL)					 //list a is empty, insert rest of b
			{
				insert(u, b->info); b = b->next;
			}
		}

		void display(NODE *p)					//display list
		{
			NODE *t = p;
			while (t != NULL)
			{
				cout << t->info << "->"; t = t->next;
			}
			cout << "NULL\n";
		}


int main()
{
	int A[4] = { 3,8,4,1 };
	int B[5] = { 4,8,6,5,7};
	NODE *setA = NULL, *setB = NULL, *setU = NULL;
	for (int i = 0; i < 4; i++)				//insert A to be ordered
	{
		insert(setA,A[i]);
	}
	cout << "Set A: ";
	display(setA);							//display ordered list
	for (int i = 0; i < 5; i++)				//insert B to be ordered
	{
		insert(setB,B[i]);
	}
	cout << "Set B: ";
	display(setB);							//display ordered list
	cout << "A union B: ";
	unionSet(setA, setB, setU);				//find union of set A and B
	display(setU);							//display union 
	system("pause");
	return 0;
}
/*
Set A: 1->3->4->8->NULL
Set B: 4->5->6->7->8->NULL
A union B: 1->3->4->5->6->7->8->NULL
Press any key to continue . . .
*/
