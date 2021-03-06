#include <iostream>
#include <cstring>
using namespace std;

int queue[5];
int size = 5;
int front = -1;
int rear = -1;
int push_val = 0;

void insert()
{
    if (front == 0 && rear == size - 1 || front == rear + 1)
    {
        cout << "The queue is full!" << endl;
    }
    else
    {
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = ++push_val;
        cout << "Call " << push_val << " added to the queue" << endl;
    }
}

void remove()
{
    if (front == -1)
    {
        cout << "All operators are busy at the moment!" << endl;
    }
    else
    {
        cout << "Call " << queue[front] << " deleted!" << endl;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    if (front == -1)
    {
        cout << "No calls in the queue, currently!" << endl;
    }
    else if (front > rear) // this means that front is somewhere in the middle of the queue & rear is at back of front
    {
        for (int i = front; i < size; i++) // to print all elements from the front position to the end
        {
            cout << queue[i] << " ";
        }
        for (int j = 0; j <= rear; j++) // to print all elements from start till rear value
        {
            cout << queue[j] << " ";
        }
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice = 0;
    do
    {
        cout << "\nQUEUE OPERATIONS\n1. Insert\n2. Delete\n3. Display\n4. Exit" << endl;
        cout << "Enter: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            remove();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid Input" << endl;
            main();
            break;
        }
    } while (choice < 4);
}