#include <cstdio>
#include <array>

	template<size_t _Sz>
	using tensor_size = std::array<size_t,_Sz>;

	template<typename _Ts>
	class array_iterator
    {
    public:
      	using value_type = _Ts;
		using pointer = value_type*;
		using reference = value_type&;
		using difference_type = typename value_type::difference_type;
		using const_self = array_iterator<typename value_type::const_self>;
		using normal_self = array_iterator<typename value_type::normal_self>;
		using elm_type = typename value_type::elm_type;
		using elm_pointer = elm_type*;

		static constexpr size_t dim = value_type::dim + 1;
		using deep_size_type = tensor_size<dim - 1>;

    private:
            value_type _value;
            difference_type _step = 0;

    public:


    };

	template<typename _Elm>
	class array_ptr
	{
	public:
		using normal_elm_type = typename std::remove_const<_Elm>::type;
		using normal_self = array_ptr<normal_elm_type>;
		using const_self = array_ptr<const _Elm>;

		using array_type = array_ptr;
		using size_type = size_t;
		using elm_type = _Elm;
		using elm_pointer = elm_type *;
		using value_type = _Elm;
		using pointer = value_type * ;
		using reference = value_type & ;
		using iterator = pointer;
		using reverse_iterator = std::reverse_iterator<iterator>;
      
      	using difference_type = size_t;

		static constexpr unsigned int dim = 1;
    };

	template<typename _Base>
	class base_tensor_ptr
    {
      public:
		using value_type = _Base;

		using normal_self = base_tensor_ptr<typename value_type::normal_self>;
		using const_self = base_tensor_ptr<typename value_type::const_self>;

		using elm_type = typename value_type::elm_type;
		using elm_pointer = elm_type*;

		using array_type = typename value_type::array_type;

		using size_type = typename value_type::size_type;
		//using reference = value_type & ;
		//using pointer = value_type * ;
		using difference_type = typename value_type::difference_type;

		using iterator = array_iterator<value_type>;
		using const_iterator = array_iterator<typename value_type::const_self>;

		static constexpr size_t dim = value_type::dim + 1;

		using deep_size_type = tensor_size<dim>;

        private:
        
            iterator _pointer;
            size_t _size = 0;
        public:
        	base_tensor_ptr(elm_pointer _elm, deep_size_type _size) :
                _pointer(value_type(_elm, sub_size(_size))),
                _size(_size[0]) {}

            const iterator& begin() const
            {
                return _pointer;
            }

            value_type at(size_t i) const
            {
                return *(begin() + (difference_type)i);
            }

            value_type operator[](size_t i) const
            {
                return at(i);
            }

    };

	template<typename _Elm, size_t _Dim>
	struct _tensor_traits
	{
		using type = base_tensor_ptr<
			typename _tensor_traits<_Elm, _Dim - 1>::type>;
	};

	template<typename _Elm>
	struct _tensor_traits<_Elm, 1>
	{
		using type = array_ptr<_Elm>;
	};

	template<typename _Elm>
	struct _tensor_traits<_Elm, 0>
	{
		using type = _Elm;
	};

	template<typename _Elm, size_t _Dim>
	using tensor_ptr = typename _tensor_traits<_Elm, _Dim>::type;
