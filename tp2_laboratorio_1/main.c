#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define T 5
int main()
{   sEmployee Empleados[T];
    initEmployees(Empleados, T);
    hardcodearDatos(Empleados,T);
    optionMenu(Empleados,T);

    return 0;
}
