#include "transform.h"
#include "bin_to_ascii_transform.h"
#include "ascii_to_bin_transform.h"

#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum class Type { BIN, ASCII }; // What format to ouput data as

struct Args 
{
	Type it; // input type
	Type ot; // Output type
	bool format = false;
};

Type getType(const string &str) 
{
	if (str == "bin"){ return Type::BIN; }
	else if (str == "ascii") { return Type::ASCII; }
	else { throw "unrecognized type"; }
}

Args parseArgs(int argc, char **argv)
{
	Args args;
	for (int i = 1; i < argc; i++)
	{
		string s(argv[i]);
		if (s == "-i" || s == "--input-type")
		{
			if (i+1 == argc) { throw "no arg to type"; }
			args.it = getType(string(argv[i+1]));
			i++; // Compensate for already seeing next arg
		}
		else if (s == "-o" || s == "--output-type")
		{
			if (i+1 == argc) { throw "no arg to type"; }
			args.ot = getType(string(argv[i+1]));
			i++; // Compensate for already seeing next arg
		}
		else if (s == "-f" || s == "--format")
		{
			args.format = true;
		}
	}

	return args;
}

// Example:
// In BIN, out ASCII --> Out spits out streem of ascii 0's and 1's
// In ASCII, out BIN --> Assume all ascii chars are 0s or 1s and output the binary
int main(int argc, char **argv)
{
	Args args = parseArgs(argc, argv);
	std::unique_ptr<Transform> transform = nullptr;
	std::istream &in = cin;
	std::ostream &out = cout;

	if (args.it == Type::BIN && args.ot == Type::ASCII)
	{
		transform.reset(new BinToAsciiTransform(in, out, args.format));
	}
	else if (args.it == Type::ASCII && args.ot == Type::BIN)
	{
		transform.reset(new AsciiToBinTransform(in, out, args.format));
	}

	transform->process();

}

