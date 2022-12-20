#ifndef FUNCOESDEDADOS_H
#define FUNCOESDEDADOS_H

#include <stdio.h>

#include "funcoesDePortateis.h"
#include "funcoesDeRequisicoes.h"
#include "funcoesDeData.h"
#include "constantes.h"

typedef struct Logs
{
    RequestType request;
    DateType todayDate;

} LogType;



void flushStdin(void);
void clrScr(void);

void plusIfNegative(int numCompared, int *result);
void plusIfEqualZero(int numCompared, int *result);
void plusIfNULL(int *numCompared, int *result);

void alignMargin(int contentSize, int totalSpaces);
void splitString(int splitPoint, char *enterStr, char firstReturnStr[MAX_SPLIT_STRING], char secondReturnStr[MAX_SPLIT_STRING]);
void getNumOfDigits(int *result, int numToCountDigits);

void readInt(char *message, int *num,int numMin, int numMax);
void readFloat(char *message, float *num, float numMin, float numMax);
void readDate(char *message,DateType *date);
void readString(char *message,char *string, int maxStringSize);
void readStringOnlyLetters(char *message,char *string, int maxStringSize);
void removeExtraSpaces(char *string);
void removeExtraSpacesAndZeros(char *string);

void getApplicantTypeName(int typeNum, char stringApplicantType[MAX_NAME_APPLICANT_TYPE]);
void getLocationName(int locationNum, char stringLocation[MAX_NAME_LOCATION]);
void getRequestStateName(int stateNum, char stringRequestState[MAX_NAME_REQUEST_STATE]);

void numAvailableLaptops(int *result, LaptopType laptop[MAX_LAPTOPS],int totalLaptos);
void numActiveRequests(int *result, RequestType *request,int totalRequests);

void storeInfoToFile(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests);
RequestType *loadFileToInfo(LaptopType laptop[MAX_LAPTOPS],int *totalLaptops, RequestType *request, int *totalRequests);
void storeLogToFile(LogType log,int totalLogs,int wroteCorrect[MAX_LOAD_INFO]);


#endif // FUNCOESDEDADOS_H
