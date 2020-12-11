#ifndef ioperand_h
    #define operand_h
        #include <string>
        #include <iostream>
        using funcPtr =  IOperand const * (IOperand_Factory::*)( std::string const & );

        enum eOperandType {Int8, Int16, Int32, Float, Double};

        class IOperand {
            public:
                virtual int getPrecision( void ) const; // Precision of the type of the instance
                virtual eOperandType getType( void ) const; // Type of the instance
                virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
                virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
                virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
                virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
                virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo
                virtual std::string const & toString( void ) const; // String representation of the instance
                virtual ~IOperand( void ) {}
        };

        class IOperand_Int8 : public IOperand {
            int8_t op_val;
            public:
                IOperand_Int8( std::string const & value) {
                    op_val = stoi(value);
                };
                int getPrecision( void ) const;
                eOperandType getType( void ) const;
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };

        class IOperand_Int16 : public IOperand {
            int16_t op_val;
            public:
                IOperand_Int16( std::string const & value) {
                    op_val = stoi(value);
                };
                int getPrecision( void ) const;
                eOperandType getType( void ) const;
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs );
                std::string const & toString( void ) const;
        };

        class IOperand_Int32 : public IOperand {
            int32_t op_val;
            public:
                IOperand_Int32( std::string const & value) {
                    op_val = stoi(value);
                };
                int getPrecision( void ) const;
                eOperandType getType( void ) const;
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };

        class IOperand_Float : public IOperand {
            float op_val;
            public:
                IOperand_Float( std::string const & value) {
                    op_val = stof(value);
                };
                int getPrecision( void ) const;
                eOperandType getType( void ) const;
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };

        class IOperand_Double : public IOperand {
            double op_val;
            public:
                IOperand_Double( std::string const & value) {
                    op_val = stod(value);
                };
                int getPrecision( void ) const;
                eOperandType getType( void ) const;
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };
        
        class IOperand_Factory {
            IOperand const * createInt8( std::string const & value) const {
                return new IOperand_Int8(value);
            };
            IOperand const * createInt16( std::string const & value ) const {
                return new IOperand_Int16(value);
            };
            IOperand const * createInt32( std::string const & value ) const {
                return new IOperand_Int32(value);
            };
            IOperand const * createFloat( std::string const & value ) const {
                return new IOperand_Float(value);
            };
            IOperand const * createDouble( std::string const & value ) const {
                return new IOperand_Double(value);
            };
            public:
                IOperand const * createOperand( eOperandType type, std::string const & value ) const;
        };

        IOperand const * IOperand_Factory::createOperand(eOperandType type, std::string const & value) const {
            IOperand const * (IOperand_Factory::*funcptr[])( std::string const &) const = { createInt8, createInt16, createInt32, createFloat, createDouble };
        }
#endif