#ifndef FUNCOESDEDESIGN_H
#define FUNCOESDEDESIGN_H

#include "funcoesDeDados.h"

/** Este ficheiro engloba todas as fun��es  *
  * relacionadas a design de alguma maneira *
  * desde o desenho das informa��es no ecr� *
  * at� o alinhamento das margens da janela *
  * --------------//------//--------------- *
  * Abaixo de cada fun��o h� uma explica��o *
  * sobre o seu funcionamento e no ficheiro *
  * .c h� a explica��o passo a passo.       */

//Titulo e Bem-Vindo

void drawTittle(void);
/**Func�o para desenhar o titulo do projeto no ecr�**/

void drawWelcome(void);
/**Func�o para desenhar a mensagem de bem-vindo no ecr�**/

void drawWelcomeBack(void);
/**Func�o para desenhar a mensagem de bem-vindo no ecr�**/

//Menus

void drawMainMenu(int totalLaptops, int availableLaptops, int activeRequests, int totalRequests);
/**Fun��o para desenhar o menu principal no ecr� com a informa��o de "total de portateis existentes",   *
  *"total de portateis disponeiveis", "total de requisi��es existentes" e "total de requisi��es ativas" *
  *Como usar:                                                                                           *
  *-> Criar 1 variavel para cada parametro, ao todo s�o 4                                               *
  *-> Adicionar uma fun��o de leitura para receber a informa��o do utilizador                           **/

void drawLaptopMenu(void);
/**Fun��o para desenhar o menu dos portateis no ecr�                          *
  *Como usar:                                                                 *
  *-> Adicionar uma fun��o de leitura para receber a informa��o do utilizador **/

void drawInfoMenu(void);
/**Fun��o para desenhar o menu das informa��es dos portateis no ecr�          *
  *Como usar:                                                                 *
  *-> Adicionar uma fun��o de leitura para receber a informa��o do utilizador **/

void drawLaptopDamagesSubMenu(int laptopId);
/**Fun��o para desenhar o menu das avarias/reapara��es no ecr�                *
  *Como usar:                                                                 *
  *-> Adicionar uma fun��o de leitura para receber a informa��o do utilizador **/

void drawRequestMenu(void);

void drawRequestReturnSubMenu(void);

void drawRequestRenewSubMenu(void);

void drawRequestShowInfoSubMenu(void);

void drawReturnSubMenuInDamageMenu(void);

void drawConfirmExit(void);
/**Fun��o para desenhar a confirma��o de sa�da no ecr�                        *
  *Como usar:                                                                 *
  *-> Adicionar uma fun��o de leitura para receber a informa��o do utilizador **/


//Fun��es de mostrar informa��es

void drawNameInfoWindow(char *margin, char *extraText, char *name);

void drawLaptopIdInfoWindow(int laptopId);
void drawLaptopStateInfoWindow(int laptopState);
void drawLaptopLocationInfoWindow(int laptopLocation);
void drawLaptopTotalDamagesInfoWindow(int damagesTotal);
void drawLaptopRamInfoWindow(int laptopRam);
void drawLaptopPurchaseDateInfoWindow(DateType purchaseDate);
void drawLaptopDamageTypeInfoWindow(int damageType);
void drawLaptopDamageDescInfoWindow(DamageType *damagesList,int indexDamage);
void drawLaptopProcessorInfoWindow(int laptopProcessor);
void drawLaptopPriceInfoWindow(float laptopPrice);
void drawLaptopTotalRequestsInfoWindow(int requestTotal);

void drawRequestDelayFeeInfoWindow(int delayFee);
void drawRequestTotalDurationInfoWindow(int durationTotal);
void drawRequestLocationInfoWindow(int returnLocation);
void drawRequestStateInfoWindow(int requestState);
void drawLaptopDaysRequested(int daysRequested);
void drawRequestLaptopIdInfoWindow(int laptopId);
void drawRequestApplicantTypeInfoWindow(int applicantType);
void drawRequestDurationInfoWindow(int duration);
void drawRequestDate(char *extraText,DateType date);


//Alertas

void drawMaxLaptopsReachAlert(void);
/**Fun��o para desenhar o aviso que o n�mero m�ximo de portateis existentes foi atingido**/

void drawMaxDamagesReachAlert(void);

void drawDamagesMaxPermanent(void);

void drawDamageCancelMaxPermanent(void);

void drawLaptopsNotFound(void);
/**Fun��o para desenhar o aviso que n�o foram encontrados portateis no sistema**/

void drawAllReturnSucessful(void);

void drawLaptopsUnavailable(void);

void drawAllRepairSucessful(void);

void drawActiveRequestsNotFound(void);

void drawReturnDelayFeeAlert(int delayFee);

void drawLaptopSelectedInfo(int laptopIndex, LaptopType laptop[MAX_LAPTOPS]);

void drawDamageDateMustBeHigherThanPurchaseDate(DateType date);

void drawDamageDateMustBeHigherThanLastDate(DateType date);

void drawRequestsNotFound(void);
/**Fun��o para desenhar o aviso que n�o foram encontradas requisi��es no sistema**/

void drawAddLaptopCancel(int numOfLaptops);
/**Fun��o para desenhar o aviso que o utilizador interrompeu a adi��o de novos portateis com                        *
  *a informa��o "total de portateis adicionados antes do cancelamento"                                              *
  *Como usar:                                                                                                       *
  *-> Criar uma vari�vel que armazene o numero de portateis adicionados a medida que o utilizador introduz os dados **/

void drawDamageCancel(int numOfDamages);
/**Fun��o para desenhar o aviso que o utilizador interrompeu a adi��o de novas avarias ao                         *
  *portatil com a informa��o "total de avarias adicionados antes do cancelamento"                                 *
  *Como usar:                                                                                                     *
  *-> Criar uma vari�vel que armazene o numero de avarias adicionados a medida que o utilizador introduz os dados **/

void drawRequestCancel(int numOfRequests);

void drawReturnCancel(int numOfReturns);

void drawRenewCancel(int numOfRenews);

void drawDamagensNoneActive(int laptopId);
/**Fun��o para desenhar o aviso que o utilizador interrompeu a adi��o de novas avarias ao                         *
  *portatil com a informa��o "total de avarias adicionados antes do cancelamento"                                 *
  *Como usar:                                                                                                     *
  *-> Criar uma vari�vel que armazene o numero de avarias adicionados a medida que o utilizador introduz os dados **/

//Solicita��es

void drawLaptopInfoAsk(int index, int totalLaptops);
/**Fun��o para desenhar a mensagem sobre pedir os dados do portatil a adicionar          *
  *com a informa��o "portatil atual a ser adicionado" e "total de portateis a adicionar" *
  *Como usar:                                                                            *
  *-> Criar um ciclo que re-execute a fun��o o numero de vezes inserido pelo utilizador  *
  *-> Armazenar a posi��o do ciclo em "portatil atual a ser adicionado"                  **/

void drawRequestInfoAsk(int index,int numOfRequests);

void drawReturnInfoAsk(int index, int numOfReturns);

void drawRenewInfoAsk(int index, int numOfRenews);

void drawRequestCodeToShowInfoAsk(void);


void drawLaptopIdToMove(void);
/**Fun��o para desenhar a mensagem sobre pedir os dados do portatil a adicionar          *
  *com a informa��o "portatil atual a ser adicionado" e "total de portateis a adicionar" *
  *Como usar:                                                                            *
  *-> Criar um ciclo que re-execute a fun��o o numero de vezes inserido pelo utilizador  *
  *-> Armazenar a posi��o do ciclo em "portatil atual a ser adicionado"                  **/

void drawLaptopIdDamageAsk(void);
/**Fun��o para desenhar a mensagem sobre pedir o id do portatil em que pretende registar a avaria**/

void drawAddLaptop(int totalLaptops);
/**Fun��o para desenhar a mensagem sobre pedir o n�mero de portateis a adicionar *
  *com a informa��o de "total de portateis j� adicionados"                       *
  *Como usar:                                                                    *
  *-> Adicionar uma fun��o de leitura para receber a informa��o do utilizador    **/

void drawLocationsMiniList(void);
/**Fun��o para desenhar a lista de localiza��es sem o efeito de janela**/

void drawLocationsBigList(void);
/**Fun��o para desenhar a lista de localiza��es com o efeito de janela**/

void drawRepairList(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *damagesIndexList, int sizeDamagesIndexList);
/**Fun��o para desenhar a lista de avarias por arranjar de um respetivo portatil        *
  *com a informa��o "data de cada avaria" e "local de cada avaria"                      *
  *Como usar:                                                                           *
  *-> Utilizar o vetor estatico de portateis                                            *
  *-> Utilizar o indice do portatil escolhido pelo utilizador                           *
  *-> Utilizar o vetor dinamico da lista de indices das avarias temporarias po portatil *
  *-> Utilizar o tamanho do vetor dinamico da lista de indices                          **/

//Design

void clearScreen(void);
/**Fun��o para limpar o ecr�**/

void enterToContinue(char *margin);
/**Fun��o para aguardar o input do utilizador antes de continuar com o par�metro de margem para alinhar**/

void drawPercentageBar(float percentage);

void centerTittle(char *extraText, char *tittle, int windowSize);

void alignMargin(int contentSize, int totalSpaces);
/**Fun��o para alinhar a margem da janela simulada de acordo com o conte�do a ser escrito                                                              *
  *                                                                                                                                                    *
  *Como usar:                                                                                                                                          *
  *-> Utilizar o tamanho de espa�os do conte�do a ser escrito                                                                                          *
  *(valor obtido ao somar o total de caracteres j� escritos com o n�mero de caracteres que t�m de ser escritos)                                        *
  *-> Utilizar o tamanho m�ximo que o conte�do pode ocupar na janela                                                                                   *
  *(valor obitido ao contar o n�mero m�ximo de caracteres por linha)                                                                                   *
  *                                                                                                                                                    *
  *Exemplo: Se h� uma janela com o seguinte formato                                                                                                    *
  * ______________                                                                                                                                     *
  *|              |                                                                                                                                    *
  *| Exemplo: XXX |                                                                                                                                    *
  *|______________|                                                                                                                                    *
  *                                                                                                                                                    *
  *Quer dizer que a janela possui 12 espa�os ao todo por linha com um conte�do que varia entre 1 e 3 (XXX), ent�o                                      *
  *chama-se da seguinte maneira:                                                                                                                       *
  *                                                                                                                                                    *
  *alignMargin("numero de caracteres j� escritos"+"variavel que armazena o n�mero de digitos a serem escritos","tamanho dispon�vel para ser escrito"); *
  *                                                                                                                                                    *
  *alignMargin(3+9,12);                                                                                                                                **/

#endif // FUNCOESDEDESIGN_H
