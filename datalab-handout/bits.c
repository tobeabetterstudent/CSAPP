/* 
 * CS:APP Data Lab 
 * 
 * <aslanwang @2022/3/22>
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) { 
  /**
   * @brief 
   * x^y = x&~y | ~x&y
   * x|y = ~(~(x|y)) = ~(~x & ~y)
   */
  return ~(~(x&~y) & ~(~x&y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /**
   * @brief 
   * the minimum two's complement is 1000...0
   */
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /**
   * @brief 
   * the maximum two's complement is 0111...1
   * Tmax+1=Tmin Tmax^(-1)=Tmin so Tmax+1 = Tmax^(-1)
   * but -1 can aslo get the equation so we need to exclusive -1
   */
  int negOne = ~0;
  return !((x+1)^(x^negOne)) & !!(x^negOne);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /**
   * @brief a number whose all odd-numbered bits set to 1 is 0xAAAAAAAA
   * x & 0xAAAAAAAA == 0xAAAAAAAA
   */
  int mask = 0xAA | 0xAA<<8 | 0xAA<<16 | 0xAA<<24;
  return !((x&mask)^mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /**
   * @brief 0x30~039 is 0x0011 0000 ~ 0x0011 1001 
   * higher bits of x is x & ~(0x0f) and lower bits is x & 0x0f; 
   * notice that h == 0x30 and l&8 == 0 || l==8 || l== 9
   */
  int h = x & ~0x0f;
  int l = x & 0x0f;
  return !(h^0x30) & (!((l&8)^0) | !(l^8) | !(l^9));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /**
   * @brief 
   * if x then  !!x=1, ((!x)<<31)>>31 = 111...1
   * else       !!x=0, ((!x)<<31)>>31 = 000...0
   */
  int mask = ((!(!x))<<31)>>31; 
  return (y&mask) | (z&(~mask));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /**
   * @brief 
   * To judge x<=y, we just need to judge y-x>=0
   * notice that result may be overflow, so we need to exclusive x[31]=y[31]
   * so we can return isSameFlag(x, y)? y-x>=0 : y is negative 
   */
  int Tmin = 1 << 31;
  int xFlag = x & Tmin;
  int yFLag = y & Tmin;
  // int isSmaeFlag = !(xFlag ^ yFLag); Acutally we can substitution it into mask
  int minus = y + (~x+1);
  int front = !(minus & Tmin);
  int back = !yFLag;
  int mask = ((!(xFlag^yFLag))<<31)>>31; 
  return (front&mask) | (back&(~mask));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /**
   * @brief 
   * each time we use x[high] | x[low];but we needn't to cut off x by mask
   * By using the first bit of the last result, we can verify whether x is 0
   */ 
  int x1 = x  | (x>>16);
  int x2 = x1 | (x1>>8);
  int x3 = x2 | (x2>>4);
  int x4 = x3 | (x3>>2);
  int x5 = x4 | (x4>>1);
  return (x5 & 1)^ 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /**
   * @brief 
   * for positive: each time we use higher half of x to decide if this part of x is non-zero
   * ans then we use the mask to decide if x need to be right-shifted and the value to be sumed into ans
   * for negative: we need to find the highest bit zero, so we can ~x
   */
  int flag = x & (1<<31);           // 100...0 / 000...0
  int mask = flag >> 31;            // 111...1 / 000...0      
  x =  (~x & mask) | (x & ~mask);   // x = flag? ~x: x
  int mask16 = (!!(x >> 16))<<4;
  x >>= mask16;
  int mask8 = (!!(x>>8))<<3;
  x >>= mask8;
  int mask4 = (!!(x>>4))<<2;
  x >>= mask4;
  int mask2 = (!!(x>>2))<<1;
  x >>= mask2;
  int mask1 = (!!(x>>1));
  x >>= mask1;
  int mask0 = x;
  return mask16 + mask8 + mask4 + mask2 + mask1 + mask0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /**
   * @brief 
   * float: [31] [30, 23] [22, 0] 
   */
  int fMask = 1 << 31;
  int flag = uf & fMask;
  int eMask = 0xff << 23;
  int exp  = uf & eMask;
  int rMask = ~(fMask | eMask);
  int frac = uf & rMask;
  if (exp == eMask)
  { // inf or NaN: return uf
    return uf;
  }
  if (!exp)
  { // denormal: M = frac; with no hidden 1 before frac head
    frac = frac << 1;
    if (frac & (1<<23))
    {
      exp += (1 << 23);
      frac = frac & rMask;
    }
  }
  else
  { // normal number
    exp += (1 << 23);
  }
  return flag | exp | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int fMask = 1 << 31;
  int flag = uf & fMask;
  int eMask = 0xff << 23;
  int exp  = uf & eMask;
  int rMask = ~(fMask | eMask);
  int frac = uf & rMask;
  if (exp == eMask)
  { // inf or NaN
    return 0x80000000u;
  }  
  exp = exp >> 23;
  if (exp < 127)
  { // in this case int(uf)=0
    return 0;
  }
  int ans = 1;
  int nMask = 1 << 22;
  int Tmin = 1 << 31;
  while (exp > 127)
  {
    ans = (ans << 1) + (frac & nMask);
    if (ans & Tmin)
    {
      return 0x80000000u;
    }
    frac <<= 1;
    exp -= 1;
  }
  if (flag)
  {
    ans = -ans;
  }
  return ans;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  /**
   * @brief 
   * use IEEE754 standard represent 2.0^x, that is 1.0*(2^x)  
   * To pass the test, need to use ./btest -T 20
   */
  if (x >= 128)
  { // too large to represent
    return 0xff << 23;
  }
  if (x >= -126)
  { // normal
    return (x+127) << 23;
  }
  if (x < -148)
  {
    return 0u;
  }
  
  // denormal: exp=000..0 E=-126
  return 1 << (23 + x + 126);
}
