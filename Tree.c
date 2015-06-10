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
struct tree{
    int level;
    int value;
    int balance;
    struct tree *left, *right;
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
    head->left = NULL;
    head->right = NULL;
    
    return head;
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
void insert(node *root, int value){
    node *father, *aux;
    int find = 0; //Loop control
    
    father = root;
    
    while((!find) &&  )
    
}

//Simple left rotation
void simpleLeft(node *root){
    node *r_aux, *f_aux;
    
    r_aux = root->right;
    f_aux = root;
    
    f_aux->right = r_aux->left;
    r_aux->left = f_aux;
}

//Simple right rotation
void simpleRight(node *root){
    node *l_aux, *f_aux;
    
    l_aux = root->left;
    f_aux = root;
    
    f_aux->left = l_aux->right;
    l_aux->right = f_aux;
}

//Double left rotation
void doubleLeft(node *root){
    node *f_aux, *r_aux, *sub_l;
    //Attribution
    f_aux = root;
    r_aux = root->right;
    sub_l = r_aux->left;
    
    //Firt rotation on sons
    r_aux->left = sub_l->right;
    sub_l->right= r_aux;
    f_aux->right = sub_l;
    
    //Final rotation on root
    f_aux->right = sub_l->left;
    sub_l->left = f_aux;
}

//Double right rotation
void doubleRight(node *root){
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