#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

/* 
 *  instancie de facon aléatoire A,
 *  B ou C et retourne un pointeur de l’instance Base. Vous pouvez utiliser n’importe quelle
 *  fonction pour la generation aléatoire.
 */
 
Base *generate(void){

  	srand(time(NULL));
	unsigned int randomValue = rand() % 3;
    Base *ptr;

    if (randomValue == 0)
        ptr = new A();
    else if (randomValue == 1)
        ptr = new B();
    else
        ptr = new C();
    return ptr;
};

/* 
 * affiche "A", "B" ou "C" selon le type réel de p. 
 */

void identify(Base * p){

    std::cout << "type: ";
    A *a = dynamic_cast<A*>(p);
    if (a != NULL)
    {
        std::cout << "A\n";
        return ;
    }
    B *b = dynamic_cast<B*>(p);
    if (b != NULL)
    {
        std::cout << "B\n";
        return ;
    }
    C *c = dynamic_cast<C*>(p);
    if (c != NULL)
    {
        std::cout << "C\n";
        return ;
    }
};

/* 
 * affiche "A", "B" ou "C" selon le type réel de p.
 *Vous ne devez jamais utiliser un pointeur dans cette fonction 
 */

void identify( Base & p){
    
    std::cout << "type: ";
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A\n";
        delete &a;
        return ;
    }
    catch (std::exception &e){};
    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B\n";
        delete &b;
        return ;
    }
    catch (std::exception &e){};
    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C\n";
        delete &c;
        return ;
    }
    catch (std::exception &e){};
};

int main( void )
{
    Base *ptr = generate();
    Base &ref = *generate();
    identify(ptr);
    identify(ref);
    delete ptr;
    return 0;
}