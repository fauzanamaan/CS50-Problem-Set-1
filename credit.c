#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long card_number;
    int digit_count = 0;
    int sum = 0;
    int first_digit = 0;
    int second_digit = 0;

    // Prompt for credit card number
    card_number = get_long("Number: ");

    // Calculate the checksum
    while (card_number > 0)
    {
        // Extract the last digit
        int digit = card_number % 10;

        if (digit_count % 2 == 0)
        {
            // Add the digit to the sum directly
            sum += digit;
        }
        else
        {
            // Multiply the digit by 2 and add the digits of the product to the sum
            int product = digit * 2;
            sum += (product % 10) + (product / 10);
        }

        // Store the first and second digits for later use
        second_digit = first_digit;
        first_digit = digit;

        // Remove the last digit from the number
        card_number /= 10;

        digit_count++;
    }

    // Check if the card number is valid
    if (sum % 10 == 0)
    {
        // Determine the type of the card
        if ((digit_count == 13 || digit_count == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else if (digit_count == 16 && first_digit == 5 && second_digit >= 1 && second_digit <= 5)
        {
            printf("MASTERCARD\n");
        }
        else if (digit_count == 15 && (first_digit == 3 && (second_digit == 4 || second_digit == 7)))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
