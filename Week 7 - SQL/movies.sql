--1.sql
SELECT title FROM movies WHERE year = 2008;
   

--2.sql
SELECT birth FROM people WHERE name = "Emma Stone";


--3.sql
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;


--4.sql
SELECT COUNT(title) FROM movies WHERE movies.id IN (SELECT movie_id FROM ratings WHERE rating = 10);


--5.sql
SELECT title, year FROM movies WHERE title LIKE "%Harry Potter%" ORDER BY year;


--6.sql
SELECT AVG(ALL rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);


--7.sql
SELECT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2010 AND ratings.rating IS NOT NULL
ORDER BY ratings.rating DESC, movies.title ASC;


--8(1).sql
SELECT name FROM people, movies, stars
WHERE people.id = stars.person_id
AND stars.movie_id = movies.id
AND title = "Toy Story";

--8(2).sql
SELECT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE title = "Toy Story";


--9.sql
SELECT DISTINCT name FROM people, movies, stars
WHERE people.id = stars.person_id
AND stars.movie_id = movies.id
AND year = 2004 ORDER BY birth;


--10.sql
SELECT DISTINCT name FROM people, directors, ratings
WHERE directors.person_id = people.id
AND directors.movie_id = ratings.movie_id
AND rating >= 9.0;


--11.sql
SELECT title FROM movies, stars, people, ratings
WHERE movies.id = stars.movie_id AND movies.id = ratings.movie_id
AND people.id = stars.person_id
AND name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;


--12.sql
SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = "Helena Bonham Carter" AND title
IN (SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = "Johnny Depp");


--13.sql
SELECT DISTINCT(name) FROM people
JOIN stars ON stars.person_id=people.id
WHERE id IN (SELECT stars.person_id FROM stars WHERE stars.movie_id
IN (SELECT stars.movie_id FROM stars WHERE stars.person_id = (
    SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)))
AND name != "Kevin Bacon";
