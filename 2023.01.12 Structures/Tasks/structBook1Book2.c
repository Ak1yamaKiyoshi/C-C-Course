#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <strings.h>

struct Book {
    char *title;
    char *author; 
    int year;
    int pages;    
};

struct Book1 {
    char title[50];
    char author[50]; 
    int year;
    int pages;    
};


void enterBook(struct Book *p) {
    printf("enter author: ");
    p->author = (char*)calloc(sizeof(char), 50);
    scanf("%[^\n]%*c", p->author);
    fflush(stdin);

    p->title = (char*)calloc(sizeof(char), 50);
    printf("enter title: ");
    scanf("%[^\n]%*c", p->title);
    fflush(stdin);

    printf("enter year: ");
    scanf("%d", &p->year);

    printf("enter pages: ");
    scanf("%d", &p->pages);
}

void printBook(struct Book *p) {
    printf(
        "\n|  Author: %s\n|  Title:  %s\n|  Year:   %d\n|  Pages:  %d\n", 
        p->author, p->title, p->year, p->pages);
}


void enterBook1(struct Book1 *p) {

    printf("enter author: ");
    scanf("%[^\n]%*c", &p->author);
    fflush(stdin);

    printf("enter title: ");
    scanf("%[^\n]%*c", &p->title);
    fflush(stdin);

    printf("enter year: ");
    scanf("%d", &p->year);

    printf("enter pages: ");
    scanf("%d", &p->pages);
}

void printBook1(struct Book1 *p) {
    printf(
        "\n__________\n|  Author: %s\n|  Title:  %s\n|  Year:   %d\n|  Pages:  %d\n", 
        p->author, p->title, p->year, p->pages);
}



int main() {
    struct Book *book1 =(struct Book*)malloc(sizeof(struct Book));
    //struct Book1 *book1 =(struct Book1*)malloc(sizeof(struct Book1));

    enterBook(book1);
    printBook(book1);
    
    free(book1);
    printf("ABCD");
    
}