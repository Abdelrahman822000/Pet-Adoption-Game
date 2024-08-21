#include "Operations.h"

// Function definition for operations on a pet
void operations(Pet *myPet)
{
    int choice; // Variable to store user's choice

    std::cout << "Pet Adoption Game" << std::endl;
    // Infinite loop to continuously prompt the user for actions
    while (true)
    {
        // Displaying the game menu
        std::cout << "1. Adopt Pet" << std::endl;
        std::cout << "2. Feed Pet" << std::endl;
        std::cout << "3. Play with Pet" << std::endl;
        std::cout << "4. Check Status" << std::endl;
        std::cout << "5. End Game" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice; // Reading user's choice

        // Handling user choice using a switch statement
        switch (choice)
        {
            case 1:
                // Case 1: Adopt a pet
                if (myPet == nullptr) // Check if no pet is currently adopted
                {
                    std::string petName;
                    std::cout << "Enter the name of your pet: ";
                    std::cin >> petName;      // Get the name of the new pet
                    myPet = new Pet(petName); // Dynamically allocate a new Pet object
                    std::cout << "Congratulations! You adopted " << myPet->name << "!" << std::endl;
                }
                else
                {
                    std::cout << "You already have a pet." << std::endl;
                }
                break;

            case 2:
                // Case 2: Feed the pet
                if (myPet != nullptr) // Ensure a pet has been adopted
                {
                    myPet->feed(); // Call the feed method
                }
                else
                {
                    // Inform the user that they need to adopt a pet first
                    std::cout << "You need to adopt a pet first." << std::endl;
                }
                break;

            case 3:
                // Case 3: Play with the pet
                if (myPet != nullptr) // Ensure a pet has been adopted
                {
                    myPet->play(); // Call the play method
                }
                else
                {
                    // Inform the user that they need to adopt a pet first
                    std::cout << "You need to adopt a pet first." << std::endl;
                }
                break;

            case 4:
                // Case 4: Check the pet's status
                if (myPet != nullptr) // Ensure a pet has been adopted
                {
                    myPet->checkStatus(); // Call the checkStatus method
                }
                else
                {
                    // Inform the user that they need to adopt a pet first
                    std::cout << "You need to adopt a pet first." << std::endl;
                }
                break;

            case 5:
                // Case 5: End the game
                if (myPet != nullptr) // Ensure a pet has been adopted
                {
                    std::cout << "Game Over." << std::endl;
                    std::cout << myPet->name << "'s hunger: " << myPet->hunger << std::endl;
                    std::cout << myPet->name << "'s happiness: " << myPet->happiness << std::endl;
                }
                std::cout << "Thank you for playing!" << std::endl;
                delete myPet; // Clean up the dynamically allocated pet
                return;       // Exit the loop and function

            default:
                // Default case: Handle invalid input
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        // Check if the pet's condition is critical (hunger or happiness <= 0)
        if (myPet != nullptr && !myPet->isAlive())
        {
            std::cout << "Game Over. Your pet's condition has reached a critical level." << std::endl;
            std::cout << myPet->name << "'s hunger: " << myPet->hunger << std::endl;
            std::cout << myPet->name << "'s happiness: " << myPet->happiness << std::endl;
            delete myPet; // Clean up the dynamically allocated pet
            return;       // Exit the loop and function
        }
    }
}