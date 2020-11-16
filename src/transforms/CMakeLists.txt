add_library(
  transforms
  streamers/streamer.cc
  common/bin_utils.cc
  binary_reader_transforms/bin_to_bin_as_ascii_transform.cc
  binary_reader_transforms/bin_to_hex_as_ascii_transform.cc
  binary_writer_transforms/ascii_as_bin_to_bin_transform.cc
  binary_writer_transforms/ascii_as_hex_to_bin_transform.cc
)

target_include_directories(transforms PUBLIC "include")
