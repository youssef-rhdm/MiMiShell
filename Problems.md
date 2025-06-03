i want to extract the content of qoutes withut extracting the main quotes

i need to skip the main quotes and then extact the content

if there was a nother main qoute it should also have its content  extracted with itself skipped

repeatedly untill the end of the string;

algo quote_extractor;

iterate through the string
	if i find quote
		save it and skip it
			must peserve everything inside
		until i find it


while(current->value[i] != NULL)
{
	quote= ft_isquote(current->value[i]);
	if(quote)
	{
		i++;
		count =count_until_you_find(qoute);
		new_str = fill_the_counted_chars();
		new_str = join_the_new_strs();
	}
}
		free(current->value);
		current->value = new_str;





































# dont forget to double check makefiles

# not syntax erros

# leave to parser syntax errors

	(echo) > (cat)
 	echo > (echo)
	((a>"f")|"he"")
	((a>"f"))
	(a)"b"
	(a) "b"
	"b"(a)
	a|


# final tokenizatio






bash-3.2$ < f
bash: f: No such file or directory
bash-3.2$ > ls
bash-3.2$ << ls
> bash-3.2$ >> ls
bash-3.2$ | ls
bash: syntax error near unexpected token `|'
bash-3.2$ || ls
bash: syntax error near unexpected token`||'
bash-3.2$ && ls
bash: syntax error near unexpected token `&&'
bash-3.2$
