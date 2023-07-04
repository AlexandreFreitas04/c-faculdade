#include <stdio.h>

    int main() {
    char cpf[15];
    printf("Digite um CPF: ");
    scanf("%s", cpf);

    int validade = 0, tam = 0, formato = 1;
    int soma1 = 0, d1 = 0, soma2 = 0, d2 = 0;
    

    while (cpf[tam] != '\0') 
{
        tam++;
}

    for (int i = 0; cpf[i] != '\0'; i++) 
{
    if (cpf[i] < '0' || cpf[i] > '9') 
{
        formato = 0;
    break;
}
}

    if (formato == 0) 
{
        validade = 3;
}

    if ((tam == 11 && formato == 1) || (tam == 14 && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-')) 
{
    switch (tam) 
{
    case 11:
    for (int i = 0; i < 9; i++) 
{
        soma1 += (cpf[i] - '0') * (10 - i);
}
        d1 = (soma1 * 10) % 11;
    if (d1 == 10) 
{
        d1 = 0;
}
if (d1 == cpf[9] - '0') {
    for (int i = 0; i < 10; i++) 
{
        soma2 += (cpf[i] - '0') * (11 - i);
}
        d2 = (soma2 * 10) % 11;
    if (d2 == 10) 
{
        d2 = 0;
}
    if (d2 == cpf[10] - '0') {
        validade = 2;  
} 
    else 
{
        validade = 1;
}
} 
    else
{
        validade = 1;
}
    break;

    case 14:
    
    cpf [9] = cpf [12];
    cpf [10] = cpf [13];

    if (cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-' && !(d1 == cpf[12] - '0' || d2 == cpf[13] - '0')) 
{
        validade = 1;
} else if (cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-' && d1 == cpf[12] - '0' && d2 == cpf[13] - '0') 
{
        validade = 2;
} 
else 
{
        validade = 3;
}
    break;
    default:
        validade = 3;
    break;
}
}

if (validade == 1) 
{
        printf("O CPF está no formato permitido, mas é inválido.\n");
} 
else if (validade == 2) 
{
        printf("O CPF está no formato permitido e também é válido.\n");
} 
else if (validade == 3) 
{
        printf("O CPF não está no formato correto.\n");
}

return 0;
}
