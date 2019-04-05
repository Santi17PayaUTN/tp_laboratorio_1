
/** \brief Funcion que pide un numero.
 *
 * \return int
 */
int pedirNumero ();
/** \brief Funcion que suma dos numeros.
 *
 * \param int
 * \param int
 * \return int
 *
 */
int sumarNumeros(int, int);
/** \brief Funcion que resta dos numeros.
 *
 * \param int
 * \param int
 * \return int
 *
 */
int restarNumeros(int, int);
/** \brief Funcion que divide dos numeros
 *
 * \param  int
 * \param int
 * \return float
 *
 */
float dividirNumeros(int,int);
/** \brief Funcion que multiplica dos numeros.
 *
 * \param int
 * \param int
 * \return int
 *
 */
int multiplicarNumeros(int,int);
/** \brief Funcion que calcula el fatorial de un numero. En caso de ser negativo retorna -1.

 *
 * \param int
 * \return int
 *
 */
int calcularFactoriales(int);
/** \brief Pregunta al usuario si desea continuar. Si el usuario coloca 's' se llama a la funcion calculadora. De lo contrario, se coloca un mensaje de agradecimiento.
 *
 * \return void
 *
 */
void preguntarAlUsuario();
/** \brief Pide dos numeros, son asignados a A y a B en el orden de ingreso.
 ** \brief Luego llama a las funciones asignadas a sumar, restar, multiplicar, dividir y factorear, y da los resultados de cada una de las cuentas
 *
 * \return void
 *
 */
void calculadora();
