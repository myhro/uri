build:
	docker-compose build

clean:
	rm -f a.out

db:
	docker-compose up -d db

db-shell:
	docker-compose run --rm db sh

down:
	docker-compose down

shell:
	docker-compose run --rm app bash
