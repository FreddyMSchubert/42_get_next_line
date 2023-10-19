/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:27:16 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/19 11:35:13 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"  // Include your header
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void test_get_next_line(void)
{
    char *test_data = 
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
        "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n"
        "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
        "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\n"
        "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n";
    
    // Create and write the test data to a temporary file
    char *file_name = "when_you_read_this_delete_me.txt";
    FILE *file = fopen(file_name, "w");
    if (!file) {
        perror("Error creating test file");
        return;
    }
    fprintf(file, "%s", test_data);
    fclose(file);

    // Open the file for reading
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);  // Don't forget to free the line!
    }

    // Clean up: close the file descriptor and remove the temporary file
    close(fd);
    remove(file_name);
}

int main(void)
{
    test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();
	test_get_next_line();

    return 0;
}
