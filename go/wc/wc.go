package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
  args := os.Args
  fileName := args[2]
  if args[1] == "-c" {
    dat, err := os.ReadFile(fileName)
    if err != nil {
      panic(err)
    }
    fmt.Printf("%d %s", len(dat), fileName)
  } else if args[1] == "-l" {
    fileReader, err := os.Open(fileName)
    if err != nil {
      panic(err)
    }
    fileScanner := bufio.NewScanner(fileReader)
    lineCount := 0
    for fileScanner.Scan() {
      lineCount++;
    }
    fmt.Printf("%d %s", lineCount, fileName)
  } else if args[1] == "-w" {
    dat, err := os.ReadFile(fileName)
    if err != nil {
      panic(err)
    }
    content := string(dat)
    fmt.Print(content)
    words := strings.Split(content, " ")
    fmt.Print(len(words))
  }
}
