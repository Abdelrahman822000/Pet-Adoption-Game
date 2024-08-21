#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>

// Pet class definition
class Pet 
{
    public:
        std::string name;  // Name of the pet
        int hunger;        // Pet's hunger level
        int happiness;     // Pet's happiness level

        // Constructor to initialize the pet's name and set initial hunger and happiness levels
        Pet(std::string petName);

        // Method to feed the pet, increasing its hunger level
        void feed();

        // Method to play with the pet, increasing its happiness level
        void play();

        // Method to check and display the pet's current hunger and happiness levels
        void checkStatus();

        // Method to check if the pet is still alive (hunger and happiness are above zero)
        bool isAlive() const;

    private:
        // Method to decrease both hunger and happiness levels
        void decreaseLevels(std::string state);
};

#endif