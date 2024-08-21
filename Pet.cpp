#include "Pet.h"

// Constructor to initialize the pet with a name and set initial hunger and happiness levels
Pet::Pet(std::string petName)
{
    name = petName;
    hunger = 50;    // Initial hunger level set to 50
    happiness = 50; // Initial happiness level set to 50
}

// Method to feed the pet, which increases its hunger level and decreases its happiness slightly
void Pet::feed()
{
    if (hunger < 90)
    {
        hunger += 10; // Increase hunger by 10, ensuring it doesn't exceed 90
        std::cout << name << " has been fed." << std::endl;
    }
    else
    {
        std::cout << name << " is already full!" << std::endl;
    }
    decreaseLevels("happiness"); // Decrease happiness slightly after feeding
}

// Method to play with the pet, which increases its happiness level and decreases its hunger slightly
void Pet::play()
{
    if (happiness < 90)
    {
        happiness += 10; // Increase happiness by 10, ensuring it doesn't exceed 90
        std::cout << name << " is playing!" << std::endl;
    }
    else
    {
        std::cout << name << " is already too happy!" << std::endl;
    }
    decreaseLevels("hunger"); // Decrease hunger slightly after playing
}

// Method to check and display the current hunger and happiness levels of the pet
void Pet::checkStatus()
{
    std::cout << name << "'s hunger: " << hunger << std::endl;
    std::cout << name << "'s happiness: " << happiness << std::endl;
    decreaseLevels("both"); // Decrease both hunger and happiness slightly after checking status
}

// Method to check if the pet is still alive based on its hunger and happiness levels
bool Pet::isAlive() const
{
    return hunger > 0 && happiness > 0; // The pet is alive if both hunger and happiness are above 0
}

// Private method to decrease hunger and/or happiness levels slightly
void Pet::decreaseLevels(std::string state)
{
    int choice;
    if (state == "hunger")
    {
        choice = 0; // Decrease only hunger
    }
    else if (state == "happiness")
    {
        choice = 1; // Decrease only happiness
    }
    else
    {
        choice = 2; // Decrease both hunger and happiness
    }

    switch (choice)
    {
        case 0:
            // Decrease hunger by 5, ensuring it doesn't go below 0
            hunger = (hunger > 5) ? hunger - 5 : 0;
            break;
        case 1:
            // Decrease happiness by 5, ensuring it doesn't go below 0
            happiness = (happiness > 5) ? happiness - 5 : 0;
            break;
        default:
            // Decrease both hunger and happiness by 2, ensuring they don't go below 0
            hunger = (hunger > 2) ? hunger - 2 : 0;
            happiness = (happiness > 2) ? happiness - 2 : 0;
            break;
    }
}