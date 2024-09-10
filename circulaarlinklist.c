#include <stdio.h>
#include <stdlib.h>


struct node {
    struct node *next;
    int data;
};



struct node* create_ll(struct node* start);
struct node* display(struct node* start);
struct node* insert_end(struct node* start);
struct node* insert_after(struct node* start);
struct node* delete_first(struct node* start);



int main() {
    int option;
    struct node* start = NULL;

    do {
        printf("\n\nMENU");
        printf("\n1. for creating circular linked list");
        printf("\n2. Display the circular List");
        printf("\n3. Add a Node at the End of the circular linked list");
        printf("\n4. Add a Node after a give node of the circular linked list");
        printf("\n5. Delete a the first node of circular linked list");
        printf("\n6. Exit");
        printf("\nEnter your options:");
        scanf("%d", &option);

        switch(option) {
            case 1:
                start = create_ll(start);
                printf("Circular linked list created.");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_end(start);
                break;
            case 4:
            start = insert_after(start);
            break;
            case 5:
                start = delete_first(start);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while(option != 5);

    return 0;
}

struct node* create_ll(struct node* start) {
    struct node *new_node, *ptr;
    int num;

    printf("Enter the data (-1 to end): ");
    scanf("%d", &num);

    while (num != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = start;

        if (start == NULL) {
            start = new_node;
            new_node->next = start;
        } else {
            ptr = start;
            while (ptr->next != start) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }

        printf("Enter the data (-1 to end): ");
        scanf("%d", &num);
    }

    return start;
}

struct node* display(struct node* start) {
    struct node* ptr = start;

    if (ptr == NULL) {
        printf("List is empty.\n");
        return start;
    }

    printf("The list is: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");

    return start;
}

struct node* insert_end(struct node* start) {
    struct node *new_node, *ptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return start;
    }

    printf("Enter data that u want in the new node: ");
    scanf("%d", &new_node->data);

    if (start == NULL) {
        start = new_node;
        new_node->next = start;
    } else {
        ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }

    return start;
}

struct node* insert_after(struct node* start) {
    struct node *new_node, *ptr,*preptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return start;
    }
    int val;
    printf("Enter node after which you want to add new ");
    scanf("%d", &val);

    printf("Enter data that u want in the new node: ");
    scanf("%d", &new_node->data);

    if (start == NULL) {
        start = new_node;
        new_node->next = start;
    } else {
        ptr = start;
        preptr=ptr;
        while (preptr->data != val) {
        ptr=preptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        new_node->next = ptr;
    }

    return start;
}

struct node* delete_first(struct node* start) {
    struct node *temp, *ptr;

    if (start == NULL) {
        printf("List is empty!!!\n");
        return start;
    }

    if (start->next == start) {
        free(start);
        return NULL;
    }

    temp = start;
    ptr = start;

    while (ptr->next != start) {
        ptr = ptr->next;
    }

    start = start->next;
    ptr->next = start;

    free(temp);

    return start;
}
