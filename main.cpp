/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:40:24 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/23 17:44:14 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "vector.hpp"
#include <vector>
#include "iterator_traits.hpp"
#include "stack.hpp"
#include "reverse_iterator.hpp"
//#include "vector.hpp"

int main(void)
{
	// std::cout << "--------------check stack----------------\n";
	// std::vector<int> myvector (2,200);        // vector with 2 elements
	// ft::stack<int> first;                    // empty stack
	// ft::stack<int,std::vector<int> > third;  // empty stack using vector
	// ft::stack<int,std::vector<int> > fourth (myvector);

	// std::cout << "size of first: " << first.size() << '\n';
	// std::cout << "size of third: " << third.size() << '\n';
	// std::cout << "size of fourth: " << fourth.size() << '\n';
	// if (!fourth.empty())
	// 	std::cout << "pas de fourth empty \n";
	// else
	// 	std::cout << "empty return something\n";
	// if (!first.empty())
	// 	std::cout << "pas de first empty \n";
	// else
	// 	std::cout << "empty return something in first\n";
	// std::cout << "fourth.top() = " << fourth.top() << std::endl;
	// fourth.top() -= 2;
	// std::cout << " apres un -= 2 fourth.top() = " << fourth.top() << std::endl;

	// if (first.empty())
	// 	std::cout << "first est vide \n";
	// for (int i = 0; i < 5; i++)
	// 	first.push(i * 10);
	// if (!first.empty())
	// 	std::cout << "first a des element \n";
	// std::cout << "nb of element in first : " << first.size() << std::endl;
	// std::cout << "pop les element jusqua ce que first soit de nouveau vide";
	// while (!first.empty())
	// {
	// 	first.pop();
	// 	std::cout << "un element supprimer\n";
	// }

	std::cout << "---------------------test des reverse_iterator----------------\n";
	std::vector<int> myvec;
	for (int i = 0; i < 10; i++)
		myvec.push_back(i * 10);

	typedef std::vector<int>::iterator iterator_type;
	iterator_type from (myvec.begin());
	iterator_type until(myvec.end());

	ft::reverse_iterator<iterator_type> rev_until (from);
	ft::reverse_iterator<iterator_type> rev_from (until);

	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout <<  "\n";
	std::cout << "test de base() :\n";
	ft::reverse_iterator<iterator_type> rev_end(myvec.begin());
	ft::reverse_iterator<iterator_type> rev_begin(myvec.end());

	for(iterator_type it = rev_end.base(); it != rev_begin.base(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::cout << "test operator* \n";
	iterator_type origin (myvec.begin());
	iterator_type finale(myvec.end());

	ft::reverse_iterator<iterator_type> rev_finale (origin);
	ft::reverse_iterator<iterator_type> rev_origin (finale);
	std::cout << "test de l'operateur [] en plus :" << std::endl; 
	std::cout << "vector qui existe : " << rev_origin[3] << std::endl;
	std::cout << "vector qui existe pas : " << rev_origin[12] << std::endl;
	while (rev_finale != rev_origin)
		std::cout << ' ' << *rev_origin++;
	std::cout << '\n';

/*	std::cout << "--------------test vector--------------\n";
	ft::vector<int> first;
	ft::vector<int> second(4, 100);
	ft::vector<int> third(second.begin(), second.end());
	ft::vector<int> fourth(third);
*/
return 0;
}

