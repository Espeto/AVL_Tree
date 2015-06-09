/* 
 * File:   main.c
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
struct tree{
    int value;
    int balance;
    struct tree *left;
    struct tree *right;
};

//Defines 'node' as a type
typedef struct tree node;

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

//Function that initialize the tree
node *start(void){
    node *head;
    
    head = malloc(sizeof(node));
    head->balance = 0;
    head->left = NULL;
    head->right = NULL;
    
}

//Incial Menu
int menu(void){
    int option;
    
    do{
        printf("\t===== MENU =====\n");
        printf("\t1 - INSERT\n");
        printf("\t2 - PRINT\n");
        printf("\t3 - EXIT\n");
        scanf("%d", &option);
    }while(option < 1 && option > 3);
    getchar();
    
    return option;
}

//Insert function
void insert(node *root){
    node *father, *aux;
    
    father = root;
}

//Simple left rotation
void simpleLeft(node *root){
    node *r_aux, *f_aux;
    
    r_aux = root->right;
    f_aux = root;
    
    r_aux->left = f_aux;
    f_aux->right = NULL;
}

//Simple right rotation
void simpleRight(node *root){
    node *l_aux, *f_aux;
    
    l_aux = root->left;
    f_aux = root;
    
    l_aux->right = f_aux;
    f_aux->left = NULL;
}

//Double left rotation
void doubleLeft(node *root){
    
}

//Double right rotation
void doubleRight(node *root){
    
}