#!/bin/bash

cd bin
printf "Server started, now you can open localhost:8000/test.html to see the result of running the code\n"
python -m SimpleHTTPServer
