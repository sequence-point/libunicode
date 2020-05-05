#include <libunittest/unittest.hxx>

#include <libunicode/decoding.hxx>
#include <libunicode/encoding.hxx>

#include <cstdint>
#include <sstream>
#include <string>
#include <iterator>

DEFINE_TEST("UTF-8: round trip")
{
  unicode::utf8_encoder encoder;
  unicode::utf8_decoder decoder;

  for (std::uint32_t i = 0; i <= 0x10ffff; ++i) {
    std::stringstream str;

    encoder.encode(str, i);

    auto unicode = decoder.decode(std::istreambuf_iterator< char >{ str },
                                  std::istreambuf_iterator< char >{});

    TEST_EQUAL(i, unicode);
  }
}

DEFINE_TEST("UTF-8: sequence")
{
  std::stringstream str;

  unicode::utf8_encoder encoder;
  unicode::utf8_decoder decoder;

  encoder.encode(str, 0x300);
  encoder.encode(str, 0x400);

  auto unicode_0 = decoder.extract(str);
  auto unicode_1 = decoder.extract(str);

  TEST_EQUAL(unicode_0, 0x300);
  TEST_EQUAL(unicode_1, 0x400);
}
