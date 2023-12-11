build:
	@go build -o bin/server

clean: 
	@rm ./bin/server

run: build
	@./bin/server

test:
	@go test -v ./...
