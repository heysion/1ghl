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


int main()
{
  error("%s,%d,%s","abc",1232,"KK");
  return 0;
}
