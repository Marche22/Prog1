#include <stdio.h>
#include <stdlib.h>

struct book{
    char author_surname[BUFSIZ];
    char title[BUFSIZ];
    char publication_date[BUFSIZ];
};

int year_int(struct book*);
int month_int(struct book*);
int day_int(struct book*);

int main(int argc, char const *argv[]) {

    struct book b = {"Rossi","Ciao","2012/07/29"};

    printf("\n%d %d\n", year_int(&b), month_int(&b));//, day_int(&b));

    return 0;
}

int year_int(struct book* this_book){
    int year = 0;
    char substring_year[5];
    substring_year[5] = '\0';
    for(int i=0; i<4; i++)
        *(substring_year+i)=(*this_book).publication_date[i];
        year = atoi(substring_year);
    return year;
}
int month_int(struct book* this_book){
    int month = 0;
    char substring_month[3];
    substring_month[3] = '\0';
    for(int i=5; i<7; i++)
        *(substring_month+i)=(*this_book).publication_date[i];
        month = atoi(substring_month);
    return month;
}
int day_int(struct book* this_book){
    int day = 0;
    char substring_day[3];
    substring_day[3] = '\0';
    for(int i=8; i<10; i++)
        *(substring_day+i)=(*this_book).publication_date[i];
        day = atoi(substring_day);
    return day;
}

/*int most_recent_book(struct book* books, int num_books){
    struct book most_recent = books*;
    int year=0, month, day;
    for(int i=0; i<num_books; i++){
        if(!i){
            year += 1000*atoi((*(books+i)).publication_date[0]);
            year += 100*atoi((*(books+i)).publication_date[1]);
            year += 10*atoi((*(books+i)).publication_date[2]);
            year += atoi((*(books+i)).publication_date[3]);
        }
        else{

        }
    }
}*/
