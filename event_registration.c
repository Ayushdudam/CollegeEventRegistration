#include <stdio.h>
#include <string.h>

#define MAX 5

struct student {
    char name[50];
    char event[50];
    int id;
};

struct student queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    if ((rear + 1) % MAX == front) {
        printf("\nQueue is Full!");
        return;
    }

    struct student s;

    printf("\nEnter Name: ");
    scanf(" %[^
]", s.name);

    printf("Enter Event: ");
    scanf(" %[^
]", s.event);

    printf("Enter ID: ");
    scanf("%d", &s.id);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = s;

    printf("Registered Successfully!");
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nRemoved: %s", queue[front].name);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("\nNo registrations!");
        return;
    }

    int i = front;
    printf("\nRegistered Students:\n");

    while (1) {
        printf("Name: %s | Event: %s | ID: %d\n",
               queue[i].name, queue[i].event, queue[i].id);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main() {
    int ch;

    while (1) {
        printf("\n\n1. Register\n2. Cancel\n3. Display\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!");
        }
    }
}
