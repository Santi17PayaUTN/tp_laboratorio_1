#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YES 0
#define NO 1
#define UP 1
#define DOWN -1

typedef struct
{
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

void askForData(sEmployee[],int);
/** \brief Pide al usuario los datos, los guarda en un auxiliar. Llama a la funcion addEmployes y sobre escribe los datos.
 *
 * \param sEmployee[]
 * \param int
 * \return void
 *
 */
int addEmployees(sEmployee[], int, int, char[],char[],float,int);
/** \brief Recibe los datos como parametro, los guarda dentro de un espacio libre.
 *
 * \param sEmployee[]
 * \param int
 * \param int
 * \param char[]
 * \param char[]
 * \param float
 * \param int
 * \return int
 *
 */
void initEmployees(sEmployee[], int);
/** \brief Inicializa la lista de sEmployee.
 *
 * \param sEmployee[]
 * \param int
 * \return int
 *
 */
int findEmptySpace(sEmployee[], int);
/** \brief Busca un espacio libre dentro de la lista de sEmployee.
 *
 * \param char[]
 * \return int
 *
 */
int menuText(char[]);
/** \brief Ingresa un texto y pide una respuesta numerica.
 *
 * \param sEmployee[]
 * \param int
 * \return void
 *
 */
void optionMenu(sEmployee[],int );
/** \brief
 *
 * \param sEmployee[]
 * \param int
 * \return void
 *
 */
void modifyEmployees(sEmployee[],int);
/** \brief Modifica los datos del empleado, pidiendo el id y despues cual es el dato que quiere modificar
 *
 * \param sEmployee[]
 * \param int
 * \return void
 *
 */
void showEmployees(sEmployee[], int );
/** \brief Llama a la funcion showOneEmployee la cantidad de filas que tenga la lista sEmployee.
 *
 * \param sEmployee
 * \return void
 *
 */
void showOneEmployee(sEmployee);
/** \brief Muestra una fila dentro de sEmployee.
 *
 * \param sEmployee[]
 * \param int
 * \param int
 * \return int
 *
 */
int findEmployeeById(sEmployee[], int,int );
/** \brief
 *
 * \param sEmployee[]
 * \param int
 * \param int
 * \return int
 *
 */
int removeEmployee(sEmployee[], int, int );
/** \brief
 *
 * \param sEmployee[]
 * \param int
 * \return void
 *
 */
void askForDelete(sEmployee[], int );
/** \brief
 *
 * \param sEmployee[]
 * \param int
 * \return
 *
 */
char areYouSure (char[]);
/** \brief
 *
 * \param char[]
 * \return
 *
 */
void sortOrPrintEmployees (sEmployee[],int);
/** \brief
 *
 * \param sEmployee[]
 * \param int
 * \param int
 * \return int
 *
 */
int sortEmployees(sEmployee[], int, int);
/** \brief
 *
 * \param sEmployee[]
 * \param int
 * \param int
 * \return int
 *
 */
void addAverageSalaries (sEmployee[], int);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void hardcodearDatos(sEmployee[], int);
/** \brief
 *
 * \param eEmplo
 * \param
 * \return
 *
 */
