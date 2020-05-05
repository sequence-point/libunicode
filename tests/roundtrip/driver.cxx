#include <libunittest/unittest.hxx>

#include <libunicode/decoding.hxx>
#include <libunicode/encoding.hxx>

#include <cstdint>
#include <sstream>
#include <string>

DEFINE_TEST("UTF-8: round trip")
{
  unicode::utf8_encoder encoder;
  unicode::utf8_decoder decoder;

  for (std::uint32_t i = 0; i <= 0x10ffff; ++i) {
    std::stringstream str;

    encoder.encode(str, i);

    auto string = str.str();

    TEST_EQUAL(i, decoder.decode(string.begin(), string.end()));
  }
}
