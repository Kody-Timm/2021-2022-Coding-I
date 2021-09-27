#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    long cardNumber;
    long cardNumbercopy;
    int totalSum = 0, position = 0, cardLength = 0;
    do
    {
        //Prompt user for credit card number
        cardNumber = get_long("Credit Card Number: ");
        cardNumbercopy = cardNumber;

        //Run Luhn algorithm
        while (cardNumber != 0)
        {
            //Checks odd numbers
            if (position % 2 != 0)
            {
                //Splits double digit numbers and adds them
                int temp = 2 * (cardNumber % 10);
                if (temp > 9)
                {
                    totalSum = totalSum + temp % 10 + temp /10;
                }
                else
                {
                    totalSum = totalSum + temp;
                }
            }

            //Checks even numbers
            else
            {
                totalSum = totalSum + cardNumber % 10;
            }
            cardNumber = cardNumber / 10;
            position++;
            cardLength++;
        }
    }
    while (cardNumber > 0);

    //Check if the sum is valid
    if (totalSum % 10 == 0)
    {
        //Checks if card number is American Express
        long amex_digits = cardNumbercopy/10000000000000;
        if ((amex_digits == 34 || amex_digits == 37) && cardLength == 15)
        {
            printf("AMEX\n");
            return 0;
        }
        //Checks if card number is MasterCard
        long mastercard_digits = cardNumbercopy/100000000000000;
        if ((cardLength == 16) && (mastercard_digits >= 51 && mastercard_digits <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        //Checks if card number is Visa
        long visa_digits = cardNumbercopy/100000000000;
        if ((cardLength == 16 || cardLength == 13) && (visa_digits == 4 || mastercard_digits / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }
        printf("Invalid!\n");
    }
    else
    {
        printf("Invalid!\n");
    }
}