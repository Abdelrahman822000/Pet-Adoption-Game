#include "Operations.h"

// Main function: Entry point of the program
int main() 
{
    // Initialize a pointer to a Pet object, set to nullptr (no pet is adopted at the start)
    Pet* myPet = nullptr;

    // Call the operations function, which handles all the user interactions
    operations(myPet);

    // Return 0 to indicate successful completion of the program
    return 0;
}