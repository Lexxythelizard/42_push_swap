*This project has been created as part of the 42 curriculum by rcollet*

# Description
The goal of this project is to learn about variadic function arguments, by recreating printf, including its formatting flags, as well as the optional min. width and precision requirements.

# Instructions
Compile the library by using make. The standard version of the project won't feature the more comprehensive formatting features. To use those type compile with make bonus instead. There is no detailed test program available, there is however a rudimentary main in the ft\_printf[\_bonus].c files which can be modified to test different edge cases.
make clean, fclean and re can be run with an additional -bonus suffix, clean and fclean can also be run with a -all suffix to clean up both the objects created by running make and make bonus. Last but not least, clean can be run with a -libft suffix to clean up the objects and the library created by running make libft, this is similar to make fclean -C libft

# Resources
AI wasn't actively used during the creation of this project. 
For a detailed description of printf, look up the man page PRINTF (3).
Further references are [CPP reference](https://www.cppreference.com/c) for C syntax, the 
[GNU C Language Manual](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/index.html)
and the [GNU make Manual](https://www.gnu.org/software/make/manual/make.html),
as well as the following [Markdown reference sheet](https://commonmark.org/help/)

#Description of the algorithm
Both of the versions convert the arguments during printing without allocating any extra memory dynamically.
The default version of the project prints the formatting string until it encounters a '%', upon which it interprets the next character as the conversion rule. If the conversion rule doesn't exist it is skipped. It then takes the next argument in the va\_list of arguments the function received and converts it according to the conversion rule, before printing it out.
The bonus version interprets everything after a '%' until an alphabetic character or another '%' as a formatting flag, resp. length/precision modifier and creates a structure t\_conv that corresponds to the format modifiers received. This struct is then used to determine if any extra steps are taken before printing out the va\_arg. 
In both versions, each call to one of the different print functions returns a count of characters printed, that are summed up by ft\_printf and determine its return value.
