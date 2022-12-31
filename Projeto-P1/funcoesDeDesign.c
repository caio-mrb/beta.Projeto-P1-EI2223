#include "funcoesDeDesign.h"

#include <stdio.h>
#include <string.h>


void drawTittle(void)
{
    printf(" _               _____ _______ ____  _____    _____  ______ ____  _    _ ______  _____ _______\n");
    printf("| |        /\\   |  __ \\__   __/ __ \\|  __ \\  |  __ \\|  ____/ __ \\| |  | |  ____|/ ____|__   __|  TM\n");
    printf("| |       /  \\  | |__) | | | | |  | | |__) | | |__) | |__ | |  | | |  | | |__  | (___    | |\n");
    printf("| |      / /\\ \\ |  ___/  | | | |  | |  ___/  |  _  /|  __|| |  | | |  | |  __|  \\___ \\   | |\n");
    printf("| |____ / ____ \\| |      | | | |__| | |      | | \\ \\| |___| |__| | |__| | |____ ____) |  | |\n");
    printf("|______/_/    \\_\\_|      |_|  \\____/|_|      |_|  \\_\\______\\___\\_\\\\____/|______|_____/   |_|\n\n");
    printf("Criado por: Andre Rosa e Caio Barbosa.\n");
}

void drawWelcome(void)
{
    printf(" ________________________\n");
    printf("|                        |\n");
    printf("| Bem-Vindo ao Programa! |\n");
    printf("|________________________|\n\n");

}

void drawWelcomeBack(void)
{
    printf(" ____________________\n");
    printf("|                    |\n");
    printf("| Bem-Vindo de volta |\n");
    printf("| ao Programa!       |\n");
    printf("|____________________|\n");
}

void drawMainMenu(int totalLaptops, int availableLaptops, int totalRequests, int activeRequests)
{
    int totalLaptopsDigits, availableLaptopsDigits, activeRequestsDigits, totalRequestsDigits;

    getNumOfDigits(&totalLaptopsDigits,totalLaptops);
    getNumOfDigits(&availableLaptopsDigits,availableLaptops);
    getNumOfDigits(&activeRequestsDigits,activeRequests);
    getNumOfDigits(&totalRequestsDigits,totalRequests);

    printf("                    _____ ___ ___ _ _\n");
    printf("                   |     | -_|   | | |\n");
    printf("                   |_|_|_|___|_|_|___|\n\n");
    printf("         ________________________________________\n");
    printf("        |                                        |\n");
    printf("        | Portateis existentes: %d",totalLaptops);
    alignMargin(totalLaptopsDigits,16);
    printf("        | Portateis disponiveis: %d",availableLaptops);
    alignMargin(availableLaptopsDigits,15);
    printf("        |                                        |\n");
    printf("        | Quantidade de requisicoes ativas: %d",activeRequests);
    alignMargin(activeRequestsDigits,4);
    printf("        | Quantidade total de requisicoes: %d",totalRequests);
    alignMargin(totalRequestsDigits,5);
    printf("        |________________________________________|\n\n");

    printf("         ________________________________________\n");
    printf("        |                                        |\n");
    printf("        | Selecione uma opcao para aceder ao     |\n");
    printf("        | respetivo submenu:                     |\n");
    printf("        | 1 - Portateis                          |\n");
    printf("        | 2 - Requisicoes/Devolucoes             |\n");
    printf("        | 3 - Estatisticas                       |\n");
    printf("        | 4 - Sair                               |\n");
    printf("        |________________________________________|\n\n");
}

void drawLaptopMenu(void)
{

    printf("         ____________________________________________\n");
    printf("        |_PORTATEIS______________________________(X)_|\n");
    printf("        |                                            |\n");
    printf("        | Selecione a opcao pretendida:              |\n");
    printf("        | 1 - Adicionar portatil(eis)                |\n");
    printf("        | 2 - Listar informacoes do(s) portatil(eis) |\n");
    printf("        | 3 - Alterar localizacao do portatil        |\n");
    printf("        | 4 - Registar avaria/reparacao do portatil  |\n");
    printf("        | 5 - Voltar                                 |\n");
    printf("        |____________________________________________|\n\n");


}

void drawInfoMenu(void)
{

    printf("         ______________________________\n");
    printf("        |_PORTATEIS________________(X)_|\n");
    printf("        |                              |\n");
    printf("        | Mostrar a informacao base do |\n");
    printf("        | portatil e o:                |\n");
    printf("        | 1 - Historico de requisicoes |\n");
    printf("        | 2 - Historico de avarias     |\n");
    printf("        | 3 - Voltar                   |\n");
    printf("        |______________________________|\n\n");

}

void drawRequestsNotFound(void)
{

    printf("         _____________________________________\n");
    printf("        |_REQUESICOES/DEVOLUCOES__________(X)_|\n");
    printf("        |                                     |\n");
    printf("        | Nao existem requisicoes no sistema. |\n");
    printf("        |_____________________________________|\n\n");

}

void drawLaptopIdInfoWindow(int laptopId)
{
    char stringId[5],extraText[13]="PORTATIL ID#";
    sprintf(stringId, "%d", laptopId);
    printf("        ");
    centerTittle(extraText,stringId,MAX_SPACES_INFO_WINDOW);
}

void drawNameInfoWindow(char *margin, char *extraText, char *name)
{
    char firstSplitedStr[MAX_SPLIT_STRING] = {'\0'}, secondSplitedStr[MAX_SPLIT_STRING] = {'\0'}, thirdSplitedStr[MAX_SPLIT_STRING] = {'\0'};

    if (strlen(name)+strlen(extraText) < MAX_SPACES_INFO_WINDOW)
    {
        printf("%s| %s%s",margin,extraText,name);
        alignMargin(strlen(name)+strlen(extraText),MAX_SPACES_INFO_WINDOW);
    }

    if (strlen(name)+strlen(extraText) < MAX_SPACES_INFO_WINDOW*2 && strlen(name)+strlen(extraText) >= MAX_SPACES_INFO_WINDOW)
    {
        splitString(MAX_SPACES_INFO_WINDOW-strlen(extraText),name,firstSplitedStr,secondSplitedStr);

        printf("%s| %s%s",margin,extraText,firstSplitedStr);
        alignMargin(strlen(firstSplitedStr)+strlen(extraText),MAX_SPACES_INFO_WINDOW);

        printf("%s| %s",margin,secondSplitedStr);
        alignMargin(strlen(secondSplitedStr),MAX_SPACES_INFO_WINDOW);

    }

    if (strlen(name)+strlen(extraText) < MAX_SPACES_INFO_WINDOW*3 && strlen(name)+strlen(extraText) >= MAX_SPACES_INFO_WINDOW*2)
    {
        splitString(MAX_SPACES_INFO_WINDOW-strlen(extraText),name,firstSplitedStr,secondSplitedStr);
        splitString(MAX_SPACES_INFO_WINDOW,secondSplitedStr,secondSplitedStr,thirdSplitedStr);


        printf("%s| %s%s",margin,extraText,firstSplitedStr);
        alignMargin(strlen(firstSplitedStr)+strlen(extraText),MAX_SPACES_INFO_WINDOW);

        printf("%s| %s",margin,secondSplitedStr);
        alignMargin(strlen(secondSplitedStr),MAX_SPACES_INFO_WINDOW);

        printf("%s| %s",margin,thirdSplitedStr);
        alignMargin(strlen(thirdSplitedStr),MAX_SPACES_INFO_WINDOW);
    }
}

void drawLaptopStateInfoWindow(int laptopState)
{
    switch(laptopState)
    {
    case AVAILABLE:
        printf("        | Estado: Disponivel");
        alignMargin(18,MAX_SPACES_INFO_WINDOW);
        break;
    case REQUESTED:
        printf("        | Estado: Requisitado");
        alignMargin(19,MAX_SPACES_INFO_WINDOW);
        break;
    case BROKEN_PERMANENT:
    case BROKEN_TEMPORARY:
        printf("        | Estado: Avariado");
        alignMargin(16,MAX_SPACES_INFO_WINDOW);
        break;
    }
}

void drawLaptopLocationInfoWindow(int laptopLocation)
{
    switch(laptopLocation)
    {
    case RESIDENCES:
        printf("        | Localizacao Atual: Residencias");
        alignMargin(30,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_1:
        printf("        | Localizacao Atual: Campus1");
        alignMargin(26,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_2:
        printf("        | Localizacao Atual: Campus2");
        alignMargin(26,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_3:
        printf("        | Localizacao Atual: Campus3");
        alignMargin(26,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_5:
        printf("        | Localizacao Atual: Campus5");
        alignMargin(26,MAX_SPACES_INFO_WINDOW);
        break;
    }
}

void drawLaptopTotalDamagesInfoWindow(int damagesTotal)
{

    int damagesDigits;
    getNumOfDigits(&damagesDigits,damagesTotal);

    printf("        | Quantidade de avarias: %d", damagesTotal);
    alignMargin(23+damagesDigits,MAX_SPACES_INFO_WINDOW);

}

void drawLaptopProcessorInfoWindow(int laptopProcessor)
{

    printf("        | Processador: Intel Core i%d     |\n",laptopProcessor);

}

void drawLaptopRamInfoWindow(int laptopRam)
{

    int ramDigits;
    getNumOfDigits(&ramDigits,laptopRam);

    printf("        | Memoria RAM: %d GB",laptopRam);
    alignMargin(16+ramDigits,MAX_SPACES_INFO_WINDOW);

}

void drawLaptopTotalRequestsInfoWindow(int requestTotal)
{
    int requestDigits;
    getNumOfDigits(&requestDigits,requestTotal);

    printf("        | Quantidade de requisicoes: %d", requestTotal);
    alignMargin(27+requestDigits,MAX_SPACES_INFO_WINDOW);
}

void drawLaptopPriceInfoWindow(float laptopPrice)
{
    int priceDigits;
    getNumOfDigits(&priceDigits,(int)laptopPrice);

    printf("        | Valor de Compra: %.2f euros",laptopPrice);
    alignMargin(26+priceDigits,MAX_SPACES_INFO_WINDOW);

}

void drawLaptopPurchaseDateInfoWindow(DateType purchaseDate)
{

    printf("        | Data de Compra: ");
    showDate(purchaseDate);
    alignMargin(26,MAX_SPACES_INFO_WINDOW);

}

void drawLaptopDamageTypeInfoWindow(int damageType)
{

    if (damageType == TEMPORARY)
    {
        printf("        | -(Avaria Temporaria)-");
        alignMargin(21,MAX_SPACES_INFO_WINDOW);
    }
    if (damageType == PERMANET)
    {
        printf("        | -(Avaria Permanente)-");
        alignMargin(21,MAX_SPACES_INFO_WINDOW);
    }

}

void drawLaptopDamageDescInfoWindow(DamageType *damagesList,int indexDamage)
{
    int dayDigits;
    getNumOfDigits(&dayDigits,damagesList[indexDamage].duration);

    if (damagesList[indexDamage].state == COMPLETED)
    {
        printf("        | Avariado por %d dias",damagesList[indexDamage].duration);
        alignMargin(18+dayDigits,MAX_SPACES_INFO_WINDOW);
    }
    if (damagesList[indexDamage].state == ACTIVE)
    {
        printf("        | Avaria ainda por arranjar...");
        alignMargin(28,MAX_SPACES_INFO_WINDOW);
    }
    if (damagesList[indexDamage].type == PERMANET)
    {
        printf("        | Avaria impossivel de arranjar");
        alignMargin(29,MAX_SPACES_INFO_WINDOW);
    }

}

void drawMaxLaptopsReachAlert(void)
{
    printf("         ____________________________________\n");
    printf("        |_PORTATEIS______________________(X)_|\n");
    printf("        |                                    |\n");
    printf("        | Ja foi atingido o limite maximo de |\n");
    printf("        | portateis existentes.              |\n");
    printf("        |____________________________________|\n\n");

}

void drawMaxDamagesReachAlert(void)
{
    printf("         __________________________________\n");
    printf("        |_PORTATEIS____________________(X)_|\n");
    printf("        |                                  |\n");
    printf("        | O portátil selecionado ja possui |\n");
    printf("        | o maximo de avarias possivel.    |\n");
    printf("        |__________________________________|\n\n");
}

void drawAddLaptop(int totalLaptops)
{

    printf("         ___________________________________\n");
    printf("        |_PORTATEIS_____________________(X)_|\n");
    printf("        |                                   |\n");
    if (totalLaptops > 0)
    {
        printf("        | Ja existe(m) %2d portatil(eis).    |\n", totalLaptops);
    }
    else
    {
        printf("        | Nao existem portateis ainda.      |\n");
    }
    printf("        | Podes adicionar %2d portatil(eis). |\n",MAX_LAPTOPS - totalLaptops);
    printf("        | Digite 0 para cancelar.           |\n");
    printf("        |___________________________________|\n\n");

}

void drawLaptopInfoAsk(int index, int numOfLaptops)
{

    printf("         ____________________________________________\n");
    printf("        |_PORTATEIS______________________________(X)_|\n");
    printf("        |                                            |\n");
    printf("        | Preencha os campos de acordo com o que e   |\n");
    printf("        | pedido.                                    |\n");
    printf("        | Estas a adicionar o portatil %2d de %2d.     |\n", index+1, numOfLaptops);
    printf("        | Digite 0 em qualquer campo para cancelar.  |\n");
    printf("        |____________________________________________|\n\n");
}

void drawRequestInfoAsk(int index,int numOfRequests)
{
    int indexDigits, numOfRequestsDigits;
    getNumOfDigits(&indexDigits,index);
    getNumOfDigits(&numOfRequestsDigits,numOfRequests);

    printf("         ____________________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES_________________(X)_|\n");
    printf("        |                                            |\n");
    printf("        | Preencha os campos de acordo com o que e   |\n");
    printf("        | pedido.                                    |\n");
    printf("        | Estas a registar a requisicao %d de %d.", index+1, numOfRequests);
    alignMargin(indexDigits+numOfRequestsDigits,7);
    printf("        | Digite 0 em qualquer campo para cancelar.  |\n");
    printf("        |____________________________________________|\n\n");
}

void drawLocationsMiniList(void)
{

    printf("         __________________\n");
    printf("        | RE - Residencias |\n");
    printf("        | C1 - Campus1     |\n");
    printf("        | C2 - Campus2     |\n");
    printf("        | C3 - Campus3     |\n");
    printf("        |_C5 - Campus5_____|\n\n");
}

void drawLocationsBigList(void)
{

    printf("         ____________________________\n");
    printf("        |_PORTATEIS______________(X)_|\n");
    printf("        |                            |\n");
    printf("        | Selecione para onde deseja |\n");
    printf("        | mover o portatil:          |\n");
    printf("        | RE - Residencias           |\n");
    printf("        | C1 - Campus1               |\n");
    printf("        | C2 - Campus2               |\n");
    printf("        | C3 - Campus3               |\n");
    printf("        | C5 - Campus5               |\n");
    printf("        |  0 - Cancelar              |\n");
    printf("        |____________________________|\n\n");
}

void clearScreen(void)
{
    int index;

    for(index=0; index<LINES_CLEAR_SCREEN; index++)
    {
        printf("\n");
    }

}

void drawAddLaptopCancel(int numOfLaptops)
{
    int laptopsDigits;
    getNumOfDigits(&laptopsDigits,numOfLaptops);
    printf("         _________________________________________________\n");
    printf("        |_PORTATEIS___________________________________(X)_|\n");
    printf("        |                                                 |\n");
    printf("        | Foi(ram) adicionado(s) apenas %d portatil(eis).",numOfLaptops);
    alignMargin(laptopsDigits,2);
    printf("        |_________________________________________________|\n\n");
}

void drawDamageCancel(int numOfDamages)
{
    int damagesDigits;

    getNumOfDigits(&damagesDigits,numOfDamages);
    printf("         _________________________________________________\n");
    printf("        |_PORTATEIS___________________________________(X)_|\n");
    printf("        |                                                 |\n");
    printf("        | Foi(ram) registada(s) apenas %d avaria(s).",numOfDamages);
    alignMargin(damagesDigits,7);
    printf("        |_________________________________________________|\n\n");
}

void drawRequestCancel(int numOfRequests)
{

    int requestsDigits;

    getNumOfDigits(&requestsDigits,numOfRequests);
    printf("         __________________________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES_______________________(X)_|\n");
    printf("        |                                                  |\n");
    printf("        | Foi(ram) registada(s) apenas %d requisicao(oes).",numOfRequests);
    alignMargin(requestsDigits,2);
    printf("        |__________________________________________________|\n\n");
}

void drawReturnCancel(int numOfReturns)
{
    int returnsDigits;

    getNumOfDigits(&returnsDigits,numOfReturns);
    printf("         _________________________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES______________________(X)_|\n");
    printf("        |                                                 |\n");
    printf("        | Foi(ram) registada(s) apenas %d devolucao(oes).",numOfReturns);
    alignMargin(returnsDigits,2);
    printf("        |_________________________________________________|\n\n");
}

void drawRenewCancel(int numOfRenews)
{
    int renewsDigits;

    getNumOfDigits(&renewsDigits,numOfRenews);
    printf("         __________________________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES_______________________(X)_|\n");
    printf("        |                                                  |\n");
    printf("        | Foi(ram) registada(s) apenas %d devolucao(oes).",numOfRenews);
    alignMargin(renewsDigits,3);
    printf("        |__________________________________________________|\n\n");
}

void drawRepairList(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *damagesIndexList, int sizeDamagesIndexList)
{
    int idDigits, index;

    clearScreen();
    getNumOfDigits(&idDigits,laptop[laptopIndex].id);

    printf("         __________________________________\n");
    printf("        |_PORTATEIS____________________(X)_|\n");
    printf("        |                                  |\n");
    printf("        | Selecionado: ->Portatil ID#%d",laptop[laptopIndex].id);
    alignMargin(idDigits,5);
    printf("        | Selecione a avaria para reparar: |\n");


    for (index = 0; index < sizeDamagesIndexList; index++)
    {
        if(sizeDamagesIndexList+1 < 10)
        {
            printf("        | %d - [",index+1);
            showDate(laptop[laptopIndex].damagesList[damagesIndexList[index]].date);
            printf("]");
            writeDamageCode(laptop[laptopIndex].damagesList[damagesIndexList[index]].code,29);
        }
        else
        {
            if (index+1 < 10)
            {
                printf("        | 0%d - [",index+1);
            }
            else
            {
                printf("        | %d - [",index+1);
            }
            showDate(laptop[laptopIndex].damagesList[damagesIndexList[index]].date);
            printf("]");
            writeDamageCode(laptop[laptopIndex].damagesList[damagesIndexList[index]].code,28);
        }
    }
    printf("        | %d - Cancelar                     |\n", sizeDamagesIndexList+1);
    printf("        |__________________________________|\n\n");


}

void drawRequestLaptopIdInfoWindow(int laptopId)
{
    int idDigits;

    getNumOfDigits(&idDigits,laptopId);
    printf("        | Portatil ID#%d",laptopId);
    alignMargin(idDigits+12,MAX_SPACES_INFO_WINDOW);
}

void drawRequestApplicantTypeInfoWindow(int applicantType)
{
    switch(applicantType)
    {
    case STUDENT:
        printf("        | Tipo do utente: Estudante");
        alignMargin(25,MAX_SPACES_INFO_WINDOW);
        break;
    case TEACHER:
        printf("        | Tipo do utente: Docente");
        alignMargin(23,MAX_SPACES_INFO_WINDOW);
        break;
        break;
    case ADMIN_TECH:
        printf("        | Tipo do utente: Tecnico");
        alignMargin(23,MAX_SPACES_INFO_WINDOW);
        printf("        | Administrativo");
        alignMargin(14,MAX_SPACES_INFO_WINDOW);
        break;
    }
}

void drawRequestDelayFeeInfoWindow(int delayFee)
{
    int feeDigits;

    getNumOfDigits(&feeDigits,delayFee);

    printf("        | Multa: %d euros",delayFee);
    alignMargin(feeDigits+13,MAX_SPACES_INFO_WINDOW);
}

void drawRequestTotalDurationInfoWindow(int durationTotal)
{
    int durationDigits;

    getNumOfDigits(&durationDigits,durationTotal);
    printf("        | Foi devolvido apos %d dias",durationTotal);
    alignMargin(durationDigits+24,MAX_SPACES_INFO_WINDOW);

}

void drawRequestLocationInfoWindow(int returnLocation)
{
    switch(returnLocation)
    {
    case RESIDENCES:
        printf("        | Devolvido em: Residencias");
        alignMargin(25,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_1:
        printf("        | Devolvido em: Campus1");
        alignMargin(21,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_2:
        printf("        | Devolvido em: Campus2");
        alignMargin(21,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_3:
        printf("        | Devolvido em: Campus3");
        alignMargin(21,MAX_SPACES_INFO_WINDOW);
        break;
    case CAMPUS_5:
        printf("        | Devolvido em: Campus5");
        alignMargin(21,MAX_SPACES_INFO_WINDOW);
        break;
    }
}

void drawRequestStateInfoWindow(int requestState)
{
    if (requestState == ACTIVE)
    {
        printf("        | Estado da Requisicao: Ativa");
        alignMargin(27,MAX_SPACES_INFO_WINDOW);
    }
    if (requestState == COMPLETED)
    {
        printf("        | Estado da Requisicao: Completa");
        alignMargin(30,MAX_SPACES_INFO_WINDOW);
    }

}

void drawLaptopDaysRequested(int daysRequested)
{
    if (daysRequested > 0)
    {
        int daysDigits;

        getNumOfDigits(&daysDigits,daysRequested);
        printf("        | Este postatil foi requisitado  |\n");
        printf("        | ao todo por %d dias.",daysRequested);
        alignMargin(daysDigits+18,MAX_SPACES_INFO_WINDOW);
    }
}

void drawRequestDurationInfoWindow(int duration)
{
    int durationDigits;
    getNumOfDigits(&durationDigits,duration);
    printf("        | Prazo da Requisicao: %d dias",duration);
    alignMargin(26+durationDigits,MAX_SPACES_INFO_WINDOW);
}

void drawLaptopsNotFound(void)
{
    printf("         __________________________________\n");
    printf("        |_PORTATEIS____________________(X)_|\n");
    printf("        |                                  |\n");
    printf("        | Nao existem portateis no sistema |\n");
    printf("        |__________________________________|\n\n");

}

void drawLaptopsUnavailable(void)
{

    printf("         ___________________________________\n");
    printf("        |_PORTATEIS_____________________(X)_|\n");
    printf("        |                                   |\n");
    printf("        | Nao existem portateis disponiveis |\n");
    printf("        | no sistema.                       |\n");
    printf("        |___________________________________|\n\n");

}

void drawDamageDateMustBeHigherThanPurchaseDate(DateType date)
{
    printf("         ___________________________\n");
    printf("        | A data da avaria nao pode |\n");
    printf("        | ser inferior a data       |\n");
    printf("        | de compra do portatil.    |\n");
    printf("        | O portatil em questao foi |\n");
    printf("        |_comprado dia ");
    showDate(date);
    printf("___|\n\n");
}

void drawDamageDateMustBeHigherThanLastDate(DateType date)
{
    printf("         __________________________\n");
    printf("        | A data da avaria         |\n");
    printf("        | permanete deve ser       |\n");
    printf("        | superior a data da       |\n");
    printf("        | ultima avaria temporaria |\n");
    printf("        | deste componente.        |\n");
    printf("        | A ultima avaria deste    |\n");
    printf("        | componte foi registada   |\n");
    printf("        |_no dia ");
    showDate(date);
    printf("________|\n\n");
}

void drawReturnDelayFeeAlert(int delayFee)
{

    printf("         __________________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES_______________(X)_|\n");
    printf("        |                                          |\n");

    if(delayFee > 0)
    {
    int delayFeeDigits;

    getNumOfDigits(&delayFeeDigits,delayFee);


    printf("        | Sera cobrada uma multa de %d euros",delayFee);
    alignMargin(delayFeeDigits,8);
    printf("        | devido aos %d dias de atraso.",(delayFee/10));
    alignMargin(delayFeeDigits-1,13);

    }
    else
    {

    printf("        | Nao sera cobrada nenhuma multa pois o    |\n");
    printf("        | portatil foi devolvido dentro do prazo   |\n");

    }

    printf("        |__________________________________________|\n\n");


}

void drawReturnSubMenuInDamageMenu(void)
{
    printf("         ___________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES________(X)_|\n");
    printf("        |                                   |\n");
    printf("        | Este portatil esta requisitado.   |\n");
    printf("        | Para registar uma ou mais avarias |\n");
    printf("        | e necessario devolve-lo antes.    |\n");
    printf("        | Selecione uma opcao:              |\n");
    printf("        | 1 - Devolver portatil             |\n");
    printf("        | 2 - Cancelar                      |\n");
    printf("        |___________________________________|\n\n");

}

void drawReturnInfoAsk(int index, int numOfReturns)
{
    int indexDigits, numOfReturnsDigits;

    getNumOfDigits(&indexDigits,index);
    getNumOfDigits(&numOfReturnsDigits,numOfReturns);

    printf("         ___________________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES________________(X)_|\n");
    printf("        |                                           |\n");
    printf("        | Preencha os campos de acordo com o que e  |\n");
    printf("        | pedido.                                   |\n");
    printf("        | Estas a registar a devolucao %d de %d.", index+1, numOfReturns);
    alignMargin(indexDigits+numOfReturnsDigits,7);
    printf("        | Digite 0 em qualquer campo para cancelar. |\n");
    printf("        |___________________________________________|\n\n");

}

void drawRenewInfoAsk(int index, int numOfRenews)
{
    int indexDigits, numOfRenewsDigits;

    getNumOfDigits(&indexDigits,index);
    getNumOfDigits(&numOfRenewsDigits,numOfRenews);

    printf("         ___________________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES________________(X)_|\n");
    printf("        |                                           |\n");
    printf("        | Preencha os campos de acordo com o que e  |\n");
    printf("        | pedido.                                   |\n");
    printf("        | Estas a registar a renovacao %d de %d.", index+1, numOfRenews);
    alignMargin(indexDigits+numOfRenewsDigits,7);
    printf("        | Digite 0 em qualquer campo para cancelar. |\n");
    printf("        |___________________________________________|\n\n");
}

void drawActiveRequestsNotFound(void)
{
    printf("         ________________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES_____(X)_|\n");
    printf("        |                                |\n");
    printf("        | Nao existem requisicoes ativas |\n");
    printf("        | no sistema.                    |\n");
    printf("        |________________________________|\n\n");
}

void drawAllRepairSucessful(void)
{
    printf("         _________________________\n");
    printf("        |_PORTATEIS___________(X)_|\n");
    printf("        |                         |\n");
    printf("        | Todas as avarias foram  |\n");
    printf("        | arranjadas com sucesso. |\n");
    printf("        |_________________________|\n\n");

}

void drawAllReturnSucessful(void)
{
    printf("         ____________________________\n");
    printf("        |_REQUISICOES/DEVOLUCOES_(X)_|\n");
    printf("        |                            |\n");
    printf("        | Todas as devolucoes foram  |\n");
    printf("        | registadas com sucesso.    |\n");
    printf("        |____________________________|\n\n");
}

void drawLaptopSelectedInfo(int laptopIndex, LaptopType laptop[MAX_LAPTOPS])
{
    int idDigits;
    char extraText[19] = "Nome do Portatil: ";

    getNumOfDigits(&idDigits,laptop[laptopIndex].id);

    printf("         ________________________________\n");
    printf("        | ->Selecionado Portatil ID#%d",laptop[laptopIndex].id);
    alignMargin(idDigits+26,MAX_SPACES_INFO_WINDOW);
    drawNameInfoWindow("        ",extraText,laptop[laptopIndex].name);
    drawLaptopProcessorInfoWindow(laptop[laptopIndex].processor);
    printf("        |_Memoria RAM: %3d_______________|\n\n",laptop[laptopIndex].ram);
}

void drawLaptopIdToMove(void)
{

    printf("         _____________________________\n");
    printf("        |_PORTATEIS_______________(X)_|\n");
    printf("        |                             |\n");
    printf("        | Digite o id do portatil que |\n");
    printf("        | pretendes mover.            |\n");
    printf("        | Digite 0 para cancelar.     |\n");
    printf("        |_____________________________|\n\n");

}

void drawLaptopIdDamageAsk(void)
{
    printf("         _______________________________________\n");
    printf("        |_PORTATEIS_________________________(X)_|\n");
    printf("        |                                       |\n");
    printf("        | Digite o id do portatil que pretendes |\n");
    printf("        | registar a avaria/reparacao.          |\n");
    printf("        | Digite 0 para cancelar.               |\n");
    printf("        |_______________________________________|\n\n");
}

void drawLaptopDamagesSubMenu(int laptopId)
{
    int idDigits;

    getNumOfDigits(&idDigits,laptopId);

    printf("         ____________________\n");
    printf("        |_PORTATEIS______(X)_|\n");
    printf("        |                    |\n");
    printf("        | Selecionado:       |\n");
    printf("        | ->Portatil ID#%d",laptopId);
    alignMargin(idDigits,4);
    printf("        |                    |\n");
    printf("        | Pretende registar: |\n");
    printf("        | 1 - Avaria         |\n");
    printf("        | 2 - Reparacao      |\n");
    printf("        | 3 - Cancelar       |\n");
    printf("        |____________________|\n\n");

}

void drawDamagensNoneActive(int laptopId)
{
    int idDigits;

    getNumOfDigits(&idDigits,laptopId);
    printf("         _________________________________________\n");
    printf("        |_PORTATEIS___________________________(X)_|\n");
    printf("        |                                         |\n");
    printf("        | Selecionado: ->Portatil ID#%d",laptopId);
    alignMargin(idDigits,12);
    printf("        |                                         |\n");
    printf("        | O portatil nao tem avarias por reparar, |\n");
    printf("        | so e possivel registar avarias.         |\n");
    printf("        | Digite 0 para cancelar.                 |\n");
    printf("        |_________________________________________|\n\n");

}

void drawDamageCancelMaxPermanent(void)
{
    printf("         ___________________________________________________\n");
    printf("        |_PORTATEIS_____________________________________(X)_|\n");
    printf("        |                                                   |\n");
    printf("        | A(s) avaria(s) anterior(es) foi(ram) registada(s) |\n");
    printf("        | com sucesso. A operacao foi cancelada pois ja foi |\n");
    printf("        | atingido o limite maxido de avarias possivel.     |\n");
    printf("        |___________________________________________________|\n\n");
}

void drawDamagesMaxPermanent(void)
{
    printf("         ______________________________________________\n");
    printf("        |_PORTATEIS________________________________(X)_|\n");
    printf("        |                                              |\n");
    printf("        | O portatil ja atingiu o maximo de avarias    |\n");
    printf("        | possivel, so e possivel registar reparacoes. |\n");
    printf("        |______________________________________________|\n\n");
}

void drawConfirmExit(void)
{
    printf("         _______________________________\n");
    printf("        |_SAIR______________________(X)_|\n");
    printf("        |                               |\n");
    printf("        | Tem certeza que deseja sair?  |\n");
    printf("        | 1 - Nao                       |\n");
    printf("        | 2 - Sim                       |\n");
    printf("        |_______________________________|\n\n");

}

void drawPercentageBar(float percentage)
{
    int index;

    printf("[");
    for(index=0; index<((int)percentage/5); index++)
    {
        printf("#");
    }
    for(index=0; index<20-((int)percentage/5); index++)
    {
        printf("-");
    }
    printf("] %.2f%%",percentage);
}

void centerTittle(char *extraText, char *tittle, int windowSize)
{
    int index, freeSpace, tittleSize, extraTextSize;

    tittleSize = strlen(tittle);
    extraTextSize = strlen(extraText);

    freeSpace = windowSize - tittleSize - extraTextSize;


    printf("(");
    for(index=0; index<=(freeSpace/2); index++)
    {
        printf("_");
    }
    printf("%s%s",extraText,tittle);
    for(index=0; index<=(freeSpace/2); index++)
    {
        printf("_");
    }

    if (freeSpace%2 == 0)
    {
        printf(")\n");
    }
    else
    {
        printf("_)\n");
    }
}

void alignMargin(int contentSize, int totalSpaces)
{

    int index;

    for(index = 0; index<totalSpaces-contentSize+1; index++)
    {
        printf(" ");
    }
    printf("|\n");

}

void enterToContinue(char *margin)
{
    printf("%sPressione ENTER para continuar...",margin);

    if (getchar() != '\n') //Impede que comece o menu com um erro de "Valor Inválido!"
    {
        flushStdin();
    }

}
