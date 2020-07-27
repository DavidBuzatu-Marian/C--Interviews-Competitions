#include <iostream>
struct Node
{
    char data;
    Node *next;
};

int *get_freq_arr(Node *head)
{
    int *freq = new int[128]{0};
    Node *p = head;

    while (p != NULL)
    {
        ++freq[p->data];
        p = p->next;
    }
    return freq;
}

void print_arr(int *arr)
{
    for (int i = 0; i < 128; ++i)
    {
        if (arr[i] != 0)
        {
            std::cout << i << " " << arr[i] << "\n";
        }
    }
}

Node *remove_duplicate(Node **head)
{
    int *counter = get_freq_arr(*head);
    Node *p = (*head)->next;
    Node *q = *head;
    counter[q->data] = 0;
    while (p != NULL)
    {
        counter[p->data] = 0;
        if (counter[p->data] < 0)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return *head;
}

int main()
{
    int n;
    Node *head, *p, *tail;
    std::cin >> n;
    head = NULL;
    for (int i = 0; i < n; ++i)
    {
        char data;
        std::cin >> data;
        if (head == NULL)
        {
            head = new Node;
            head->data = data;
            head->next = NULL;
            tail = head;
        }
        else
        {
            p = new Node;
            p->data = data;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
    }
    head = remove_duplicate(&head);
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    return 0;
}