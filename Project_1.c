//Project name- Game(Snack Water Gun, Guess the number)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menu()
{
    int choice;

    printf("\n\n|What Game do you want to Play|\n\n");
    printf(" 1.Snake_Water_Gun\n");
    printf(" 2.Guess the number\n");
    scanf("%d", &choice);
    return (choice);
}
int snackwatergun(char you, char comp)
{
    
    if (you == comp)
    {
        return 0;
    }
    else if (you == 's' && comp == 'w') 
    {
        return 1;
    }
    else if (you == 'w' && comp == 's') 
    {
        return -1;
    }
    else if (you == 'g' && comp == 's') 
    {
        return 1;
    }
    else if (you == 's' && comp == 'g') 
    {
        return -1;
    }
    else if (you == 'w' && comp == 'g') 
    {
        return 1;
    }
    else if (you == 'g' && comp == 'w') 
    {
        return -1;
    }
}

int main()
{
    int number, result, n, nguesses = 1;
    char you, comp;

    srand(time(0));
    number = rand() % 100 + 1;
   // printf("%d\n", number);

    switch (menu())
    {
    case 1:
        
        if (number < 33)
        {
            comp = 's';
        }
        else if (number > 33 && number < 66)
        {
            comp = 'w';
        }
        else
        {
            comp = 'g';
        }
        printf("Enter 's' for Snack, 'w' for Water and 'g' for Gun\n");
        fflush(stdin);
        scanf("%c", &you);
    
        result = snackwatergun(you, comp);
        if (result == 0)
        {
            printf("\t  Match Draw\n");
        }
        else if (result == 1)
        {
            printf("\n\t  You Win!\n");
        }
        else
        {
            printf("\n\t  You Loss!\n");
        }
        printf("You choice %c and Computer choice %c\n", you, comp);
        printf("\t -Thank You-\n\n\n");
        break;

    case 2:
        //Guess the number
        do
        {
            printf("Guess the number between 1 to 100\n");
            scanf("%d", &n);
            if (n < number)
            {
                printf("Higher number Please!\n");
            }
            else if (n > number)
            {
                printf("Lower number Please!\n");
            }
            else
            {
                printf("You Guessed it in %d attempts\n", nguesses);
                printf("\t-Thank You-\n\n\n");
            }
            nguesses++;
        } while (n != number);

        break;

    default:
        printf("Invalid Attempt\n\n");
    }

    return 0;
}