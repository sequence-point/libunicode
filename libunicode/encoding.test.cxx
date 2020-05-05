#include <libunittest/unittest.hxx>

#include <libunicode/encoding.hxx>

#include <sstream>
#include <string>

DEFINE_TEST("UTF-8: 0")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0);

  auto string = str.str();

  TEST_EQUAL(string.size(), 1);
  TEST_EQUAL(string[0], 0);
}

DEFINE_TEST("UTF-8: 0x7f")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0x7f);

  auto string = str.str();

  TEST_EQUAL(string.size(), 1);
  TEST_EQUAL((unsigned char)string[0], 0x7f);
}

DEFINE_TEST("UTF-8: 0x80")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0x80);

  auto string = str.str();

  TEST_EQUAL(string.size(), 2);
  TEST_EQUAL((unsigned char)string[0], 0xc2);
  TEST_EQUAL((unsigned char)string[1], 0x80);
}

DEFINE_TEST("UTF-8: 0x7ff")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0x7ff);

  auto string = str.str();

  TEST_EQUAL(string.size(), 2);
  TEST_EQUAL((unsigned char)string[0], 0xdf);
  TEST_EQUAL((unsigned char)string[1], 0xbf);
}

DEFINE_TEST("UTF-8: 0x800")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0x800);

  auto string = str.str();

  TEST_EQUAL(string.size(), 3);
  TEST_EQUAL((unsigned char)string[0], 0xe0);
  TEST_EQUAL((unsigned char)string[1], 0xa0);
  TEST_EQUAL((unsigned char)string[2], 0x80);
}

DEFINE_TEST("UTF-8: 0xffff")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0xffff);

  auto string = str.str();

  TEST_EQUAL(string.size(), 3);
  TEST_EQUAL((unsigned char)string[0], 0xef);
  TEST_EQUAL((unsigned char)string[1], 0xbf);
  TEST_EQUAL((unsigned char)string[2], 0xbf);
}

DEFINE_TEST("UTF-8: 0x10000")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0x10000);

  auto string = str.str();

  TEST_EQUAL(string.size(), 4);
  TEST_EQUAL((unsigned char)string[0], 0xf0);
  TEST_EQUAL((unsigned char)string[1], 0x90);
  TEST_EQUAL((unsigned char)string[2], 0x80);
  TEST_EQUAL((unsigned char)string[3], 0x80);
}

DEFINE_TEST("UTF-8: 0x10ffff")
{
  std::stringstream str;

  unicode::utf8_encoder utf8;
  utf8.encode(str, 0x10ffff);

  auto string = str.str();

  TEST_EQUAL(string.size(), 4);
  TEST_EQUAL((unsigned char)string[0], 0xf4);
  TEST_EQUAL((unsigned char)string[1], 0x8f);
  TEST_EQUAL((unsigned char)string[2], 0xbf);
  TEST_EQUAL((unsigned char)string[3], 0xbf);
}
