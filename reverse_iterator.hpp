/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:33:52 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/23 17:45:06 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
//#include <iterator>
#include "iterator_traits.hpp"

namespace ft 
{
	//reverse iterator///////////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename Iterator>
	class reverse_iterator
{
		protected:
			Iterator current;

		public:
			typedef Iterator							iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type		value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::reference		reference;
			typedef typename ft::iterator_traits<Iterator>::pointer			pointer;


			reverse_iterator() : current() {};

			explicit reverse_iterator (Iterator x) : current(x){};

			template <class U>
			reverse_iterator(const reverse_iterator<U> &u) : current(u.base()) {};

			template <class U>
			reverse_iterator& operator=(const reverse_iterator<const U>& other)
			{
				if (this != &other)
					current = other.base();
				return *this;
			};

			virtual ~reverse_iterator() {};

			reverse_iterator& operator++()
			{
				current--;
				return *this;
			};
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp (*this);
				this->operator++();
				return tmp;
			};
			reverse_iterator& operator--()
			{
				current++;
				return *this;
			};
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp (*this);
				this->operator--();
				return tmp;
			};

			reverse_iterator operator+ (difference_type n) const
			{
				return reverse_iterator(current - n);
			};
			reverse_iterator& operator+= (difference_type n)
			{
				current -= n;
				return *this;
			};
			reverse_iterator operator- (difference_type n) const
			{
				return reverse_iterator(current + n);
			};
			reverse_iterator& operator-= (difference_type n)
			{
				current += n;
				return *this;
			};
			reference operator[](difference_type n) const
			{
				return *(*this + n);
			};
//fct base
			Iterator base() const
			{
				return (current);
			};

			reference operator*() const
			{
				Iterator tmp = current;
				return *--tmp;
			};

			pointer operator->()
			{
				return &(operator*());
			};
			pointer operator->() const
			{
				return &(operator*());
			};
	}; // fin class reverse_iterator



//continuer les template ci dessous avec la norme iso page 523

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return (x.base() == y.base());
	};
	template <class Iterator>
		bool operator<(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return (x.base() > y.base());
		};
	template <class Iterator>
		bool operator!=(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return (x.base() != y.base());
		};

	template <class Iterator>
		bool operator>(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return (x.base() < y.base());
		};

	template <class Iterator>
		bool operator>=(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return (x.base() <= y.base());
		};

	template <class Iterator>
		bool operator<=(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return (x.base() >= y.base());
		};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (y.base() - x.base());
		};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
		{
			return (x + n);
		};
};
#endif

