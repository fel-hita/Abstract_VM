#ifndef ioperand_h
    #define operand_h
        #include <string>
        #include <iostream>

        enum eOperandType {Int8, Int16, Int32, Float, Double};

        class IOperand {
            public:
                virtual int getPrecision( void ) const; // 0 of the type of the instance
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
            private:
                int8_t op_val;
            public:
                IOperand_Int8( std::string const & value) {
                    op_val = stoi(value);
                };
                int getPrecision( void ) const {
                    int8_t x = abs(x);  
                    return (x < 10 ? 1 :   
                        (x < 100 ? 2 :   
                        3));  
                };
                eOperandType getType( void ) const {
                    return Int8;
                };
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };

        class IOperand_Int16 : public IOperand {
            private:
                int16_t op_val;
            public:
                IOperand_Int16( std::string const & value) {
                    op_val = stoi(value);
                };
                int getPrecision( void ) const {
                    int16_t x = abs(x);  
                    return (x < 10 ? 1 :   
                        (x < 100 ? 2 :   
                        (x < 1000 ? 3 :   
                        (x < 10000 ? 4 :   
                        5))));  
                };
                eOperandType getType( void ) const {
                    return Int16;
                };
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs );
                std::string const & toString( void ) const;
        };

        class IOperand_Int32 : public IOperand {
            private:
                int32_t op_val;
            public:
                IOperand_Int32( std::string const & value) {
                    op_val = stoi(value);
                };
                int getPrecision( void ) const {
                    int32_t x = abs(x);  
                    return (x < 10 ? 1 :   
                        (x < 100 ? 2 :   
                        (x < 1000 ? 3 :   
                        (x < 10000 ? 4 :   
                        (x < 100000 ? 5 :   
                        (x < 1000000 ? 6 :   
                        (x < 10000000 ? 7 :  
                        (x < 100000000 ? 8 :  
                        (x < 1000000000 ? 9 :  
                        10)))))))));  
                };
                eOperandType getType( void ) const {
                    return Int32;
                };
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };

        class IOperand_Float : public IOperand {
            private:
                float op_val;
            public:
                IOperand_Float( std::string const & value) {
                    op_val = stof(value);
                };
                int getPrecision( void ) const {
                    return 0;
                };
                eOperandType getType( void ) const {
                    return Float;
                };
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };

        class IOperand_Double : public IOperand {
            private:
                double op_val;
            public:
                IOperand_Double( std::string const & value) {
                    op_val = stod(value);
                };
                int getPrecision( void ) const {
                    return 0;
                };
                eOperandType getType( void ) const {
                    return Double;
                };
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };
        
        class IOperand_Factory {
            private:
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
            // IOperand const * (IOperand_Factory::*funcArr[])( std::string const & ) const = { createInt8, createInt16, createInt32, createFloat, createDouble };
            typedef IOperand const * (IOperand_Factory::*funcPtr) ( std::string const & value) const;
            funcPtr funcArr[] = { createInt8, createInt16, createInt32, createFloat, createDouble };
            return (this->*funcArr[type])(value); // ->* // .* specifically to access function members with function pointers
        }
#endif