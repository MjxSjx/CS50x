# Week 8 – HTML, CSS, JavaScript
Algorithm: A step-by-step set of instructions for solving a problem

## The Internet
Are computer servers that allow data wired or wirelessly to flow from point A to point B etc. 

### Routers
Are millions of servers interconnected much like a grid. Moving data back and forth left to right.

## TCP/IP
Is the how. How does the data from 1 router to another get there.
*	IP (Internet Protocol): is a protocol that computers speak that allow them to know how address other computers on the internet.
*	Protocol: is a set of conventions that computers adhere to.
*	TCP (transmission Control Protocol): A separate set of conventions that computers adhere to in order to solve problems. Sends confirmations as well.
*	Distinguishing one type of service from another. 80 = HTTP 443 = HTTPS (s) stands for secure. 
*	Helps with large files. It devises a plan to break large files into smaller files then notices if all are saved into memory or not. aka a checksum.

IP dictates every computer on the internet has a unique address in this form #.#.#.#. Dotted decimal notation, which in total is 32 bits allowing for 4 billion possible unique addresses. There is a new system that takes 128 bits allowing for quadrillions.

## DNS (domain Name System)
Allows us to use words rather than numbers to find things. The conversion of integer IP addresses into strings DNS. 

A collection of servers on the internet whose purpose in life is to convert domain names to IP addresses and sometimes vice versa as well. 

Your router is a DNS server, a cache; locally saving websites IP addresses just to avoid bothering the larger, more expensive servers all day long.

DNS info is stored as an object, meaning a key value pair. Domain Name | IP Address

### HTTP (Hyper-Text Transfer Protocol)
Browsers automatically insert HTTP/HTTPS at the beginning of a website’s name. It is one of the most popular and most powerful features of the internet nowadays. 

HTTP aka the web is a service that runs on top of the internet, it is an application-level protocol. Because the internet is considered “lower-level plumbing,” the TCP/IP stuff. 

https://www.example.com/

That / is applied automatically much like https and is saying go to the root of the server aka the default page. The .com is categorization of the URL and called the TLD (Top Level Domain). There are hundreds of types of TLD’s.

https://www.example.com/path/folder/

The next line is called a path and is some sequence of folder and/or file name.
	
### Keywords:
*	GET: Get me that thing
*	POST: upload something



### Inspect
Inspect is right clicking in your browser and seeing the tabs for Elements, Console, Sources, Network, Performance, Memory and so on

### curl
Inside VS Code or other text editors in the terminal type “curl -i” then the web address you want to load. It’s going to pretend to be a browser, although it doesn’t load images or graphics, just the header info which is stored as objects aka key value pairs.

### Error Codes
404 is Not Found. 503 Service Unavailable (overloaded)

### Search
The question mark “?” to your browser is how you specifically pass human user input to a server and search for things.
*	GET: /search?q=cats HTTP/1.1
*	Host: www.google.com


## HTML (Hyper-Text Markup Language)
HTTP and TCP/IP is all about just getting data from point A to point B in some standardized way. 

HTML – The language in which web pages are written. HTML is not a programming language, there are no functions, no loops, no programming logic.

The two key features of HTML are:
* Tags/elements: the boundaries and structure of HTML
* Attributes: things that modify tags

### Hello.html
```
<!doctype html> // the most basic boilerplate

<html lang = "en">
    <head>
        <title>
            Hello, title
        </title>
    </head>
    <body>
        Hello, body
    </body>
</html>

$code hello.html
$ http-server //this will run your html code in the Harvard codespace servers
```
If I remember correctly, you can use ! then hit tab and the boilerplate will be made for you.

Servers are programs and not hardware. A server’s purpose in life is to respond to requests with responses. 

## DOM (Document Object Model)
The DOM is the absolute root of everything web related. The DOM is above even HTML; again, the tree is analogist to a family tree from top to bottom and not an actual tree, from bottom to top.

## Paragraphs
```
Using <p> tags and <br> tags

<!doctype html> // the most basic boilerplate
<html lang = "en">
    <head>
        <title>
            Paragraphs
        </title>
    </head>
    <body>
        <p>
        lorem*3
        </p>
        lorem
        <br></br>
        blah
    </body>
</html>
```

## Headings
H1 is only to be used once, headings go up to h6
```
<!doctype html> // the most basic boilerplate

<html lang = "en">
    <head>
        <title>
            Headings
        </title>
    </head>
    <body>
        <h1>
            One
        </h1>
        <p>
        lorem*3
        </p>
        <h2>
            Two
        </h2>
        lorem
        <h3>
            Three
        </h3>
        <p>
        blah
        </p>
    </body>
</html>
```


## List
```
<ul> unordered list (bullet points) <ol> ordered list (numbers) <li> list item
<!doctype html> // the most basic boilerplate

<html lang = "en">
    <head>
        <title>
            List
        </title>
    </head>
    <body>
        <ul>
            <li>foo</li>
            <li>bar</li>
            <li>baz</li>
        </ul>
    </body>
</html>
```

## Table
```	
<tr> table row <td> table data <th> table header
<!doctype html> // the most basic boilerplate

<html lang = "en">
    <head>
        <title>
            Table
        </title>
    </head>
    <body>
        <table>
            <tr>
                <td>1</td>
                <td>2</td>
                <td>3</td>
            </tr>
        </table>
    </body>
</html>
```

## Image
```
<img> do not have closing tags
<html lang = "en">
    <head>
        <title>
            Image
        </title>
    </head>
    <body>
        <img alt="Harvard" src="harvard.jpg">
    </body>
</html>
```
## Video
This is syntax I didn’t know.
```
<html lang = "en">
    <head>
        <title>
            Video
        </title>
    </head>
    <body>
        <video autoplay loop muted width="1280">
            <source src="halloween.mp4" type="video/mp4">
        </video>
    </body>
</html>
```
## Link
```	
  <a> anchor tag
<html lang = "en">
    <head>
        <title>
            Link
        </title>
    </head>
    <body>
        Visit <a href="https://www.harvard.edu/">Harvard</a>
    </body>
</html>
```

## Meta
Has nothing to do with FB, it has to do with making the webpage scale dynamically with all different resolutions and screen sizes.
```
<html lang = "en">
    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width">  
        <title>
            Meta
        </title>
    </head>
    <body>
        Lorem 
    </body>
</html>
```

## Search.html
Attaching google to a form input. Adding autofocus and complete and a placeholder.
```
<html lang = "en">
    <head>
        <title>
            Search
        </title>
    </head>
    <body>
        <form action="https://www.google.com/search">
            <input autocomplete="off" autofocus name="q" placeholder="Search" type="search">
            <input type="submit" value="Google Search">
        </form>
    </body>
</html>
```
Inspect (Continued)
	As already known, All the HTML Elements used on a webpage are inside the inspect option.


## CSS (Cascading Style Sheet)
CSS is the cosmetics of a webpage. Once again like HTML, CSS is not a programming language, there are no functions, loops, or programmable logic.  CSS manipulates, font size, colors, borders, and the like.

The key feature of CSS:
*	properties are objects aka key value pairs. Akin to Attributes in HTML things that modify.
Key phrases:
*	type selector
*	class selector used with a .
*	ID selector used with a #
*	attribute selector
The ultimate goal is to use a framework like Bootstrap or Bulma for you CSS needs. All that you  to do is include a link tag in your HTML to your CSS file in the head section

## home.html
Applying CSS directly to HTML elements without a link tag. NOT GOOD.
```
<html lang = "en">
    <head>
        <title>
            Home 
        </title>
    </head>
    <body style="text-align: center">
            <header style="font-size: large;">
                John Harvard
            </header>
            <main style="font-size: medium;">
                Welcome to my home page
            </main>
            <footer style="font-size: medium;">
                Copyright &#169; John Harvard 1636
            </footer>
    </body>
</html>
```
Applying CSS in the HTML head without a link tag. Still NOT GOOD!
```
    <head>
        <style>
            body {
                text-align: center;
            }
            header {
                font-size: large;
            }
            main {
                font-size: medium;
            }
            footer {
                font-size: small;
            }
        </style>
        <title>
            Home 
        </title>
    </head>
```
This is just the <head> element code the <body> is the same as above just without any of the style attributes, making it cleaner.

### Applying CSS properly using the link element

    <head>
        <link href="styles.css" rel="stylesheet"></link>
        <title>
            Home 
        </title>
    </head>
    <body class="centered">
            <header class="large">
                John Harvard
            </header>
            <main class="medium">
                Welcome to my home page
            </main>
            <footer class="small">
                Copyright &#169; John Harvard 1636
            </footer>
    </body>
</html>

## This is the CSS syntax.
```
.centered {
    text-align: center;
}

.large {
    font-size: large;
}

.medium {
    font-size: medium;
}

.small {
    font-size: small;
}
```

## favorites
Is an HTML file using all the favorites data from the week before with SQL. The data contains hundreds of user entries pertaining 3 things.
1.	The time and date each user entered their data
2.	The Coding project they preferred
3.	The coding language that project was in
David is using a <link href:“”> element to enable Bootstrap which is a framework that makes CSS super duper simple. Bulma is better but that okay. 

## JavaScript
JS is an OOL like Python, it supports conditionals and the like. JavaScript can do things for web development that Python can’t, because JS was designed for Web purposes. JS lets you see web changes happen live through manipulation of the DOM. 




## Greet
A very archaic way of using JS in a HTML file. The ideal way is to  <link href:“”>  the JS not insert it in the actual HTML
```
<html lang = "en">
    <head>
        <script>
            function greet() 
            {
                let name = document.querySelector("#name").value;
                alert("Hello, " + name);
            }
        </script>
        <title>
            Greet
        </title>
    </head>
    <body>
        <form onsubmit="greet(); return false;">
            <input autocomplete="off" autofocus id="name" placeholder="Name" type="text"></input>
            <button type="submit">Greet</button>
        </form>
    </body>
</html>
```
### The way the code should actually be, with the JS script separated
```
<html lang = "en">
    <head>
        <script src="testing.js"></script>
        <title>
            Greet
        </title>
    </head>
    <body>
        <form onsubmit="greet(); return false;">
            <input autocomplete="off" autofocus id="name" placeholder="Name" type="text"></input>
            <button type="submit">Greet</button>
        </form>
    </body>
</html>
```
### the JS file code
```
document.addEventListener('DOMContentLoaded', function() {
    document.querySelector('form').addEventListener('submit', function(event) {
        let name = document.querySelector("#name").value;
        alert("Hello, " + name);
        event.preventDefault();
    });
});
```
### favorites.html (Continued)
That favorites data from last week that keeps getting brought up. Now, has CSS and JS applied to it and is clean, colorful, and interactive. You can use up and down arrows at the top of each list and choose highest or lowest option; meaning highest time or lowest time. highest letter or lowest letter and on. 

### Background
Demonstrating the power of JS and CSS in HTML all combined. addEventListener() and ‘click’ is mainly on display. The webpage file loads to a white screen with 3 buttons R, G, and B. If you click a button the color of the background changes to either Red, Green, or Blue. Colt Steele did a similar thing.  

There is always a solution to coding problems
