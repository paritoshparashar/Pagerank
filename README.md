# Page Rank Project

This project is an implementation of a PageRank algorithm using C, designed to analyze directed graphs and compute the PageRank of its vertices. This project is part of the Saarland University Programming 2 course for the Summer Term 2024.

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)

## Overview

The goal of this project is to compute the PageRank of vertices in a directed graph, which can be considered as websites connected by hyperlinks. The implementation uses two methods to calculate the PageRank:

1. **Random Surfer Model:** Simulates the behavior of a random surfer navigating through the network of websites to approximate PageRank.
2. **Markov Chain Model:** Uses mathematical foundations to compute PageRank with higher precision.

## Installation

To compile and run the program, ensure you have a C compiler installed (e.g., `gcc`). Follow the steps below:

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/pagerank.git
   cd pagerank
2. Compile the project using `make`
   ```bash
   make
   
## Usage

The pagerank program can be executed with various command line options:
   ```bash
   ./pagerank [OPTIONS]... [FILENAME]
   ```

### Options
*   -h   : Print a brief overview of the available command line parameters.
*   -r N : Simulate N steps of the random surfer and output the result.
*   -m N : Simulate N steps of the Markov chain and output the result.
*   -s   : Compute and print the statistics of the graph.
*   -p P : Set the probability parameter p for the random surfer model (default is 10%).


### Examples
To run a simulation using the random surfer model for 100 steps:
```bash
./pagerank -r 100 graph.dot
```
To run a simulation using the markov chains model with probability(=15):
```bash
./pagerank -m -p 15 prog2graph.dot
```
To display all the different parameter options
```bash
./ pagerank -h
```

## Features

+ Random Surfer Simulation: Approximates the PageRank by simulating a user's navigation through the network.
+ Markov Chain Computation: Provides a more accurate PageRank calculation using matrix multiplication.
+ Graph Statistics: Computes and prints statistics about the input graph.

## Contributing
Contributions are welcome! Please follow these steps:

+ Fork the repository.
+ Create a new branch
  ```bash
   git checkout -b feature/your-feature
   ```
+ Commit your changes
  ```bash
   git commit -m 'Add your feature'
   ```
+ Push to the branch
  ```bash
   git push origin feature/your-feature
   ```
+ Open a pull request.
