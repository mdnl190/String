#include "mystring.h"
#include <stdio.h>

#define require(e) if (!(e)) fprintf(stderr, "FAILED line %d        %s: %s       %s\n", __LINE__, __FILE__, __func__, #e)

void test_strlen()
{
    require(strlen("") == 0);
    require(strlen("hello") == 5);
}

void test_strcpy()
{
    	char r[20] = "hello", m[10]; char *s = "goodbye", *t = "salam";
    	require(strcmp(strcpy(r,s), "goodbye") == 0);
   	require(strcmp(strcpy(r,t), "salam") == 0);
	require(strcmp(strcpy(m,t), "salam") == 0);
}

void test_strcat()
{
	char r[20] = "he"; char *s = "llo", *t = " there", *b = "!";
	require(strcmp(strcat(r,s), "hello") == 0);
	require(strcmp(strcat(r,t), "hello there") == 0);
	require(strcmp(strcat(r,b), "hello there!") == 0);
}

void test_strcmp()
{
    	char *r = "hello", *s = "hello", *t = "he";
    	require(strcmp(r,s) == 0);
    	require(strcmp(t,r) < 0);
    	require(strcmp(s,t) > 0);
}

void test_strncmp()
{
	char *r = "hello", *s = "heLLO", *t = "kangaroo";
	require(strncmp(r,s,2) == 0);
	require(strncmp(s,r,3) < 0);
	require(strncmp(t,r,1) > 0);
}

void test_strchr()
{
	char *r = "hello"; int c = 'e', x = 'm'; int i = 'o';
	require(strcmp(strchr(r,c),"ello") == 0);
	require(strchr(r,x) == 0);
	require(strcmp(strchr(r,i),"o") == 0);
}

void test_strpbrk()
{
	char *r = "hello", *s = "goodbye", *t = "mary";
	require(strpbrk(r,s) != 0);
	require(strpbrk(s,t) != 0);
	require(strpbrk(r,t) == 0);
}

void test_strstr()
{
	char *r = "mississippi", *s = "miss", *t = "sip", *m = "pi";
	require(strcmp(strstr(r,s),"mississippi") == 0);
	require(strcmp(strstr(r,t),"sippi") == 0);
	require(strcmp(strstr(r,m),"pi") == 0);
}

void test_strspn()
{
	char *r = "mary", *s = "ray", *t = "ym", *m = "a";
	require(strspn(r,s) == 3);
	require(strspn(r,t) == 2);
	require(strspn(r,m) == 1); 
}

void test_strtok()
{
	char r[100] = "Hi I'm, Mary"; char *s = "Hi", *t = "I'm", *m = "Mary";	
	char* delim = " ,";
	require(strcmp(strtok(r,delim),s) == 0);
	require(strcmp(strtok(NULL,delim),t) == 0);
	require(strcmp(strtok(NULL,delim),m) == 0);
}

int main()
{
    	test_strlen();
	test_strcpy();
    	test_strcat();
    	test_strcmp();  
    	test_strncmp();
	test_strchr(); 
	test_strpbrk();
	test_strstr();
	test_strspn();
	test_strtok();
   	
 	return 0;
}

