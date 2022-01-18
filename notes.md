# CPP Module 06
This module revolves around type conversion.

## Definitions Implicit Promotions

Data types determine how an object will be stored in memory and how the compiler should interpret the data stored in bits. Similar values may have completely different data storage:
    - 3 stored as an integer: 0000 0000 0000 0000 0000 0000 0011
    - 3.0 stored as a float: 0100 0000 0100 0000 0000 0000 0000 0000
The number of bits used by a data type is calles its width.
* implicit type conversion: the compiler will automatically convert from the supplied data type of a variable to the required data type, when different. Implicit conversion might be disallowed by the compiler if it ends up in data loss.
* Numeric promotions: numeric promotion is the conversion from a narrow data type to a wider data type. From char to int for example. 2 advantages: narrow type can be processed more efficiently by the CPU / less overflow prone. Numeric promotion is safe from data loss.
* Numeric conversions: numeric conversions cover all conversions that are not numeric promotions. You can have demotion which can result in data loss (float to int) and may throw compiler warning. In this case, '''static_cast''' should be used.
* Arithmetic conversions: arithmetic, relational and bitwise arithmetic operations require their operands to be of the same type. The compiler will prioritize certain wider types over other and may promote both operands if required. The priorization hierarchy might cause issue when mixing signed and unsigned values. For example, substracting (5u - 10) will not be result in -5 but in 4294967291. Unsigned int has higher priority over int, thus int is converted to unsigned int.

## Definitions Explicit Promotions
* static casts: convert a value of one type to the value of another type. Static cast enables compile-time checks y the compiler and constness cannot be removed from a var. Static cast can be used for narrowing conversion.
`static_cast<new_type> var_to_convert`
* const casts: this cast is used to remove constness from a value.
`const_cast<new_type> var_to_convert`
* dynamic casts: this cast is used for converting a base-class pointer into a derived-class pointer (downcasting). Dynamic cast requires a virtual table which enables Run-Time Information (RTTI), hence the base class should have a virtual function. In case of downcasting, dynamic cast is usually a better choice than static cast.
`dynamic_cast<new_type*>(pointer_to_class_to_convert)` (return null in case of failure) 
`dynamic_cast<new_type&>(pointer_to_class_to_convert)` (throw std::bad_cast in case of failure) 
* reinterpret casts
`reinterpret_cast<new_type> var_to_convert`

[On floats](https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html)