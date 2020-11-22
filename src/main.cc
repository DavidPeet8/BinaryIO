#include <iostream>
#include <memory>
#include <optional>
#include <string>

#include "ascii_as_bin_to_bin_transform.h"
#include "ascii_as_hex_to_bin_transform.h"
#include "bin_to_bin_as_ascii_transform.h"
#include "bin_to_hex_as_ascii_transform.h"
#include "bin_utils.h"
#include "transform.h"
using namespace std;

enum class Type
{
  BIN,
  ASCII_BIN,
  ASCII_HEX
};  // What format to ouput data as

struct Args
{
  Type it;  // input type
  Type ot;  // Output type
  bool format                        = false;
  optional<unsigned long> start_addr = std::nullopt;
  optional<unsigned long> end_addr   = std::nullopt;
};

Type getType(const string &str)
{
  if (str == "bin") {
    return Type::BIN;
  } else if (str == "hrbin") {
    return Type::ASCII_BIN;
  } else if (str == "hex") {
    return Type::ASCII_HEX;
  } else {
    throw "unrecognized type";
  }
}

unsigned long getValInBase(const string &num, unsigned base)
{
  unsigned long ret = 0;

  for (int i = 2; i < num.length(); i++) {
    ret *= base;
    if (base == 16) {
      ret += BinUtils::getHexDigit(num[i]);
    } else {
      ret += num[i] - '0';
    }
  }

  return ret;
}

unsigned long strBaseToUL(const string &num)
{
  if (num.length() >= 2 && num[0] == '0') {
    if (num[1] == 'x') {  // Interp as Hex
      return getValInBase(num, 16);
    } else if (num[1] == 'b') {  // Interp as Binary
      return getValInBase(num, 2);
    } else if (num[1] == 'o') {  // Interp as Octal
      return getValInBase(num, 8);
    }
  }

  // default interpret as decimal
  return stoul(num);
}

Args parseArgs(int argc, char **argv)
{
  Args args;

  for (int i = 1; i < argc; i++) {
    string s(argv[i]);
    if (s == "-i" || s == "--input-type") {
      if (i + 1 == argc) {
        throw "no arg to type";
      }
      args.it = getType(string(argv[i + 1]));
      i++;  // Compensate for already seeing next arg
    } else if (s == "-o" || s == "--output-type") {
      if (i + 1 == argc) {
        throw "no arg to type";
      }
      args.ot = getType(string(argv[i + 1]));
      i++;  // Compensate for already seeing next arg
    } else if (s == "-f" || s == "--format") {
      args.format = true;
    } else if (s == "-s") {  // Starting address to read from
      unsigned long addr = strBaseToUL(argv[i + 1]);
      args.start_addr    = make_optional<unsigned long>(addr);

    } else if (s == "-e") {  // End address to read up to - exclusive
      unsigned long addr = strBaseToUL(argv[i + 1]);
      args.end_addr      = make_optional<unsigned long>(addr);
    }
  }

  return args;
}

// Example:
// In BIN, out ASCII --> Out spits out streem of ascii 0's and 1's
// In ASCII, out BIN --> Assume all ascii chars are 0s or 1s and output the
// binary
int main(int argc, char **argv)
{
  Args args                            = parseArgs(argc, argv);
  std::unique_ptr<Transform> transform = nullptr;
  std::istream &in                     = cin;
  std::ostream &out                    = cout;

  if (args.it == Type::BIN && args.ot == Type::ASCII_BIN) {
    transform.reset(new BinToBinAsAsciiTransform(in, out, args.format));
  } else if (args.it == Type::ASCII_BIN && args.ot == Type::BIN) {
    transform.reset(new AsciiAsBinToBinTransform(in, out, args.format));
  } else if (args.it == Type::ASCII_HEX && args.ot == Type::BIN) {
    transform.reset(new AsciiAsHexToBinTransform(in, out, args.format));
  } else if (args.it == Type::BIN && args.ot == Type::ASCII_HEX) {
    transform.reset(new BinToHexAsAsciiTransform(in, out, args.format));
  } else {
    cout << "Unsupported I/O config." << endl;
    exit(1);
  }

  if (args.start_addr.has_value()) {
    transform->setStartAddr(args.start_addr.value());
  }
  if (args.end_addr.has_value()) {
    transform->setEndAddr(args.start_addr.value());
  }

  transform->process();
}
