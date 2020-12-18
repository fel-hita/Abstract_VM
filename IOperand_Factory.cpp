#include "IOperand.h"
#include "Operand.cpp"

class IOperand_Factory {
    private:
        IOperand const * createInt8( std::string const & value) const {
            return new Operand<int8_t>(value, Int8);
        };
        IOperand const * createInt16( std::string const & value ) const {
            return new Operand<int16_t>(value, value, Int16);
        };
        IOperand const * createInt32( std::string const & value ) const {
            return new Operand<int32_t>(value, value, Int32);
        };
        IOperand const * createFloat( std::string const & value ) const {
            return new Operand<float>(value, value, Float);
        };
        IOperand const * createDouble( std::string const & value ) const {
            return new Operand<double>(value, value, Double);
        };
    public:
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

IOperand const * IOperand_Factory::createOperand(eOperandType type, std::string const & value) const {
    // IOperand const * (IOperand_Factory::*funcArr[])( std::string const & ) const = { createInt8, createInt16, createInt32, createFloat, createDouble };
    typedef IOperand const * (IOperand_Factory::*funcPtr) ( std::string const & value) const;
    funcPtr funcArr[] = { createInt8, createInt16, createInt32, createFloat, createDouble };
    return (this->*funcArr[type])(value); // ->* // .* specifically to access function members with function pointers
}