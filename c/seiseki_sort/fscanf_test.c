#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char seps[] = ",";// [,]文字による区切り-->CSVファイル

int** allocArray(int row, int col);
void freeArray(int** data, int row);
void chop_crlf(char* buff);
void readFileFormat(FILE* fp, int* row, int* col);
void readFileData(FILE* fp, int** data);
void dispData(int** data, int row, int col);

int main(int argc, char* argv[])
{
    int row,col;
    FILE* fp;
    int** data;

    if ( argc < 2 ) return 0;
    fp = fopen(argv[1],"r");
    if ( fp == NULL ) {
        fprintf(stderr,"%s: No such file\n",argv[1]);
        return 0;
    }

    readFileFormat(fp,&row,&col);
    printf("File format: col/row = %d/%d\n",col,row);

    data = allocArray(row,col);
    readFileData(fp,data);
    fclose(fp);

    dispData(data,row,col);

    freeArray(data,row);

    return 0;
}

int** allocArray(int row, int col)
{
    int** data = (int**)calloc(row,sizeof(int*));
    for ( int i=0; i<row; i++ ) data[i] = (int*)calloc(col,sizeof(int));
    return data;
}

void freeArray(int** data, int row)
{
    for ( int i=0; i<row; i++ ) free(data[i]);
    free(data);
}

// 改行コードの除去
void chop_crlf(char* buff)
{
    for ( unsigned i=0; i<strlen(buff); i++ ) {
        if ( buff[i] == '\r' ) buff[i] = 0;
        if ( buff[i] == '\n' ) buff[i] = 0;
    }
}

void readFileFormat(FILE* fp, int* row, int* col)
{
    int data;
    char buf[256],*token;

    rewind(fp);
    *row = *col = 0;
    while ( fgets(buf,256,fp) ) {
        chop_crlf(buf);
        if ( buf[0] == '#' || strlen(buf) == 0 ) continue;
        if ( *row == 0 ) {
            token = (char*)strtok(buf,seps);
            while ( token != NULL ) { // buf にトークンがなくなるまで繰り返す
                sscanf(token,"%d",&data);
                token = (char*)strtok(NULL,seps); // 次のトークンを取得
                *col += 1;
            }
        }
        *row += 1;
    }
}

void readFileData(FILE* fp, int** data)
{
    char buf[256],*token;
    int row,col;

    rewind(fp);
    row = col = 0;
    while ( fgets(buf,256,fp) ) {
        chop_crlf(buf);
        if ( buf[0] == '#' || strlen(buf) == 0 ) continue;
        col = 0;
        token = (char*)strtok(buf,seps);
        while ( token != NULL ) { // buf にトークンがなくなるまで繰り返す
            sscanf(token,"%d",&data[row][col]);
            token = (char*)strtok(NULL,seps); // 次のトークンを取得
            col ++;
        }
        row ++;
    }
}

void dispData(int** data, int row, int col)
{
    printf("** CSV Data:\n");
    for ( int i=0; i<row; i++ ) {
        printf("row[%d]: ", i);
        for ( int ii=0; ii<col; ii++ ) {
            printf("%d, ", data[i][ii]);
        }
        printf("\n");
    }
}
