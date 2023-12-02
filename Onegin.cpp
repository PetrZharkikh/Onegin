#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

size_t count_lines(char* Arr);
void bsort(char* arr[], size_t sizeofarr, size_t sizeoftype, int (*cmp)(const void*, const void*));
int strcmp_reversed(const void* ptr1, const void* ptr2);
void bsort_reversed(char* arr[], size_t sizeofarr, size_t sizeoftype, int (*cmp)(const void*, const void*));
size_t sizeof_file(FILE * fileName);
void swap(void* ptr1, void* ptr2, size_t sizeofelem);
int mystrcmp(const void* ptr1, const void* ptr2);


int main(void)
    {

    FILE* fileOnegin = fopen("file.txt", "r");

    if (fileOnegin == NULL)
        {
        printf("File did not open");
        return 0;
        }

    size_t tsize = sizeof_file(fileOnegin);

    rewind(fileOnegin);

    char* big_buffer = (char*)calloc(tsize+1, sizeof(char));
    fread(big_buffer, sizeof(char), tsize, fileOnegin);


    fclose(fileOnegin);

    size_t nLines = count_lines(big_buffer);

    char** arrPointer = (char**)calloc(nLines, sizeof(char*));

    arrPointer[0] = &big_buffer[0];
    for (unsigned int i = 1; i<nLines; i++)
        {
        arrPointer[i] = strchr(arrPointer[i-1], '\0') + 1;
        if (*arrPointer[i] == '\n')
            arrPointer[i]++;
        }

    bsort(arrPointer, nLines, sizeof(char*), mystrcmp);

    for (int unsigned j = 0; j < nLines; j++)
        {
        printf("%s", arrPointer[j]);
        putchar('\n');
        }

    putchar('\n');

    bsort_reversed(arrPointer, nLines, sizeof(char*), strcmp_reversed);

    for (int unsigned j = 0; j < nLines; j++)
        {
        printf("%s", arrPointer[j]);
        putchar('\n');
        }

    return 0;
    }


size_t count_lines(char* Arr)
    {
   int i = 0;
   int cnt = 0;
   while (Arr[i]!='\0')
        {
        if (Arr[i] == '\r')
            {
            Arr[i] = '\0';
            cnt++;
            i+=2;
            continue;
            }
        if (Arr[i] == '\n')
            {
            Arr[i] = '\0';
            cnt++;
            }
        i++;
        }
    if(Arr[i - 1] != '\0' && Arr[i - 1] != '\n')
        cnt++;
    return cnt;
    }

//int str_cmp(const void* lhs, const void* rhs)
//{
  //  return strcmp();
//}


//void bsort(char* arr[], size_t size, int (*cmp)(const void*, const void*))
void bsort(char* arr[], size_t sizeofarr, size_t sizeoftype, int (*cmp)(const void*, const void*))
    {
     for (int unsigned pass = 0; pass < sizeofarr - 1; pass++)
        {
         int scr = 0;
         for (int unsigned i = 0; i < sizeofarr - 1 -pass; i++)
            {
             if (cmp(arr[i], arr[i + 1]) > 0)
                {
                 scr++;
                 swap(&arr[i], &arr[i+1], sizeoftype);       //!!!!!!!
                }
            }
         if (scr == 0) break;
        }
    }


void bsort_reversed(char* arr[], size_t sizeofarr, size_t sizeoftype, int (*r_cmp)(const void*, const void*))
    {
    for (int unsigned pass = 0; pass < sizeofarr - 1; pass++)
        {
         int scr = 0;
         for (int unsigned i = 0; i < sizeofarr -1 - pass; i++)
            {
             if (r_cmp(arr[i],arr[i+1])>0)
                {
                 scr++;
                 swap(&arr[i], &arr[i+1], sizeoftype);
                }
            }
         if (scr == 0) break;
        }
    }

int mystrcmp(const void* ptr1, const void* ptr2)
    {
    int pos = 0;

    const char* str1 = (const char*)ptr1;
    const char* str2 = (const char*)ptr2;

    while (str1[pos] != 0 && str2[pos] != 0 &&  str1[pos] == str2[pos])
        {
        pos++;
        }

    return (str1[pos]) - (str2[pos]);
    }

int strcmp_reversed(const void* ptr1, const void* ptr2)
    {
    const char* s1 = (const char*)ptr1;
    const char* s2 = (const char*)ptr2;

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


size_t sizeof_file(FILE * fileName)
{
    fseek(fileName, 0, SEEK_END);
    size_t size = ftell(fileName);
    return size;
}


void swap(void* ptr1, void* ptr2, size_t sizeofelem)
    {
    void* temp = (void*)malloc(sizeofelem);
    memcpy(temp, ptr1, sizeofelem);
    //printf("%s\n", temp);
    memcpy(ptr1, ptr2, sizeofelem);
    //printf("%s\n", ptr1);
    memcpy(ptr2, temp, sizeofelem);
    //printf("%s\n", ptr2);
    free(temp);
    }
