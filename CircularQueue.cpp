// circular queue

#include <iostream>
#include <queue>
using namespace std;

#include <iostream>
using namespace std;

class CircularQueue{
    private:
        int front, rear, itemCount, arr[5];
    public:
        CircularQueue ()
        {
            itemCount = 0;
            front == -1;
            rear = -1;
            for (int i = 0; i < 5; i++)
            {
                arr[i]= 0;
            }
        }
        bool isEmpty()
        {
            if (front==-1 && rear == -1)
                return true;
            else 
                return false;
        }
        bool isFull()
        {
            if ((rear+1)%5==front) //difference between the circular queue and a regular queue 
                return true;
            else 
                return false;
        }
        void Enqueue (int val)
        {
            if (isFull())
            {
                cout <<"Queue is full"<<endl;
                return;
            }
            else if (isEmpty())
            {
                rear = 0;
                front = 0;
                arr[rear] = val;
            } 
            else 
            {
                rear = (rear + 1)%5 ; //this is to keep the rear slot moving to the empty dequeued slot after a full queue is dequeued 
                arr[rear] = val;
            }
            itemCount ++;
        }
        int Dequeue ()
        {
            int x = 0;
            if (isEmpty())
            {
                cout <<"There's nothing left in this queue"<<endl;
                return x;
            }
            else if (front == rear)
            {
                x = arr[rear];
                rear = -1;
                front = -1;
                itemCount--;
                return x;
            }
            else 
            {
                cout <<"Front Value: "<< front <<endl;
                x = arr[front];
                arr[front] = 0;
                front = (front +1) % 5;
                itemCount--;
                return x;
            }
        }
        int count ()
        {
            return (itemCount);
        }
        void display()
        {
            cout <<" The values in this queue are "<<endl;
            for (int i = 0; i<5; i++)
            {
                cout << arr[i] <<"  ";
            }        
        }
};

int main()
{
    CircularQueue Q1;
    int option, value;
    do
    {
        cout <<"\n\nWhat operation do you need? Select a number. 0 to exit."<<endl;
        cout <<"1. Enqueue()"<<endl;
        cout <<"2. Dequeue()"<<endl;
        cout <<"3. isEmpty()"<<endl;
        cout <<"4. isFull()"<<endl;
        cout <<"5. Count"<<endl;
        cout <<"6. Display"<<endl;
        cout <<"7. Clear "<<endl<<endl;

        cin >> option;

        switch (option)
        {
            case 0:
                break;
            case 1:
                cout << "Enqueue(): Enter the number you want to queue: "<<endl;
                cin >> value;
                Q1. Enqueue(value);
                break;
            case 2:
                cout <<"Dequeue(): "<< Q1.Dequeue() <<endl;
                break;
            case 3:
                if (Q1.isEmpty())
                    cout<< "isEmpty(): The Queue is Empty"<<endl;
                else 
                    cout<< "There are values left in this queue"<<endl;
                break;
            case 4:
                if (Q1.isFull())
                    cout << "isFull(): This queue is full"<<endl;
                else   
                    cout << "There are slots available in here"<<endl;
                break;
            case 5:
                cout<<"Count: There are " <<Q1.count()<< "values in this queue"<<endl;
                break;
            case 6:
                cout <<"Display: ";
                Q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout<< "Pick from the provided choices, you dolt!"<<endl;
                break; 
        }

    } 
    while (option!=0);
    return 0;

    
}



