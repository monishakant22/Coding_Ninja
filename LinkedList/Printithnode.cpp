#include <iostream>
class node
{
public:
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

node *takeinput()
{
    int data;
    cin>>data;
    node *head=NULL, *tail=NULL;
    while (data!=-1){
        node *newnode= new node(data);
        if(head==NULL){
            head = newnode;
            tail=newnode;
        }
        else{
            tail->next =newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}


void printIthNode(node *head, int i)
{
    int count=0;
    if(i==0){
        cout<<" ";
        return;
    }
    while(count!=i && head!=NULL){
        count++;
        head=head->next;
    }
    if(i > count){
        return;
    }
    cout<<head->data;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node *head = takeinput();
        int pos;
        cin>>pos;
        printIthNode(head, pos);
        cout<<endl;
    }
    return 0;
}