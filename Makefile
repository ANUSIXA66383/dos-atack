all: build run

build:
	# Build the project
	go build dos.go
	g++ -o ccp-dos dos.cpp

run_python:
	# Run the 
    python3 python-dos.py

run_java_script:
	# Run the 
    node dos.js

echo_control_files:
	# Echo control files
	echo info.json data.xml README.md Makefile

run_go:
	# Run the 
	go run dos.go

run_perl:
	# Run the 
	perl dos.perl

run_php:
	# Run the 
	php -e dos.php

.PHONY: all build run_python run_java_script echo_control_files run_go run_perl run_php