#include "../include/MutantStack.hpp"

int main()
{
	/*******MutantStack Test*******/
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Stack Elements" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // std::stack copy test
    std::stack<int> s(mstack);


	// /**************std::list Test**********/
	// /*to test std::list, uncomment next lines and comment previous*/
    // std::list<int> mstack; // MutantStack >>> std::list

    // mstack.push_back(5);  // push >>> push_back
    // mstack.push_back(17);

    // std::cout << "Top: " << mstack.back() << std::endl; // top >>> back

    // mstack.pop_back(); // pop >>> pop_back

    // std::cout << "Size: " << mstack.size() << std::endl;

    // mstack.push_back(3);
    // mstack.push_back(5);
    // mstack.push_back(737);
    // mstack.push_back(0);

    // std::list<int>::iterator it = mstack.begin();
    // std::list<int>::iterator ite = mstack.end();

    // ++it;
    // --it;

    // std::cout << "Stack Elements" << std::endl;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }

    return 0;
}
