#include "ArrayItr.hh"

template<size_t _Sz>
inline arraySize<_Sz - 1>& sub_size(arraySize<_Sz>& sz)
{
	static_assert(_Sz > 1, "size too small!");
	return static<arraySize<_Sz - 1>>(sz[1]);
}
template<size_t _Sz>
inline const arraySize<_Sz - 1>& sub_size(const arraySize<_Sz>& sz)
{
	static_assert(_Sz > 1, "size too small!");
	return static<arraySize<_Sz - 1>>(sz[1]);
}

template<typename _Type>
class HighVecPtr
{
public:
    using valueType = _Type;
    using elemType = valueType::elemType;
    using elemPointer = elemType*;

    using differenceType = typename valueType::differenceType;

    using iterator = array<valueType>;

    constexpr size_t dim = valueType::dim + 1;
    using dimSizeType = arraySize<dim>;

public:
    HighVecPtr() = default;

    HighVecPtr(elemPointer elem, dimSizeType& size):
        m_pointer(valueType(elem, subSize(size))),
        m_myDimSize(size[0])
    {}


private:
    iterator m_pointer; //下一维指针
    size_t m_myDimSize; //本维长度

};