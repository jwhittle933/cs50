#include <cs50.h>
#include <stdio.h>

void render(int steps)
{
    string p = "########";
    string space = "        ";
    for (int i = 1; i <= steps; i++)
    {
        printf("%.*s", steps - i, space);
        printf("%.*s", i, p);
        printf("  ");
        printf("%.*s\n", i, p);
    }
}

int main(void)
{
    int steps;
    do {
        steps = get_int("Height: ");
    } while (steps < 0 || steps > 8);
    
    render(steps);
}

