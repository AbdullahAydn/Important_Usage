#include <stdio.h>

typedef struct my_val{
    unsigned short e:2;
    unsigned short d:2;
    unsigned short c:3;
    unsigned short b:4;
    unsigned short a:5;
}my_vals;

typedef union my_same_val{
    my_vals bits;
    unsigned short val;
}my_same_vals;

typedef struct my_val_r{
    unsigned short a:5;
    unsigned short b:4;
    unsigned short c:3;
    unsigned short d:2;
    unsigned short e:2;
}my_vals_revert;

typedef union my_same_val_r{
    my_vals_revert bits;
    unsigned short val;
}my_same_vals_revert;

void DecToBinary(unsigned short val)
{
   unsigned short k;
   unsigned short n = val;
   for (int c = 15; c >= 0; c--)
  {
        k = n >> c;
     
        if (k & 1)
          printf("1");
        else
          printf("0");
  }
 
  printf("\n");   
}

 

int main(void)
{
    my_same_vals        input;
    my_same_vals_revert output;
    
    scanf("%d",&input.val);

    output.bits.a = input.bits.a;
    output.bits.b = input.bits.b;
    output.bits.c = input.bits.c;
    output.bits.d = input.bits.d;
    output.bits.e = input.bits.e;

    printf("Input Val(Decimal) = %u\n",input.val);
    printf("Input Val(Binary) = ");
    DecToBinary(input.val);
    
    printf("Output Val(Decimal) = %u\n",output.val);
    printf("Output Val(Binary) = ");
    DecToBinary(output.val);
    
    return 0;
}