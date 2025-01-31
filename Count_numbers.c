#include <stdio.h>

int main() {
    int number, count = 0, amp;
    
    printf("Enter a number (2 to 7 digits): ");
    scanf("%d", &number);
    
    
    amp = number;
    while (amp != 0) {
        amp /= 10; 
        count++; 
    }
    
    if (count < 2 || count > 7) {
        printf("Invalid input! Please enter a number with 2 to 7 digits.\n");
    } else {
        printf("The number %d has %d digits.\n", number, count);
        
        
        if (number % 2 == 0) {
            printf("The number of digits is even.\n");
        } else {
            printf("The number of digits is odd.\n");
        }
    }
    
    return 0;
}
