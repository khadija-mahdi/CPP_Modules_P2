#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    Base *ptr = NULL;
    int randomNum = std::rand() % 3;
    if (randomNum == 1)
        ptr = new A;
    else if (randomNum == 2)
        ptr = new B;
    else
        ptr = new C;
    return ptr;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "the actual type of the object pointed to by p: "
                  << "\"A\"" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "the actual type of the object pointed to by p: "
                  << "\"B\"" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "the actual type of the object pointed to by p: "
                  << "\"C\"" << std::endl;
    else
        throw("Cast Failed");
}

void identify(Base &p)
{
    try
    {
        identify(&p);
    }
    catch (char const *s)
    {
        std::cout << s << std::endl;
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(time(NULL)));
    {
        Base *Obj = generate();
        identify(Obj);
        delete Obj;
    }
    {
        Base *Obj = generate();
        Base &ref = *Obj;
        try
        {
            identify(ref);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        delete Obj;
    }
    {
        Base *Obj = generate();
        Base &ref = *Obj;
        identify(ref);
        delete Obj;
    }
}
