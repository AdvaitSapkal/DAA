// bottom up approach for longest common subsequence
#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void lcs(char str1[], char str2[], int sz1, int sz2)
{

    // making the table bottom up
    int table[sz1 + 1][sz2 + 1];
    for (int i = 0; i <= sz1; i++)
    {
        for (int j = 0; j <= sz2; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    // finding the lcs
    int index = table[sz1][sz2]; 
    int temp = index;           

    char lcs[index + 1];
    lcs[index] = '\0';

    int i = sz1;
    int j = sz2;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (table[i - 1][j] < table[i][j - 1])
            j--;
        else
            i--;
    }
    printf("LCS of %s and %s is :\n", str1, str2);
    printf("[ %s ] and length is [ %d ] \n", lcs, temp);
}

int main()
{
    char str1[100];
    char str2[100];
    
    printf("enter string 1:\n"); scanf("%s", str1);
    printf("enter string 2:\n"); scanf("%s", str2);

    lcs(str1, str2, strlen(str1), strlen(str2));
}