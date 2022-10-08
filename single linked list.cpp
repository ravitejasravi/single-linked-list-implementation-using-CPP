#include<iostream>
using namespace std;

class Node{
	
	public: int data;
			Node *next;
			
			Node(int data) 
			{
				this -> data = data;
				this -> next = NULL;
			}
			
//			~Node()
//			{
//				int value = this -> data;
//				if(this -> next != NULL)
//				{
//					delete next;
//					this -> next = NULL;
//					
//				}
//				cout<<"Memory freed for data "<<value<<endl;
//			}
};

void display(Node* &head){
	Node* temp = head;
	temp = head;
	while(temp != NULL){
		
		cout<< temp -> data <<" ";
		temp = temp -> next;
	}
	cout<<endl;
	
}


void insertAtHead(Node* &head, int data)
{
	
	Node *temp = new Node(data);
	temp -> next = head;
	head = temp;
}

void insertAtTail(Node* &tail, int data)
{
		
	Node* temp = new Node(data);
	tail -> next = temp;
	tail = temp;
	
}

void insertAtPosition(Node* &tail,Node* &head, int position, int data){
	
	if(position ==1)
	{
		insertAtHead(head, data);
	}
	
	else
	{
	
		Node* temp = head;
		for(int i = 1; i < position - 1; i++)
		{
			temp = temp -> next;
		}
		
		if(temp -> next == NULL)
		{
			insertAtTail(tail,data);
		}
		else
		{
			Node* node = new Node(data);
			node -> next = temp -> next;
			temp -> next = node;
		}
		
	
	}
}

void deleteAtHead(Node* &head)
{
	Node* temp = head;
	head = head -> next;
	temp -> next = NULL;
	delete temp;
	
}

void deleteAtTail(Node* &tail, Node* &head)
{
	Node* cur = head;
	Node* prev = head;
	
	while(cur -> next != NULL)
	{
		prev = cur;
		cur = cur -> next;
	}
	if (cur -> next == NULL)
	{
		tail = prev;
	}
		
	prev -> next = NULL;
	cur -> next = NULL;
	delete cur;
}

void deleteAtPosition(Node* &tail, Node* &head,  int position)
{
	if(position == 1)
	{
		deleteAtHead(head);
	}
	else
	{
		Node* cur = head;
		Node* prev = head;
		for(int i = 1; i < position;i++)
		{
			prev = cur;
			cur = cur->next;
		}
		
		if (cur -> next == NULL)
		{
			prev -> next = NULL;
			tail = prev;
		}
		else
		{
			prev -> next = cur->next;
			
		}
		
		cur -> next = NULL;
		delete cur;
		
	}
}

int len(Node* &head)
{
	Node* temp = head;
	
	if (temp == NULL)
	{
		
		return 0;
	}
	
	int length = 0;
	while(temp != NULL)
	{
		length++;
		temp = temp -> next;
	}
	return length;
}

int search(Node* head, int element)
{
	int length;
	Node* temp = head;
	length = len(head);
	for(int i=1; i<=length; i++)
	{
		if(element==temp->data)
		{
			return i;
		}
		temp = temp->next;
	}
	return 0;
}

Node* reverse(Node* head)
{
	Node* current = head;
	Node* pre = NULL;
	Node* next;
	
	while(current != NULL)
	{
		next = current -> next;
		current -> next = pre;
		pre = current;
		current = next;
	}
	return pre;
}

int sort(Node* head)
{
	Node* pre = head;
	Node* cur;
	int temp;
	
	while(pre!=NULL)
	{
		cur = pre -> next;
		while(cur != NULL)
		{
			if( pre -> data > cur -> data)
			{
				temp = pre -> data;
				pre -> data = cur -> data;
				cur -> data = temp;
			}
			cur = cur->next;
		}
		pre = pre -> next;
	}
}

int main(){
	
	Node* node1 = new Node(100);
	
	Node* head = node1;
	Node* tail = node1;

	
	insertAtTail(tail,2);
	insertAtTail(tail,3);
	insertAtTail(tail,40);
	insertAtTail(tail,1);
	insertAtTail(tail,6);
//	insertAtPosition(tail,head, 5, 0); 
	
//	deleteAtHead(head);
//	deleteAtTail(tail,head);
//	deleteAtPosition(tail,head, 5);
//	deleteAtTail(tail,head);
	cout << "Head " << head -> data<<endl;
	cout << "Tail " << tail -> data<<endl;
	display(head);
//	head = reverse(head);
	sort(head);
	display(head);
	cout << "Head " << head -> data<<endl;
	cout << "Tail " << tail -> data<<endl;
	
//	cout<<"element found at: "<<search(head,60);
	

	return 0;
}

