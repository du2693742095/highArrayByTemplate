#include <array>

template<size_t _Sz>
using arraySize = std::array<size_t,_Sz>;

template<typename _Elem>
class ArrayItr;

template<typename _Elem>
class HighVecPtr;

template<typename _Elem, size_t _Dim>
struct _HighVecTraits
{
	using type = HighVecPtr<
		typename _HighVecTraits<_Elem, _Dim - 1>::type>;
};

template<typename _Elem>
struct _HighVecTraits<_Elem, 1>
{
	using type = ArrayItr<_Elem>;
};

template<typename _Elem>
struct _HighVecTraits<_Elem, 0>
{
	using type = _Elem;
};