ft_strjoin();
get_line()
{
	returns index of 1st new line
	or -42
}

get_next_line()
{
	static char		*next_line;
	char			*this_line;

	if get_line(next_line) > -1
		substr, get it, return it
	else
		🤪 write next_line into this_line
	
	while (true)
		keep reading new data
		🤪 join it to this_line

		if get_line > -1 or end of string
			🤪 substr of overwrap, write into next_line
			substr, get it, return it
}

TODO
- 🤪cat_strings: function to cat to a string by just making a new malloc and freeing the old

Problems
- how to know whether we have reached end of file descriptor string