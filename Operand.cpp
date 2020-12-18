#include "IOperand.h"

template<typename T>
class Operand : public IOperand {
    private:
        T _val;
        std::string _str;
        eOperandType _type;
    public:
        Operand<T>();
        Operand<T>(std::string const & value, eOperandType type) {
            std::stringstream ss;
            ss(value) >> _val;
            _str = str;
            _type = type;
        };
        Operand<T>( Operand const & obj ) {
            *this = obj;
        };
        int getPrecision( void ) const {
            int precision = 0;
            if( Int32 < _type ) {
                //floating point type, get the precision
                break;
            }
            return precision;
        };
        eOperandType getType( void ) const {
            return _type;
        };
        IOperand const * operator+( IOperand const & rhs ) const;
        IOperand const * operator-( IOperand const & rhs ) const;
        IOperand const * operator*( IOperand const & rhs ) const;
        IOperand const * operator/( IOperand const & rhs ) const;
        IOperand const * operator%( IOperand const & rhs ) const;
        std::string const & toString( void ) const;
};