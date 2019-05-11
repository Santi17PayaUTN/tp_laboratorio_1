#include "ArrayEmployees.h"


void initEmployees(sEmployee list[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        list[i].isEmpty = YES;
    }
}
int findEmptySpace(sEmployee list[], int len)
{
    int i;
    int index=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==YES)
        {
            index = i;
            break;
        }
    }
    return index;
}
void askForData(sEmployee list[], int len)
{
    sEmployee aux[1];
    int reply;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(aux[1].name);
    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(aux[1].lastName);
    printf("Ingrese su salario: ");
    fflush(stdin);
    scanf("%f", &aux[1].salary);
    printf("Ingrese su sector: ");
    fflush(stdin);
    scanf("%d", &aux[1].sector);

    reply=addEmployees(list,len,aux[1].id,aux[1].name,aux[1].lastName,aux[1].salary,aux[1].sector);
    if(reply==-1)
    {
        printf("Error en el ingreso de datos.");
    }
}
int addEmployees(sEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    i = findEmptySpace(list, len);
    if(i!=-1)
    {
        list[i].id=i+1;
        strcpy(list[i].name,name);
        strcpy(list[i].lastName,lastName);
        list[i].salary=salary;
        list[i].sector=sector;
        list[i].isEmpty = NO;
    }
    else
    {
        printf("No hay espacio");
    }
    return i;
}
void modifyEmployees(sEmployee list[],int len)
{
    int i;
    int identification;
    int option;
    char newName[20];
    char newLastName[20];
    float newSalary;
    int newSector;
    int flag=0;

    printf("Ingrese la identificacion del empleado: ");
    fflush(stdin);
    scanf("%d",&identification);
    for(i=0; i<len; i++)
    {
        if(list[i].id==identification)
        {
            flag=1;
            option= menuText("1_Cambiar nombre\n 2_Cambiar apellido\n 3_Cambiar salario\n 4_Cambiar sector\n 5_Cancelar\n Elija una opcion: ");
            switch(option)
            {
            case 1:
                printf("Reingrese el nombre: ");
                fflush(stdin);
                scanf("%s",newName);
                strcpy(list[i].name, newName);
                break;
            case 2:
                printf("Reingrese el apellido: ");
                scanf("%s", newLastName);
                strcpy(list[i].lastName, newLastName);
                break;
            case 3:
                printf("Reingrese el salario: ");
                scanf("%f", &newSalary);
                list[i].salary= newSalary;
                break;
            case 4:
                printf("Reingrese el sector: ");
                scanf("%d", &newSector);
                list[i].sector= newSector;
            case 5:
                printf("Modificacion cancelada.");

            }
        }
    }
    if(flag==0)
    {
        printf("No se encontro ninguna coincidencia\n");

    }
}
int menuText(char messageMenu[])
{
    int option;
    printf("%s", messageMenu);
    scanf("%d", &option);

    return option;
}

void optionMenu(sEmployee list[],int len)
{
    int option;
    do
    {
        option = menuText("1.Altas\n2.Modificar\n3.Baja\n4.Informar/Mostrar\n5.Salir\nElija una opcion: ");
        switch(option)
        {
        case 1:
            askForData(list,  len);

            break;
        case 2:
            modifyEmployees(list,len);
            break;
        case 3:
            askForDelete(list,len);
            break;
        case 4:
            sortOrPrintEmployees(list,len);
            printf("\n-------------Empleados ordenados------------\n");
            showEmployees(list,len);
            break;

        }
    }
    while(option!=5);


}
void showEmployees(sEmployee list[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty!=YES)
        {
            showOneEmployee(list[i]);
        }

    }
}
void showOneEmployee(sEmployee oneEmployee)
{
    printf("%d- %s - %s - %f - %d\n", oneEmployee.id,oneEmployee.name,oneEmployee.lastName,oneEmployee.salary, oneEmployee.sector);

}
int findEmployeeById(sEmployee list[], int len,int id)
{
    int index=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].id==id)
        {

            index=i;

        }
    }
    return index;
}
int removeEmployee(sEmployee list[], int len, int id)
{
    int index;
    index=findEmployeeById(list,len,id);
    if(index!=-1)
    {
        list[index].isEmpty=YES;
    }

    return index;
}
void askForDelete(sEmployee list[], int len)
{
    int id;
    int index;
    char answer;
    printf("Ingrese la identificacion del empleado que quiera borrar: ");
    fflush(stdin);
    scanf("%d",&id);
    printf("La identificacion ingresada fue %d", id);
    answer=areYouSure("¿Esta seguro que desea continuar?\n [S]i--------[N]o\n");
    if(answer=='s'||answer=='S')
    {
        index=removeEmployee(list,len, id);
        if(index==-1)
        {
            printf("El id ingresado es inexistente\n");
        }
    }
    else if(answer=='n'||answer=='N')
    {
        printf("Se a cancelado la accion\n");
    }
    else
    {
        printf("Su respuesta no es valida\n");

    }
}
char areYouSure (char text[])
{
    char answer;
    printf("%s", text);
    fflush(stdin);
    scanf("%c", &answer);

    return answer;
}
void sortOrPrintEmployees (sEmployee list[],int  len)
{
    int answer, order, result;
    printf("Desea:\n 1_Ordenar por apellido y sector los empleados.\n 2_Mostrar total de los salarios, el promedio y empleados que superan el mismo.\n");
    fflush(stdin);
    scanf("%d", &answer);
    if(answer==1)
    {
        printf("Desea ordenarlo:\n1_Alfabeticamente de arriba para abajo\n2_Alfabeticamente de abajo para arriba\nRespuesta: ");
        scanf("%d",&order);
        if(order==1)
        {
            result=sortEmployees(list,len,UP);
            if (result==-1)
            {
                printf("No se ordeno la fila");
            }
        }
        else if(order==2)
        {
            result=sortEmployees(list,len,DOWN);
        }

        else
        {
            printf("El dato ingresado es incorrecto");
        }


    }
    else if(answer==2)
    {
        addAverageSalaries(list,len);
    }
    else
    {
        printf("La opcion igresada es incorrecta");
    }
}
int sortEmployees(sEmployee list[], int len, int order)
{
    sEmployee aux;
    int i,j,flag;
    flag=-1;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if((stricmp(list[i].lastName,list[j].lastName))<0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
                flag=1;

            }
        }

    }


    return flag;
}
void hardcodearDatos(sEmployee list[], int len)
{
    int i;
    int identificaciones[]= {1,2,3,4,5,6};
    char nombres[][50]= {"Maria","Pedro","Jose","Pedro","Pablo","Mateo"};
    char apellidos[][50]= {"Juarez","Juarez","Albornoz","Urquiza","Velez","Jorge"};
    float salario[]= {1000,2000,3000,4000,5000,6000};
    int sector[]= {2,1,2,3,1,2,3};

    for(i=0; i<len; i++)
    {
        list[i].id = identificaciones[i];
        strcpy(list[i].name, nombres[i]);
        strcpy(list[i].lastName, apellidos[i]);
        list[i].salary=salario[i];
        list[i].sector=sector[i];
        list[i].isEmpty = NO ;

    }
}
void addAverageSalaries (sEmployee list[], int len)
{
    float averageSalaries;
    float sumOfWages= 0;
    int i;
    int counter = 0;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == NO)
        {
            sumOfWages = sumOfWages + list[i].salary;
            counter++;
        }
    }
    averageSalaries = sumOfWages / (float)counter;
    printf("Total de salarios: $%.f\n", sumOfWages);
    printf("Promedio de salarios: $%.f\n",averageSalaries);
    printf("\n-------------------Lista de empleados que superan el promedio-------------------------\n");
    for(i=0;i<len;i++)
    {
        if(list[i].salary>averageSalaries)
            {
              printf("\n-----------------------------------------------------------------------------------\n");
              showOneEmployee(list[i]);
              printf("\n-----------------------------------------------------------------------------------\n");
            }

    }
}
