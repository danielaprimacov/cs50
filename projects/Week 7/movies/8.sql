SELECT people.name
    FROM people, stars, movies
        WHERE stars.person_id = people.id AND
            movies.id = stars.movie_id AND movies.title = "Toy Story"
