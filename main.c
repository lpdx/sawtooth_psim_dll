#include "main.h"

static int acc = 0; //
/** @brief OpenSimUser
*
* Fun��o necessaria para integra��o com PSIM. Ela � executada somente na inicia-
* liza��o da DLL.
*
* @return N�o h� retorno para esta fun��o.
*
* @note Esta � uma nota
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
* Fun��o necess�ria para integra��o com PSIM. Ela � executada a cada ciclo de
* processamento do PSIM.
* @param freq_sawtooth in Hertz
* @return sawtooth wave with range [0-1]
*
* @note Nesta fun��o que s�o chamados todos os c�lculos e intera��es planta.
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
* fun��o do PSIM que � executada ao final da simula��o.
*/
DLLPSIM void CloseSimUser(const char* szId, void** ptrUserData)
{

}
/*** end of file ***/

