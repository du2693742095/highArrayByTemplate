#include "ptrType.hh"

template<typename _Type>
class ArrayItr
{
 public:
    using valueType = _Type;
    using pointer = valueType* ;
    using elemType = valueType::elemType;
    using elemPointer = elemType* ;

    using differenceType = typename valueType::differenceType;

    constexpr size_t dim = valueType::dim + 1;
    using dimSizeType = arraySize<dim - 1>;

public:
    ArrayItr() = default;

 private:
    valueType m_value;
    differenceType m_step;

};