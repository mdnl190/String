#ifndef mystring_h
#define mystring_h
#include <stddef.h>

/* ~~~~~~~~~~~~~~~~~~~~~~ String Functions ~~~~~~~~~~~~~~~~~~~~~~~*/

// Computes the length of the string str up to but not including the 
// terminating null character
size_t strlen (const char* str) 
{
	size_t result = 0;
	for (int i = 0; str[i] != '\0'; ++i) ++result;
	return (result);
}

// Copies the string pointed to, by src to dest
char* strcpy (char* dest, const char* src)
{
	char *d = dest;
	while (*dest++ = *src++);
	return d;
}

// Appends the string pointed to, by src to the end of the string 
// pointed to by dest
char* strcat (char* dest, const char* src)
{
	char* d = dest;
	while (*dest) dest++;
	strcpy (dest, src);
	return d;
}

// Compares the string pointed to, by str1 to the string pointed to 
// by str2
int strcmp (const char* str1, const char* str2)
{
	for ( ; *str1 && (*str1 == *str2); str1++, str2++);
	return (*str1 - *str2); 
}

// Compares at most the first n bytes of str1 and str2
int strncmp (const char* str1, const char* str2, int n)
{
	for (int i = 0; i < n; i++, str1++, str2++)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
	}
    return 0;	
}

// Searches for the first occurrence of the character c (an unsigned 
// char) in the string pointed to, by the argument str
char* strchr (const char* str, int c)
{
	while (*str) 
	{
		if (*str == c) return (char*)str;
		str++;
	}       
	return 0;
}


// ********************* 7 line function ***********************
// Finds the first character in the string str1 that matches any 
// character specified in str2
char* strpbrk (const char* str1, const char* str2)
{
	for (; *str1; str1++)
	{
		for (; *str2; str2++)
		{
			char* result = strchr(str1, *str2);
			if(result) return (char*)str1;
		}	
	}
        return 0;

}


// ********************* 7 line function ***********************
// Finds the first occurrence of the entire string needle (not 
// including the terminating null character) which appears in the 
// string haystack
char* strstr (const char* haystack, const char* needle)
{
	int i = strlen(needle);

	for ( ;*haystack; haystack++)
	{
		if (*haystack == *needle)
		{
			const char *temp1 = haystack, *temp2 = needle;
			if (strncmp(temp1, temp2, i) == 0)
				return (char *)haystack;
		}
	}
	return 0;
}

// Calculates the length of the initial segment of str1 which 
// consists entirely of characters in str2
size_t strspn (const char* str1, const char* str2)
{
	size_t result = 0;
	while (*str1)
	{
		// if char in s1 exists in s2, increment length
		while (*str1 && strchr(str2, *str1++)) 
			++result;
	}
	return result;
}

// helper function for strtok
size_t strcspn (const char* str1, const char* str2)
{
	size_t result;
	for (result = 0; *str1; str1++, result++)
		if (strchr(str2, *str1)) 
			return result;
	return result;
}

// ********************* 9 line function ********************** 
// Breaks string str into a series of tokens separated by delim
char* strtok (char* str, const char* delim)
{
    	static char *previousToken;
    	static int placeholder;

    	if (str == 0) str = previousToken;
    
   	do {
		if ((placeholder = *str++) == '\0')
	    	return 0;
    	} while (strchr(delim, placeholder));
  
	str--, previousToken = str + strcspn(str, delim);
   
	if (*previousToken != 0) *previousToken++ = 0;
     	return str;
}
#endif
