#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

size_t count_lines(const char* filename);

const int buffer_length=200;


int main(void)
    {
    FILE* fileOnegin = fopen("file.txt", "r");
    printf("red\n");
    size_t nLines=count_lines("file.txt");
    char* arrPointer=(char*)calloc(nLines, sizeof(char*));
    char buffer[buffer_length]={};
    //printf("%d\n", strlen(buffer[1]));
    printf("go to cycle\n");
    for (int unsigned i=0; i<nLines; i++)
        {
        fgets(buffer, buffer_length*sizeof(char), fileOnegin);
        size_t bufSize = strlen(buffer)+1;
        char*StrMem = (char*)calloc(bufSize, sizeof(char*));
        //strcpy(StrMem, buffer);
        arrPointer[i]=strcpy(StrMem, buffer);
        printf("%s", arrPointer[i]);
        }
    printf("end");
    fclose(fileOnegin);
    //printf("%d ", strlen(arrPointer[2]));
    return 0;
    }


size_t count_lines(const char* filename)
{
   size_t cnt = 0;
   FILE*fp;
   if((fp = fopen(filename, "r")) == NULL)
       return 0;
   while(fscanf(fp, "%*[^\n]%*c") != EOF)
   {
         cnt++;
    if (ferror(fp))
        printf("err\n");
   }
   fclose(fp);
   return cnt;
}
