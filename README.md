# BManip

`bmanip` is a binary file manipulation tool allowing users to write binary files directly using a regular text editor.
- Mainly for educational purposes including experimenting with
	- File's identifying magic number 
	- Other binary data as it is stored on the OS
- Not suggested to try to make meaningful changes to a binary file with this tool

### Supported Modes 
1. Bin --> Ascii
- Binary is interpreted **one bit at a time**, each bit is converted to ascii and then output

> The binary file with contents 0b00101 will be translated the ascii string "00101"

2. Ascii --> Bin
- Ascii is interpreted as binary where each ASCII character corresponds to **one bit** of binary

> The string "0001011" in as ASCII will be translated to the binary file with contents 0b0001011

### Options and CLI

| Option | Usage | 
| :----: | :---: |
| `-o` / `--output` | Specify output file format | 
| `-i` / `--input` | Specify input file format |
| `-f` / `--format` | Format Output |

```bash
bmanip -o <output type> -i <input type>  < input/file/path
```