#ifndef FUNCOESDEREQUISICOES_H
#define FUNCOESDEREQUISICOES_H

#include <stdio.h>

#include "funcoesDePortateis.h"
#include "funcoesDeData.h"


typedef struct Requests
{
    char code[20];
    char laptopIndex;
    char applicantName[MAX_NAME_CHAR];
    int applicantType;
    int state;
    int renewLocation;
    int requestPeriod;
    int delayFee;
    DateType requestDate;
    DateType renewDate;

} RequestType;

#endif // FUNCOESDEREQUISICOES_H
