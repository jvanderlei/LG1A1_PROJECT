#include <stdio.h>
int main()
{
int c[2][4][3];
int i,j,k;
  
printf("Enter elements into 3-D array: ");
for(i=0;i<2;i++)
{
  for(j=0;j<4;j++)
  {
    for(k=0;k<3;k++)
    {
    scanf("%d",&c[i][j][k]);
    }
  }
}
  for(i=0;i<2;i++)
{
	for(j=0;j<4;j++)
	{
		for(k=0;k<3;k++)
		{
		printf("\t%d",c[i][j][k]);
		}
	printf("\n");
	}
printf("\n");
}
getch();
return 0;
}
