#include <stdio.h>
#include <stdlib.h>
#include <cJSON.h>

int main(int argc,char **argv)
{
    cJSON *rootJ=cJSON_CreateObject();
    cJSON *headJ=cJSON_CreateObject();
    cJSON_AddNumberToObject(headJ,"ErrorCode",0);
    cJSON_AddStringToObject(headJ,"Message","Success");
    cJSON_AddItemToObject(rootJ,"Head",headJ);
    char *pfResult=cJSON_Print(rootJ);
    printf("%s \n",pfResult);
    free(pfResult);
    cJSON_Delete(rootJ);
    return 0;
}

