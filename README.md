# BIO - Binary Input Output

`bio` is a binary file manipulation tool allowing users to write binary files directly using a traditional text editor.

- Designed to assist developers of binary file formats & others working closely with them
- `bio` is intended to **decouple the reading and the writing** of binary files for easier debugging

## Usaage & Options

`bio` will read from `stdin` and will output to `stdout`, I/O redirection is done via shell I/O redirection

### Recognized file format keywords
- Human Readable Hex: `hex`
- Human Readable Binary: `hrbin`
- Binary: `bin`

### Command Invocation

```bash
bio -o output_type -i input_type < input/file/path > output/file/path
```

### Options

| Option | Usage |
| :----: | :---: |
| `-o` / `--output` | Specify output file format |
| `-i` / `--input` | Specify input file format |

---

## Supported Transformations

1. **Binary to Human Readable Binary (ASCII encoded)**
	- Binary is interpreted **one byte at a time**, each byte is converted to an ASCII string representing it's binary value
> The byte *00000101* will be translated to the ASCII string *"00000101"*

2. **Binary to Human Readable Hex (ASCII encoded)**
	- Binary is interpreted **one byte at a time**, each byte is converted to an ASCII string representing it's hex value
> The byte *01111111* will be translated to the ASCII string *"7F"*

3. **Human Readable Binary (ASCII encoded) to Binary**
	- ASCII is interpreted as binary where each ASCII character corresponds to **one bit** of binary
> The string *"00001011"* will be translated to the byte *00001011*

4. **Human Readable Hex (ASCII encoded) to Binary**
	- ASCII is interpreted as binary where each ASCII character corresponds to a nibble of binary (based on that character's hex value)
> The string *"7F 46"* will be translated to the byte sequence *01111111  01000110*

## Noteworthy Behavior
- When transforming ASCII text to binary Ex. `bmanip -i hex -o bin < input/file/path`
	- Incomplete bytes at the end of a file will be truncated. A file containing the string *"00101"* will be truncated to an empty binary file on transformation as it contains less than one byte of information
- When transforming ASCII text to binary
	1. All whitespace characters will be ignored
	2. Any non whitespace characters that are not in the alphabet of the input format (Ex *'Q'* is not in the alphabet for the hex format) will be treated as the value 0
