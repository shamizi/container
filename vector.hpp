/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:47 by shamizi           #+#    #+#             */
/*   Updated: 2023/03/10 16:29:37 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

//#include <deque>
//#include "stack.hpp"
#include <stdexcept>
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "ConstVectorIterator.hpp"
#include "VectorIterator.hpp"
#include "utils.hpp"




namespace ft {
	template <class T, class Allocator = std::allocator<T> >
		class vector 
		{
			public:
				// types:
				typedef T 						value_type;
				typedef Allocator 					allocator_type;
				typedef T& 			reference;
				typedef const T&		const_reference;
				typedef T* 			pointer;
				typedef const T* 		const_pointer;
				typedef typename ft::VectorIterator<value_type> 	iterator;
				typedef typename ft::ConstVectorIterator<value_type> 	const_iterator;
				typedef typename std::size_t 				size_type;
				typedef typename ft::reverse_iterator<iterator> 			reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
				typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;



				//constructeur destructeur
				explicit vector(const Allocator& alloc = Allocator()) :
					_alloc(alloc), _begin(NULL), _size(0), _capacity(0) 
			{};
				//fill constructor
				explicit vector(size_type n, const T& value = T(), const Allocator& alloc = Allocator()): _alloc(alloc)
			{
				//	std::cout << "vector fill constructor\n";
				_begin = _alloc.allocate(n);
				_size = n;
				_capacity = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_begin + i, value);
			};

				//range constructor
				template <class InputIterator>
				vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const Allocator& alloc = Allocator())
					{
						_alloc = alloc;
						_size = 0;
						for(InputIterator it = first; it != last; it++)
							_size++;
						_capacity = _size;
						_begin = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(_begin + i, *(first++));
						//		std::cout << "range constructor pas fini\n";
					};



				vector(const vector& x)
				{
					_alloc = x.get_allocator();
					_size = x.size();
					_capacity = x.size();
					//_begin = _alloc.allocate(x.size()); // ct capacity avant
					_begin = NULL;
					//for (size_type i = 0; i < x.size(); i++)
					//	_alloc.construct(_begin + i, x._begin[i]);
					if (x.size() > 0)
					{
						_begin = _alloc.allocate(_capacity);
						for (size_type i = 0; i < x.size(); i++)
							_alloc.construct(_begin + i, x._begin[i]);
					}
				};



				~vector() //penser a destroy puis deallocate alloc
				{
					for (size_t i = 0; i < _size; i++)
						_alloc.destroy(_begin + i);
					_alloc.deallocate(_begin, _capacity);
				//	std::cout << "vector destructor\n";
				};

				vector& operator=(const vector& x)
				{
					//vector tmp(x);
					//swap(tmp);
					//return *this;
					if (this != &x)
					{
						clear();
						assign(x.begin(), x.end());
					}
					return (*this);
				};


				////////////////////////////////
				template <class InputIterator>
					void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
					{
						size_type n = 0;
						for (InputIterator it = first; it != last; it++)
							n++;
						if (n > _capacity)
							reserve(n);
						for (size_type i = 0; i < _size; i++)
							_alloc.destroy(_begin + i);
						_size = 0;
						for (InputIterator it = first; it != last; it++)
							push_back(*it);
					};


				void assign(size_type n, const T& u)
				{
					if (n > _capacity)
						reserve(n);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_begin + i);
					_size = 0;
					for(size_type i = 0; i < n; i++)
						push_back(u);
				};



				////////////////////////////////////
				allocator_type get_allocator() const
				{
					return (_alloc);
				};



				//iterators:
				iterator begin()
				{
					return (iterator(_begin));
				};
				const_iterator begin() const
				{
					return (const_iterator(_begin));
				};
				iterator end()
				{
					return (iterator(_begin + _size));
				};
				const_iterator end() const
				{
					return (const_iterator(_begin + _size));
				};
				reverse_iterator rbegin()
				{
					return (reverse_iterator(_begin + _size));
				};
				const_reverse_iterator rbegin() const
				{
					return (const_reverse_iterator(_begin + _size));
				};
				reverse_iterator rend()
				{
					return (reverse_iterator(_begin));
				};
				const_reverse_iterator rend() const
				{
					return (const_reverse_iterator(_begin));
				};



				// 23.2.4.2 capacity:

				size_type size() const
				{
					return (this->_size);
				};

				size_type max_size() const
				{
					return (_alloc.max_size());
				};

				size_type capacity() const
				{
					return (this->_capacity);
				};

				void resize(size_type sz, value_type val = value_type())
				{
					if (sz < this->_size)
					{
						while (sz < this->_size)
						{
							_alloc.destroy(&_begin[_size -1]);
							_size--;
						}
					}
					else
					{
						if (_capacity == 0 || sz > 2 * _capacity)
							reserve(sz);
						else if (sz > this->_capacity)
							reserve(_capacity * 2);
						while (_size < sz)
						{
							_alloc.construct(_begin + _size, val);
							_size++;
						}
					}
				};

				//coder begin / end et les iterator pour pouvoir utiliser
				bool empty() const
				{
					return (begin() == end()); // si begin et end sont egaut il est donc vide
				};

				void reserve(size_type n)
				{
					if (n > max_size())
					{
						throw std::length_error("vector::reserve");
					}
					if (n <= this->_capacity) // <=
						return ;
					pointer tmp = _alloc.allocate(n);
					for(size_type i = 0; i < n; i++)
					{
						if (i < _size)
						{
							_alloc.construct(tmp + i, _begin[i]);
							_alloc.destroy(_begin + i);
						}
					}
					if (_capacity != 0)
						_alloc.deallocate(_begin, _capacity);
					_capacity = n;
					_begin = tmp;
				};



				// element access:
				reference operator[](size_type n)
				{
					return (_begin[n]);
				};
				const_reference operator[](size_type n) const
				{
					return (_begin[n]);
				};

				const_reference at(size_type n) const
				{
					if (n >= _size)
						throw std::out_of_range("vector::at");
					return (_begin[n]);
				};

				reference at(size_type n)
				{
					if (n >= _size)
						throw std::out_of_range("vector::at");
					return(_begin[n]);
				}; // throw exception out of range si n > size

				reference front()
				{
					return(*_begin);
				};
				const_reference front() const
				{
					return (*_begin);
				};
				reference back()
				{
					return (*(end() - 1));
				};
				const_reference back() const
				{
					return (*(end() - 1));
				};


				// 23.2.4.3 modifiers:
				void push_back(const T& x)
				{
					if (_capacity == 0)
						reserve(1);
					if (_size == _capacity)
						reserve(_capacity * 2); // x2 a la base
					get_allocator().construct(_begin + _size, x);
					_size++;
				};
				void pop_back()
				{
					//	if (_size == 0)
					//		return ;
					get_allocator().destroy(_begin + _size -1);
					_size--;
				};

				////////////////////
				iterator insert(iterator position, const T& x)
				{
					//crer un iterateur
					//verifier si size +1 > capacity
					//reserve en augmentant la taille si besoin
					// position - it == endroit ou on insert 
					//en partant de la fin du vector on peut _alloc.construct a la position n+1 et donc decaler
					// tout ce qui est apres notre insertion de 1 sans avoir besoin de variable tmp;
					//la position de notre insert sera donc vacant
					//construire a la position avec la valeur x;

					iterator it = begin();
					if (_size + 1 > _capacity)
					{
						if (_capacity == 0 || _capacity * 2 < _size + 1)
							reserve(_size + 1);
						else if (_size + 1 > _capacity)
							reserve(_capacity * 2);
					}
					size_type pos = position - it;
					for(size_type i = _size; i > pos; i--)
						_alloc.construct(_begin + i, _begin[i - 1]);
					_alloc.construct(&_begin[pos], x);
					_size++;
					return (begin() + pos); // iterator sur la position ou on a inserer
				};


				void insert(iterator position, size_type n, const T& x)
				{
					if (n <= 0)
						return ;
					iterator it = begin();
					if (_size + n > _capacity)
					{
						if (_capacity == 0 || _capacity * 2 <= _size + n)
							reserve(_size + n);
						else if (_size + n < _size * 2)
							reserve(_size * 2);
						else
							reserve(_capacity * 2);
					}
					size_type pos = position - it;
					size_type j = 1;
					for (size_type i = pos; i < _size; i++)
					{
						_alloc.construct(&_begin[_size + n - j], _begin[_size - j]);
						_alloc.destroy(&_begin[_size - j++]);
					}
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_begin[pos++], x);
					_size += n;
				};
				template <class InputIterator>
					void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
					{
						//eventuellement utiliser enable if + isintegral pour inputiteratorfirst 
						//aussi pour assign
						//meme chose qu'au dessus plus ou moins
						iterator it = begin();
						size_type n = std::distance(first, last);

						if (_size + n > _capacity)
						{
							if (_capacity == 0 || _capacity * 2 < _size + n)
								reserve(_size + n);
							else if (_size + n > _capacity)
								reserve (_capacity * 2);
						}

						size_type pos = position - it;
						size_type j = 1;
						for (size_type i = pos; i < _size; i++)
						{
							_alloc.construct(&_begin[_size + n - j], _begin[_size - j]);
							_alloc.destroy(&_begin[_size - j++]);
						}
						for (size_type i = 0; i < n; i++)
							_alloc.construct(&_begin[pos++], *(first++));
						_size += n;

					};
				/////////////////////////////////////////////////////

				iterator erase(iterator position)
				{
					size_type n = position - begin();
					_alloc.destroy(_begin + n);
					for(size_type i = n; i < _size - 1; i++)
						_alloc.construct(_begin + i, _begin[i + 1]);
					_size--;
					return(_begin + n);
				};
				iterator erase(iterator first, iterator last)
				{
					size_type n = last - first;
					for(size_t i = 0; i != n; i++)
						erase(first);
					return (first);
				};
				void swap(vector& x)
				{
					allocator_type	tmpalloc = _alloc;
					pointer		tmppointer = _begin;
					size_type	tmp_size = _size;
					size_type	tmp_capacity = _capacity;

					_alloc = x._alloc;
					_begin = x._begin;
					_size = x._size;
					_capacity = x._capacity;

					x._alloc = tmpalloc;
					x._begin = tmppointer;
					x._size = tmp_size;
					x._capacity = tmp_capacity;
				};
				void clear()
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_begin + i);
					_size = 0;
				};


				//copy paste les template juste en dessous en ajoutant friend
			protected:
				allocator_type	_alloc;
				pointer		_begin;
				size_type	_size;
				size_type	_capacity;

		}; //fin de classe template

	template <class T, class Allocator>
		bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
		{
			if (x.size() != y.size())
				return false;
			for (size_t i = 0; i < x.size(); i++)
				if (x[i] != y[i])
					return false;
			return true;
		};
	template <class T, class Allocator>
		bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
		{
			return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
		};
	template <class T, class Allocator>
		bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
		{
			return (!(x == y));
		};
	template <class T, class Allocator>
		bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
		{
			return (y < x);
		};
	template <class T, class Allocator>
		bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
		{
			return (!(x < y));
		};
	template <class T, class Allocator>
		bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
		{
			return (!(y < x));
		};
	// specialized algorithms:
	template <class T, class Allocator>
		void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
		{
			x.swap(y); //a tester
		};
};

#endif
