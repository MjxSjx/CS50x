# Week 10 - Emoji

This week covered:

* The orgin of emojis and how they have evolved. A relaxed week to give time to finish the final project. Week 9 was the largest obstacle and deepest learning curve. 

* I choose to make a ping pong score tracker based off traditional CRUD fundementals. In truth, I was pressed for time. The website was adequate enough to pass the course!

# Final Project
<details>
<summary>Ping Pong Score Tracker</summary>
  
Video: <https://youtu.be/z5_f7x9Xi3A>

## Description:

This Ping Pong Score Keeper is a web application that allows users to keep track of the score during a ping pong match. Because it is a web application, I used HTML as the noun. All the text and most the spacing is done via HTML tags and some associated HTML attributes. The CSS as I will mention in further detail below is done without a Stylesheet. I used a CSS framework called "Bulma" which i like because the syntax is terse and feels "human". The JavaScript is kept as tight and clean as I could possibly do. I made sure to leave plenty of comments for anyone wanting to understand or add to the code. The user can select the winning score limit from a dropdown menu and use the "+" buttons to increment the score for each player. The application will automatically detect the winner and disable the buttons once the winning score limit has been reached.

## Files:

### index.html
This file contains the HTML structure for the web page. It includes the necessary stylesheets and JavaScript file. Comments were left for others to understand it simply.

### app.js
This file contains the JavaScript code that provides the functionality of the score keeper application. It uses DOM manipulation to update the score and detect the winner. Comments were left for others to understand it simply. I start by initializing the variables of player 1 and player 2, setting their scores to 0 and connecting them to their respective button and display. I then defined the reset button and set the variables to allow winning conditions. Then came the functions: which include updating the scores to align with each player when their respective buttons were clicked (using of course addEventListeners). Then I made the function for the reset button, which disables the buttons once it fires.

### styles.css
This file was not necessary because I used the Bulma CSS framework to style the elements.

apple-touch-icon.png, favicon-32x32.png, favicon-16x16.png, and site.webmanifest
These are files for the website's  app icon, as well as the web app manifest file that specifies the application's metadata.

### Design Choices
The Ping Pong Score Keeper was designed to be a simple and intuitive web application for keeping track of the score during a game of ping pong. The user interface is clean and easy to use, with a minimalist design that is both functional and aesthetically pleasing.
I choose to use Bulma CSS framework to style the web page because of its flexibility and ease of use. It provides a solid foundation for building the user interface and allows the user to create responsive layouts quickly and simply with terse vocabulary.
In terms of functionality, I decided to use DOM manipulation to update the score and detect the winner. This allowed me to create a dynamic user experience without the need for complex backend code.
Overall, given my limited time, I’m proud of the Ping Pong Score Keeper and hope that it will be useful for anyone who needs to keep score during a ping pong match. I know I’ll use it at least once because I am a moderate ping pong enthusiast and play with friends.
</details>  
