/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_trait.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:45:31 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/16 12:59:31 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAIT_HPP
#define ITERATOR_TRAIT_HPP

template<class Iterator> struct iterator_traits {
	typedef typename Iterator::difference_type 			difference_type;
	typedef typename Iterator::value_type 				value_type;
	typedef typename Iterator::pointer 				pointer;
	typedef typename Iterator::reference 				reference;
	typedef typename Iterator::iterator_category 			iterator_category;
};

template<class T> struct iterator_traits<T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template<class T> struct iterator_traits<const T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template<class T> struct iterator_traits<T _ _far*> {
	typedef long difference_type;
	typedef T value_type;
	typedef T _ _far* pointer;
	typedef T _ _far& reference;
	typedef random_access_iterator_tag iterator_category;
};


#endif
