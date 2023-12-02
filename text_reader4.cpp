#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

size_t sizeof_file(FILE * fileName);
size_t count_lines(char* Arr);

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

size_t sizeof_file(FILE * fileName)
{
    fseek(fileName, 0, SEEK_END);
    size_t size = ftell(fileName);
    return size;
}

