SELECT DISTINCT people.name FROM people, movies, stars
WHERE people.id = stars.person_id AND
    movies.id = stars.movie_id AND
    movies.title IN (
        SELECT DISTINCT movies.title FROM people, movies, stars
        WHERE people.id = stars.person_id AND
        movies.id = stars.movie_id AND
        people.name = "Kevin Bacon" AND people.birth = 1958
    ) AND people.name != "Kevin Bacon";