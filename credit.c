#import <cs50.h>
#import <stdio.h>

void digits(int *buf, long int cc)
{
    int count = 0;
    long int prev_cc = cc;
    do {
        cc = prev_cc / 10;
        buf[count] = prev_cc % 10;
        prev_cc = cc; 
        count++;
    } while ( cc > 0 );
}

int multiply_and_sum_digits(int *buf)
{
    int count = 0;
    
    for (int i = 1; i < 16; i += 2)
    {
        if (buf[i] * 2 > 10)
        {
            int scratch[2];
            digits(scratch, (long int) buf[i] * 2);
            for (int j = 0; j < 2; j++) count += scratch[j];
        } else count += buf[i] * 2;
    }
    return count;
}

int sum_rest(int *buf) 
{
    int count = 0;
    for (int i = 0; i < 16; i += 2) count += buf[i];
    return count;
}

bool check_valid(int sum)
{
    if (sum % 2 == 0) return true;
    else return false;
}

int first_digit(long int cc)
{
    long int first = cc; 
    while (first >= 10)
    {
        first = first / 10;
    }
    return (int) first;
}

int main(void)
{
    long int cc = 0;
    do {
        cc = get_long("Number: "); 
    } while (cc == 0);
    
    // buffer[17] for max cc number of 16, plus 1
    int buffer[17];
    // fill buffer with cc digits
    digits(buffer, cc);

    // for(int i = 0; i < 16; i++) printf("%i ", buffer[i]);
    int sum = multiply_and_sum_digits(buffer) + sum_rest(buffer);
    
    if (!check_valid(sum)) printf("INVALID\n");
    
    if (first_digit(cc) == 3) printf("AMEX\n");   
    if (first_digit(cc) == 4) printf("VISA\n");
    if (first_digit(cc) == 5) printf("MASTERCARD\n");
    return 0;
}

