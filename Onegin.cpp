#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

size_t count_lines(const char* filename);
void bsort(char* arr[], size_t size);
int strcmp_reversed(char arr1[], char arr2[]);
void bsort_reversed(char* arr[], size_t size);

const int buffer_length = 200;


int main(void)
    {
    FILE* fileOnegin = fopen("file.txt", "r");

    //printf("red\n");

    size_t nLines = count_lines("file.txt");

    char** arrPointer = (char**)calloc(nLines, sizeof(char*));
    char buffer[buffer_length] = {};

    //printf("%d\n", strlen(buffer[1]));
    //printf("nLines = %d\n", nLines);

    for (int unsigned i = 0; i < nLines; i++)
        {
        fgets(buffer, buffer_length*sizeof(char), fileOnegin);
        size_t bufSize = strlen(buffer)+1;
        char* StrMem = (char*)calloc(bufSize, sizeof(char*));

        //strcpy(StrMem, buffer);

        arrPointer[i] = strcpy(StrMem, buffer);

        //printf("%s", arrPointer[i]);
        }

    fclose(fileOnegin);

    bsort(arrPointer, nLines);

    //printf("end");

    for (int unsigned j = 0; j < nLines; j++)
        {
        printf("%s", arrPointer[j]);
        putchar('\n');
        }

    printf("-----------------------------------------\n");

    bsort_reversed(arrPointer, nLines);

    for (int unsigned j = 0; j < nLines; j++)
        {
        printf("%s", arrPointer[j]);
        putchar('\n');
        }

    //printf("%d ", strlen(arrPointer[2]));

    return 0;
    }


size_t count_lines(const char* filename)
{
   size_t cnt = 0;
   char buffer[buffer_length] = {};

   FILE*fp;
   if((fp = fopen(filename, "r")) == NULL)
       return 0;
   while (!feof(fp))
   {
     fgets(buffer, buffer_length*sizeof(char), fp);
     cnt++;
   }
   fclose(fp);
   return cnt;
}


void bsort(char* arr[], size_t size)
    {
     for (int unsigned pass = 0; pass < size-1; pass++)
        {
         int scr = 0;
         for (int unsigned i = 0; i < size -1 -pass; i++)
            {
             if (strcmp(arr[i],arr[i+1])>0)
                {
                 scr++;
                 char* temp = arr[i];
                 arr[i] = arr[i+1];
                 arr[i+1] = temp;
                }
            }
         if (scr == 0) break;
        }
    }


void bsort_reversed(char* arr[], size_t size)
    {
    for (int unsigned pass = 0; pass < size-1; pass++)
        {
         int scr = 0;
         for (int unsigned i = 0; i < size -1 -pass; i++)
            {
             if (strcmp_reversed(arr[i],arr[i+1])>0)
                {
                 scr++;
                 char* temp = arr[i];
                 arr[i] =   arr[i+1];
                 arr[i+1] = temp;
                }
            }
         if (scr == 0) break;
        }
    }


int strcmp_reversed(char s1[], char s2[])
    {
    int pos1 = strlen(s1);
    int pos2 = strlen(s2);

    for ( ; pos1!=0 && pos2!=0; )
        {
        if (s1[pos1]>s2[pos2]) return 1;
        if (s1[pos1]<s2[pos2]) return -1;
        pos1--;
        pos2--;
        }

    if (s1[pos1]>s2[pos2]) return 1;
    if (s1[pos1]<s2[pos2]) return -1;
    return 0;
    }
