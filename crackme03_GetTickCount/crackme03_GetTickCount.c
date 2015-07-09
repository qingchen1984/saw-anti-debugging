/*****************************************************************
* File:			crackme03_GetTickCount.c
* Description:	Es un crackme que implementa la protecci�n 
* 				anti-debugging basada en la funci�n GetTickCount()
* Date: 		06/07/2015
* Author: 		reverc0de
* Twitter:		@reverc0de
* Site:			www.reverc0de.com
* Github:		https://github.com/reverc0de/saw-anti-debugging	
*****************************************************************/

#include <windows.h>
#include <stdio.h>

int main(void)
{
	unsigned long t1,t2,t3;
	int i,x;
	t1 = GetTickCount(); //Tiempo en milisegundos
	//C�digo intermedio
	for (i=0;i<10000000;i++)
	{
		x = i; //C�digo de relleno
	}
	t2 = GetTickCount(); //Tiempo en milisegundos
	t3 = t2-t1; //Tiempo empleado
	printf("t1: \t%ld\nt2: \t%ld\nt2-t1: \t%ld",t1,t2,t3);
	//Si el tiempo empleado es mayor a 100 ms, entonces
	//est� siendo debuggeado
	if (t3 > 100) 
	{
		MessageBox(0, "Debugger detectado!!","Crackme03 GetTickCount",MB_OK);
		exit(0);
	}	
	MessageBox(0, "Debugger NO detectado!!","Crackme03 GetTickCount",MB_OK);
	return 0;
}
