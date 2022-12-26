#include <iostream>
using namespace std;
//faraz
struct node
{
    int info;
    node *next;
    node *prev;
};

node *list = NULL;

void insertionAtStart(int value)
{
    node *p;
    if (list == NULL)
    {
        p = new node();
        p->info = value;
        p->next = NULL;
        p->prev = NULL;
        list = p;
    }
    else
    {
        p = new node();
        p->info = value;
        p->prev = NULL;
        p->next = list;
        (p->next)->prev = p;
        list = p;
    }
}

void insertionAtEnd(int value)
{
    node *p, *q;
    if (list == NULL)
    {
        p = new node();
        p->info = value;
        p->next = NULL;
        p->prev = NULL;
        list = p;
    }
    else
    {
        p = list;
        while (p->next != NULL)
        {
            p = p->next;
        }
        q = new node();
        q->info = value;
        q->next = NULL;
        q->prev = p;
        p->next = q;
    }
}

void insertionAtSpecificPoint(int value, int placeValue)
{
    node *p, *q;
    if (list == NULL)
    {
        p = new node();
        p->info = value;
        p->next = NULL;
        p->prev = NULL;
        list = p;
    }
    else if (list->info == placeValue)
    {
        q = new node();
        q->info = value;
        q->prev = NULL;
        q->next = list;
        list->prev = q;
        list = q;
    }
    else
    {

        p = list;

        while (p != NULL)
        {

            if (p->info == placeValue)
            {
                q = new node();
                q->info = value;
                q->prev = p->prev;
                q->next = p;
                p->prev = q;
                (q->prev)->next = q;
            }
            p = p->next;
        }
    }
}

void deletionAtStart()
{
    node *p, *q;
    if (list == NULL)
    {
        cout << "No value to delete from linked list . " << endl;
    }
    else
    {
        p = list;
        q = p->next;
        q->prev = NULL;
        delete (p);
        list = q;
    }
}

void deletionAtEnd()
{
    node *p;
    if (list == NULL)
    {
        cout << "No value to delete from doubly Linked List . " << endl;
    }
    else if (list->next != NULL)
    {
        p = list;
        while (p->next != NULL)
        {
            p = p->next;
        }
        (p->prev)->next = NULL;
        delete (p);
    }
    else
    {
        delete (list);
    }
}

void deletionAtSpecificPoint(int placeValue)
{
    if (list == NULL)
    {
        cout << "No value to delete from linked list . " << endl;
    }
    else
    {
        node *p;
        p = list;
        if (placeValue == p->info)
        {
            (p->next)->prev = NULL;
            list = p->next;
            delete (p);
            return;
        }

        while (p != NULL)
        {
            if (p->next == NULL)
            {
                (p->prev)->next = NULL;
                delete(p);
                return;
            }
            
            if (p->info == placeValue)
            {
                (p->prev)->next = p->next;
                (p->next)->prev = p->prev;
                delete (p);
                return;
            }
            p = p->next;
        }
    }
}

void display()
{
    if (list == NULL)
    {
        cout << "No value in doubly linked list to display . " << endl;
    }
    else
    {
        node *q;
        q = list;
        cout << "Doubly linked list is : ";
        while (q != NULL)
        {
            cout << " " << q->info << " ";
            q = q->next;
        }
    }
}

int main()
{
    cout << "Press 1 to insert value at start of doubly linked list . " << endl;
    cout << "Press 2 to insert value at end of doubly linked list . " << endl;
    cout << "Press 3 to insert value at specific point of doubly linked list . " << endl;
    cout << "Press 4 to delete value from start of doubly linked list . " << endl;
    cout << "Press 5 to delete value from end of doubly linked list . " << endl;
    cout << "Press 6 to delete value from specific point of doubly linked list . " << endl;
    cout << "Press -1 to exit the program . " << endl;
    int placeValue, choice, value;
    do
    {

        cout << "Enter the choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value that you want to insert : ";
            cin >> value;
            insertionAtStart(value);
            cout << "Value insert successfully . " << endl;
            break;
        case 2:
            cout << "Enter the value that you want to insert : ";
            cin >> value;
            insertionAtEnd(value);
            cout << "Value insert successfully . " << endl;
            break;
        case 3:
            cout << "Enter the value where you want to insert : ";
            cin >> placeValue;
            cout << "Enter the value that you want to insert : ";
            cin >> value;
            insertionAtSpecificPoint(value, placeValue);
            cout << "Value insert successfully . " << endl;
            break;
        case 4:
            deletionAtStart();
            cout << "Value delete from start successfullly . " << endl;
            break;
        case 5:
            deletionAtEnd();
            cout << "Value delete from end successfullly . " << endl;
            break;
        case 6:
            cout << "Enter the placeValue that you want to dselete : ";
            cin >> placeValue;
            deletionAtSpecificPoint(placeValue);
            cout << "Value delete from specific point successfullly . " << endl;
            break;
        case 7:
            display();
            cout << endl;
            break;
        }

    } while (choice != -1);

    return 0;
}