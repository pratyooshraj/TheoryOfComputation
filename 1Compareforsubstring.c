#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define max 25

int validstr(char arr[], char s[])
{
    int l=strlen(s);
    int k;
    for(int i=0; i<l; i++)
    {
        k=1;
        for(int j=0; j<10; j++)
        {
            if (s[i]==arr[j])
            {
                k=0;
                break;
            }
        }
        if (k!=0)
        {
            return k;
        }
    }
    return k;
}

void substring_type(char s1[], char s2[])
{
    int n=strlen(s2);
    if(strcmp(s1,s2)==0)
    	printf("improper substring");
    else if(strncmp(s1,s2,n)==0)
    		printf("Prefix\n");
    else if(strncmp(s1+strlen(s1)-n,s2,n)==0)
    		printf("suffix\n");
    		//string is an array of characters so adding integer increments the index hence moving the postion to the required position
   else if (strstr(s1, s2) != NULL) {
        if (strcmp(s1, s2) != 0)
            printf("proper substring\n");
    }
	else
		printf("not a substring");

}

int main()
{
    int i,j,l1,l2,k,val;
    char s1[max],s2[max];
    char arr[10]= {'a','b','c','d','e','f','g','h','i','j'};
    printf("symbol set= %s\n",arr);
top:
top1:
    printf("enter string one: ");
    scanf("%s",s1);
    val=validstr(arr,s1);
    if(val!=0)
    {
        printf("Element not in universal set");
        goto top1;
    }
top2:
    printf("enter string two: ");
    scanf("%s",s2);
    val=validstr(arr,s2);
    if(val!=0)
    {
        printf("Element not in universal set");
        goto top2;
    }
    if(strlen(s1)<strlen(s2))
    	goto top;
    printf("valid string1: %s\n",s1);
    printf("valid string2: %s\n",s2);

    substring_type(s1, s2);
    return 0;
}


