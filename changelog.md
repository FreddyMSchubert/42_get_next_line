# Commit Changelog get_next_line by @fschuber

> v grading_attempt.logic_version.update

### v0.4.6
- did some docker + valgrind checking. no memory leaks! only thing you gotta do is free the lines that are being returned by get_next_line.
Correct example using 42 norminette:
```C
int main(void) {
	int			fd;
	char		*line;

	fd = open("./file.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return 0;
}
```

### v0.4.5
- added a makefile and compiled the files into a library for easier use in other projects

#### v0.4.4
- Post hand-in update, changed function names to stop conflicting definitions of same name when importing project

### v0.4.3
- Fixed gnl new line if condition in return block, was checking for wrong value (-1 instead of -2)
	- Now all test cases work perfectly but 4
- there was an error with the reaccessing a freed left, but setting left to NULL after freeing it did the trick
	- all non-strict test cases functional

#### v0.4.2
- Various smaller logic & clarity improvements
- most general cases now work, there are still failing edge cases.
- included testing function

#### v0.4.1
- fixed filedes validity check
- get_next_chunk error case improvements
- can just return left instead of making exact copy at last function call
- various improvements
- no change to errors, but defenitely a positive improvement still

### v0.4.0
- logic revamp, made get_next_line iterative instead of recursive
- there are many sigsevs as it stands.

#### v0.3.2
- ensured functionality of util functions, ironed out edge cases
- made strjoin return the other string if either string is NULL
- logic improvements in get_line
- General Improvements

#### v0.3.1
- strjoin while condition logic + typo fix
- read return value fix
- Norminette Improvements
- General Improvements
- Corrected Header Order
- Memory leaks
	- buffer now gets freed when read fails
	- previous leftovers content gets freed on strjoin

### v0.3.0
- third iteration, recursive approach
- not tested

### v0.2.0
- second attempt, solid concept, logic is there
- not tested

### v0.1.0
- first attempt, essentially pseudocode
- erroneous code, ends in timeout after having printed 1 line.
