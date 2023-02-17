/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:52:34 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/17 13:11:46 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector> //a remplacer par mon ft_vector bientot
#include <iostream>

namespace ft {
	template < class T, class Container = std::vector<T> >
		class stack 
		{
			public:
				typedef typename Container::value_type value_type;
				typedef typename Container::size_type size_type;
				typedef Container container_type;
			protected:
				Container c;
			public:
				explicit stack(const Container& = Container())
				{
					std::cout << "stack constructor called" << std::endl;
				}
				stack& operator= (const stack& other){c = other.c;}
				~stack() {}

				bool empty() const { return c.empty(); }
				size_type size() const { return c.size(); }
				value_type& top() { return c.back(); }
				const value_type& top() const { return c.back(); }
				void push(const value_type& x) { c.push_back(x); }
				void pop() { c.pop_back(); }


				template <class U, class V>
					friend bool operator==(const stack<U, V>& x,
							const stack<U, V>& y);
				template <class U, class V>
					friend bool operator< (const stack<U, V>& x,
							const stack<U, V>& y);
				template <class U, class V>
					friend bool operator!=(const stack<U, V>& x,
							const stack<U, V>& y);
				template <class U, class V>
					friend bool operator> (const stack<U, V>& x,
							const stack<U, V>& y);
				template <class U, class V>
					friend bool operator>=(const stack<U, V>& x,
							const stack<U, V>& y);
				template <class U, class V>
					friend bool operator<=(const stack<U, V>& x,
							const stack<U, V>& y);
		}; //fin de la classe template

	template <class T, class Container>
		bool operator==(const stack<T, Container>& x,
				const stack<T, Container>& y)
		{ return (x.c == y.c); }
	template <class T, class Container>
		bool operator< (const stack<T, Container>& x,
				const stack<T, Container>& y)
		{ return (x.c < y.c);}
	template <class T, class Container>
		bool operator!=(const stack<T, Container>& x,
				const stack<T, Container>& y)
		{ return (x.c != y.c);}
	template <class T, class Container>
		bool operator> (const stack<T, Container>& x,
				const stack<T, Container>& y)
		{ return (x.c > y.c);}
	template <class T, class Container>
		bool operator>=(const stack<T, Container>& x,
				const stack<T, Container>& y)
		{ return (x.c >= y.c);}
	template <class T, class Container>
		bool operator<=(const stack<T, Container>& x,
				const stack<T, Container>& y)
		{ return (x.c <= y.c);}

} // fin du namespace

#endif
