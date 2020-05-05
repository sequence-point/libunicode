#include <libunittest/unittest.hxx>

#include <libunicode/decoding.hxx>

#include <string>

DEFINE_TEST("UTF-8: 0 <= codepoint <= 0x7f")
{
  std::string const encoded_0{ "\x00", 1 };
  std::string const encoded_1{ "\x7f", 1 };

  unicode::utf8_decoder utf8;

  auto decoded_0 = utf8.decode(encoded_0.begin(), encoded_0.end());
  auto decoded_1 = utf8.decode(encoded_1.begin(), encoded_1.end());

  TEST_EQUAL(decoded_0, 0);
  TEST_EQUAL(decoded_1, 0x7f);
}

DEFINE_TEST("UTF-8: 0x80 <= codepoint <= 0x7ff")
{
  std::string const encoded_0{ "\xc2\x80" };
  std::string const encoded_1{ "\xdf\xbf" };

  unicode::utf8_decoder utf8;

  auto decoded_0 = utf8.decode(encoded_0.begin(), encoded_0.end());
  auto decoded_1 = utf8.decode(encoded_1.begin(), encoded_1.end());

  TEST_EQUAL(decoded_0, 0x80);
  TEST_EQUAL(decoded_1, 0x7ff);
}

DEFINE_TEST("UTF-8: 0x800 <= codepoint <= 0xffff")
{
  std::string const encoded_0{ "\xe0\xa0\x80" };
  std::string const encoded_1{ "\xef\xbf\xbf" };

  unicode::utf8_decoder utf8;

  auto decoded_0 = utf8.decode(encoded_0.begin(), encoded_0.end());
  auto decoded_1 = utf8.decode(encoded_1.begin(), encoded_1.end());

  TEST_EQUAL(decoded_0, 0x800);
  TEST_EQUAL(decoded_1, 0xffff);
}

DEFINE_TEST("UTF-8: 0x10000 <= codepoint <= 0x10ffff")
{
  std::string const encoded_0{ "\xf0\x90\x80\x80" };
  std::string const encoded_1{ "\xf4\x8f\xbf\xbf" };

  unicode::utf8_decoder utf8;

  auto decoded_0 = utf8.decode(encoded_0.begin(), encoded_0.end());
  auto decoded_1 = utf8.decode(encoded_1.begin(), encoded_1.end());

  TEST_EQUAL(decoded_0, 0x10000);
  TEST_EQUAL(decoded_1, 0x10ffff);
}
