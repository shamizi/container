/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator1.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:33:52 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/17 16:16:16 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace ft {
	// 24.3, primitives: //
	template <class Iterator> 
		struct iterator_traits
		{

			typedef typename Iterator::difference_type			difference_type;
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference				reference;
			typedef typename Iterator::iterator_category			iterator_category;
		};

//
	template<class T> 
		struct iterator_traits<T*>
		{
			typedef std::ptrdiff_t			difference_type;
			typedef T 				value_type;
			typedef T* 				pointer;
			typedef T& 				reference;
			typedef std::random_access_iterator_tag 	iterator_category;
		};

//
	template<class T> 
		struct iterator_traits<const T*>
		{
			typedef std::ptrdiff_t			difference_type;
			typedef T 				value_type;
			typedef const T* 			pointer;
			typedef const T& 			reference;
			typedef std::random_access_iterator_tag 	iterator_category;
		};




	//
	template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef T		value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;

		};


	//
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: public input_iterator_tag {};
	struct bidirectional_iterator_tag: public forward_iterator_tag {};
	struct random_access_iterator_tag: public bidirectional_iterator_tag {};



/*	// 24.3.4, iterator operations:
	template <class InputIterator, class Distance>
		void advance(InputIterator& i, Distance n);
//galerrrrrrre besooin de operator+ et operator++ pareil en dessous


	template <class InputIterator>
		typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last);



//au dessus j'suis pas sur que j'ai besoin de les laisser la
*/











	//reverse iterator///////////////////////////////////////////////////////////////////////////////////////////////////////
	template <class Iterator>
		class reverse_iterator : public
					 iterator<typename iterator_traits<Iterator>::iterator_category,
					 typename iterator_traits<Iterator>::value_type,
					 typename iterator_traits<Iterator>::difference_type,
					 typename iterator_traits<Iterator>::pointer,
					 typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator current;

		public:
			typedef Iterator						iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename iterator_traits<Iterator>::reference		reference;
			typedef typename iterator_traits<Iterator>::pointer		pointer;


			reverse_iterator() : current()
			{};

			explicit reverse_iterator (Iterator x)
			{
				current = x;
			};

			//tjr besoin surchage operateur =
			template <class U>
			reverse_iterator(const reverse_iterator<U> &u)
			{
				current = u.base();
			};
			virtual ~reverse_iterator() {};





			reverse_iterator& operator++()
			{
				--current;
				return *this;
			};
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--current;
				return tmp;
			};
			reverse_iterator& operator--()
			{
				++current;
				return *this;
			};
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++current;
				return tmp;
			};

			reverse_iterator operator+ (difference_type n) const
			{
				return reverse_iterator(current -n);
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
				return current[-n - 1];
			};



			////////////////////////tjr dans reverse fct membre
			Iterator base() const
			{
				return (current);
			};

			reference operator*() const
			{
				Iterator tmp = current;
				return *--tmp;
			};

			pointer operator->() const
			{
				return &(operator*());
			};
	}; // fin class reverse_iterator



//continuer les template ci dessous avec la norme iso page 523

	template <class Iterator>
		bool operator==(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return x.base() == y.base();
		};
	template <class Iterator>
		bool operator<(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return x.base() < y.base();
		};
	template <class Iterator>
		bool operator!=(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return x.base() != y.base();
		};

	template <class Iterator>
		bool operator>(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return x.base() > y.base();
		};

	template <class Iterator>
		bool operator>=(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return x.base() >= y.base();
		};

	template <class Iterator>
		bool operator<=(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return x.base() <= y.base();
		};

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return y.base() - x.base();
		};

	template <class Iterator>
		reverse_iterator<Iterator>
		operator+(
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& x)
		{
			return reverse_iterator<Iterator> (x.base() - n);
		};


	//back_insert_iterator pas forcement necessaire
/*
	//template <class Container> class back_insert_iterator;
	template <class Container>
	class back_insert_iterator : public iterator<output_iterator_tag, void ,void ,void, void>
	{
		protected:
			Container *container;
		public:
			typedef Container			container_type;
			explicit back_insert_iterator(Container& x);
			back_insert_iterator<Container>& operator=(typename Container::const_reference value);
			back_insert_iterator<Container>& operator*();
			back_insert_iterator<Container>& operator++();
			back_insert_iterator<Container> operator++(int);
	};
	template <class Container>
		back_insert_iterator<Container> back_inserter(Container& x);
//	template <class Container> class front_insert_iterator;
//	template <class Container>
//		front_insert_iterator<Container> front_inserter(Container& x);
//	template <class Container> class insert_iterator;
//	template <class Container, class Iterator>
//		insert_iterator<Container> inserter(Container& x, Iterator i);







		// 24.5, stream iterators:j'sais pas si necessaire mais c dans le template
		template <class T, class charT = char, class traits = char_traits<charT>,
		class Distance = ptrdiff_t>
		class istream_iterator;
		template <class T, class charT, class traits, class Distance>
		bool operator==(const istream_iterator<T,charT,traits,Distance>& x,
		const istream_iterator<T,charT,traits,Distance>& y);
		template <class T, class charT, class traits, class Distance>
		bool operator!=(const istream_iterator<T,charT,traits,Distance>& x,
		const istream_iterator<T,charT,traits,Distance>& y);
		template <class T, class charT = char, class traits = char_traits<charT> >
		class ostream_iterator;
		template<class charT, class traits = char_traits<charT> >
		class istreambuf_iterator;
		template <class charT, class traits>
		bool operator==(const istreambuf_iterator<charT,traits>& a,
		const istreambuf_iterator<charT,traits>& b);
		template <class charT, class traits>
		bool operator!=(const istreambuf_iterator<charT,traits>& a,
		const istreambuf_iterator<charT,traits>& b);
		template <class charT, class traits = char_traits<charT> >
		class ostreambuf_iterator;*/
}

#endif
