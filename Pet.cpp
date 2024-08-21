#include "Pet.h"

// Constructor to initialize the pet with a name and set initial hunger and happiness levels
Pet::Pet(std::string petName)
{
    name = petName;
    hunger = 50;    // Initial hunger level set to 50
    happiness = 50; // Initial happiness level set to 50
}

// Method to feed the pet, which increases its hunger level
void Pet::feed()
{
    if (hunger < 90)
    {
        hunger += 10; // Increase hunger by 10, but don't exceed 90
        std::cout << name << " has been fed." << std::endl;
    }
    else
    {
        std::cout << name << " is already full!" << std::endl;
    }
    decreaseLevels(); // After feeding, decrease both hunger and happiness slightly
}

// Method to play with the pet, which increases its happiness level
void Pet::play()
{
    if (happiness < 90)
    {
        happiness += 10; // Increase happiness by 10, but don't exceed 90
        std::cout << name << " is playing!" << std::endl;
    }
    else
    {
        std::cout << name << " is already too happy!" << std::endl;
    }
    decreaseLevels(); // After playing, decrease both hunger and happiness slightly
}

// Method to check and display the current hunger and happiness levels of the pet
void Pet::checkStatus() const
{
    std::cout << name << "'s hunger: " << hunger << std::endl;
    std::cout << name << "'s happiness: " << happiness << std::endl;
}

// Method to check if the pet is still alive
bool Pet::isAlive() const
{
    return hunger > 0 && happiness > 0; // The pet is alive if both hunger and happiness are above 0
}

// Private method to decrease both hunger and happiness levels slightly
void Pet::decreaseLevels()
{
    // Decrease hunger and happiness by 5 each time an action is taken
    hunger = (hunger > 5) ? hunger - 5 : 0;          // Ensure hunger doesn't go below 0
    happiness = (happiness > 5) ? happiness - 5 : 0; // Ensure happiness doesn't go below 0
}