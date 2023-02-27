/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:37:16 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/26 18:39:12 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

//enable if / is integral

namespace ft {

	//////////////////////////////////////////
	//enable if :
	template<bool Cond, class T = void>
		struct enable_if{};
	template<class T> 
		struct enable_if<true, T> {typedef T type;};

	/////////////////////////////////////////////////
	//is_integral:
	template< class T> struct is_integral
	{
		static const bool value = false;
	};


	template <> struct is_integral<bool> {static const bool value = true;};
	template <> struct is_integral<char> {static const bool value = true;};
	template <> struct is_integral<char16_t> {static const bool value = true;};
	template <> struct is_integral<char32_t> {static const bool value = true;};
	template <> struct is_integral<wchar_t> {static const bool value = true;};
	template <> struct is_integral<signed char> {static const bool value = true;};
	template <> struct is_integral<short int> {static const bool value = true;};
	template <> struct is_integral<int> {static const bool value = true;};
	template <> struct is_integral<long int> {static const bool value = true;};
	template <> struct is_integral<long long int> {static const bool value = true;};
	template <> struct is_integral<unsigned char> {static const bool value = true;};
	template <> struct is_integral<unsigned short int> {static const bool value = true;};
	template <> struct is_integral<unsigned int> {static const bool value = true;};
	template <> struct is_integral<unsigned long int> {static const bool value = true;};
	template <> struct is_integral<unsigned long long int> {static const bool value = true;};

	/////////////////////////////////////////////////
	//lexicographical compare:

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, InputIterator2 last2)
		{
			while (first1 != last1)
			{
				if (first2 == last2 || *first2 < *first1)
					return false;
				else if (*first1 < *first2)
					return true;
				++first1;
				++first2;
			}
			return (first2 != last2);
		};

	////////////////////////////////////////////
	//equal :

	template<class InputIterator1, class InputIterator2>
		bool equal(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2)
		{
			while (first1 != last1)
			{
				if (!(*first1 == *first2))
					return false;
				++first1;
				++first2;
			}
			return true;
		};


	/////////////////////////////////////////////
	//pair :
	template<class T1, class T2>
		struct pair
		{
			typedef T1 first_type;
			typedef T2 second_type;

			first_type first;
			second_type second;

			pair() : first(first_type()), second(second_type()){};

			pair(const ft::pair<T1, T2> &other)
			{
				first = other.first;
				second = other.second;
			};
			template<class U, class V>
				pair(const ft::pair<U, V>& pr)
				{
					first = pr.first;
					second = pr.second;
				};

			pair(const first_type& a, const second_type& b)
			{
				first = a;
				second = b;
			};

			pair& operator=(const pair& pr)
			{
				if (this == &pr)
					returnn *this;
				first = pr.first;
				second = pr.second;
				return *this;
			}
		};

	//pair non member fonction
	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs==rhs); }

	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs<lhs); }

	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs<lhs; }

	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs<rhs); }


	///////////////////////////////////////////////////
	//make pair :
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x,y));
	};
};//end of ft

#endif
