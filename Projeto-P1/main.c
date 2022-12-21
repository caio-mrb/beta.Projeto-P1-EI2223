#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "funcoesDePortateis.h"
#include "funcoesDeRequisicoes.h"
#include "funcoesDeDados.h"
#include "funcoesDeDesign.h"
#include "constantes.h"


int main()
{
    //Cria e inicializa a 0 um vetor estatico com MAX_LAPTOPS posições
    //Constante MAX_LAPTOPS = 30
    LaptopType laptop[MAX_LAPTOPS] = {0};

    //Cria e inicializa a NULL um vetor dinamico
    RequestType *request = NULL;

    //Cria e inicializa a 0 quatro variaveis.
    //totalLaptops: Representa todos os portateis inseridos no sistema
    //availableLaptops: Representa todos os portateis disponíveis para serem requisitados
    //totalRequests: Representa todas as requisições efetuadas no sistema
    //activeRequests: Representa todas as requisições ativas
    int totalLaptops = 0, availableLaptops, totalRequests = 10, activeRequests = 0;

    //Aloca na memoria memoria no vetor dinamico
    request = malloc(totalRequests*sizeof(RequestType));

    //Desenha o titulo do projeto
    drawTittle();

    //Cria um ficheiro para verificar se o programa já foi executado alguma vez no computador do utilizador
    FILE *check;

    //Verifica se consegue abrir o ficheiro "info.dat"
    check = fopen("info.dat","rb");

    //Se não conseguir conclui que é a primeira vez que o utilizador abre o programa
    if (check == NULL)
    {
        //Desenha a mensagem de bem-vindo
        drawWelcome();
    }
    //Se conseguir conclui que não é a primeira vez que o utilizador abre o programa
    else
    {

        //Desenha a mensagem de bem-vindo de volta
        drawWelcomeBack();

        //Carrega a informação do ficheiro para os respetivos ficheiros
        request = loadFileToInfo(laptop,&totalLaptops,request,&totalRequests);

        //Fecha o arquivo que foi previamente aberto
        fclose(check);
    }

    //Aguarda o input do utilizador para dar seguimento ao programa
    enterToContinue();


    int optMainMenu,optLapMenu, optDamageMenu,numOfLaptops,optReqMenu,optStatsMenu,optExtMenu,index,equalIndex,lastLocation,readedID = 0, optRepairMenu, idDigits;

    DamageType damageInfo;

    int *damagesIndex, numOfDamages, sizeDamageIndex = 0;

    int cancel = FALSE_0;

    char message[MAX_READ_MESSAGE_SIZE] = "Selecione uma opcao";

    numAvailableLaptops(&availableLaptops,laptop,totalLaptops);
    numActiveRequests(&activeRequests,request,totalRequests);

    do
    {
        //Limpa a tela
        clearScreen();

        //Desenha o menu principal
        drawMainMenu(totalLaptops,availableLaptops,totalRequests,activeRequests);

        //Pede uma opção (int) ao utilizador
        strcpy(message,"Selecione uma opcao");
        readInt(message,&optMainMenu,1,4);

        //Executa alguma ação de acordo com a escolha do utilizador
        //Opção 1: Menu dos portateis com 4 submenus
        //Opção 2: Menu das requisições/devoluções com X submenus
        //Opção 3: Menu das estatísticas com X submenus
        //Opção 4: Menu para confirmar a escolha de sair

        //----------------------------------------------COMEÇO MENU PRINCIPAL----------------------------------------------
        switch (optMainMenu)
        {
        case 1:
            /************************************************COMEÇO OPÇÃO PORTATEIS******************************************************/
            do
            {
                //Limpa a tela
                clearScreen();

                //Desenha o menu dos portateis
                drawLaptopMenu();

                //Altera o texto da mensagem para fazer sentido ao utilizador
                strcpy(message,"Selecione uma opcao");
                //Pede uma opção (int) ao utilizador
                readInt(message,&optLapMenu,1,5);

                //Executa alguma ação de acordo com a escolha do utilizador
                //Opção 1: Adicionar portateis
                //Opção 2: Listar informações dos portateis
                //Opção 3: Menu das estatísticas com X submenus


                //----------------------------------------------COMEÇO MENU DE PORTATEIS----------------------------------------------
                switch (optLapMenu)
                {
                case 1:
                    /************************************************COMEÇO OPÇÃO 1******************************************************/

                    /** Nesta opção o utilizador pode:                   **
                      * ->Escolher a quantidade de portateis a adicionar *
                      * ->Cancelar a adição durante o processo           *
                      *                                                  *
                      * Nesta opção o utilizador não pode:               *
                      * ->Adicionar mais que MAX_LAPTOPS portateis       *
                      * Constante MAX_LAPTOPS = 30                       **/

                    //Limpa a tela
                    clearScreen();

                    //Verifica se já foi atingido o limite de portateis existentes
                    if (totalLaptops == MAX_LAPTOPS)
                    {
                        //Desenha o alerta de limite de portateis atingido
                        drawMaxLaptopsReachAlert();

                        printf("         ");
                        enterToContinue();
                    }
                    //Executa se for possível adicionar um novo portatil
                    else
                    {
                        //Limpa a tela
                        clearScreen();

                        //Desenha a mensagem de adição de portatil
                        /*Mais informações em "funçõesDeDesign.h"*/
                        drawAddLaptop(totalLaptops);

                        //Altera a mensagem da string para fazer sentido ao utilizador
                        strcpy(message,"Digite quantos portateis deseja adicionar");

                        //Le um numero (int) introduzido pelo utilizador e armazena no segundo parametro
                        /*Mais informações em "funçõesDeDados.h"*/
                        readInt(message,&numOfLaptops,0,(MAX_LAPTOPS - totalLaptops));

                        //Verifica se o ID introduzido pelo utilizador é maior que 0
                        if (numOfLaptops > 0)
                        {
                            //Define a variavel como falso
                            cancel = FALSE_0;

                            //Repete o ciclo o numero de vezes que o utilizador inseriu
                            for (index = 0; index<numOfLaptops; index++)
                            {
                                //Limpa a tela
                                clearScreen();

                                //Desenha o pedido de informações
                                drawLaptopInfoAsk(index,numOfLaptops);

                                //Lê o ID do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
                                /*Mais informações em "funcoesDePortateis.h*/
                                readLapId(laptop,totalLaptops,&cancel);

                                //Lê a designação do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
                                /*Mais informações em "funcoesDePortateis.h*/
                                readLapName(laptop,totalLaptops,&cancel);

                                //Lê o processador do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
                                /*Mais informações em "funcoesDePortateis.h*/
                                readLapProcessor(laptop,totalLaptops,&cancel);

                                //Lê a quantidade de memoria RAM do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
                                /*Mais informações em "funcoesDePortateis.h*/
                                readLapRam(laptop,totalLaptops,&cancel);

                                //Lê o preço do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
                                /*Mais informações em "funcoesDePortateis.h*/
                                readLapPrice(laptop,totalLaptops,&cancel);

                                //Lê a data de compra do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
                                /*Mais informações em "funcoesDePortateis.h*/
                                readLapPurchaseDate(laptop,totalLaptops,&cancel);

                                //Executa se o pedido de adição não tiver sido cancelado
                                if (cancel == FALSE_0)
                                {
                                    //Desenha a lista de localizações possíveis para o portatil
                                    drawLocationsMiniList();
                                }

                                //Lê a localização do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
                                /*Mais informações em "funcoesDePortateis.h*/
                                readLapLocation(laptop,totalLaptops,&cancel);

                                //Executa se o pedido de adição não tiver sido cancelado
                                if (cancel == FALSE_0)
                                {
                                    //Define o estado do portatil a ser adicionado como disponível
                                    laptop[totalLaptops].state = AVAILABLE;
                                    //Acrescenta um aos portateis disponiveis
                                    availableLaptops++;
                                    //Acrescenta um ao total de portateis
                                    totalLaptops++;
                                    //Guarda a informação do portatil adicionado no ficheiro "info.dat"
                                    storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                }

                                //Executa se o pedido de adição tiver sido cancelado
                                if (cancel == TRUE_1)
                                {
                                    //Iguala o número de portateis ao índice para quebrar o ciclo e cancelar a adição de novos portateis
                                    numOfLaptops = index;
                                }
                            }

                            //Executa se o pedido de adição tiver sido cancelado e o numero
                            //de portateis a serem adicionados for maior que 0
                            if (cancel == TRUE_1 && numOfLaptops > 0)
                            {
                                //Desenha o aviso que apenas alguns portateis foram adicionados
                                drawAddLaptopCancel(numOfLaptops);

                                //Desenha a margem a esquerda
                                printf("        ");

                                //Aguarda o input do utilizador para dar seguimento ao programa
                                enterToContinue();
                            }
                        }
                    }
                    /************************************************FIM OPÇÃO 1******************************************************/
                    break;
                case 2:
                    /**********************************************COMEÇO OPÇÃO 2*****************************************************/

                    /** Nesta opção o utilizador pode:                         *
                      * ->Listar a informação de todos os portateis existentes **/


                    clearScreen();
                    if (totalLaptops > 0)
                    {
                        //Mostra a informação de todos os portateis existentes
                        showLaptopInfo(laptop,totalLaptops);
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();
                    }
                    else
                    {
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();
                    }
                    /************************************************FIM OPÇÃO 2*****************************************************/
                    break;
                case 3:
                    /**********************************************COMEÇO OPÇÃO 3*****************************************************/

                    /** Nesta opção o utilizador pode:                              *
                      * ->Alterar a localização de um portatil existente            *
                      *                                                             *
                      * Nesta opção o utilizador não pode:                          *
                      * ->Mover o portatil para a localização em que já se encontra **/

                    //Limpa a tela
                    clearScreen();

                    //Executa se existirem portateis no sistema
                    if (totalLaptops > 0)
                    {
                        //Desenha a mensagem de pedir um id para mover o portatil
                        drawLaptopIdToMove();

                        //Muda o texto da mensagem para fazer sentido ao utilizador
                        strcpy(message,"ID do Portatil");

                        //-----Do{}While-----
                        //Executa o conjuto de instruções
                        //a seguir enquanto o utilizador
                        //inserir um ID inexistente
                        //(equalIndex == -1) e enquanto
                        //não pedir para cancelar
                        //(readedID != 0)
                        do
                        {
                            //Redefine a variavel para falso
                            cancel = FALSE_0;

                            //Lê um inteiro inserido pelo utilizador até MAX_ID
                            //Constante MAX_ID = 9999
                            readInt(message,&readedID,0,MAX_ID);

                            //Executa se o utilizador não cancelar a ação
                            if(readedID > 0)
                            {
                                //Procura um portatil com um id igual ao pedido pelo utilizador e guarda no primeiro parâmetro, caso contrário devolve -1
                                /*Mais informações em "funcoesDePortateis.h*/
                                searchEqualLapId(&equalIndex,laptop,totalLaptops,readedID);

                                //Executa se encontrar um portatil com o ID inserido pelo utliziador
                                if (equalIndex > -1)
                                {
                                    //Armazena em uma variavel a localização (int) atual do portatil
                                    lastLocation = laptop[equalIndex].location;

                                    //Desenha a lista de localizações possíveis
                                    drawLocationsBigList();

                                    //-----Do{}While-----
                                    //Executa o conjuto de instruções
                                    //a seguir enquanto o utilizador
                                    //pedir para mudar o portatil para
                                    //a posição em que já se encontra
                                    //(lastLocation == laptop[equalIndex].location)
                                    //e enquanto não pedir para cancelar
                                    //(cancel == FALSE_0)
                                    do
                                    {
                                        //Lê a localização do portatil e sobrepõe a localização anterior
                                        readLapLocation(laptop,equalIndex,&cancel);

                                        //Executa se o utilizador mover o portatil para a localização em que já se encontra e se não pedir pra cancelar
                                        if (lastLocation == laptop[equalIndex].location && cancel == FALSE_0)
                                        {
                                            //Informa o utilizador que está a tentar mover para o posição que o portatil já está
                                            printf("        O portatil ja esta nesta localizacao!\n");
                                        }

                                        //Executa se o utilizador mover o portatil para uma localização diferente da que já se encontra e se não pedir pra cancelar
                                        if (lastLocation != laptop[equalIndex].location && cancel == FALSE_0)
                                        {
                                            //Informa o utilizador que a localização do portatil foi alterada com sucesso
                                            printf("        Localizacao alterada com sucesso!\n\n");
                                            //Armazena a informação alterada no ficheiro "info.dat"
                                            /*Mais informações em "funcoesDeDados.h"*/
                                            storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                            //Desenha a margem a esquerda
                                            printf("        ");
                                            //Aguarda o input do utilizador para dar seguimento ao programa
                                            enterToContinue();
                                        }
                                    }
                                    while (lastLocation == laptop[equalIndex].location && cancel == FALSE_0);
                                }
                            }
                            //Executa se não encontrar um portatil com o ID inserido pelo utilizador
                            if (equalIndex == -1)
                            {
                                //Informa o utilizador que não foi encontrado um portatil com o ID inserido
                                printf("        Nao existe um portatil com este ID!\n");
                            }

                        }
                        while(equalIndex == -1 && readedID != 0);
                    }
                    else
                    {
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();
                    }
                    /************************************************FIM OPÇÃO 3*****************************************************/
                    break;
                case 4:
                    /**********************************************COMEÇO OPÇÃO 4*****************************************************/
                    /** Nesta opção o utilizador pode:                                                       *
                      * ->Registar X avarias de um portatil                                                  *
                      * ->Registar o reparo de todas as avarias temporarias ainda por reparar de um portatil *
                      *                                                                                      *
                      * Nesta opção o utilizador não pode:                                                   *
                      * ->Escolher reparar um portatil se não possuir avarias por reparar                    **/

                    //Limpa a tela
                    clearScreen();

                    //Executa se houverem portateis no sistema
                    if (totalLaptops > 0)
                    {
                        //Desenha o pedido de ID ao utilizador referente ao portatil para registar avaria/reparação
                        drawLaptopIdDamageAsk();

                        //Muda o texto da mensagem para fazer sentido ao utilizador
                        strcpy(message,"ID do Portatil");

                        //-----Do{}While-----
                        //Executa o conjunto de instruções
                        //a seguir enquanto o utilizador não
                        //pedir para cancelar (readedID != 0)
                        do
                        {
                            //Redefine o valor da variavel para falso
                            cancel = FALSE_0;

                            //Lê um inteiro inserido pelo utilizador até MAX_ID
                            //Constante MAX_ID = 9999
                            readInt(message,&readedID,0,MAX_ID);

                            //Execita se o utilizador não pedir para cancelar
                            if(readedID > 0)
                            {
                                //Procura um portatil com um id igual ao pedido pelo utilizador e guarda no primeiro parâmetro, caso contrário devolve -1
                                /*Mais informações em "funcoesDePortateis.h*/
                                searchEqualLapId(&equalIndex,laptop,totalLaptops,readedID);

                                //Executa se encontrar um portatil com o id inserido pelo utilizador
                                if (equalIndex > -1)
                                {
                                    //Executa se o portatil não possuir avarias registadas
                                    if(laptop[equalIndex].damagesCounterTotal == 0)
                                    {
                                        //Inicializa o vetor dinamico da lista de avarias do respetivo portatil a NULL
                                        laptop[equalIndex].damagesList = NULL;
                                    }

                                    //-----Do{}While-----
                                    //Executa o conjunto de instruções
                                    //a seguir enquanto o utilizador não
                                    //pedir para cancelar (readedID != 0)

                                    do
                                    {


                                        //Executa se o portatil selecionado pelo utilizador possuir avarias ativas
                                        if (laptop[equalIndex].damagesCounterActive != 0)
                                        {
                                            //Limpa a tela
                                            clearScreen();

                                            //Desenha o menu de avarias/reparações
                                            drawLaptopDamagesSubMenu(laptop[equalIndex].id);

                                            //Altera o texto da mensagem para fazer sentido ao utilizador
                                            strcpy(message,"Selecione uma opcao");
                                            //Lê uma opção (int) do menu de avarias/reparações
                                            readInt(message,&optDamageMenu,1,3);

                                        }
                                        //Executa se o portatil selecionado pelo utilizador não possuir avarias ativas o que implica só poder registar avarias
                                        //e não reparações, ou seja, sem avarias é impossível registar reparações.
                                        else
                                        {
                                            //Define a variavel como 1 (Registar Avaria)
                                            optDamageMenu = 1;
                                        }

                                        //--------------------------------------COMEÇO SUBMENU DE AVARIAS/REPARAÇÕES------------------------------------------
                                        switch(optDamageMenu)
                                        {
                                        case 1:
                                            /*******************************************COMEÇO OPÇÃO 1************************************************/
                                            /** Nesta opção o utilizador pode:      *
                                              * ->Registar X avarias de um portatil *
                                              *                                     *
                                              * Nesta opção o utilizador não pode:  *
                                              * ->Alterar o poratil já selecionado  **/

                                            //Executa se o portatil não possuir avarias por arranjar
                                            if(laptop[equalIndex].damagesCounterActive == 0)
                                            {
                                                //Limpa a tela
                                                clearScreen();

                                                //Desenha o alerta que o portatil selecionado pelo utilizador não possui avarias por arranjar
                                                //e só é possivel registar novas avarias
                                                drawDamagensNoneActive(laptop[equalIndex].id);

                                                //Redefine o valor da variavel para falso
                                                cancel = FALSE_0;
                                            }

                                            //Altera o texto da mensagem para fazer sentido ao utilizador
                                            strcpy(message,"Digite quantas avarias desejas registar");

                                            //Lê a quantidade de avarias (int) que o utilizador deseja registar
                                            readInt(message,&numOfDamages,0,9999);

                                            //Executa se o utilizador não pedir para cancelar
                                            if (numOfDamages > 0)
                                            {
                                                //Repete o ciclo o numero de vezes que o utilizador inseriu
                                                for (index = 0; index<numOfDamages; index++)
                                                {
                                                    //Limpa a tela
                                                    clearScreen();

                                                    //Lê o local/código da avaria se o registo de avaria não tiver sido cancelado
                                                    /*Mais informações em "funcoesDePortateis.h*/
                                                    readDamageInfoCode(index,numOfDamages,&damageInfo, &cancel);

                                                    //Lê o tipo da avaria se o registo de avaria não tiver sido cancelado
                                                    /*Mais informações em "funcoesDePortateis.h*/
                                                    readDamageInfoType(index,numOfDamages,&damageInfo, &cancel);

                                                    //Lê a data da avaria se o registo de avaria não tiver sido cancelado
                                                    /*Mais informações em "funcoesDePortateis.h*/
                                                    readDamageInfoDate(index,numOfDamages,&damageInfo, &cancel);

                                                    //Armazena na lista de avarias do portatil se o registo de avaria não tiver sido cancelado
                                                    /*Mais informações em "funcoesDePortateis.h*/
                                                    laptop[equalIndex].damagesList = addDamageRepairInfo(damageInfo, laptop, equalIndex, &cancel);

                                                    //Executa se o registo de avaria não tiver sido cancelado
                                                    if(cancel == FALSE_0)
                                                    {
                                                        //Armazena no ficheiro as atualizações do portatil
                                                        storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                                    }

                                                    ////Executa se o registo de avaria tiver sido cancelado
                                                    if (cancel == TRUE_1)
                                                    {
                                                        //Iguala o número de avarias ao índice para quebrar o ciclo e cancelar o registo de novas avarias
                                                        numOfDamages = index;
                                                    }
                                                }

                                                //Executa se o pedido de registo de avaria tiver sido cancelado
                                                //e o numero de avarias a serem registadas for maior que 0
                                                if (cancel == TRUE_1 && numOfDamages > 0)
                                                {

                                                    //Desenha o aviso que apenas algumas avarias foram registadas
                                                    drawDamageCancel(numOfDamages);

                                                    //Desenha a margem a esquerda
                                                    printf("        ");
                                                    //Aguarda o input do utilizador para dar seguimento ao programa
                                                    enterToContinue();
                                                }
                                            }
                                            //Executa se o utilizador pedir para cancelar
                                            else
                                            {
                                                //Redefine o valor da variavel para verdadeiro
                                                cancel = TRUE_1;
                                            }
                                            /********************************************FIM OPÇÃO 1************************************************/
                                            break;
                                        case 2:
                                            /*******************************************COMEÇO OPÇÃO 2***********************************************/
                                            /** Nesta opção o utilizador pode:                       *
                                              * ->Registar o reparo de todas as avarias por arranjar *
                                              *                                                      *
                                              * Nesta opção o utilizador não pode:                   *
                                              * ->Alterar o poratil já selecionado                   **/
                                            do
                                            {
                                                //Encontra e armazena no vetor dinamico o indice de cada avaria
                                                //temporaria pertencente a lista de avarias do respetivo portatil.
                                                /*Mais informações em "funcoesDePortateis.c*/
                                                damagesIndex = searchTemporaryDamagesIndex(&sizeDamageIndex,laptop,equalIndex);
                                                //Executa se encontrar avarias temporárias por arranjar
                                                if (sizeDamageIndex>0)
                                                {
                                                    //Desenha a lista de avarias do respetivo portatil
                                                    drawRepairList(laptop,equalIndex,damagesIndex,sizeDamageIndex);

                                                    //Altera o texto da mensagem para fazer sentido ao utilizador
                                                    strcpy(message,"Selecione uma opcao");
                                                    //Lê a opção (int) da avaria para registar o arranjo
                                                    readInt(message,&optRepairMenu,1,sizeDamageIndex+1);

                                                    //Executa se o utilizador não pedir para cancelar
                                                    if (optRepairMenu != sizeDamageIndex+1)
                                                    {
                                                        //Altera o texto da mensagem para fazer sentido ao utilizador
                                                        strcpy(message,"Digite quantos dias o portatil esteve avariado");
                                                        //Lê e guarda o tempo (int) em dias até ser reparado
                                                        readInt(message,&laptop[equalIndex].damagesList[damagesIndex[optRepairMenu-1]].duration,0,MAX_DAMAGE_DAYS);
                                                        //Altera o estado da avaria para concluida
                                                        laptop[equalIndex].damagesList[damagesIndex[optRepairMenu-1]].state = COMPLETED;
                                                        //Remove 1 a quantidade de avarias ativas
                                                        laptop[equalIndex].damagesCounterActive--;
                                                        //Armazena no ficheiro as atualizações do portatil
                                                        storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                                        //Remove a avaria acabada de arranjar da lista de avarias temporárias
                                                        damagesIndex = removeTemporaryDamage(damagesIndex,sizeDamageIndex,sizeDamageIndex);
                                                        //Executa se não houverem mais avarias por reparar
                                                        if(sizeDamageIndex == 0)
                                                        {
                                                            //Iguala a opção do menu de reparação ao número que cancela no menu para quebrar o ciclo
                                                            optRepairMenu = sizeDamageIndex+1;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    //Iguala a opção do menu de reparação ao número que cancela no menu para quebrar o ciclo
                                                    optRepairMenu = sizeDamageIndex+1;
                                                    //Redefine a variavel para verdadeiro para quebrar o outro ciclo e voltar ao menu dos portateis
                                                    cancel = TRUE_1;
                                                }


                                            }
                                            while(optRepairMenu != sizeDamageIndex+1);
                                            /********************************************FIM OPÇÃO 2************************************************/
                                            break;
                                        case 3:
                                            /*******************************************COMEÇO OPÇÃO 3***********************************************/
                                            cancel = TRUE_1;
                                            /********************************************FIM OPÇÃO 3************************************************/
                                            break;
                                        }
                                    }
                                    while (cancel == FALSE_0);
                                }
                                //Executa se não encontrar um portatil com o ID inserido pelo utilizador
                                if (equalIndex == -1)
                                {
                                    printf("        Nao existe um portatil com este ID!\n");
                                }
                            }
                        }
                        while (readedID != 0 && cancel == FALSE_0);

                        /************************************************FIM OPÇÃO 4*****************************************************/
                        break;
                    }
                    else
                    {
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();

                    }
                }
                //---------------------------------------------------FIM MENU DE PORTATEIS----------------------------------------------
            }
            while (optLapMenu != 5);
            /************************************************FIM OPÇÃO PORTATEIS******************************************************/
            break;
        case 2:
            /****************************************COMEÇO OPÇÃO REQUISIÇÕES/DEVOLUÇÕES**********************************************/
            printf("Caso 2\n");
            /******************************************FIM OPÇÃO REQUISIÇÕES/DEVOLUÇÕES***********************************************/
            break;
        case 3:
            /*********************************************COMEÇO OPÇÃO ESTATISTICAS***************************************************/
            printf("Caso 3\n");
            /***********************************************FIM OPÇÃO ESTATISTICAS****************************************************/
            //infoLaptop();
            break;
        case 4:
            /*********************************************COMEÇO CONFIRMAÇÃO DE SAIDA*************************************************/
            //Limpa a tela
            clearScreen();

            //Desenha o alerta de confirmação de saída
            drawConfirmExit();

            //Altera o texto da mensagem para fazer sentido ao utilizador
            strcpy(message,"Selecione uma opcao");
            //Lê uma opção (int) inserida pelo utilizador
            readInt(message,&optExtMenu,1,2);
            /***********************************************FIM CONFIRMAÇÃO DE SAIDA***************************************************/
            break;
        }
        //--------------------------------------------------FIM MENU PRINCIPAL----------------------------------------------
    }
    while(optExtMenu != 2);
    //Liberta a memória do vertor dinamico
    free(request);
    return 0;
}


