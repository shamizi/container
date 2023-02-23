/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:33:52 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/22 14:43:42 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP
#include <iostream>
#include <iterator>
#include "iterator_traits.hpp"
#include "ConstVectorIterator.hpp"

namespace ft 
{
	//vector iterator///////////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename T>
		class VectorIterator
		{

			public:
				typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, T> > traits;
				//typedef Iterator					iterator_type;
				typedef typename traits::iterator_category		iterator_category;
				typedef typename traits::value_type			value_type;
				typedef typename traits::difference_type		difference_type;
				typedef typename traits::reference			reference;
				typedef typename traits::pointer			pointer;


				VectorIterator() : current() {};

				VectorIterator (pointer x) : current(x){};

				//			template <class U>
				//			VectorIterator(const VectorIterator<U> &u) : current(u) {};

				VectorIterator operator=(const VectorIterator& other)
				{
					if (*this != other)
						current = other.current;
					return *this;
				};

				//virtual ~VectorIterator() {};


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


				VectorIterator& operator++()
				{
					current++;
					return *this;
				};
				VectorIterator operator++(int)
				{
					VectorIterator tmp (*this);
					current++;
					return tmp;
				};
				VectorIterator& operator--()
				{
					current--;
					return *this;
				};
				VectorIterator operator--(int)
				{
					VectorIterator tmp (*this);
					current--;
					return tmp;
				};
				////////////////////////////// les operator + et -
				VectorIterator operator+ (difference_type n) const
				{
					return VectorIterator(current + n);
				};
				friend VectorIterator operator+ (difference_type n, const VectorIterator &rhs)
				{
					return VectorIterator(rhs.current + n);
				};
				VectorIterator operator- (difference_type n) const
				{
					VectorIterator tmp(*this);
					tmp -= n;
					return tmp;
				};

				difference_type operator-(VectorIterator rhs)
				{
					return (current - rhs.current);
				};

				difference_type operator-(ConstVectorIterator<T> rhs)
				{
					return (current - rhs.current);
				};
				///////////////////////////////////////operator de comparaison

				bool operator<(const VectorIterator &rhs) const
				{
					return (current < rhs.current);
				};
				bool operator>(const VectorIterator &rhs) const
				{
					return (current > rhs.current);
				};
				bool operator<=(const VectorIterator &rhs) const
				{
					return (current <= rhs.current);
				};
				bool operator>=(const VectorIterator &rhs) const
				{
					return (current >= rhs.current);
				};
				bool operator==(const VectorIterator &rhs) const
				{
					return (current == rhs.current);
				};
				bool operator!=(const VectorIterator &rhs) const
				{
					return (current != rhs.current);
				};


				VectorIterator& operator-= (difference_type n)
				{
					current -= n;
					return *this;
				};

				VectorIterator& operator+= (difference_type n)
				{
					current += n;
					return *this;
				};

				reference operator[](difference_type n) const
				{
					return (current[n]);
				};

				/////////////////////////////////////////////

				bool operator<(const ConstVectorIterator<T> &rhs) const
				{
					return (current < rhs.current);
				};
				bool operator>(const ConstVectorIterator<T> &rhs) const
				{
					return (current > rhs.current);
				};
				bool operator<=(const ConstVectorIterator<T> &rhs) const
				{
					return (current <= rhs.current);
				};
				bool operator>=(const ConstVectorIterator<T> &rhs) const
				{
					return (current >= rhs.current);
				};
				bool operator==(const ConstVectorIterator<T> &rhs) const
				{
					return (current == rhs.current);
				};
				bool operator!=(const ConstVectorIterator<T> &rhs) const
				{
					return (current != rhs.current);
				};


				pointer							 current;
		}; // fin class VectorIterator
};

#endif

