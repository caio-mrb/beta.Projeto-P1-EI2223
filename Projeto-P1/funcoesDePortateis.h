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
    DateType date;
    int duration;

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
    DamageType *damagesList;
    int damagesCounterTotal;
    int damagesCounterActive;
    DateType purchaseDate;
} LaptopType;

void searchEqualLapId(int *result, LaptopType laptop[MAX_LAPTOPS],int totalLaptops, int numToComp);
int *searchTemporaryDamagesIndex(int *sizeDamageIndex, LaptopType laptop[MAX_LAPTOPS], int laptopId);

void readLapName(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLapId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLapProcessor(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLapRam(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLapPrice(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLapLocation(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);
void readLapPurchaseDate(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel);


void readDamageInfoCode(int index, int numOfDamages, DamageType *damageInfo, int *cancel);
void readDamageInfoType(int index, int numOfDamages, DamageType *damageInfo, int *cancel);
void readDamageInfoDate(int index, int numOfDamages, DamageType *damageInfo, int *cancel);

int *changeLapLocationTo(int locationNum,LaptopType laptop[MAX_LAPTOPS],int laptopIndex);
void showLaptopInfo(LaptopType laptop[MAX_LAPTOPS],int totalLaptops);
void writeDamageCode(int code, int windowSize);
DamageType *addDamageRepairInfo(DamageType damageRepairInfo, LaptopType laptop[MAX_LAPTOPS],int laptopIndex, int *cancel);
int *removeTemporaryDamage(int *damageIndexList,int sizeDamageIndexList, int indexPosition);

#endif // FUNCOESDEPORTATEIS_H
