## Solution

Solution for this challenge was pretty straightforward.

First of all, what I did is to setup a stego/image analysis toolbox,
thi is'nt much helpfull for this challenge, but it is helpfull in general.

Then I started trying things for finding something secret, maybe the flag
hidden in the image.

The first thing i did:

```
strings image.jpg
```
From the output the following string is shown:
```
flag{wow!_data_is_cool}
```
So thats it. The flag bytes where hidden as string into the image!

You can check the output of the command in output.txt


