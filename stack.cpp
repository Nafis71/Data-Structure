#include <bits/stdc++.h>
using namespace std;
#define capacity 5
class Stack
{
    private:
        int top;
        int arr[capacity];
    public:
        Stack()
        {
            top = -1;
            for(int i=0; i<capacity; i++)
            {
                arr[i] = 0;
            }
        }
        bool isEmpty()
        {
            if(top == -1)
            {
                return true;        //to prevent underflow
            }
            return false;
        }
        bool isFull()
        {
            if(top == 4)
            {
                return true;        //to prevent overflow
            }
            else
            {
                return false;
            }
        }
        void push(int val);
        int pop();
        int count();
        int peek(int position);
        void change(int position, int value);
        void display();

};
void Stack::push(int val) //pushes a value onto the stack
{
     if(isFull())
     {
        cout<<"Stack Overflow"<<endl;
     }
     else
     {
        top++;
        arr[top] = val;
     }
}
int Stack::pop() //return a value and remove it from the stack
{
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        return 0;
    }
    else
    {
        int value = arr[top];
        arr[top] = 0;
        top--;
        return value;
    }
}
int Stack::count() //returns the number of elements in the stack
{
    return top+1;
}
int Stack::peek(int position) //accessing the particular position in the stack
{
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        return 0;
    }
    else
    {
        return arr[position];
    }
}
void Stack::change(int position,int value)
{
    arr[position] = value;
    cout<<"Value changed at the position: "<<position<<endl;
}
void Stack::display()
{
    cout<<"Stack Values : "<<endl;
    for(int i=0; i<=top; i++)
    {
        cout<<arr[i]<<endl;
    }

}

int main()
{
    Stack s;
    int option,position,value;
    do
    {
        cout<<"Which Operation do you want to perform?"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Count"<<endl;
        cout<<"4. Change"<<endl;
        cout<<"5. Peek"<<endl;
        cout<<"6. isEmpty"<<endl;
        cout<<"7. isFull"<<endl;
        cout<<"8. Display"<<endl;
        cout<<"9. Clear Screen"<<endl;
        cout<<"10. Exit"<<endl;
        cout<<"Enter your option : "<<endl;
        cout<<">> ";
        cin>>option;
        switch(option)
        {
            case 1:
                system("cls");
                cout<<"Enter an item to push in the stack"<<endl;
                cout<<">> ";
                cin>>value;
                s.push(value);
                break;
            case 2:
                system("cls");
                cout<<"Pop function called - Poped value: "<<s.pop()<<endl;
                break;
            case 3:
                system("cls");
                cout<<"Total elements in the stack: "<<s.count()<<endl;
                break;
            case 4:
                system("cls");
                cout<<"Enter an index position to change"<<endl;
                cout<<">> ";
                cin>>position;
                cout<<"Enter a value to change in position "<<position<<endl;
                cout<<">> ";
                cin>>value;
                s.change(position,value);
                break;
            case 5:
                system("cls");
                cout<<"Enter an index position to see value"<<endl;
                cout<<">> ";
                cin>>position;
                cout<<"Value at index "<<position<<": "<<s.peek(position)<<endl;
                break;
            case 6:
                system("cls");
                if(s.isEmpty())
                {
                    cout<<"Stack is Empty"<<endl;
                }
                else
                {
                    cout<<"Stack is not Empty"<<endl;
                }
                break;
            case 7:
                system("cls");
                if(s.isFull())
                {
                    cout<<"Stack is Full"<<endl;
                }
                else
                {
                    cout<<"Stack is not Full"<<endl;
                }
                break;
            case 8:
                s.display();
                break;
            case 9:
                system("cls");
                break;
            case 10:
                exit(0);
            default:
                cout<<"Wrong option"<<endl;
        }  

    }while(true);
    
    return 0;
}