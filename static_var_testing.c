/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_var_testing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:48:40 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/19 10:18:56 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_combined_value(int nbr)
{
    static int	prev_comb_value;
    prev_comb_value += nbr;
    return (prev_comb_value);
}


int	main(void)
{
	printf("Run 1: %d\n", get_combined_value(1));
	printf("Run 2: %d\n", get_combined_value(3));
	printf("Run 3: %d\n", get_combined_value(4));
	printf("Run 4: %d\n", get_combined_value(182));
	printf("Run 5: %d\n", get_combined_value(9));
	printf("Run 6: %d\n", get_combined_value(221));
	printf("Run 7: %d\n", get_combined_value(-192));
	return (1);
}
