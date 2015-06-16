/* 
 * File:   Tree.c
 * Author: gilberto
 *
 * Created on 7 de Junho de 2015, 05:16
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

//Defines the base of main structure

struct tree {
    int level;
    int value;
    int balance;
    struct tree *left, *right;
};

//Defines 'node' as a type
typedef struct tree node;

//Define structure of queue

struct queue {
    node *nd;
    struct queue *next;
};

//Define queue as a type named 'list'
typedef struct queue list;

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

//Function that initialize the tree

node *create(void) {
    node *new;

    new = malloc(sizeof (node));
    new->left = NULL;
    new->right = NULL;

    return new;
}

//Incial Menu

int menu(void) {
    int option;

    do {
        printf("\t===== MENU =====\n");
        printf("\t1 - INSERT\n");
        printf("\t2 - PRINT\n");
        printf("\t3 - EXIT\n");
        scanf("%d", &option);
    } while (option < 1 && option > 3);
    getchar();

    return option;
}

//Insert function

void insert(node *root, int numb) {
    node *new, *aux;
    int find = 0, set = 0; //Loop control

    aux = root;

    while ((!find) && (!set)) {
        if (numb > aux->value) {
            if (aux->right != NULL) {
                aux = aux->right;
            } else {
                set = 2;
            }
        } else if (numb < aux->value) {
            if (aux->left != NULL) {
                aux = aux->left;
            } else {
                set = 1;
            }
        } else {
            find = 1;
        }
    }
    if (find) {
        printf("===\tNumber already exists in the tree\t===\n");
    }
    else {
        new = create();
        new->value = numb;

        if (set == 1) {
            aux->left = new;
        } else {
            aux->right = new;
        }
    }
}

//Simple left rotation

void simpleLeft(node *root) {
    node *r_aux, *f_aux;

    r_aux = root->right;
    f_aux = root;

    f_aux->right = r_aux->left;
    r_aux->left = f_aux;
}

//Simple right rotation

void simpleRight(node *root) {
    node *l_aux, *f_aux;

    l_aux = root->left;
    f_aux = root;

    f_aux->left = l_aux->right;
    l_aux->right = f_aux;
}

//Double left rotation

void doubleLeft(node *root) {
    node *f_aux, *r_aux, *sub_l;
    //Attribution
    f_aux = root;
    r_aux = root->right;
    sub_l = r_aux->left;

    //Firt rotation on sons
    r_aux->left = sub_l->right;
    sub_l->right = r_aux;
    f_aux->right = sub_l;

    //Final rotation on root
    f_aux->right = sub_l->left;
    sub_l->left = f_aux;
}

//Double right rotation

void doubleRight(node *root) {
    node *f_aux, *l_aux, *sub_r;
    //Attribution
    f_aux = root;
    l_aux = root->left;
    sub_r = l_aux->right;

    //First rotation on sons
    l_aux->right = sub_r->left;
    sub_r->left = l_aux;
    f_aux->left = sub_r;

    //Final rotation on root
    f_aux->left = sub_r->right;
    sub_r->right = f_aux;
}

void enqueue(list *h, list *t, node *v) {
    list *new, *aux;

    new = malloc(sizeof (list));
    new->nd = v;

    if (t->next != NULL) {
        aux = t->next;
        aux->next = new;
        new->next = NULL;
        t->next = new;
    } else {
        t->next = new;
        new->next = NULL;
    }

    if (h->next == NULL) {
        h->next = new;
    }
}

node *dequeue(list *h) {
    list *f;
    node *val;

    f = h -> next;
    val = f->nd;

    if (f != NULL) {
        h -> next = f -> next;
        free(f);
    }

    return val;
}

list *startQueue(void) {
    list *start;

    start = malloc(sizeof (list));
    start->nd = NULL;
    start->next = NULL;

    return start;
}
