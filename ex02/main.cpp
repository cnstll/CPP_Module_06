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

    static bool done = false;
    if (done == false) {
  	    std::srand(time(NULL));
        done = true;
    }
	unsigned int randomValue = std::rand() % 3;
    Base *ptr;

    if (randomValue == 0) {
        std::cout << "Generated class: " << "A\n";
        ptr = new A();
    }
    else if (randomValue == 1){
        std::cout << "Generated class: " << "B\n";
        ptr = new B();
    }
    else {
        std::cout << "Generated class: " << "C\n";
        ptr = new C();
    }
    return ptr;
};

/* 
 * affiche "A", "B" ou "C" selon le type réel de p. 
 */

void identify(Base * p){

    std::cout << ">> type identified: ";
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
    
    std::cout << ">> type identified: ";
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
    identify(ptr);
    std::cout << std::endl;
    Base &ref = *generate();
    identify(ref);
    delete ptr;
    return 0;
}