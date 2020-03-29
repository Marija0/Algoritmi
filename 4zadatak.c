#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

//kopirano za stog
// A structure to represent a stack 
struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root)
{
    return !root;
}

void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
//------------------------//

//definirana velicina matrice
// M -> IxJ
#define I 10
#define J 10

//popunjavanje stogova
void push_s(struct StackNode** s1, struct StackNode** s2, int n) {
    //glavna dijagonala matrice M = N
    for (int i = 0; i < n; i++) {
        push(s1, i);
        push(s2, i);
    }
}

//elementi matrice na -1 (nije potrebno ali se bolje vidi algoritam)

void default_v(int matrica[I][J], int y, int x, int v) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
                matrica[i][j] = v;
        }
    }
}

//ovo stavlja 1 na elemente koji su u stogovima
void popuni_definirane(struct StackNode** s1, struct StackNode** s2, int matrica[I][J]) {
    int i, j;
    //prva dva elementa za pocetak
    i = pop(s1);
    j = pop(s2);

    while (i>=0&&j>=0) {
        matrica[i][j] = 1;
        i = pop(s1);
        j = pop(s2);
    }
}

//stavlja 0 na ostale
void popuni_ostale(int matrica[I][J], int y, int x) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (matrica[i][j] != 1) {
                matrica[i][j] = 0;
            }
        }
    }

}


void ispis(int matrica[I][J], int y, int x) {
    printf("\n");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d", matrica[i][j]);
            if (j < (x - 1)) {
                printf(", ");
            }
        }
        printf("\n");
    }
}




int main()
{
    struct StackNode* s1 = NULL;    //redak
    struct StackNode* s2 = NULL;    //stupac
    int M[I][J];  
    default_v(M, I, J, 4);//matrica popunjena 4 vrijednostima, moze biti bilo koja

    push_s(&s1, &s2, I);    //popunjavanje stogova dijagonalom matrice
    printf("\nStogovi popunjeni\n");

    printf("\nDefinirano u stogovima\n");
    popuni_definirane(&s1, &s2, M);
    ispis(M, I, J);

    printf("\nOstalo");
    popuni_ostale(M, I, J);
    ispis(M, I, J);

    return 0;
}
