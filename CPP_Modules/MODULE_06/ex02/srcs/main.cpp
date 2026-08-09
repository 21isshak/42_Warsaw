#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/Base.hpp"
#include "../include/C.hpp"


Base* generate()
{
	int i = std::rand() % 3;

	if (i == 0)
	{
		std::cout << "A was randomly generated" << std::endl;
		return new A();
	}
	else if (i == 1)
	{
		std::cout << "B was randomly generated" << std::endl;
		return new B();
	}
	else if (i == 2)
	{
		std::cout << "C was randomly generated" << std::endl;
		return new C();
	}
	else
		return NULL;
}

void identify(Base* p)
{
	std::cout << "Identify by pointer:" << std::endl;
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Actual type is: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Actual type is: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Actual type is: C" << std::endl;
	else
		std::cerr << "bad cast" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Identify by reference:" << std::endl;
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Actual type is: A" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		//A and B exceptions catch block should be empty, because if 'C' object is created
		//in their try block because of dynamic_cast<A&> and dynamic_cast<B&>(p)
		//they will throw exception and catch block will take it
		//if it is empty it will be just catched and swallowed to contuniue
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Actual type is: B" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Actual type is: C" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Actual type is unknown or bad cast!" << std::endl;
	}
}


int main()
{
    // Random üretimi başlatıyoruz
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "***TEST 1: RANDOM OBJECT CREATION***" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "\n[Try " << (i + 1) << "]" << std::endl;
        
        //random creation
        Base* basePtr = generate();

        if (basePtr != NULL)
        {
            //test the object with pointer
            identify(basePtr);

            //test the same object with referance
            identify(*basePtr);

            delete basePtr;
        }
    }

    std::cout << "\n***TEST 2: NULL POINTER AND INVALID REFERANCE TEST***" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
	//Edge case for pointer: NULL pointer
    Base* nullPtr = NULL;
    identify(nullPtr); // "bad cast" should be printed

	//Edge case for referance: A Base object that has no A, B or C
	Base rawBaseObj;
    identify(rawBaseObj); //All exceptions should be thrown
						  //and "Actual type is unknown or bad cast!" should be printed

    return 0;
}