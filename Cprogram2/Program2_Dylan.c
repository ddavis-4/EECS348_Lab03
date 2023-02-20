#include <stdio.h>

int nflscorecalculator(score)
{
    int touchdown = 6;
    int fieldgoal = 3;
    int safety = 2;
    int twopointconversion = 8; // Touch down + 2
    int extrapoint = 7;         // Touch down + 1

    for(int a = 0; a <= score / 8; ++a)
    {
        for(int b = 0; b <= (score - 8 * a) / 7; ++b)
        {
            for(int c = 0; c <= (score - 7 * a) / 6; ++c)
            {
                for(int d = 0; d <= (score - 6 * a) / 3; ++d)
                {
                    for(int e = 0; e <= (score - 3 * a) / 2; ++e)
                    {
                        if( a * 8 + b * 7 + c * 6 + d * 3 + e *2 == score)
                        {
                            printf("%d Touchdown + 2 point conversion, %d Touchdown + Extrapoint, %d Touchdown, %d Fieldgoal, %d safety\n", a,b,c,d,e);
                        } else{
                            continue;
                        }
                    }

                }
            }
        }
    }
}


int main()
{
    int var = 5;
    
    while (var > 1)
    {


        int score;

        printf("Enter 0 or 1 to STOP or Enter a NFL score: ");
        scanf("%d", &score);

        if (score <= 1)
        {
            var = score;
            break;
        } else
        {
            nflscorecalculator(score);
        } 
    }
    return 0;
}
