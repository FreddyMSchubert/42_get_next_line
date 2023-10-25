# Commit Changelog get_next_line by @fschuber

> v grading_attempt.logic_version.update

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
