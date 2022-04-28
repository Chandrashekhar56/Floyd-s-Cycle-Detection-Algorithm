#include <bits/stdc++.h>
using namespace std;
class Node_of_Linkedlist
{
       public:int data_part;
       Node_of_Linkedlist* next_part;
       Node_of_Linkedlist(int data)
       {
            this->data_part = data;
            next_part = NULL;
       }
};
Node_of_Linkedlist* head_pointer = NULL;
class list_of_node
{
public:
    void insert_data_function(int data)
    {
		Node_of_Linkedlist* new_Node = new Node_of_Linkedlist(data);
		if (head_pointer == NULL)
			head_pointer = new_Node;
		else
        {
			new_Node->next_part = head_pointer;
			head_pointer = new_Node;
		}
	}
	bool findLoop()
	{
		Node_of_Linkedlist *temp1 = head_pointer,
			*temp2 = head_pointer;

		while (temp1 != NULL&& temp2 != NULL&& temp2->next_part != NULL)
        {
			temp1 = temp1->next_part;
			temp2 = temp2->next_part->next_part;
			if (temp1 == temp2)
				return 1;
		}

		return 0;
	}
};
int main()
{
	list_of_node l;
	l.insert_data_function(50);
	l.insert_data_function(10);
	l.insert_data_function(40);
	l.insert_data_function(20);
	l.insert_data_function(30);

	Node_of_Linkedlist* temporary = head_pointer;
	while (temporary ->next_part != NULL)
		temporary  = temporary ->next_part;

	temporary ->next_part = head_pointer;

	if (l.findLoop())
		cout << "Loop exists in the Linked List" << endl;
	else
		cout << "Loop does not exists in the Linked List" << endl;

	return 0;
}

