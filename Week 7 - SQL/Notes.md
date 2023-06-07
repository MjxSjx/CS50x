# Week 7 – SQL 
Algorithm: A step-by-step set of instructions for solving a problem

### Introduction
It’s time for data. Lots and lots of data. 

## SQL – Structured Query Language (sequel)
A language designed to handle data “querying databases and storing data” ; “it does less than C or Python, but does certain things really well.” 
•	Updating data
•	Inserting data
•	Deleting data 
•	And much more
SQL is used in web apps and mobile apps, data science, analytics and much more. It’s good at storing lots and lots of data. Think of R.

## Flat-file Databases
David has a large excel file with a lot of data. Normally you’re limited to whatever the program (excel) has to offer. David just wants the raw data, because he is going to manipulate it inside VS Code.
David then states that excel and the like are what’s called a “flat file database.” The simplest database in the world is a .csv file.
The fastest way to load the data to VS Code is to simply drag the file into the explorer tab, in the utmost far left section.
Python is one of the most used Languages for Data science and analytics. Python has native support for .csv files via a package called csv.
```
# In Python to open a csv file

import csv

# Opening the file
with open("file_name.csv", "r") as file:
# Now we need to load the file
    reader = csv.reader(file)
# Finally give me the 2nd column of the csv file
    for row in reader:
        print(row[1])
```
The final product, using Python to take the data from the 2nd row of the .csv and total up each option.
```
import csv

with open("file_name.csv", "r") as file:
    reader = csv.Dictreader(file)
    counts = {}
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
```
	
Lambda is a special keyword in Python for when you want a fn but you’re only going to use it once. Lambda is a 1-line function that doesn’t need normal syntax. Just keep that in mind.

Now, we’re graduating from mere flat file databases like text files or binary files in which all your data is stored, to something more proper.

## Relational Databases
A popular way of storing lots of data. Google, Twitter, FB and so on use them to store some of their data at scale. What’s nice is that they’re similar to the spreadsheets with which most are familiar with. 
	
A relational database is going to store, all its data in row and columns called tables. SQL does just 4 basic things. CRUD

* Creating data aka insert
* Reading data aka select
* Updating data aka update
* Deleting data aka drop 

Create a basic table like this
```
CREATE TABLE table (column type, ...);
```
* table = the title 
* column type is where you list your headers of the table

### creating a new empty database using a program called sqlite3 
```
sqlite3 favorites.db 

$ sqlite3 favorites.db
Are you sure you want to create favorites.db? [y/N] y
SQLite version 3.40.1 2022-12-28 14:03:47
Enter ".help" for usage hints.
sqlite> .mode csv -- preparing it to read a csv file
sqlite> .import example_file.csv favorites-- importing said file called favorites
sqlite> .schema -- a keyword to show the macro of the loaded database
```
The most common and useful syntax is SELECT. Everything in all caps is a SQL keyword. It isn’t necessary but stylistically preferred.  
```
SELECT columns FROM table; -- aka read data
```
* Again, table is the title of the table I’m reading from.
* SELECT * is saying give me every column without me even knowing what they’re called.
* What was 15 lines of code in Python, is now 1 line in SQL. WOW.

An actual use case from what we were just doing in Python. Although, I don’t have the .csv file or data table loaded. 
```
SELECT language FROM favorites;
```
## Fns in SQL
Here is a list of some of the most useful fns in SQL
 
* AVG
* COUNT
* DISTINCT gives back just uniques
* LOWER
* MAX
* MIN
* UPPER
* …
 
### give me the total count of the columns in my file
```
SELECT COUNT(*) FROM favorites;
``` 
### give me all the choices selected in a small list which only prints unique entries
```
SELECT DISTINCT(language) FROM favorites;
```
### give me back a physical number of the total amount of choices selected
```
SELECT COUNT(DISTINCT(language)) FROM favorites;
```

Here is a list of some more advanced fns in SQL
 
•	WHERE filters data
•	LIKE aka to an = sign
•	ORDER BY aka sorting
•	LIMIT sets a limit to rows
•	GROUP BY is better explained in example form
•	…

### give me just the amount of rows for C
```
SELECT COUNT(*) FROM favorites WHERE language = 'C';
```
### even more granular
```
SELECT COUNT(*) FROM favorites WHERE language = 'C'; AND problem = 'Mario';
```
### give me a two temporary cols  where 1st col is lang and 2nd is the count thereof data set
```
SELECT language, COUNT(*) FROM favorites GROUP BY language;
```
### creating data aka using the keyword insert
```
INSERT INTO table (column, ...) VALUES(value, ...);
```
### using the UPDATE keyword aka command, to update a column
```
UPDATE table SET column = value WHERE condition;
```
#### using the keyword DELETE removes rows specifically 
```
DELETE FROM table WHERE condition;
```


## Schemas
IMDb has millions of entries of flat file database data for anyone to download. David using Python and SQL created an “entity relationship diagram.” The image is that of 6 tables with arrows pointing directionally around. What makes SQL unique (I’m assuming R as well) is you can have multiple data sets which is to say, multiple tables. 

Back to the entity relationship diagram there are 6 dedicated tables for different aspects of data. Things like genre’s ratings, writers, shows, movies, actors. 

And as mentioned, schemas are a keyword to show the macro of the loaded databases.

Relational databases allow you to create relations between tables which allows you to factor out some of your information and store specifically versatile data in a way that allows for actual flexibility. The example being from IMDb, one table would be about listing shows, which would include columns such as: id, title, year, and # of episodes. Genres however would be in its own table which contains: show_id and genre. This frees up how specific each table has be to. Afterall a show can be more than 1 genre and tight casting it is messy and not optimized.

Everything is connected from 1 main table to then 5 sub-tables. The main table has a column called ID, while the sub-tables have a column called show_id.

The POINT, rather than hardcoding things like genre or ratings into the main table “shows,” we use relational connections to allow versatility. If we placed “people” in the shows table, then people could only be featured in 1 show. OR they would be relisted repeatedly. Creating a mess and not efficient use of data. 

Using separate tables for: people, genres, ratings, writers allow our main table “shows” to operate efficiently and relate one thing to another. 

## Data Types
In the world of SQLite, there’s these 5 data types:

* BLOB – Binary large object
* INTEGER – an int
* NUMERIC – a catchall for nums that are formatted specifically like dates and time
* REAL – aka float
* TEXT – strings and the like


## Constraints
Not data types but important
* NOT NULL – makes sure NULL is never applied 
* UNIQUE – makes sure every row in a column is always unique aka whatever value is being stored is always unique

## Data types: PRIMARY KEY, FOREIGN KEY, Relationships
PRIMARY KEY (A column): The database will use the ID as the unique identifier. Similar to UNIQUE making sure that this column is uniquely identifying your database will treat special. 

FOREIGN KEY: References to other columns, aka the copy keys. They have a different variable name aka column name, but contain the same value.

PRIMARY KEY & FOREIGN KEY Are what line up and point to other tables whether the parent or child 

JOIN: The most powerful keywords in SQL. Join two tables together using PRIMARY KEY & FOREIGN KEY(S) to sync the data around those keys.

### Indexes
You can tell the database to index the data for you. An index is an efficient cheat sheet for finding data fast. Books often have indices at the end of the book. A way for you to find a certain keyword quickly. 
By default, the columns are going to be searched in a linear search aka top to bottom left to right. Using indexes and greatly accelerate the process and is apt to a logarithmic search. 

## Python and SQL
In the real world Devs are constantly using 2 or more languages at once.	
```
# Searches database popularity of a problem
import csv
from cs50 import SQL

# Open database
db = SQL("sqlite:///favorites.db")
```
```
# Prompt user for favorite
favorite = input("Favorite: ")

# Search for title using SQL in the ()
rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", "%" + favorite + "%")

# Get first (and only) row
row = rows[0]

# Print popularity
print(row["COUNT(*)"])
```

### Race Conditions
Last round of advanced SQL keywords:
•	BEGIN TRANSACTION -  wait for 1 thing to finish before allowing another 
•	COMMIT
•	ROLLBACK - rewind

There is always a solution to coding problems
