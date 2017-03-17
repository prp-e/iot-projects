# IoT Projects (for fun :joy:)

This repository is for my IoT projects. I make this projects for fun and learning. 

## List of projects 

* LED : 
This project is simple. It connects to a WiFi network, initializes a http server, then 
you can control a LED using these requests :

```
/on 
``` 

This turns LED on . 

```
/off
```

This turns LED off. 

```
/blink
```

This turns LED on & off each 0.5 second. 

```
/double
```
This is a double blink for 0.1 second, and a 0.5 waiting time. 

* Seven Segment : 

This code is written for a ***common anode*** seven segment display. So, when you send a request like this :

```
/0 
``` 

It will show the `0` on your seven segment. Also, it works for 0 to 9. If you want to turn your display off, just send this request :

```
/off
```

* Shift Register : 

The same as ***Seven Segment***, it has no *off* option. The hardware circuit, includes a `74HC595` *Serial-In, Parallel-Out* shift register, and takes only one of the pins of NodeMCU board. 
