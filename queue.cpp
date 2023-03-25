#include <iostream>
using namespace std;
#define capacity 4

template < typename Type >
class Queue
{
    private:
        Type front,rear,arr[capacity];
    public:
        Queue()
        {
            front=rear=-1;
            Type i = 0;
            while(i < capacity)
            {
                arr[i]=0;
                i++;
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
        bool isFull()
        {
            if(rear == capacity - 1)  // or we can write as rear == size(arr) - 1
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void enqueue(Type value)
        {
            if(isFull())
            {
                cout<<"Queue is Full"<<endl;
                return;
            }
            else if(isEmpty())
            {
                front = 0;
                rear = 0;
                arr[rear] = value;
            }
            else
            {
                rear++;
                arr[rear] = value;
            }
        }
        Type dequeue()
        {
            Type value;
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
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
                front++;
            }
            return value;
        }
        Type count()
        {
            return rear - front + 1;
        }
        void display()
        {
            for(int i = 0; i <=rear; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    
};

int main()
{
    Queue<int> Q;
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
                cout<<"Total elements present in the queue is : "<<Q.count()<<endl;
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