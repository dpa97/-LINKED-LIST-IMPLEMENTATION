#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at the end
void insert(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Delete from beginning
void delete() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Display the list
void display() {
    struct Node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    int choice, val;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\nChoose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
