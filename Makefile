build:
	docker-compose build

clean:
	rm -f a.out

shell:
	docker-compose run --rm app bash
