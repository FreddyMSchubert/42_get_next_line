# Commit Changelog get_next_line by @fschuber

> v grading_attempt.logic_version.update

#### Potential Future Improvements
- Change strjoin to use realloc instead of new malloc
- make get_next_line iterative to stop stack overflows for large files
- General Improvements

#### v0.3.2
- ensured functionality of util functions, ironed out edge cases
- made strjoin return the other string if either string is NULL
- logic improvements in get_line

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
