SELECT DISTINCT people.name FROM people, stars, movies
WHERE stars.movie_id = movies.id AND movies.year = 2004
 AND stars.person_id = people.id ORDER BY people.birth
