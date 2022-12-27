#ifndef FUNCOESDEDATA_H
#define FUNCOESDEDATA_H

#include <stdio.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} DateType;

void showDate(DateType date);
void numOfDaysBetweenDates(int *result,DateType lowerDate, DateType higherDate);
void writeDateToFile(DateType date, FILE *infoFile);

#endif // FUNCOESDEDATA_H
