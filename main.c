#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"
int main()
{
    int res = compile_file("./test.c", "./test", 0);
    if (res == COMPILER_FILE_COMPILED_OK)
    {
        printf("Good to go!\n");
    }
    else if (res == COMPILER_FAILED_WITH_ERRORS)
    {
        printf("you write bad code\n");
    }
    else
    {
        printf("WHAT HAVE YOU DONE???? Unknown response\n");
    }
    return 0;
}