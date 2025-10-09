/*
 * linearsearch.c
 *
 *  Created on: Jul 24, 2025
 *      Author: administrator
 */


#include <stdio.h>
int linearSeach(int fa[5], int fns);

int linearSeach(int fa[5], int fns)
{
	int i=0;
	int flag=1;
	for (i=0;i<5;i++)
		{
			if (fa[i]==fns)
				flag=0;
		}
	return flag;
}

int main(void)
{
	int a[]={5,19,24,52,29};
	int ns=100;
	int found=linearSeach(a,ns);
	if (found==0)
	{
		printf("the number %d is found in the array",ns);
	}
	else
		printf("the number %d is not found in the array",ns);

	return 0;

}
