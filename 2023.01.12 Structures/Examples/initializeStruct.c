struct dot {
    double x;
    double y;
};

struct book1 {
    char title[50];
    char author[50];
    int year; 
    int pages;
}; 

struct book2 {
    char *title;
    char *author;
    int year;
    int pages;
};