## Solution

In this challenge you are asked yo bypass a security mesure.

When we enter the url given we find out the following message
```
Sorry, it seems as if your user agent is not correct, in order to access this website. The one you supplied is: *****
```
So it seems we have to change our user-agent from the HTTP header. 
If you dont know what it is, bassically lets you specify some parameters for the request of the website,
for example, from which computer you are accessing (user-agent).
For a reference of the HTTP header: [http header](https://en.wikipedia.org/wiki/List_of_HTTP_header_field)
```
<!--Sup3rS3cr3tAg3nt-->
```
So I tried to change my user agent to that string. The tool I used to modify
my HTTP header is *curl*.

With the following command I changed my user agent.
```
curl -A "Sup3rS3cr3tAg3nt" http://165.227.106.113/header.php
```

And got the output:

```
Sorry, it seems as if you did not just come from the site, "awesomesauce.com".
<!-- Sup3rS3cr3tAg3nt  -->
```
Okey, at this point is pretty clear what we have to do. We have to modify
the HTTP header to something to tell the website we are comming from
awesomesauce.com.

I had no idea how to do it so I did a reasearch in the HTTP header specification.
I searched for the word *from* and going next and next found the following parameter.

```
Referer [sic] 	This is the address of the previous web page from which a 
                link to the currently requested page was followed.
```
So for adding more parameters to the header we can use -H option with curl.
I used the following command:
```
curl -A "Sup3rS3cr3tAg3nt" -H "Referer: awesomesauce.com"  http://165.227.106.113/header.php
```
And got the output:
```
Here is your flag: flag{did_this_m3ss_with_y0ur_h34d}
<!-- Sup3rS3cr3tAg3nt  -->
```
Easy!
