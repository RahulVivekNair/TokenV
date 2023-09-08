# TokenV

## Overview

This is a small command-line utility to visualize the generation of tokens by a language model (LLM) on the console. It provides a simple way to observe how tokens are generated at a specified speed.

![Demo](demo.gif)

## Features

- Load tokens from a file or use a default set of tokens.
- Control the token generation speed by specifying the number of tokens per second.

## Usage

### Command-Line Options

- `-t <number_of_tokens>`: Specify the number of tokens to generate per second.
- `-f <filename>` (optional): Provide a text file containing tokens to use as the source. If not specified, a default set of tokens will be used.

### Examples

1. Generate tokens at a rate of 2 tokens per second:
   `./token-generator -t 2`
2. Generate tokens with words.txt as source:
   `./token-generator -t 10 -f words.txt`
