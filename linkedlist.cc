#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef struct node_linked_list_int
{
    int value;
    struct node_linked_list_int *next;

} Node_linked_list_int;

Node_linked_list_int *create_node_linked_list_int(int value)
{
    Node_linked_list_int *node = (Node_linked_list_int *)malloc(sizeof(node));
    node->value = value;
    node->next = NULL;
    return node;
}

Node_linked_list_int *traverse_linked_list(Node_linked_list_int *node)
{
    Node_linked_list_int *temp = node;
    while (temp->next != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}

Node_linked_list_int *is_there_a_cycle(Node_linked_list_int *node)
{
    Node_linked_list_int *slow = node;
    Node_linked_list_int *fast = node;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    }

    return nullptr;
}

Node_linked_list_int *what_is_the_cycle_start(Node_linked_list_int *head, Node_linked_list_int *meetuppoint)
{
    Node_linked_list_int *start = head;
    Node_linked_list_int *meetup = meetuppoint;
    while (true)
    {
        if(start==meetup) return start;
        start = start->next;
        meetup = meetup->next;
    }
}

void reverse_linked_list_int(Node_linked_list_int *node)
{
    if (node != NULL)
    {
        reverse_linked_list_int(node->next);
        printf("%d ", node->value);
    }
}

int main(int argc, char const *argv[])
{
    Node_linked_list_int *head = create_node_linked_list_int(10);

    Node_linked_list_int *next1 = create_node_linked_list_int(20);
    head->next = next1;

    Node_linked_list_int *next2 = create_node_linked_list_int(30);
    next1->next = next2;

    Node_linked_list_int *next3 = create_node_linked_list_int(40);
    next2->next = next3;

    Node_linked_list_int *next4 = create_node_linked_list_int(50);
    next3->next = next4;

    Node_linked_list_int *next5 = create_node_linked_list_int(60);
    next4->next = next5;

    next5->next = next3;

    // reverse_linked_list_int(head);
    // traverse_linked_list(head);
    Node_linked_list_int *meetsat = is_there_a_cycle(head);
    Node_linked_list_int *cycleStart = what_is_the_cycle_start(head, meetsat);

    cout << meetsat->value << endl;
    cout << cycleStart->value << endl;
    return 0;
}