## Solution

This time we are facing a "medium" tagged challenge. If you haven't tried, try it! Its easyer than you may think.

In the first insight of the problem I tought, oh this time will be more challenging.
So the first thing I did after downloading the binary was running it, when running it,
it asks for a PIN which I suposed to be the flag, after trying some PIN you get the output.

```
PIN salah !
```

Which I suposed is wrong password. Then I oppened my favourite reversing tool (in my case radare2)
You can find that the binary is really simple. This is the simplified main.
```
            ------------------------------------------------
            |  callq sym.imp.__isoc99_scanf;[gb]            |            
            | movl local_4h, %eax                           |            
            | movl %eax, %edi                               |            
            | callq sym.cek;[gc]                            |            
            | testl %eax, %eax                              |            
            | je 0x400623;[gd]                              |            
            `-----------------------------------------------'            
                    f t                                                  
                    | |                                                  
                    | '-------------------.                              
    .---------------'                     |                              
    |                                     |                              
.---------------------------------.   .----------------------------------
|  0x400615 [gh]                  |   |  0x400623 [gd]                   
| ; const char *s                 |   | ; const char *s                  
| ; 0x4006d6                      |   | ; CODE XREF from main (0x400613) 
| ; "PIN benar ! \n"              |   | ; 0x4006e4                       
| leaq str.PIN_benar, %rdi        |   | ; "PIN salah ! \n"               
| ; int puts(const char *s)       |   | leaq str.PIN_salah, %rdi         
| callq sym.imp.puts;[gf]         |   | ; int puts(const char *s)        
| jmp 0x40062f;[gg]               |   | callq sym.imp.puts;[gf]          
`---------------------------------'   `----------------------------------
    v                                     v                              
    |                                     |                              
    '-------------------.                 |                              
                        | .---------------'                              
                        | |                                              
                  .----------------------------------.                   
                  |  0x40062f [gg]                   |                   
                  | ; CODE XREF from main (0x400621) |                   
                  | movl $0, %eax                    |                   
                  | leave                            |                   
                  | retq                             |                   
                  `----------------------------------' 
```
You can see that is telling our PIN is benar or salah by checking the result
of the *cek* function. After this I checked the cek function.

The cek function follows same scheme. Recieves 1 parameter (the input we give)
and compares it against a value. We can eassly find out that the value is: 333333.

When feeding the program with this input we get the following output:
```
PIN benar !
```

So i suposed this was the flag.
And it was.
Really simple challenge. 
