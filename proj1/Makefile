# Your program must compile with 'make'
# You must not change this file.

CC = gcc
FLAGS = -std=c99 -O0 -Wall -Werror -g -pedantic 

rgrep:
	$(CC) $(FLAGS) rgrep.c -o rgrep

clean:
	rm -rf rgrep *.dSYM

check: clean rgrep
	test "`echo "a\nb\nc" | ./rgrep 'a'`" = "a"
	test "`echo "a\n" | ./rgrep 'a'`" = "a"
	test "`echo "a" | ./rgrep '...'`" = ""
	test "`echo "abc" | ./rgrep '.b.'`" = "abc"
	test "`echo "h\naaaaah" | ./rgrep 'a+h'`" = "aaaaah"
	test "`echo "h\naaaaahhhhh" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "h\naaaaahhhhh\n" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "a" | ./rgrep 'a?a'`" = "a"
	test "`echo "woot\nwot\nwat\n" | ./rgrep 'wo?t'`" = "wot"
	test "`echo "CCCCCCC\nC+\nC++" | ./rgrep '.\+\+'`" = "C++"
	test "`echo "GG" | ./rgrep '.+'`" = "GG"
	test "`echo "woooooo_CSE31.jpg" | ./rgrep 'w.+_...31\.jpg'`" = "woooooo_CSE31.jpg"
	test "`echo "abc" | ./rgrep '.+'`" = "abc"
	#test "`echo ".." | ./rgrep '\.\.'`" = ".."
	test "`echo "A++" | ./rgrep '.\+\+'`" = "A++"
	test "`echo "abcff+" | ./rgrep '...+\+'`" = "abcff+"
	test "`echo "abccccc" | ./rgrep 'abc+'`" = "abccccc"
	test "`echo "aaabbbcccd" | ./rgrep 'a+b+c+d'`" = "aaabbbcccd"
	test "`echo "Gasdfg" | ./rgrep 'abc'`" = ""
	test "`echo "abc" | ./rgrep 'a?a?bc'`" = "abc"
	test "`echo "a?" | ./rgrep 'a?\?'`" = "a?"
	test "`echo "aaaaaaaabbbbbbb" | ./rgrep 'a+h?b+'`" = "aaaaaaaabbbbbbb"
	test "`echo "?+..." | ./rgrep '\?\+\.+'`" = "?+..."
	test "`echo "abcdefghijkl" | ./rgrep '............'`" = "abcdefghijkl"
	test "`echo "..." | ./rgrep '\.+'`" = "..."
	test "`echo "???" | ./rgrep '\?+'`" = "???"
	test "`echo "test.test" | ./rgrep '...+\.test'`" = "test.test"
	test "`echo "+thisshouldwork" | ./rgrep '\+.+'`" = "+thisshouldwork"
	@echo "Passed sanity check."

