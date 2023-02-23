/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:47 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/23 17:27:27 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <deque>
#include "stack.hpp"
#include <stdexcept>
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "ConstVectorIterator.hpp"
#include "VectorIterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
		class vector 
		{
			public:
				// types:
				typedef T 						value_type;//
				typedef Allocator 					allocator_type;//
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
			{
				std::cout << "construction basique d'un vector\n";
			};
				//fill constructor
				explicit vector(size_type n, const T& value = T(), const Allocator& alloc = Allocator()): _alloc(alloc)
			{
				std::cout << "vector fill constructor\n";
				_begin = _alloc.allocate(n);
				_size = n;
				_capacity = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_begin + i, value);
			};

				//range constructor
				template <class InputIterator>
					vector(InputIterator first, InputIterator last, const Allocator& = Allocator())
					{
						(void)first;
						(void)last;
						std::cout << "range constructor pas fini\n";
						//a remplit
					};



				//copy constructor : //faux parce que j'alloc pas _begin
				vector(const vector& x)
				{
					_alloc = x._alloc;
					_begin = x._begin;
					_size = x._size;
					_capacity = x._capacity;
				};



				~vector() //penser a destroy puis deallocate alloc
				{
					std::cout << "vector destructor\n";
				};

				/////////////////////////////////////////////////////////////////////////////////////////
				vector& operator=(const vector& x)
				{
					vector tmp(x);
					swap(tmp);
					return *this;
				};


				////////////////////////////////
				/*				
								template <class InputIterator>
								void assign(InputIterator first, InputIterator last)
								{
								erase(begin(), end());
								insert(begin(), first, last);
								};
								void assign(size_type n, const T& u);*/

				allocator_type get_allocator() const
				{
					return (_alloc);
				};



				//iterators:
				iterator begin()
				{
					return ((iterator)_begin);
				};
				const_iterator begin() const
				{
					return ((const_iterator)_begin);
				};
				iterator end()
				{
					return ((iterator)(_begin + _size));
				};
				const_iterator end() const
				{
					return ((const_iterator)(_begin + _size));
				};
				reverse_iterator rbegin()
				{
					return ((reverse_iterator)(_begin + _size));
				};
				const_reverse_iterator rbegin() const
				{
					return ((const_reverse_iterator)(_begin + _size));
				};
				reverse_iterator rend()
				{
					return ((reverse_iterator)_begin);
				};
				const_reverse_iterator rend() const
				{
					return ((const_reverse_iterator)_begin);
				};



				// 23.2.4.2 capacity:

				size_type size() const
				{
					return (this->_capacity);
				};

				size_type max_size() const
				{
					return (_alloc.max_size());
				};

				void resize(size_type sz, value_type val = value_type())
				{
					std::cout << "in resize fct" << std::endl;
					std::cout << "before capacity print " << this->_capacity <<std::endl;
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
						if (sz > this->_capacity)
							reserve(sz * 2);
						while (_size < sz)
						{
							_alloc.construct(_begin + _size, val);
							_size++;
						}
					}
				};

				//size_type capacity() const
				//{
				//	return (this->_capacity);
				//};

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
						std::cout << "je dois mettre une exception" << std::endl;
						return ;
					}
					if (n <= this->_capacity)
						return ;
					pointer tmp = _alloc.allocate(n);
					for(size_type i = 0; i < _size; i++)
						_alloc.construct(tmp + i, _begin[i]); //besoin du copy constructeur

					for(size_type i = 0; i < _size; i++)
						_alloc.destroy(_begin + i);
					_alloc.deallocate(_begin, _size);
					_begin = tmp;
					_capacity = n;
				};



				// element access:
				reference operator[](size_type n)
				{
					return (_begin[n]);
				}; //return reference to requested element
				const_reference operator[](size_type n) const
				{
					return (_begin[n]);
				};
				const_reference at(size_type n) const
				{
					if (n > _size)
						throw std::out_of_range("vector::at");
					return (_begin[n]);
				};
				reference at(size_type n)
				{
					if (n > _size)
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
					return (*(end() - 1));










				// 23.2.4.3 modifiers:
				void push_back(const T& x)
				{

				};
				  //void pop_back();
				  //iterator insert(iterator position, const T& x);
				  //void insert(iterator position, size_type n, const T& x);
				  //template <class InputIterator>
				 // void insert(iterator position,
				 // InputIterator first, InputIterator last);
				 // iterator erase(iterator position);
				  //iterator erase(iterator first, iterator last);
				  //void swap(vector<T,Allocator>&);
				 // void clear();
				 

				//copy paste les template juste en dessous en ajoutant friend
			protected:
				allocator_type	_alloc;
				pointer		_begin;
				size_type	_size;
				size_type	_capacity;

		}; //fin de classe template

	template <class T, class Allocator>
		bool operator==(const vector<T,Allocator>& x,
				const vector<T,Allocator>& y);
	template <class T, class Allocator>
		bool operator< (const vector<T,Allocator>& x,
				const vector<T,Allocator>& y);
	template <class T, class Allocator>
		bool operator!=(const vector<T,Allocator>& x,
				const vector<T,Allocator>& y);
	template <class T, class Allocator>
		bool operator> (const vector<T,Allocator>& x,
				const vector<T,Allocator>& y);
	template <class T, class Allocator>
		bool operator>=(const vector<T,Allocator>& x,
				const vector<T,Allocator>& y);
	template <class T, class Allocator>
		bool operator<=(const vector<T,Allocator>& x,
				const vector<T,Allocator>& y);
	// specialized algorithms:
	template <class T, class Allocator>
		void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
		{
			x.swap(y); //a tester
		};
}

#endif
