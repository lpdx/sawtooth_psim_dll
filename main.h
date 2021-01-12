#pragma once
/**
* @file  main.h
* @brief Arquivo header para execução do algoritimo GMPPT-PSO-INCOND
* @copyright Andre Leopoldino <andre.leopoldino@gmail.com>
*/
#ifndef MAIN_H
#define MAIN_H

#ifndef BUILD_DLL_PSIM
#define DLLPSIM __declspec(dllexport)
#else
#define DLLPSIM __declspec(dllimport)
#endif


/* Funções principais*/

/**
 * @brief OpenSimUser
 *
 * @param szId
 * @param szNetlist
 * @param nInputCount
 * @param nOutputCount
 * @param pnError
 * @param szErrorMsg
 * @return DLLPSIM OpenSimUser
 */
DLLPSIM void OpenSimUser(const char* szId,
    const char* szNetlist,
    void** ptrUserData,
    int  nInputCount,
    int  nOutputCount,
    int* pnError,
    char* szErrorMsg);

/**
 * @brief
 *
 * @param t
 * @param delt
 * @param in
 * @param out
 * @param pnError
 * @param szErrorMsg
 * @return DLLPSIM RunSimUser
 */
DLLPSIM void RunSimUser(double t,
    double delt,
    double* in,
    double* out,
    void** ptrUserData,
    int* pnError,
    char* szErrorMsg);
DLLPSIM void CloseSimUser(const char* szId, void** ptrUserData);


#endif // !MAIN_H
/*** end of file ***/