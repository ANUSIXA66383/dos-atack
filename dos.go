package main

import (
	"fmt"
	"net/http"
)

func main() {
	var website string
	fmt.Print("Enter the website: ")
	fmt.Scanln(&website)

	for {
		resp, err := http.Get(website)
		if err != nil {
			fmt.Println(err)
			return
		}
		defer resp.Body.Close()
		fmt.Println("Response code:", resp.StatusCode)
	}
}
