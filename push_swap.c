/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:49:56 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/27 10:22:08 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_printf("ERROR. Too few arguments."))
	
}

//a way for program to analyze what moves are needed to achieve the desired result
//   rank them based on how many moves you need, choose the lowest number
//a way for program to optimize the number of moves (an algorithm)
//idea? give each number in the array a number based on its value, then arrange those numbers. 
//   this way I can handle negative numbers
//   problem? how to make the program detect which number is lowest, etc. 
//if duplicates, an error