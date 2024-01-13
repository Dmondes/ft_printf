Additional checks
printf() and ft_printf() have different outputs. 
1) Missing conversion specifier, where % is given without escape character, such as %%
 2) Mismatched format specifier such as %d and argument "hello". In both case printf() throws error, but ft_print() returns output. 
