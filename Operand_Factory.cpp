#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP


# include "eOperandType.hpp"
# include "IOperand.hpp"
# include "../src/OperandExceptions.cpp"
# include <limits>
# include <iostream>
# include <array>


class OperandFactory {
public:
	OperandFactory();
	virtual ~OperandFactory() = default;

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

    typedef IOperand const *(OperandFactory::*ftAddrCreate) (std::string const & value) const;

private:

	std::array<ftAddrCreate , 5> _creator;

	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	OperandFactory(OperandFactory const &src) = default;
	OperandFactory &operator=(OperandFactory const &rhs) = default; //equals
};

#endif
