#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>
#include <optional>

#include "streamer.h"

class Transform
{
protected:
  Streamer streamer;
  const unsigned read_size               = 1;  // bytes read per thing
  unsigned long addr                     = 0;
  std::optional<unsigned long> startAddr = std::nullopt;
  std::optional<unsigned long> endAddr   = std::nullopt;

public:
  Transform(std::istream &in, std::ostream &out, bool formatted) : streamer(in, out, formatted) {}

  virtual void process() = 0;

  virtual ~Transform(){};

  void setStartAddr(unsigned long start)
  {
    startAddr = start;
  }

  void setEndAddr(unsigned long end)
  {
    startAddr = end;
  }

protected:
  Streamer &Out()
  {
    return streamer;
  }
  Streamer &In()
  {
    return streamer;
  }

  bool inRange()
  {
    if (!startAddr.has_value()) return true;
    else if (addr >= startAddr.value()) {
      if (!endAddr.has_value() || addr <= endAddr.value()) return true;
    }
    return false;
  }

  bool pastEndAddr()
  {
    return endAddr.has_value() && (addr > endAddr.value());
  }
};

#endif
