SELECT movies.title FROM movies, stars, people
WHERE people.id = stars.person_id AND
    movies.id = stars.movie_id AND
    people.name = "Johnny Depp" AND movies.title IN (
        SELECT movies.title FROM movies, stars, people
        WHERE people.id = stars.person_id AND
        movies.id = stars.movie_id AND
        people.name = "Helena Bonham Carter"
    )