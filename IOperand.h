#ifndef ioperand_h
    #define operand_h
        #include <string>
        #include <iostream>

        enum eOperandType {Int8, Int16, Int32, Float, Double};

        class IOperand {
            public:
                IOperand const * createOperand( eOperandType type, std::string const & value ) const;
                virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
                virtual eOperandType getType( void ) const = 0; // Type of the instance
                virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
                virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
                virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
                virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
                virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
                virtual std::string const & toString( void ) const = 0; // String representation of the instance
                virtual ~IOperand( void ) {}
        };

        class IOperand_Int8 : public IOperand {
            IOperand const * createInt8( std::string const & value ) const {
                return ;
            };
            public:
                int getPrecision( void ) const = 0; // Precision of the type of the instance
                eOperandType getType() {
                };
                IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
                IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
                IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
                IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
                IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
                std::string const & toString( void ) const = 0; // String representation of the instance
                // ~IOperand( void ) {}
        };

        class IOperand_Int16 : public IOperand {
            IOperand const * createInt16( std::string const & value ) const;
            public:
                int getPrecision( void ) const = 0; // Precision of the type of the instance
                eOperandType getType( void ) const = 0; // Type of the instance
                IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
                IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
                IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
                IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
                IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
                std::string const & toString( void ) const = 0; // String representation of the instance
                // ~IOperand( void ) {}
        };

        class IOperand_Int32 : public IOperand {
            IOperand const * createInt32( std::string const & value ) const;
            public:
                int getPrecision( void ) const = 0; // Precision of the type of the instance
                eOperandType getType( void ) const = 0; // Type of the instance
                IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
                IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
                IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
                IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
                IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
                std::string const & toString( void ) const = 0; // String representation of the instance
                // ~IOperand( void ) {}
        };

        class IOperand_Float : public IOperand {
            IOperand const * createFloat( std::string const & value ) const;
            public:
                int getPrecision( void ) const = 0; // Precision of the type of the instance
                eOperandType getType( void ) const = 0; // Type of the instance
                IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
                IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
                IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
                IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
                IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
                std::string const & toString( void ) const = 0; // String representation of the instance
                // ~IOperand( void ) {}
        };

        class IOperand_Double : public IOperand {
            IOperand const * createDouble( std::string const & value ) const;
            public:
                int getPrecision( void ) const = 0; // Precision of the type of the instance
                eOperandType getType( void ) const = 0; // Type of the instance
                IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
                IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
                IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
                IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
                IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
                std::string const & toString( void ) const = 0; // String representation of the instance
                // ~IOperand( void ) {}
        };

        IOperand const * IOperand::createOperand(eOperandType type, std::string const & value) const {
            void (*funcptr[])() = {};
        }
#endif