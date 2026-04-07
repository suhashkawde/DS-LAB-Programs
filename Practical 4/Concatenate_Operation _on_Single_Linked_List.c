#include<stdio.h>
#include<stdlib.h>

int main() {
    NODE list1 = NULL, list2 = NULL;
    int choice, x;

    while (1) {
        printf("1. Create SLL1\n");
        printf("2. Create SLL2\n");
        printf("3. Display SLL1\n");
        printf("4. Display SLL2\n");
        printf("5. Concatenation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter elements for SLL1 (-1 to end): ");
                scanf("%d", &x);
                while (x != -1) {
                    list1 = addNode(list1, x);
                    scanf("%d", &x);
                }
                break;
            case 2:
                printf("Enter elements for SLL2 (-1 to end): ");
                scanf("%d", &x);
                while (x != -1) {
                    list2 = addNode(list2, x);
                    scanf("%d", &x);
                }
                break;
            case 3:
                printf("SLL1: ");
                displayList(list1);
                break;
            case 4:
                printf("SLL2: ");
                displayList(list2);
                break;
            case 5:
                list1 = concatenate(list1, list2);
                printf("Concatenated List: ");
                displayList(list1);
                break;
            case 6:
                exit(0);
        }
    }

    return 0;
}
struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
	NODE newNode = (NODE)malloc(sizeof(struct node));
	if (newNode == NULL) {
		exit(1);
	}
	newNode -> data = x;
	newNode -> next = NULL;
	return newNode;
}

NODE addNode(NODE first, int x) {
	NODE newNode = createNode(x);
	if (first == NULL) {
		return newNode;
	}
	NODE temp = first;
	while (temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = newNode;
	return first;
}

NODE concatenate(NODE t1, NODE t2) {
	if (t1 == NULL)
		return t2;
	if (t2 == NULL)
		return t1;
	NODE temp = t1;

	while (temp -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = t2;
	return t1;
}

void displayList(NODE first) {
	if (first == NULL) {
		printf("NULL\n");
		return;
	}
	NODE temp = first;
	while (temp != NULL) {
		printf ("%d --> ", temp -> data);
		temp = temp -> next;
	}
	printf ("NULL\n");
}