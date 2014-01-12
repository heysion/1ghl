#include <stdio.h>
#include <stdarg.h>

void error(char *format, ...)  
{
  va_list ap ;

  va_start(ap,format) ;
  fprintf(stderr,"error : ");
  fprintf(stderr,format , ap);
  va_end(ap) ;
  fprintf(stderr,"\n");

}

void printargs(int arg1, ...) /* 輸出所有int型態的參數，直到-1結束 */
{
  va_list ap;
  int i;
 
  va_start(ap, arg1); 
  for (i = arg1; i != -1 ; i = va_arg(ap, int))
    printf("%d ", i);
  va_end(ap);
  putchar('\n');
}

/* 
%d%s%f 

*/
void printff(char *fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  fprintf(stderr,"ptf:");
  
}

int main()
{
  printargs(3,1,2,3,-4,-1);

  error("%s,%d,%s","abc",1232,"KK");
  return 0;
}
