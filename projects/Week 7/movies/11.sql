SELECT movies.title FROM movies, stars, people, ratings
WHERE people.id = stars.person_id AND
    movies.id = stars.movie_id AND
    ratings.movie_id = movies.id AND
    people.name = "Chadwick Boseman" ORDER BY ratings.rating DESC LIMIT 5;