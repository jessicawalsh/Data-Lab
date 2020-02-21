/* 
 * CS:APP Data Lab 
 * 
 * Author: Jessica Walsh
 * Email: jaw6122@psu.edu
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  //declare variables, 0x55 is 01010101 in binary and has all even-numbered bits set to 1 
  int  evenBits = 0x55;
  int  evenBits1;
  int  evenBits2;
  int  evenBits3;
  int  result;
  int  result2;
 
  // shift 0x55 to the left by 8 bits so that the last 8 bits are filled with 0 
  evenBits1 = evenBits << 8;
  // add 0x55 to the shifted number so that the last 8 bits are filled with all even bits set to 1 
  evenBits2 = evenBits1 + evenBits;
  // shift left so that the last 16 bits are filled with 0's
  evenBits3 = evenBits2 << 16;
  //fill the last 16 bits with all even bits set to 1 by adding evenBits2
  evenBits3 = evenBits3 + evenBits2;
  
  //and x with evenBits3 to set all odd-numbered bits to 0 in x  
  result = evenBits3 & x;
  //xor the result with evenBits3, if the bits are the same 0 will be stored in results2 and 1 otherwise     
  result2 = evenBits3 ^ result;
 
  // return 1 if x contains all even-numbered bits set to 1
  return !result2;

         
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  // declare variables 
  int shift;
  int shift2;
  int shift3;
  int shift4;

  //add all of the bits in x by repeatedly shifting to the right and oring the results 
  shift = x >> 16;
  x = shift | x;
  shift2 = x >> 8;
  x = x | shift2;
  shift3 = x >> 4;
  x = x | shift3;
  shift4 = x >> 2;
  x = x | shift4; 
  x = x | x >> 1;
  
  //return 1 if x is 0 and 0 if x is a number     
  return(x & 1) ^ 1;
}
/* 
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
  
  // declare variables and divide ug and uf into their exponent and mantissa
  int mantissaMask = ~(~0 << 23);
  int ufExponent = (uf >> 23) & 0xFF ;
  int ufMantissa = mantissaMask & uf;
  int ugExponent = (ug >> 23) & 0xFF;
  int ugMantissa = mantissaMask & ug;

  /* check if either ug or uf is NaN, ug and uf will be NaN when the exponent is all 1's 
  * and the mantissa is any non-zero number*/      
  if(((ufExponent == 0xFF) && (ufMantissa !=0)) || ((ugExponent == 0xFF) && (ugMantissa !=0)))
  {
    return 0;
  }

  /* check to see if ug and uf are 0, if they are 0 both their exponent and mantissa should 
  * be all 0's*/
  if(((ufExponent == 0) && (ufMantissa == 0)) && ((ugExponent == 0) && (ugMantissa == 0)))
  {
    return 1;
  }   
  
  //return 1 if uf and ug are equal and 0 otherwise
  return uf == ug;
}
/* 
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
: *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u) {
  //declare variables
  int mantissa;
  int i = 0;
  int exp = 0;
  int shift; 
  int leftOver;
  int mask;
  int half;
  int round = 0;
  
  // return 0 if u = 0
  if ( u == 0)
  { 
    return 0;
  } 
    
  //find the value of the exponent by finding the position of the most significant 1
  while (i != 32)
  { 
    if (u >> i == 1)
    {
      exp = i;
      break; 
    }
    i++;
  }
  
  // find the value of the mantissa   
  shift = 32 - exp;
  mantissa = (u<<shift)>>9; 

  //find the value of the last three bits of the mantissa which will be used to determine rounding  
  mask = ~(~0<<(exp-23));
  leftOver = u & mask;

  //determine whether the floating point number requires rounding  
  if (exp > 23)
  {
    half = 1 << (exp - 23 - 1);

    if (leftOver > half)
    {
      round = 1;
    }
    
    else if (leftOver < half)
    {
      round = 0;
    }

    else if ((leftOver == half) && (mantissa & 1))
    {
      round = 1;
    }
    else
    {
      round = 0;
    }
    
   }

  //add the exponent, mantissa, and rounding to create the floating point number  
  return ((exp + 127)<<23) + mantissa + round;   

}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  //declare variables
  int diff;
  int sign;
  int sign_x;
 
  // subtract y from x and store the difference 
  diff = x + (~y + 1);
  /*determine whether the difference results in a positive or negative number 
   * the difference should be negative is x is less than y*/
  diff = (diff >> 31)&1;
  //determine whether x and y have the same sign or not
  sign = (x ^ y) >> 31;
  sign = sign & 1;
  //determine whether x is a positive or negative number
  sign_x = x >> 31;
  sign_x = sign_x & 1;
  
  //return 1 if x is less than y and 0 otherwise  
  return (sign_x & sign) | (diff & !sign);  
  
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNonNegative(int x) {
  /* Find the most significant bit which will be 1 if it is
   * negative and 0 if it is positive */  
  int msb = x >> 31;

  /* return 1 if x is positive and 0 otherwise by negating the msb */
  return !msb;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /*if x is Tmax then x + x will result in -2 and isTmax will be 0
   * isTmax will also be 0 when x = -1 */      
  int isTmax = x + x + 2;

  //determine if x is -1 or not, isNegOne will be 0 when x = -1
  int isNegOne = x + 1;
   
  //return 1 if x is Tmax and 0 otherwise    
  return  (!isNegOne ^ !isTmax);
 
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  //declare variables
  int shift;
  int temp;
  int mask;
  int shift2;
  
  //find the last n bits of x and store it in temp  
  shift = 32 + (~n + 1);
  temp = x >> shift;
  
  //create a mask that is all 0's except the last n bits  
  mask = ~0;
  mask = mask << n;
  mask = ~mask; 
  
  
  temp = temp & mask;

  // shift x to the left by n bits
  shift2 = x << n;
   
  // or the last n bits of x with x shifted to the left by n bits  
  return temp | shift2;
}
/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
  //find the msb to determine if x is postive or negative
  int msb = (x >> 31);
  /* create a mask that is either all 0's if x is positive or 31 0's 
   * and a 1 in the lsb if x is negative */ 
  int mask = msb << 31;
  // calculate the two's complement of x 
  int twosComp = ~x + 1;
  
  /* if x is positive return x and if x is negative return its two's complement
   * which will be all the bits of x inverted plus 1*/    
  return (~msb & x) | (msb & (twosComp ^ mask));
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  //declare variables  
  int y;
  // in binary 0x49 is 01001001 which has every third bit set to 1
  int x = 0x49;  
  // shift x to the left by 9 so the last 9 bits are filled with 0's
  y = x <<  9;
  // add 0x49 so the 0's are filled with every third bit set to 1
  y = y + x;
  //fill the last 9 bits of y with 9 0's
  y = y << 9;
  //add 0x49 so the 0's are filled with every third bit set to 1 
  y = y + x;
  //fill the last 9 bits of y with 9 0's
  y = y << 9;
  //add 0x49 so that the 0's are filled with every third bit set to 1 
  y = y + x;  
 
  //return word with every third bit set to 1  
  return y;
}
