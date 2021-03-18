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
                IOperand_Int8( std::string const & value);
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
            private:
                int16_t op_val;
            public:
                IOperand_Int16( std::string const & value);
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
            private:
                int32_t op_val;
            public:
                IOperand_Int32( std::string const & value) {
                    op_val = std::stoi(value);
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
            private:
                float op_val;
            public:
                IOperand_Float( std::string const & value) {
                    op_val = std::stof(value);
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
            private:
                double op_val;
            public:
                IOperand_Double( std::string const & value);
                int getPrecision( void ) const;
                eOperandType getType( void ) const;
                IOperand const * operator+( IOperand const & rhs ) const;
                IOperand const * operator-( IOperand const & rhs ) const;
                IOperand const * operator*( IOperand const & rhs ) const;
                IOperand const * operator/( IOperand const & rhs ) const;
                IOperand const * operator%( IOperand const & rhs ) const;
                std::string const & toString( void ) const;
        };
#endif
