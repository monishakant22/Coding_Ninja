#include <iostream>
class Node{
public:
int data;
Node *next;
Node(int data){
    this->data=data;
    this->next=NULL;
}
};

using namespace std;
Node *takeinput(){
    int data;
    cin>>data;
    Node *head=NULL, *tail=NULL;
    while(data!=-1){
        Node *newnode = new Node(data);
        if (head==NULL){
            head=newnode;
            tail=newnode;}
            else{
                tail->next=newnode;
                tail=newnode;
            }
            cin>>data;
        }
        return head;
}

void print(Node *head){
    Node *temp=head;
    while (temp!= NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

Node *deleteNode(Node *head, int pos)
{
    if(head==NULL){
       return head; 
    }
    if(pos==0){
        return head->next;
    }
    Node *curr=head;
    int curr_pos=0;
    while(curr!=NULL && curr_pos < pos-1){
        ++curr_pos;
        curr=curr->next;
    }
    if(curr==NULL || curr->next==NULL){
        return head;
    }
    curr->next=curr->next->next;
    return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}
