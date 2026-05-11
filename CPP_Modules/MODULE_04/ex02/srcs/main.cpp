/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:55 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 17:04:03 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	//std::cout << "----- Test 1: Basic Polymorphism -----\n";
    const AAnimal* a = new Dog();
    const AAnimal* b = new Cat();
	//const AAnimal* c = new AAnimal();  //This should not compile
	
    a->makeSound();
    b->makeSound();
    delete a;
    delete b;

    // std::cout << "\n\n\n----- Test 2: Array of AAnimals -----\n";
    // AAnimal* animals[10];
    // for (int i = 0; i < 5; ++i)
    //     animals[i] = new Dog();
    // for (int i = 5; i < 10; ++i)
    //     animals[i] = new Cat();

    // for (int i = 0; i < 10; ++i)
    //     animals[i]->makeSound();

    // for (int i = 0; i < 10; ++i)
    //     delete animals[i];

    // std::cout << "\n\n\n----- Test 3: Deep Copy (Copy Constructor) -----\n";
    // Dog dog1;
    // dog1.setIdea(0, "I want a bone");
    // dog1.setIdea(1, "I want to play");

    // Dog dog2(dog1); // Copy constructor
    // std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
    // std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;

    // dog2.setIdea(0, "I want a nap");
    // std::cout << "After changing dog2 idea[0]:\n";
    // std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
    // std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;

    // std::cout << "\n\n\n----- Test 4: Deep Copy (Assignment Operator) -----\n";
    // Dog dog3;
    // dog3 = dog1; // Assignment operator

    // std::cout << "dog1 idea[1]: " << dog1.getIdea(1) << std::endl;
    // std::cout << "dog3 idea[1]: " << dog3.getIdea(1) << std::endl;

    // dog3.setIdea(1, "I want to run");
    // std::cout << "After changing dog3 idea[1]:\n";
    // std::cout << "dog1 idea[1]: " << dog1.getIdea(1) << std::endl;
    // std::cout << "dog3 idea[1]: " << dog3.getIdea(1) << std::endl;

    // std::cout << "\n\n\n----- All tests complete -----\n";

    return 0;
}