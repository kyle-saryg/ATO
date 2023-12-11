package main

import (
	"fmt"
)

func main() {
	fmt.Print("Hello there\n")
	server := NewAPIServer(":3000")
}
