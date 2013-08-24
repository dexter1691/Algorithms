/**
 * Exponentiation By Squaring: Efficient way of caluclationg power x^y.
 * More efficient than library function which uses double type
 * Source: http://www.programminglogic.com/fast-exponentiation-algorithms/

 * Every Step, square the base, half the exponent, if the number is odd, multiply result with the number
 */

int expo(int a, int b){
  int result = 1;

  while (b){
    if (b&1)        // check odd or not
    {
      result *= a;
    }
    b>>=1 ;     //divide operator
    a *= a;
  }

  return result;
}
