main()
{
    int var0[5], i;
    for(i = 0; i < 5; i++)
    {
        printf("Digite o valor da posicao %d: ",i+1);
        scanf("%d",&var0[i]);
    }
    for(i = 0; i < 5; i++)
        printf("Posicao %d: %d\n",i+1,var0[i]);
    system("pause");
}
