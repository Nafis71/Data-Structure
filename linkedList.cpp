/*
Operation Description:
 -> append node
 -> prepend node
 -> insert node
 -> delete node
 -> update node
 -> print node


*/


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key,data;
        Node* next;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k,int d)
        {
            key = k;
            data = d;
        }
};
class SinglyLinkedList{
    public:
        Node* head;
        SinglyLinkedList() : head(NULL){}
        SinglyLinkedList(Node* n) : head(n){}
        Node* nodeExists(int k)  //check if node exists using a key value
        {
            Node* temp = NULL;  
            Node* ptr = head;
            while(ptr != NULL)
            {
                if(ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } 
            return temp;
        }
        void appendNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node Already Exists"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head = n;
                    cout<<"Node Appended"<<endl;
                }
                else
                {
                    Node *ptr = head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr->next;    //triversing the linked list
                    }
                    ptr->next = n;
                    cout<<"Node Appended"<<endl;
                }
            }
        }
        void prependNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node Already Exists"<<endl;
            }
            else
            {
                n->next =head;
                head = n;
                cout<<"Node Prepended"<<endl;
            }
        }
        void insertNodeAfter(int k,Node *n)
        {
            Node *ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No node exists with key value: "<<k<<endl;
            }
            else
            {
                if(nodeExists(n->key)!=NULL)
                {
                    cout<<"Node Already Exists"<<endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                }
            }
        }
        void deleteNode(int k) //unlink
        {
            if(head == NULL)
            {
                cout<<"List is already empty"<<endl;
            }
            else if(head!=NULL)
            {
                if(head->key == k)
                {
                    head = head->next;
                    cout<<"Node Unlinked"<<endl;
                }
                else
                {
                    Node *temp = NULL;
                    Node *prevNode = head;
                    Node *currentNode = head->next;
                    while(currentNode!=NULL)
                    {
                        if(currentNode->key == k)
                        {
                            temp = currentNode;
                            currentNode = NULL;
                        }
                        else
                        {
                            prevNode = prevNode->next;
                            currentNode = currentNode->next;
                        }
                    }
                    if(temp!=NULL)
                    {
                        prevNode->next = temp->next;
                        cout<<"Node Unlinked"<<endl;
                    }
                    else
                    {
                        cout<<"Node doesn't exist"<<endl;
                    }
                }
            }
        }
        void update(int k, int d)
        {
            Node *ptr = nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data = d;
                cout<<"Node data updated"<<endl;
            }
            else
            {
                cout<<"Node doesn't exist"<<endl;
            }
        }
        void print()
        {
            if(head==NULL)
            {
                cout<<"Nodes don't exist"<<endl;
            }
            else
            {
                cout<<"Singly Linked List Values: "<<endl;
                Node *temp = head;
                while(temp!=NULL)
                {
                    cout<<"Key: "<<temp->key<<" Data: "<<temp->data<<endl;
                    temp = temp->next;
                }
            }
        }


};


int main()
{
    SinglyLinkedList s;
    int option,key,data;
    do
    {
       cout<<"Choose One: "<<endl;
       cout<<"1. Append Node"<<endl;
       cout<<"2. Prepend Node"<<endl;
       cout<<"3. Insert Node"<<endl;
       cout<<"4. Delete Node"<<endl;
       cout<<"5. Update Node"<<endl;
       cout<<"6. Print"<<endl;
       cout<<">> ";
       cin>>option;
       Node *node = new Node();  //every time new node is created in the heap memory beacuse of using dynamic memory allocation and do while loop
       switch(option)
       {
            case 1:
                system("cls");
                cout<<"Append Node: \n Enter Key: ";
                cin>>key;
                cout<<"Enter Data: ";
                cin>>data;
                node->key = key;
                node->data = data;
                s.appendNode(node);
                break;
            case 2:
                system("cls");
                cout<<"Prepend Node: \n Enter Key: ";
                cin>>key;
                cout<<"Enter Data: ";
                cin>>data;
                node->key = key;
                node->data = data;
                s.prependNode(node);
                break;
            case 3:
                system("cls");
                int tempKey;
                cout<<"Insert Node: \n Enter Existing Node's Key after which you want to insert: ";
                cin>>tempKey;
                cout<<"Enter Key: ";
                cin>>key;
                cout<<"Enter Data: ";
                cin>>data;
                node->key = key;
                node->data = data;
                s.insertNodeAfter(tempKey,node);
                break;
            case 4:
                system("cls");
                cout<<"Delete node by key\n Enter Key: ";
                cin>>key;
                s.deleteNode(key);
                break;
            case 5:
                system("cls");
                cout<<"Updation"<<endl;
                cout<<"Enter Key: ";
                cin>>key;
                cout<<"Enter Data: ";
                cin>>data;
                s.update(key,data);
                break;
            case 6:
                system("cls");
                s.print();
                break;
            default:
                exit(0);
       }
    } while (true);
    
}
