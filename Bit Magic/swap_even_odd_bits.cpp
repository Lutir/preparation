Input = 23
Output = 43
Swap all odd bits with even bits

Algo:
  Odd Bits = num&(10101010)
  Even Bits = num&(010101010)
  right shift odd bits
  left shift even bits
  Add them (Or Operator)
  
Code:
  int swap(int a){
    return (((a&170)>>1)|((a&85)<<1));
}
