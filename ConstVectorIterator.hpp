/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstVectorIterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:33:52 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/22 14:41:54 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTVECTORITERATOR_HPP
#define CONSTVECTORITERATOR_HPP
#include <iostream>
#include <iterator>
#include "iterator_traits.hpp"
#include "ConstVectorIterator.hpp"

namespace ft 
{
	template <class T>
	class VectorIterator;
	//vector iterator///////////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename T>
		class ConstVectorIterator
		{

			public:
				typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, const T> > traits;
				//typedef Iterator					iterator_type;
				typedef typename traits::iterator_category		iterator_category;
				typedef typename traits::value_type			value_type;
				typedef typename traits::difference_type		difference_type;
				typedef typename traits::reference			reference;
				typedef typename traits::pointer			pointer;


				ConstVectorIterator() : current() {};

				ConstVectorIterator (pointer x) : current(x){};

				ConstVectorIterator(const ConstVectorIterator &u) : current(u.current) {};

				ConstVectorIterator(const VectorIterator<T> &u) : current(u.current) {};

				~ConstVectorIterator(){};
			
				ConstVectorIterator operator=(const ConstVectorIterator& other)
				{
					if (*this != &other)
						current = other.current;
					return *this;
				};

				ConstVectorIterator operator=(const VectorIterator<T>& other)
				{
					current = other.current;
					return *this;
				};


				/////////////////////////////////////////////////////////////////////////////////////////
				reference operator*() const
				{
					return (*current);
				};

				pointer operator->()
				{
					return current;
				};
				pointer operator->() const
				{
					return current;
				};

				pointer operator&() const
				{
					return current;
				};


				ConstVectorIterator& operator++()
				{
					current++;
					return *this;
				};
				ConstVectorIterator operator++(int)
				{
					ConstVectorIterator tmp (*this);
					current++;
					return tmp;
				};
				ConstVectorIterator& operator--()
				{
					current--;
					return *this;
				};
				ConstVectorIterator operator--(int)
				{
					ConstVectorIterator tmp (*this);
					current--;
					return tmp;
				};
				////////////////////////////// les operator + et -
				ConstVectorIterator operator+ (difference_type n) const
				{
					ConstVectorIterator tmp(*this);
					tmp += n;
					return tmp;
				};
				friend ConstVectorIterator operator+ (difference_type n, const ConstVectorIterator &rhs)
				{
					return ConstVectorIterator(rhs + n);
				};

				ConstVectorIterator operator- (difference_type n)
				{
					ConstVectorIterator tmp(*this);
					tmp -= n;
					return tmp;
				};

				difference_type operator-(const ConstVectorIterator &rhs) const
				{
					return (current - rhs.current);
				};
				///////////////////////////////////////operator de comparaison

				bool operator<(const ConstVectorIterator &rhs) const
				{
					return (current < rhs.current);
				};
				bool operator>(const ConstVectorIterator &rhs) const
				{
					return (current > rhs.current);
				};
				bool operator<=(const ConstVectorIterator &rhs) const
				{
					return (current <= rhs.current);
				};
				bool operator>=(const ConstVectorIterator &rhs) const
				{
					return (current >= rhs.current);
				};
				bool operator==(const ConstVectorIterator &rhs) const
				{
					return (current == rhs.current);
				};
				bool operator!=(const ConstVectorIterator &rhs) const
				{
					return (current != rhs.current);
				};


				ConstVectorIterator& operator-= (difference_type n)
				{
					current -= n;
					return *this;
				};

				ConstVectorIterator& operator+= (difference_type n)
				{
					current += n;
					return *this;
				};

				reference operator[](difference_type n) const
				{
					return (current[n]);
				};

				/////////////////////////////////////////////

				bool operator<(const VectorIterator<T> &rhs) const
				{
					return (current < rhs.current);
				};
				bool operator>(const VectorIterator<T> &rhs) const
				{
					return (current > rhs.current);
				};
				bool operator<=(const VectorIterator<T> &rhs) const
				{
					return (current <= rhs.current);
				};
				bool operator>=(const VectorIterator<T> &rhs) const
				{
					return (current >= rhs.current);
				};
				bool operator==(const VectorIterator<T> &rhs) const
				{
					return (current == rhs.current);
				};
				bool operator!=(const VectorIterator<T> &rhs) const
				{
					return (current != rhs.current);
				};


				pointer							 current;
		}; // fin class ConstVectorIterator
};

#endif

