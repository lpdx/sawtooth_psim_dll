#include "main.h"

static int acc = 0; //
/** @brief OpenSimUser
*
* Função necessaria para integração com PSIM. Ela é executada somente na inicia-
* lização da DLL.
*
* @return Não há retorno para esta função.
*
* @note Esta é uma nota
*/
DLLPSIM void OpenSimUser(const char* szId,
    const char* szNetlist,
    void** ptrUserData,
    int  nInputCount,
    int  nOutputCount,
    int* pnError,
    char* szErrorMsg)
{
    acc = 0;
}


/**
* @brief RunSimUser
*
* Função necessária para integração com PSIM. Ela é executada a cada ciclo de
* processamento do PSIM.
* @param freq_sawtooth in Hertz
* @return sawtooth wave with range [0-1]
*
* @note Nesta função que são chamados todos os cálculos e interações planta.
*/
DLLPSIM void RunSimUser(double t,
    double delt,
    double* in,
    double* out,
    void** ptrUserData,
    int* pnError,
    char* szErrorMsg)

{   
    float freq_sawtooth;
    int threshold;
   
    freq_sawtooth = in[0];
    threshold = (int)(1/ delt)/freq_sawtooth - 1;

    if (acc < threshold)
    {
        acc = acc + 1;
    }
    else
    {
        acc = 0;
    }

    out[0] = (float)acc / threshold;

}

/**
* @brief CloseSimUser
* função do PSIM que é executada ao final da simulação.
*/
DLLPSIM void CloseSimUser(const char* szId, void** ptrUserData)
{

}
/*** end of file ***/

