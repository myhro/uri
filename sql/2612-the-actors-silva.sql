SELECT movies.id, movies.name
    FROM movies
    INNER JOIN movies_actors ON (movies.id = movies_actors.id_movies)
    INNER JOIN actors ON (movies_actors.id_actors = actors.id)
    INNER JOIN genres ON (movies.id_genres = genres.id)
    WHERE actors.name IN ('Marcelo Silva', 'Miguel Silva')
        AND genres.description = 'Action'
    GROUP BY movies.id;
