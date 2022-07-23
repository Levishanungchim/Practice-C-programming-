#include<stdio.h>
int main()
{int a,feet;
float rem,inch;
printf("Enter height in cm\n");
scanf("%d",&a);
feet=a/30;
rem=a%30;
inch=rem/2.5;
printf("The value of %d is %d\'%.2f\"\n",a,feet,inch);
return 0;
}

