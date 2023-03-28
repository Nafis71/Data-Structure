#include <iostream>
using namespace std;
#define size 4
class cqueue
{
    private:
        int front,rear, arr[size],count=0;
    public:
            cqueue()
            {
                front=rear=-1;
                for(int i=0;i<size;i++)
                {
                    arr[i]=0;
                }
            }
            bool isFull()
            {
                if((rear+1)%size == front)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            bool isEmpty()
            {
                if(front == -1 && rear == -1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            void enqueue(int x)
            {
                if(isFull())
                {
                    cout<<"Queue Full"<<endl;
                }
                else if(front == -1 && rear == -1)
                {
                    front=0;
                    rear=0;
                    arr[rear]=x;
                }
                else
                {
                    rear = (rear+1)%size;
                    arr[rear]=x;
                }
                count++;
            }
            int dequeue()
            {
                int value = 0;
                if(isEmpty())
                {
                    cout<<"Queue Empty"<<endl;
                }
                else if(front == rear)
                {
                    value = arr[front];
                    arr[front] = 0;
                    front = rear = -1;
                }
                else
                {
                    value = arr[front];
                    arr[front] = 0;
                    front = (front+1)%size;
                }
                count--;
                return value;
            }
            int icount()
            {
                return count;
            }
            void display()
            {
                for(int i=0;i<size;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
};

int main()
{
    cqueue Q;
    int option,value;
    do
    {
        
        cout<<"Select one operation from below to perform execution of Queue"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. Count"<<endl;
        cout<<"6. Display"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>option;
        switch(option)
        {
            case 1:
                system("cls");
                cout<<"Enter a value to enqueue"<<endl;
                cout<<">> ";
                cin>>value;
                Q.enqueue(value);
                break;
            case 2:
                system("cls");
                cout<<"Dequeued Value: "<<Q.dequeue()<<endl;
                break;
            case 3:
                system("cls");
                if(Q.isEmpty())
                {
                    cout<<"Queue is Empty"<<endl;
                }
                else
                {
                    cout<<"Queue is not Empty"<<endl;
                }
                break;
            case 4:
                system("cls");
                if(Q.isFull())
                {
                    cout<<"Queue is Full"<<endl;
                }
                else
                {
                    cout<<"Queue is not Full"<<endl;
                }
                break;
            case 5:
                system("cls");
                cout<<"Total elements present in the queue is : "<<Q.icount()<<endl;
                break;
            case 6:
                system("cls");
                Q.display();
                break;
            case 7:
                exit(0);
                break;
            default:
                cout<<"Wrong Input"<<endl;

        }
    }while(true);
}