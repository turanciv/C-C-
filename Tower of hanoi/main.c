#include <stdio.h>
void towers(int,char,char,char);

int main()
{
    int num;


    printf("Wähle die Anzahl von Scheibe: ");
    scanf("%d",&num);
    printf("Die Anzahl an bewegten Scheiben ist:\n");
    towers(num,'A','B','C');
    return 0;
}

void towers(int num, char vonTurm, char zuTurm, char auxTurm)
{
    if(num == 1)
    {
        printf("\n Bewege Scheibe 1 von Turm %c zu Turm %c",vonTurm,zuTurm);
        return;
    }
    towers(num - 1,vonTurm,auxTurm,zuTurm);
    printf("\n Scheibe %d geht von Turm %c zu Turm %c", num, vonTurm, zuTurm);
    towers(num - 1,auxTurm,zuTurm,vonTurm);
    printf("\n Anzahl Zuege: %d",num);
}
