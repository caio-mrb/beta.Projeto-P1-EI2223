#ifndef FUNCOESDEPORTATEIS_H
#define FUNCOESDEPORTATEIS_H

#include <stdio.h>

#include "funcoesDeData.h"
#include "constantes.h"

typedef struct Damages
{
    int code;
    int state;
    int type;
    int duration;
    DateType date;
} DamageType;

typedef struct Laptops
{
    int id;
    char name[MAX_NAME_CHAR];
    int processor;
    int ram;
    float price;
    int location;
    int state;
    int requestsCounter;
    int daysRequestedCounter;
    DamageType *damagesList;
    int damagesCounterTotal;
    int damagesCounterActive;
    DateType purchaseDate;
} LaptopType;

#include "funcoesDeRequisicoes.h"

void searchEqualLaptopId(int *result, LaptopType laptop[MAX_LAPTOPS],int totalLaptops, int numToComp);
void searchEqualDamage(int *equalIndex, DamageType *damageList, int totalDamages, DamageType damageToComp);
void searchEqualDamageCodeAndHigherDate(int *equalIndex, DamageType *damageList, int totalDamages, DateType dateToComp, int codeToComp);
int *searchTemporaryDamagesIndex(int *sizeDamageIndex, LaptopType laptop[MAX_LAPTOPS], int laptopId);

void readLaptopName(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLaptopId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLaptopProcessor(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLaptopRam(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLaptopPrice(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLaptopLocation(LaptopType laptop[MAX_LAPTOPS],int laptopIndex,int *cancel);
void readLaptopPurchaseDate(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void registerNewLaptop(LaptopType laptop[MAX_LAPTOPS], int totalLaptops, int index, int numOfLaptops, int *cancel);

void changeLaptopLocation(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *cancel);

void readDamageInfoCode(int index, int numOfDamages, DamageType *damageInfo, DamageType *damageList, int totalDamages, int *cancel);
void readDamageInfoType(int index, int numOfDamages, DamageType *damageInfo, int *cancel);
void readDamageInfoDate(int index, int numOfDamages, DamageType *damageInfo, DateType purchaseDate, DamageType *damageList, int totalDamages, int *cancel);
void registerNewDamage(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *index, int numOfDamages, int *cancel);
int *registerNewRepair(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *damageIndexList, int *sizeDamageIndex, int optRepairMenu);

void showLaptopInfo(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,RequestType *request,int totalRequests);
void showDamageHistoric(LaptopType laptop[MAX_LAPTOPS],int totalLaptops);
void writeDamageCode(int code, int windowSize);
DamageType *addDamageRepairInfo(DamageType damageRepairInfo, LaptopType laptop[MAX_LAPTOPS],int laptopIndex, int *cancel);
int *removeTemporaryDamage(int *damageIndexList,int *sizeDamageIndexList, int indexPosition);

#endif // FUNCOESDEPORTATEIS_H
