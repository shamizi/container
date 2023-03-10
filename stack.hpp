/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:52:34 by shamizi           #+#    #+#             */
/*   Updated: 2023/03/09 15:14:27 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

//#include <vector> //a remplacer par mon ft_vector bientot
#include <iostream>
#include "vector.hpp"

namespace ft 
{
	template < class T, class Container = ft::vector<T> > class stack 
		{
			public:

				typedef Container 				container_type;
				typedef typename Container::value_type		value_type;
				typedef typename Container::size_type		size_type;
				typedef typename Container::reference		reference;
				typedef typename Container::const_reference 	const_reference;
				
/////////////////////////////////////////////////////////////////////////////////////////////////////////


				explicit stack(const container_type& ctnr = container_type()) : container(ctnr) {};
				
			//	stack& operator= (const stack& other){c = other.c;}
				
				~stack() {};

				bool empty() const { return container.empty(); }; //
				size_type size() const { return container.size(); }; //
				value_type& top() { return container.back(); }; //
				const value_type& top() const { return container.back(); };
				void push(const value_type& x) { container.push_back(x); };
				void pop() { container.pop_back(); };

			private :
				container_type container;

				template <typename U, typename V>
					friend bool ft::operator==(const ft::stack<U, V>& x, const ft::stack<U, V>& y);
				template <typename U, typename V>
					friend bool ft::operator< (const ft::stack<U, V>& x, const ft::stack<U, V>& y);
				template <typename U, typename V>
					friend bool ft::operator!=(const ft::stack<U, V>& x, const ft::stack<U, V>& y);
				template <typename U, typename V>
					friend bool ft::operator> (const ft::stack<U, V>& x, const ft::stack<U, V>& y);
				template <typename U, typename V>
					friend bool ft::operator>=(const ft::stack<U, V>& x, const ft::stack<U, V>& y);
				template <typename U, typename V>
					friend bool ft::operator<=(const ft::stack<U, V>& x, const ft::stack<U, V>& y);
		}; //fin de la classe template

	template <class T, class Container>
		bool operator==(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
		{
			return (x.container == y.container);
		};
	template <class T, class Container>
		bool operator<(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
		{ 
			return (x.container < y.container);
		};
	template <class T, class Container>
		bool operator!=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
		{ 
			return (x.container != y.container);
		};
	template <class T, class Container>
		bool operator>(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
		{ 
			return (x.container > y.container);
		};
	template <class T, class Container>
		bool operator>=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
		{ 
			return (x.container >= y.container);
		};
	template <class T, class Container>
		bool operator<=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
		{ 
			return (x.container <= y.container);
		};

} // fin du namespace

#endif
