#include "funcoesDeDesign.h"

#include <stdio.h>


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

    printf("                    _____ ___ ___ _ _\n");
    printf("                   |     | -_|   | | |\n");
    printf("                   |_|_|_|___|_|_|___|\n\n");
    printf("         ________________________________________\n");
    printf("        |                                        |\n");
    printf("        | Portateis existentes: %2d               |\n",totalLaptops);
    printf("        | Portateis disponiveis: %2d              |\n",availableLaptops);
    printf("        |                                        |\n");
    printf("        | Quantidade de requisicoes ativas: %4d |\n",activeRequests);
    printf("        | Quantidade total de requisicoes: %4d  |\n",totalRequests);
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

void drawMaxLaptopsReachAlert(void)
{
    printf("         ____________________________________\n");
    printf("        |_PORTATEIS______________________(X)_|\n");
    printf("        |                                    |\n");
    printf("        | Ja foi atingido o limite maximo de |\n");
    printf("        | portateis existentes.              |\n");
    printf("        |____________________________________|\n\n");

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

void drawLocationsMiniList(void)
{

    printf("         __________________\n");
    printf("        | RE - Residencias |\n");
    printf("        | C1 - Campus1     |\n");
    printf("        | C2 - Campus2     |\n");
    printf("        | C3 - Campus3     |\n");
    printf("        |_C5 - Campus5_____|\n");
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
    printf("         _________________________________________________\n");
    printf("        |_PORTATEIS___________________________________(X)_|\n");
    printf("        |                                                 |\n");
    printf("        | Foi(ram) adicionado(s) apenas %2d portatil(eis). |\n",numOfLaptops);
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

void drawRepairList(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *damagesIndexList, int sizeDamagesIndexList)
{
    int idDigits, index;

    clearScreen();
    getNumOfDigits(&idDigits,laptop[laptopIndex].id);

    printf("         __________________________________\n");
    printf("        |_PORTATEIS____________________(X)_|\n");
    printf("        |                                  |\n");
    printf("        | Selecionado: ->Portatil #ID%d",laptop[laptopIndex].id);
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

void drawLaptopsNotFound(void)
{
    printf("         __________________________________\n");
    printf("        |_PORTATEIS____________________(X)_|\n");
    printf("        |                                  |\n");
    printf("        | Nao existem portateis no sistema |\n");
    printf("        |__________________________________|\n\n");

}


void drawLaptopIdToMove(void)
{

    printf("         _____________________________\n");
    printf("        |_PORTATEIS_______________(X)_|\n");
    printf("        |                             |\n");
    printf("        | Digite o id do portatil que |\n");
    printf("        | pretendes mover.            |\n");
    printf("        | Digite 0 para cancelar      |\n");
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
    printf("        | Digite 0 para cancelar                  |\n");
    printf("        |_________________________________________|\n\n");

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

void alignMargin(int contentSize, int totalSpaces)
{

    int index;

    for(index = 0; index<totalSpaces-contentSize+1; index++)
    {
        printf(" ");
    }
    printf("|\n");

}


void enterToContinue(void)
{
    printf("Pressione ENTER para continuar...");

    if (getchar() != '\n') //Impede que comece o menu com um erro de "Valor Inválido!"
    {
        flushStdin();
    }

}
