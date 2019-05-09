/**
 *
 * \file   : ClasseEditable.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>
#include "ieditable.hpp"
#include "cstcoderr.h"
#include "cexception.h"

using namespace std;
using namespace nsUtil;


void contenu (const IEditable & ed) { cout << ed << endl; }
namespace {
    class CA : public IEditable
    {
    protected:
        virtual void display(ostream& os) const
        {
            os<<"classe CA"<<endl;
        }
    public:
        virtual ~CA() {}
    };

    class CB : public IEditable
    {
    protected:
        virtual void display(ostream& os) const
        {
            os<<"classe CB"<<endl;
        }
    public:
        virtual ~CB() {}
    };
}

namespace
{
void testClasse (void) {
    CA A;
    CB B;
    contenu(A);
    contenu(B);
}

} // namespace

int main (int argc, char * argv [])
{
    try
    {
        testClasse ();

        return KNoExc;
    }
    catch (const CException & e)
    {
        cerr << "Erreur        : " << e.getLibelle () << '\n'
             << "Code d'erreur = " << e.getCodErr ()  << '\n';
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()




