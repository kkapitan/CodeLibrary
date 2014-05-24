###Description

An implementation of a Manacher algorithm for finding all palindromic
substrings in a given word. 

###Usage

####Input

<b>s</b> - a word we will search for palindromes.

IMPORTANT!
There is an additional boolean parameter 'even' which should be set to 'true' in order
to find a palindromes with even length or 'false' otherwise. 


####Output

An array R. R[i] is a radius of a palindrome centred on the i-th letter of a word. 

####Additional comments

<b>MAXN</b> - maximal length of a word<br>

This algorithm seems pretty magical, however it can be explained in a nice and 
not very painful manner. The main idea involves the following lemma:

<b>Lemma:</b>
If R[i]-k is not equal to R[i-k] then R[i+k] is equal to min(R[i]-k),R[i-k]).

<b>Proof:</b>

Case R[i]-k > R[i-k]:
	It means that the palindrome centred on (i-k)th letter is fully inside
	the palindrome centred on i-th letter. Therefore we can apply symmetry around i-th
	letter (because of palindrome's property) and as a result we can see that
	we have the same palindrome centred in position R[i+k] as that centred on R[i-k] so
	R[i+k] >= R[i-k]. Can we prolong that palindrome? The answer is: nope. Because if we do
	we would've been able to prolong  the palindrome centred on the i-k, 
	but we know from R[i-k] that we can't. 

Case R[i]-k < R[i-k]:
	This is a bit harder. We know that the palindrome centred on i-k are not fully inside 
	the palindrome centred on i. Therefore we can reflect only that part of an i-k centred 
	palindrome which lies inside a palindrome centred on the i-th letter, so R[i+k] >=  R[i]-k.
	But can we prolong it? The answer is again - nope. Why? Because we can't prolong
	the i-th centred one.

Case R[i]-k = R[i-k]:
	We can also apply symmetry but we are not able to make any statements about R[i+k]
	except that R[i+k] >= R[i-k], because we might be able to prolong the palindrome
	centred on the i+k.

With that in mind we can compute some R[i] and then efficently compute R[i+k]
using this lemma.  

###Solved problems
[Mirror Strings !!!](http://www.spoj.com/problems/MSUBSTR/)
