#ifndef __TBDCPROVIDER_H
#define __TBDCPROVIDER_H

#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fxcg/misc.h>
float math_floor(float x);
double math_modf(double x, double *ipart);

typedef struct {
  unsigned char hnibble:4;
  unsigned char lnibble:4;
} TBCDbyte;

typedef struct {
  unsigned short exponent:12;
  unsigned short mantissa0:4;
  TBCDbyte mantissa[7];
  char flags;
  short info;
} TBCDvalue;

typedef struct {
  int exponent;
  int sign;
  int unknown;
  char mantissa[15];
} TBCDInternal;
class TBCD {
  public:
    TBCDvalue*PValue();
    void Get(TBCDvalue &value);
    void Set(TBCDvalue &value);
    void Set(double &value);
    void Get(double &value);
    int SetError(int error);
    int GetError();
    void Swap();
  protected:
  private:
    TBCDvalue FValue[2];
};

#endif