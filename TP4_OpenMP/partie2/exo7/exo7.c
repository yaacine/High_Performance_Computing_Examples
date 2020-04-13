
/**
 * exi 7
 * */

#include <stdio.h>
#include <stdlib.h>
int fibo ( int n ) {
if ( n < 2)
return n ;
return fibo ( n-1) + fibo ( n-2);
}
int main ( int argc , char_ argv [ ] ) {
int n =atoi ( argv [ 1 ] ) ;
printf ( " fibo (%d ) = %d \ n " , n , fibo (n) ) ;
return 0;
}