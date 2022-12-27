#ifndef FUNCOESDEDADOS_H
#define FUNCOESDEDADOS_H

#include <stdio.h>

#include "funcoesDePortateis.h"
#include "funcoesDeRequisicoes.h"

void flushStdin(void);
void clrScr(void);

void splitString(int splitPoint, char *enterStr, char firstReturnStr[MAX_SPLIT_STRING], char secondReturnStr[MAX_SPLIT_STRING]);
void toupperString(char *result, char *stringToUp);
void getNumOfDigits(int *result, int numToCountDigits);

void readInt(char *message, int *num,int numMin, int numMax);
void readFloat(char *message, float *num, float numMin, float numMax);
void readDate(char *message,DateType *date);
void readString(char *message,char *string, int maxStringSize);
void readStringOnlyLetters(char *message,char *string, int maxStringSize);
void removeSpecificChar(char *stringToEdit,char charToRemove);

void showStatistics(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,RequestType *request,int totalRequests);
void avarageFees(float *avarage,RequestType *request,int totalRequests);
void higherFee(int *higher, RequestType *request,int totalRequests);
void lowerFee(int *lower, RequestType *request,int totalRequests);
void percentageApplicant(float *percentage,RequestType *request, int totalRequests,int applicantType);
void percentageProcessor(float *percentage,LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int processor);
void showRecentCompletedRequests(int numOfRequests,RequestType *request, int totalRequests);

void numAvailableLaptops(int *result, LaptopType laptop[MAX_LAPTOPS],int totalLaptos);
void numActiveRequests(int *result, RequestType *request,int totalRequests);
void numCompletedRequests(int *result, RequestType *request,int totalRequests);

void writeApplicantTypeToFile(int numApplicantType, FILE *infofile);
void writeLocationToFile(int numLocation, FILE *infofile);

void storeInfoToFile(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests);
RequestType *loadFileToInfo(LaptopType laptop[MAX_LAPTOPS],int *totalLaptops, RequestType *request, int *totalRequests);
void storeLogData(LaptopType laptop[MAX_LAPTOPS], RequestType *request, int requestIndex);

#endif // FUNCOESDEDADOS_H
