#ifndef IEDITABLE_HPP
#define IEDITABLE_HPP
#include <ostream>

using namespace std;

namespace nsUtil {

    class IEditable {
    protected:
        virtual void display(ostream& os) const = 0;

    public:
        virtual ~IEditable() {}
        friend ostream & operator << (ostream & os, const IEditable & obj);
    };

    inline ostream & operator << (ostream & os, const IEditable & editable)
    {
        editable.display (os);
        return os;

    } // operator <<()
}

#endif // IEDITABLE_HPP
