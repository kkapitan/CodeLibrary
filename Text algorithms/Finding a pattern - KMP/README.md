###Description

An implementation of a KMP approach for finding a pattern in a given text. 

###Usage

####Input

<b>pattern</b> - a pattern we are looking for.
<b>text</b> - a text searched for a pattern.

####Output

All positions in a given text from which the pattern begins.

####Additional comments

<b>MAXN</b> - maximal length of a text and pattern (combined) <br>

This implementation uses a prefix-sufix array which holds a lenght of 
a largest proper prefix that is equal to the sufix in each prefix 
of a word pattern#text where # is some symbol not included in our alphabet. 
This allows us to check if our pattern starts in a particular position by comparing
the length of a pattern and the length of a prefix-sufix in that position.

###Solved problems
[Wyszukiwanie wzorca w tekœcie PL](http://pl.spoj.com/problems/KMP/)
