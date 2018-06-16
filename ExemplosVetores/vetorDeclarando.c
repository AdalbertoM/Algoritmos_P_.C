#include<stdio.h>


main()
{
    int var0[5] = {5,-8,3,0,-2};
    printf("%d, %d, %d, %d , %d\n",var0[0], var0[1], var0[2], var0[3], var0[4]);
    system("pause");
    var0[2] = 10;
    printf("%d, %d, %d, %d , %d\n",var0[0], var0[1], var0[2], var0[3], var0[4]);
    system("pause");

}
