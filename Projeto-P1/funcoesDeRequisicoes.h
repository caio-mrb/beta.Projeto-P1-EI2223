#ifndef FUNCOESDEREQUISICOES_H
#define FUNCOESDEREQUISICOES_H

#include <stdio.h>

#include "funcoesDeData.h"
#include "constantes.h"

typedef struct Requests
{
    char code[MAX_CODE_CHAR];
    char applicantName[MAX_NAME_CHAR];
    int applicantType;
    int state;
    int duration;
    int delayFee;
    int laptopIndex;
    int durationTotal;
    int returnLocation;
    DateType requestDate;
    DateType returnDate;

} RequestType;

#include "funcoesDePortateis.h"
#include "funcoesDeDesign.h"

void searchEqualReqCode(int *equalIndex, RequestType *request,int totalRequests, char *codeToComp);
void searchRequestIndex(int *equalIndex, RequestType *request,int totalRequests, int laptopIndex);


RequestType *registerNewRequest(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,RequestType *request, int *totalRequests,int index,int numOfRequests, int *cancel);

void registerReturnByRequestCode(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfReturns, int *cancel);
void registerReturnByLaptopId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfReturns, int *cancel);
void registerReturnByDamageMenu(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests, int laptopIndex, int *cancel);

void registerRenewByLaptopId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfReturns, int *cancel);
void registerRenewByRequestCode(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfRenews, int *cancel);

void readRequestCodeToShowInfo(int *requestIndex,RequestType *request,int totalRequests, int *cancel);

void readRequestCode(RequestType *newRequestInfo,RequestType *request,int totalRequests,int *cancel);
void readRequestLaptopId(RequestType *newRequestInfo,LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readRequestApplicantName(RequestType *newRequestInfo,int *cancel);
void readRequestApplicantType(RequestType *newRequestInfo,int *cancel);
void readRequestDate(RequestType *newRequestInfo,LaptopType laptop[MAX_LAPTOPS],int *cancel);
void readRequestRequestDuration(RequestType *newRequestInfo,int *cancel);

void readReturnRequestCode(int *requestIndex,RequestType *request, int totalRequests,int *cancel);
void readReturnLaptopId(int *laptopIndex, LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readReturnDate(int *days,RequestType *request, int requestIndex, int *cancel);

void showRequestInfo(LaptopType laptop[MAX_LAPTOPS], RequestType *request, int requestIndex);

#endif // FUNCOESDEREQUISICOES_H
